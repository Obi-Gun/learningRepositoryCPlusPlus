using System;
using System.IO;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace FileParserCsharp
{
    public class Parser
    {
        private string _text;
        private string[] _filteredStringsArr;
        private string _filteredStrings;
        private string[,] _SubStrings;
        private string _filteredSubStrings;
        private int _length;
        private int _columns;
        private int[] _neededColumns;
        
        public void ReadFile(string sourseFilepath)
        {
            using (
                FileStream fs = new FileStream(sourseFilepath, FileMode.Open, FileAccess.Read, FileShare.Read))
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
            if (_text != null)
            {
                return _text;
            }
            return "";
        }

        private void concatFilteredStrings()
        {
            _filteredStrings = "";
            for (int i = 0; i < _length; ++i)
            {
                _filteredStrings += "\n" + _filteredStringsArr[i];
            }
        }

        public string getFilteredStrings()
        {
            if (_filteredStringsArr != null)
            {
                return _filteredStrings;
            }
            return "";
        }

        public string getFilteredSubStrings()
        {
            if (_filteredSubStrings != null)
            {
                return _filteredSubStrings;
            }
            return "";
        }

        public void print()
        {
            if (_text != null)
            {
                Console.WriteLine(this.getText());
            }
        }

        public void printFilteredStrings()
        {
            if (_filteredStringsArr != null)
            {
                for (int i = 0; i < _length; ++i)
                {
                    Console.WriteLine(this.getFilteredStrings());
                }
            }
        }

        public void printSubStrings()
        {
            if (_SubStrings != null)
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
            if (_filteredSubStrings != null)
            {
                Console.WriteLine(_filteredSubStrings);
            }
        }

        public void filterStrWith(string key) {
            string[] tmp = _text.Split("\n");
            _filteredStringsArr = new string[tmp.Length];
            _length = 0;
            for (int i = 0; i < tmp.Length; ++i)
            {
                if (tmp[i].Contains(key))
                {
                    _filteredStringsArr[_length++] = tmp[i];
                }
            }
            concatFilteredStrings();
        }

        private char[] splitSeparators(string separators)
        {
            char[] separatorsArr = new char[separators.Length];
            for (int i = 0; i < separatorsArr.Length; ++i)
            {
                separatorsArr[i] = separators[i];
            }
            return separatorsArr;
        }

        public void separateSubStr(string separators)
        {
            char[] separatorsArr = splitSeparators(separators);
            string[] tmp = _filteredStringsArr[0].Split(separatorsArr);
            _columns = tmp.Length;
            _SubStrings = new string[_length, _columns];
            for (int i = 0; i < _length; ++i)
            {
                tmp = _filteredStringsArr[i].Split(separatorsArr);
                for (int j = 0; j < _columns; ++j)
                {
                    _SubStrings[i,j] = tmp[j];
                }
            }
        }

        private void splitNeededColumns(string neededColumns)
        {
            string[] tmp = neededColumns.Split(',');
            _neededColumns = new int[tmp.Length];
            for (int i = 0; i < tmp.Length; ++i)
            {
                _neededColumns[i] = int.Parse(tmp[i]);
            }
        }

        private bool isInNeededColumns(int num)
        {
            for (int i = 0; i < _neededColumns.Length; ++i)
            {
                if (num == _neededColumns[i])
                {
                    return true;
                }
            }
            return false;
        }

        public void filterNeededColumns(string neededColumnsSeparatedByComma)
        {
            splitNeededColumns(neededColumnsSeparatedByComma);
            if (_SubStrings != null)
            {
                _filteredSubStrings = "";
                for (int i = 0; i < _length; ++i)
                {
                    for (int j = 0; j < _columns; ++j)
                    {
                        if (isInNeededColumns(j))
                        {
                            _filteredSubStrings += " " + _SubStrings[i, j];
                        }
                    }
                    _filteredSubStrings += "\n";
                }
            }
        }
    }
}