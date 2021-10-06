using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice
{
    public class Integer_to_Roman
    {
        IDictionary<string, int> IntToRom = new Dictionary<string, int>()
            {
                { "I", 1}, { "V", 5}, { "X", 10}, { "L", 50}, { "C", 100}, { "D", 500},
                { "M", 1000}, { "IV", 4}, { "IX", 9}, { "XL", 40}, { "XC", 90}, { "CD", 400},
                { "CM", 900}
            };
        public string IntToRoman(int num)
        {
            IntToRom = IntToRom.OrderByDescending(x => x.Value).ToDictionary(x => x.Key, x => x.Value);
            string romStr = "";
            while (num > 0)
            {
                foreach (var item in IntToRom)
                {
                    if (num >= item.Value)
                    {
                        num -= item.Value;
                        romStr += item.Key;
                        break;
                    }
                }
            }

            return romStr;
        }
    }
}
