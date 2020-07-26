using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace FileParserCsharp
{
    class Parser
    {
        private string _buffer;

        public void WriteFile(string destFilepath)
        {
            using (
                FileStream fs = new FileStream(destFilepath, FileMode.Create, FileAccess.Write, FileShare.None))
            {
                Console.WriteLine("Enter:");
                string writeText = Console.ReadLine();
                byte[] writeBytes = Encoding.Default.GetBytes(writeText);
                fs.Write(writeBytes, 0, writeBytes.Length);
                Console.WriteLine("recorded!");
            }
        }

        public void ReadFile(string sourseFilepath)
        {
            using (
                FileStream fs = new FileStream(sourseFilepath, FileMode.Open, FileAccess.Read, FileShare.Read))
            {
                byte[] readBytes = new byte[(int)fs.Length];
                fs.Read(readBytes, 0, readBytes.Length);
                _buffer = Encoding.Default.GetString(readBytes);
            }
        }

        /*void WriteFile(string destFilepath)
        {
            using (
                FileStream fs = new FileStream(destFilepath, FileMode.Create, FileAccess.Write, FileShare.None))
            {
                Console.WriteLine("Enter:");
                string writeText = Console.ReadLine();
                byte[] writeBytes = Encoding.Default.GetBytes(writeText);
                fs.Write(writeBytes, 0, writeBytes.Length);
                Console.WriteLine("recorded!");
            }
        }

        string ReadFile(string sourseFilepath)
        {
            using (
                FileStream fs = new FileStream(sourseFilepath, FileMode.Open, FileAccess.Read, FileShare.Read))
            {
                byte[] readBytes = new byte[(int)fs.Length];
                fs.Read(readBytes, 0, readBytes.Length);
                return Encoding.Default.GetString(readBytes);
            }
        }*/
    }
}
