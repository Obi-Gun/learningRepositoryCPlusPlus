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
            Parser parser = new Parser();
            try
            {
                parser.ReadFile("C:\\Users\\Alexandr\\Desktop\\Test.log");
                parser.filterStrWith("Request for");
                parser.separateSubStr(" _|");
                parser.printSubStrings();
                parser.filterNeededColumns("10,9,8,7,0,1");
                parser.WriteFilteredSubStringsToFile("C:\\Users\\Alexandr\\Desktop\\FilteredSubStrings.log");
            }
            catch (ParserException e)
            {
                Console.WriteLine("ParserException: ", e.Message);
            }
            
        }
    }
}
