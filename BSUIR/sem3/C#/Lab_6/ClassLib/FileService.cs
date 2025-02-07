using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using Lab_6_Task_1.Interfaces;
using Lab_6_Task_1.Entities;

namespace ClassLib
{
    internal class FileService<T> : IFileService<T> where T : class
    {
         public IEnumerable<T> ReadFile(string fileName)
        {
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                return JsonSerializer.Deserialize<List<T>>(fs)!;
            }
        }

        public void SaveData(IEnumerable<T> data, string fileName)
        {
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                JsonSerializer.SerializeAsync(fs, data.ToList());
            }
        }
    }
}
