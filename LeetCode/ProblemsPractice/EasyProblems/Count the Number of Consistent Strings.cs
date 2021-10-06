using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Count_the_Number_of_Consistent_Strings
    {
        public int CountConsistentStrings(string allowed, string[] words)
        {
            int count = words.Length;
            bool isMatch = false;

            foreach (var word in words)
            {
                foreach (var ch in word)
                {
                    foreach (var alwCh in allowed)
                    {
                        if (ch == alwCh)
                        {
                            isMatch = true;
                            break;
                        }
                    }
                    if (!isMatch)
                    {
                        count--;
                        break;
                    }
                    else
                    {
                        isMatch = false;
                    }
                }
            }

            return count;
        }
    }
}
