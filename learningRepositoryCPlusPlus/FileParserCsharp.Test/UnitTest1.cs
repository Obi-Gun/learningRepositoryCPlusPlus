using FileParserCsharp;
using NUnit.Framework;
using System.Security.Cryptography.X509Certificates;

namespace FileParserCsharp.Test
{
    [TestFixture]
    public class ParserTest
    {
        [SetUp]
        public void Setup()
        {
        }

        //public void filterStrWith(string key)
        [TestCase]
        public void filterStrWith()
        {
            Parser parser = new Parser();
            string text = "5\n55\n666..\n8";
            parser.SetText(text);
            string key = ".";
            parser.filterStrWith(key);
            Assert.AreEqual("666..", parser.getFilteredStrings());
        }

        //private void concatFilteredStrings()
        
        //private char[] splitSeparators(string separators)
        //public void separateSubStr(string separators)
        //private void splitNeededColumns(string neededColumns)
        //private bool isInNeededColumns(int num)
        //public void filterNeededColumns(string neededColumnsSeparatedByComma)
    }
}