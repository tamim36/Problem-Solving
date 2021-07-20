using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Replace_All_Digits_with_Characters
    {
        public char shiftChar(char c, int x)
        {
            Console.WriteLine(c);
            Console.WriteLine(x);
            return (char)((int)c + x);
        }
        public string ReplaceDigits(string s)
        {
            var inp = s.ToCharArray();
            for (int i = 1; i < inp.Length; i += 2)
            {
                inp[i] = shiftChar(inp[i - 1], inp[i]- '0');
            }

            return new string(inp);
        }
    }
}
