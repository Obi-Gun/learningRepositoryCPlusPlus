using System;
using System.IO;
using System.Text;
using System.Threading;

namespace FileParserCsharp
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("Hello World!");
            WriteFile("C:\\Users\\Alexandr\\Desktop\\Result.log");
            string x = ReadFile("C:\\Users\\Alexandr\\Desktop\\Result.log");
            Console.WriteLine(x);

        }

       


        
    }
}
