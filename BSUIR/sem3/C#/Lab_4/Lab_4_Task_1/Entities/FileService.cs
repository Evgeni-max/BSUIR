using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace Lab_4_Task_1.Entities
{
    internal class FileService : Interfaces.IFiliService<Patient>
    {
        public void SaveData(IEnumerable<Patient> data, string fileName)
        {
            if (File.Exists(fileName))
            {
                File.Delete(fileName);
            }

            File.Create(fileName).Close();
            using var bw = new BinaryWriter(File.OpenWrite(fileName));

            foreach (Patient patient in data)
            {
                try
                {
                    bw.Write(patient.Id + ":" + patient.Infected + ":" + patient.Name);
                }
                catch
                {
                    throw new Exception("Error while writing file.");
                }
            }
        }

        public IEnumerable<Patient> ReadFile(string fileName)
        {
            if (File.Exists(fileName))
            {
                using var br = new BinaryReader(File.OpenRead(fileName));

                List<Patient> patients = new List<Patient>();
                while (br.PeekChar() > -1)
                {
                    try
                    {
                        patients.Add(new Patient(br.ReadString()));
                    }
                    catch
                    {
                        throw new Exception("Error while reading file.");
                    }
                    yield return patients[^1];
                }
            }
        }

        public static void RenameFile(string oldFilenameWithPathWithExtension, string newFilenameWithoutPathWithExtension)
        {
            try
            {
                string directoryPath = Path.GetDirectoryName(oldFilenameWithPathWithExtension);
                if (directoryPath == null)
                {
                    throw new Exception($"Directory not found in given path value:{oldFilenameWithPathWithExtension}");
                }

                var newFilenameWithPath = Path.Combine(directoryPath, newFilenameWithoutPathWithExtension);
                FileInfo fileInfo = new FileInfo(oldFilenameWithPathWithExtension);
                fileInfo.MoveTo(newFilenameWithPath);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }
    }
}
