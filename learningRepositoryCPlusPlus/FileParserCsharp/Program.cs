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
            Parser parser = new Parser("C:\\Users\\Alexandr\\Desktop\\Test.log", "C:\\Users\\Alexandr\\Desktop\\FilteredSubStrings.log",
                " _|", "Request for", "10,9,8,7,0,1");

            /*Parser parser2 = new Parser();
            try
            {
                parser2.ReadFile("C:\\Users\\Alexandr\\Desktop\\Test.log");
                parser2.filterStrWith("Request for");
                parser2.separateSubStr(" _|");
                parser2.printSubStrings();
                parser2.filterNeededColumns("10,9,8,7,0,1");
                parser2.WriteFilteredSubStringsToFile("C:\\Users\\Alexandr\\Desktop\\FilteredSubStrings.log");
            }
            catch (ParserException e)
            {
                Console.WriteLine("ParserException: " + e.Message);
            }*/
        }
    }
}
