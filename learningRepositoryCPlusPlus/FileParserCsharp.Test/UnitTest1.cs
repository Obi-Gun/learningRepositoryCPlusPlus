using FileParserCsharp;
using NUnit.Framework;
using System.Security.Cryptography.X509Certificates;

namespace FileParserCsharp.Test
{
    [TestFixture]
    public class ParserTest
    {
        /// <summary>
        /// testmethod: public void filterStrWith(string key)
        /// </summary>
        [Test]
        public void filterStrWith_ifGet4StringsAndFilterTrirdStrThenTestPassed()
        {
            Parser parser = new Parser();
            string text = "5\n55\n666..\n8";
            parser.SetText(text);
            string key = ".";
            parser.filterStrWith(key);
            Assert.That("\n666..", Is.EqualTo(parser.getFilteredStrings()));
        }

        /// <summary>
        /// testmethod: public void separateSubStr(string separators)
        /// </summary>
        [Test]
        public void separateSubStr_()
        {
            Parser parser = new Parser();
            string text = "Olia/Kolia.Tolia";
            string expected = " Olia Kolia Tolia\n";
            parser.SetText(text);
            parser.filterStrWith();
            parser.separateSubStr("/.");
            parser.filterNeededColumns();
            Assert.That(expected, Is.EqualTo(parser.getFilteredSubStrings()));
        }

        /// <summary>
        /// testmethod: public void filterNeededColumns(string neededColumnsSeparatedByComma)
        /// </summary>
        [Test]
        public void filterNeededColumns_()
        {
            Parser parser = new Parser();
            string text = "Olia.Kolia.Tolia.Egor . Evgeny.Goga_Ivanov";
            string expected = " Kolia Tolia Goga_Ivanov\n";
            parser.SetText(text);
            parser.filterStrWith();
            parser.separateSubStr(".");
            parser.filterNeededColumns("2,1,5");
            Assert.That(expected, Is.EqualTo(parser.getFilteredSubStrings()));
        }

        /// <summary>
        /// testmethod: public string getText()
        /// </summary>
        [Test]
        public void getText_ifTextIsNullThenThrowException()
        {
            try
            {
                Parser parser = new Parser();
                parser.getText();
                Assert.Fail();
            }
            catch (ParserException e) { }
        }

        /// <summary>
        /// testmethod: public string getFilteredStrings()
        /// </summary>
        [Test]
        public void getFilteredStrings_ifFilteredStringsIsNullThenThrowException()
        {
            try
            {
                Parser parser = new Parser();
                parser.getFilteredStrings();
                Assert.Fail();
            }
            catch (ParserException e) { }
        }

        /// <summary>
        /// testmethod: public string getFilteredSubStrings()
        /// </summary>
        [Test]
        public void getFilteredSubStrings_ifFilteredSubStringsIsNullThenThrowException()
        {
            try
            {
                Parser parser = new Parser();
                parser.getFilteredSubStrings();
                Assert.Fail();
            }
            catch (ParserException e) { }
        }

        /// <summary>
        /// testmethod: public string print()
        /// </summary>
        [Test]
        public void print_ifTextIsNullThenThrowException()
        {
            try
            {
                Parser parser = new Parser();
                parser.print();
                Assert.Fail();
            }
            catch (ParserException e) { }
        }

        /// <summary>
        /// testmethod: public void printFilteredStrings()
        /// </summary>
        [Test]
        public void printFilteredStrings_ifFilteredStringsIsNullThenThrowException()
        {
            try
            {
                Parser parser = new Parser();
                parser.printFilteredStrings();
                Assert.Fail();
            }
            catch (ParserException e) { }
        }

        /// <summary>
        /// testmethod: public void printFilteredSubStrings()
        /// </summary>
        [Test]
        public void printFilteredSubStrings_ifFilteredSubStringsIsNullThenThrowException()
        {
            try
            {
                Parser parser = new Parser();
                parser.printFilteredSubStrings();
                Assert.Fail();
            }
            catch (ParserException e) { }
        }

        /// <summary>
        /// testmethod: public void printSubStrings()
        /// </summary>
        [Test]
        public void printSubStrings_ifSubStringsIsNullThenThrowException()
        {
            try
            {
                Parser parser = new Parser();
                parser.printSubStrings();
                Assert.Fail();
            }
            catch (ParserException e) { }
        }
    }
}