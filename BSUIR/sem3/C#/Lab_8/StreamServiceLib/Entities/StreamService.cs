using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Xml;

namespace StreamServiceLib.Entities
{
    public class StreamService<T>
    {
        XmlSerializer _serializer = new XmlSerializer(typeof(List<T>));
        private readonly AutoResetEvent _waitHandlerForStream = new(true);
        public async Task WriteToStreamAsync(Stream stream, IEnumerable<T> data, IProgress<string> progress)
        {
            await Task.Run(() =>
            {
                _waitHandlerForStream.WaitOne();
                long threadId = Environment.CurrentManagedThreadId;
                progress.Report($"Thread {threadId}: Starting write to the stream");

                using (var xmlWriter = XmlWriter.Create(stream, new XmlWriterSettings { Async = true }))
                {
                    _serializer.Serialize(xmlWriter, data.ToList());
                }

                for (var i = 0; i < 100; i++)
                {
                    //await Task.Delay(50);
                    string s = "";
                    int j;
                    for (j = 0; j < i / 5; ++j)
                    {
                        s += '=';
                    }
                    s += '>';
                    for (; j < 19; ++j)
                    {
                        s += ' ';
                    }
                    progress.Report($"Thread {threadId}: [{s}] {i}%");
                }

                progress.Report($"Thread {threadId}: Writing finished");
                _waitHandlerForStream.Set();
            });
        }

        public async Task CopyFromStreamAsync(Stream stream, string fileName, IProgress<string> progress)
        {
            _waitHandlerForStream.WaitOne();
            var threadId = Environment.CurrentManagedThreadId;
            progress.Report($"Thread {threadId}: Starting copy to the fileStream");

            await using var destinationStream = new FileStream(fileName, FileMode.Create);
            stream.Seek(0, SeekOrigin.Begin);
            await stream.CopyToAsync(destinationStream);

            progress.Report($"Thread {threadId}: Copy finished");
            _waitHandlerForStream.Set();
        }

        public async Task<int> GetStatisticsAsync(string fileName, Func<T, bool> filter)
        {
            await using Stream sourceStream = new FileStream(fileName, FileMode.Open);
            List<T>? data;

            using (var xmlReader = XmlReader.Create(sourceStream, new XmlReaderSettings { Async = true }))
            {
                data = (List<T>?)_serializer.Deserialize(xmlReader);
            }

            return data!.Where(filter).Count();
        }

    }
}
