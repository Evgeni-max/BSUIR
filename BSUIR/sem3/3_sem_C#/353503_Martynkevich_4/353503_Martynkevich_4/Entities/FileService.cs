using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_4.Entities
{
    internal class FileService
    {
        static public void SaveData(IEnumerable<Client> data, string fileName) {
            using (FileStream fs = new FileStream(fileName, FileMode.Create, FileAccess.Write))
            using(BinaryWriter bw = new BinaryWriter(fs))
            {
                foreach (var item in data)
                {
                    try
                    {
                        bw.Write(item.Id);
                        bw.Write(item.Name);
                        bw.Write(item.MumName);
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex.Message);
                        break;
                    }
                }
            }
        }

        static public IEnumerable<Client> ReadFile(string fileName)
        {
            using (FileStream fc = new FileStream(fileName, FileMode.OpenOrCreate, FileAccess.Read))
            using (BinaryReader br = new BinaryReader(fc))
            {
                while(br.BaseStream.Position < br.BaseStream.Length)
                {
                    Client client;

                    try
                    {
                        int _id = br.ReadInt32();
                        string _name = br.ReadString();
                        string _mumName = br.ReadString();

                        client= new Client(_id, _name, _mumName);
                    }
                    catch(Exception ex) 
                    {
                        Console.WriteLine(ex.Message);
                        break;
                    }

                    yield return client;
                }

            }
        }
    }
}
