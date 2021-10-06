using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Determine_if_String_Halves_Are_Alike
    {
        public bool HalvesAreAlike(string s)
        {
            List<char> vowels = new List<char> { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
            int count = 0;

            for (int i = 0; i < s.Length; i++)
            {
                if (vowels.Contains(s[i]))
                {
                    count = i >= s.Length/2 ? --count : ++count;
                }
            }
            return count == 0;
        }
    }
}