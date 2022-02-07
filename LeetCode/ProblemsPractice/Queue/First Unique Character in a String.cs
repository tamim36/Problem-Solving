using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Queue
{
    public class First_Unique_Character_in_a_String
    {
        public int FirstUniqChar(string s)
        {
            int[] arr = new int[120];

            foreach (char c in s)
            {
                arr[c]++;
            }

            for (int i = 0; i < s.Length; i++)
            {
                if (arr[s[i]] == 1)
                    return i;
            }

            return -1;
        }
    }
}
