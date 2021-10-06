using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.TwoPointer
{
    public class Valid_Palindrome_II
    {
        public bool ValidPalindrome(string s)
        {
            int i = 0, j = s.Length - 1;
            bool oneTime = true;
            bool result = true;

            while (i < j)
            {
                if (s[i] != s[j])
                {
                    if (oneTime)
                    {
                        oneTime = false;
                        i++;
                    }
                    else
                    {
                        result = false;
                        break;
                    }  
                }
                else
                {
                    i++; j--;
                }
            }

            if (result)
                return result;

            i = 0; j = s.Length - 1;
            oneTime = true;

            while (i < j)
            {
                if (s[i] != s[j])
                {
                    if (oneTime)
                    {
                        oneTime = false;
                        j--;
                    }
                    else
                        return  result || false;
                }
                else
                {
                    i++; j--;
                }
                    
            }

            return result || true;
        }
    }
}
