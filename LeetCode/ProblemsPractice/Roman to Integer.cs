using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Roman_to_Integer
    {
        public int RomanToInt(string s)
        {
            IDictionary<string, int> romToInt = new Dictionary<string, int>()
            {
                { "I", 1}, { "V", 5}, { "X", 10}, { "L", 50}, { "C", 100}, { "D", 500},
                { "M", 1000}, { "IV", 4}, { "IX", 9}, { "XL", 40}, { "XC", 90}, { "CD", 400},
                { "CM", 900}
            };

            int value = 0;
            for (int i=0; i<s.Length; i++)
            {
                if (i < s.Length-1 && romToInt.ContainsKey("" + s[i] + s[i + 1]))
                {
                    value += romToInt["" + s[i] + s[i + 1]];
                    i++;
                }
                else
                {
                    value += romToInt["" + s[i]];
                }
            }

            return value;
        }
    }
}
