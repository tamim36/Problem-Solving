using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.EasyProblems
{
    public class Count_Binary_Substrings
    {
        public int CountBinarySubstrings(string s)
        {
            return GetNumGroups(s, '0') + GetNumGroups(s, '1');
        }

        public int GetNumGroups(string s, char x)
        {
            int counter = 0, total = 0;
            bool oppositeChar = false;

            foreach (char c in s)
            {
                if (c == x)
                {
                    if (oppositeChar)
                    {
                        oppositeChar = false;
                        counter = 0;
                    }
                    counter++;
                }
                else if (counter > 0)
                {
                    oppositeChar = true;
                    counter--;
                    total++;
                }
            }
            return total;
        }
    }
}
