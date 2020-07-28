using System;
using System.Collections.Generic;
using System.Text;

namespace FileParserCsharp
{
    public class ParserException : Exception
    {
        public ParserException(string message) : base(message)
        {
        }
    }
}
