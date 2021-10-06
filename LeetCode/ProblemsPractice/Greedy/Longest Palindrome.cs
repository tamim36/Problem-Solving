using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Longest_Palindrome
    {
        public int LongestPalindrome(string s)
        {
            int[] ara = new int[60];
            foreach (var ch in s)
            {
                ara[ch - 65]++;
            }

            int PalindromeLength = 0;
            bool HaveExtraCharacter = false;

            foreach (var item in ara)
            {
                if (item > 1)
                {
                    if (item % 2 == 1)
                        PalindromeLength += (item - 1);
                    else
                        PalindromeLength += item;
                }
                if (!HaveExtraCharacter && item%2 == 1)
                {
                    HaveExtraCharacter = true;
                }
            }

            if (HaveExtraCharacter)
                PalindromeLength++;

            return PalindromeLength;
        }
    }
}
