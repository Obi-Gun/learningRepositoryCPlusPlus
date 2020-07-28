using System;
using System.IO;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace FileParserCsharp
{
    /// <summary>
    /// The main Parser class.
    /// Contains methods for read, filter and write substrings to file.
    /// </summary>
    /// <remarks>
    /// This class can read, filter by key, split by separators and write substrings to file.
    /// </remarks>
    public class Parser
    {
        private string _text;
        private string[] _filteredStringsArr;
        private string _filteredStrings;
        private string[,] _SubStrings;
        private string _filteredSubStrings;
        private int[] _neededColumns;
        private int _length { get; set; }
        private int _columns { get; set; }

        public Parser() { }
        public Parser(string sourceFilepath, string destFilepath, string subStrSeparators, string strFilter = "all strings", string neededSubStrColumnsSeparatedByComma = "all columns")
        {
            Parse(sourceFilepath, destFilepath, subStrSeparators, strFilter, neededSubStrColumnsSeparatedByComma);
        }

        /// <summary>
        /// The main logic method. Like in test task.
        /// </summary>
        /// <param name="sourceFilepath"></param>
        /// <param name="destFilepath"></param>
        /// <param name="subStrSeparators"></param>
        /// <param name="strFilter"></param>
        /// <param name="neededSubStrColumnsSeparatedByComma"></param>
        /// <example>
        ///    Parser parser2 = new Parser();
        ///    try
        ///    {
        ///        parser2.ReadFile("C:\\Users\\Alexandr\\Desktop\\Test.log");
        ///        parser2.filterStrWith("Request for");
        ///        parser2.separateSubStr(" _|");
        ///        parser2.printSubStrings();
        ///        parser2.filterNeededColumns("10,9,8,7,0,1");
        ///        parser2.WriteFilteredSubStringsToFile("C:\\Users\\Alexandr\\Desktop\\FilteredSubStrings.log");
        ///    }
        ///    catch (ParserException e)
        ///    {
        ///        Console.WriteLine("ParserException: " + e.Message);
        ///    }</example>
        private void Parse(string sourceFilepath, string destFilepath, string subStrSeparators, string strFilter, string neededSubStrColumnsSeparatedByComma)
        {
            try
            {
                this.ReadFile(sourceFilepath);
                this.filterStrWith(strFilter);
                this.separateSubStr(subStrSeparators);
                this.filterNeededColumns(neededSubStrColumnsSeparatedByComma);
                this.WriteFilteredSubStringsToFile(destFilepath);
            }
            catch (ParserException e)
            {
                Console.WriteLine("ParserException: " + e.Message);
            }
        }

        public void ReadFile(string sourceFilepath)
        {
            using (
                FileStream fs = new FileStream(sourceFilepath, FileMode.Open, FileAccess.Read, FileShare.Read))
            {
                byte[] readBytes = new byte[(int)fs.Length];
                fs.Read(readBytes, 0, readBytes.Length);
                _text = Encoding.Default.GetString(readBytes);
            }
        }

        private void WriteFile(string destFilepath, string textToBeWrited)
        {
            using (
                FileStream fs = new FileStream(destFilepath, FileMode.Create, FileAccess.Write, FileShare.None))
            {
                byte[] writeBytes = Encoding.Default.GetBytes(textToBeWrited);
                fs.Write(writeBytes, 0, writeBytes.Length);
            }
        }

        public void WriteFilteredStringsToFile(string destFilepath)
        {
            this.WriteFile(destFilepath, _filteredStrings);
        }

        public void WriteFilteredSubStringsToFile(string destFilepath)
        {
            this.WriteFile(destFilepath, _filteredSubStrings);
        }

        public void SetText(string text)
        {
            _text = text;
        }

        public string getText()
        {
            if (_text == null)
            {
                throw new ParserException("public string getText() ==> _text == null");
            }
            else
            {
                return _text;
            }
        }

        /// <summary>
        /// Method concatinate substrings from string array.
        /// </summary>
        private void concatFilteredStrings()
        {
            _filteredStrings = "";
            for (int i = 0; i < _length; ++i)
            {
                _filteredStrings += "\n" + _filteredStringsArr[i];
            }
        }

        private string[] getFilteredStringsArr()
        {
            if (_filteredStringsArr == null)
            {
                throw new ParserException("public void separateSubStr(string separators) ==> _filteredStringsArr == null");
            }
            return _filteredStringsArr;
        }

        private string getFilteredStrings()
        {
            if (_filteredStringsArr == null)
            {
                throw new ParserException("public string getFilteredStrings() ==> _filteredStringsArr == null");
            }
            else
            {
                return _filteredStrings;
            }
        }

        private string[,] getSubStrings()
        {
            if (_SubStrings == null)
            {
                throw new ParserException("private string[,] getSubStrings() ==> _SubStrings == null");
            }
            return _SubStrings;
        }

        public string getFilteredSubStrings()
        {
            if (_filteredSubStrings == null)
            {
                throw new ParserException(" public string getFilteredSubStrings() ==> _filteredSubStrings == null");
            }
            else
            {
                return _filteredSubStrings;
            }
        }

        public void print()
        {
                Console.WriteLine(this.getText());
        }

        public void printFilteredStrings()
        {
                Console.WriteLine(this.getFilteredStrings());
        }

        public void printSubStrings()
        {
            if (_SubStrings == null)
            {
                throw (new ParserException("public void printSubStrings() ==> _SubStrings == null"));
            }
            else
            {
                for (int i = 0; i < _length; ++i)
                {
                    for (int j = 0; j < _columns; ++j)
                    {
                        Console.Write(j + ":" + _SubStrings[i, j] + " ");
                    }
                    Console.WriteLine();
                }
            }
        }

        public void printFilteredSubStrings()
        {
            Console.WriteLine(this.getFilteredSubStrings());
        }


        public void filterStrWith(string key = "all strings") {
            bool allStrings = key.Equals("all strings");
            string[] tmp = getText().Split("\n");
            _filteredStringsArr = new string[tmp.Length];
            _length = 0;
            foreach (string i in tmp)
            {
                if (allStrings || i.Contains(key))
                {
                    _filteredStringsArr[_length++] = i;
                }
            }
            concatFilteredStrings();
        }

        /// <summary>
        /// Method split separators string to char array.
        /// </summary>
        /// <returns>
        /// char array of separated symbols.
        /// </returns>
        private char[] splitSeparators(string separators)
        {
            char[] separatorsArr = new char[separators.Length];
            for (int i = 0; i < separatorsArr.Length; ++i)
            {
                separatorsArr[i] = separators[i];
            }
            return separatorsArr;
        }

        /// <summary>
        /// Method split string to substrings by separators string to string array.
        /// </summary>
        public void separateSubStr(string separators)
        {
            if (separators.Equals("") || separators.Equals("\n"))
            {
                throw new ParserException("public void separateSubStr(string separators) ==> separators.Equals(\"\") || separators.Equals(\"\\n\") == true");
            }
            char[] separatorsArr = splitSeparators(separators);
            string[] tmp = getFilteredStringsArr()[0].Split(separatorsArr);
            _columns = tmp.Length;
            _SubStrings = new string[_length, _columns];
            for (int i = 0; i < _length; ++i)
            {
                tmp = getFilteredStringsArr()[i].Split(separatorsArr);
                for (int j = 0; j < _columns; ++j)
                {
                    _SubStrings[i, j] = tmp[j];
                }
            }
        }

        /// <summary>
        /// Method split neededColumns string to int array.
        /// </summary>
        private void splitNeededColumns(string neededColumns)
        {
            string[] tmp = neededColumns.Split(',');
            _neededColumns = new int[tmp.Length];
            for (int i = 0; i < tmp.Length; ++i)
            {
                _neededColumns[i] = int.Parse(tmp[i]);
            }
        }

        /// <summary>
        /// Method check _neededColumns contains the number.
        /// </summary>
        /// <returns>
        /// true if _neededColumns contains the number.
        /// false if _neededColumns does not contain the number.
        /// </returns>
        private bool isInNeededColumns(int num)
        {
            foreach (int i in _neededColumns)
            {
                if (num == i)
                {
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// Method filter columns what you have writed in 'neededColumnsSeparatedByComma' 
        /// and concatinate all filtered substrings to string this._filteredSubStrings
        /// </summary>
        public void filterNeededColumns(string neededColumnsSeparatedByComma = "all columns")
        {
            bool allColumns = neededColumnsSeparatedByComma.Equals("all columns");
            if (!allColumns)
            {
                splitNeededColumns(neededColumnsSeparatedByComma);
            }
            _filteredSubStrings = "";
            getSubStrings(); //check exception
            for (int i = 0; i < _length; ++i)
            {
                for (int j = 0; j < _columns; ++j)
                {
                    if (allColumns || isInNeededColumns(j))
                    {
                        _filteredSubStrings += " " + getSubStrings()[i, j];
                    }
                }
                _filteredSubStrings += "\n";
            }
        }
    }
}