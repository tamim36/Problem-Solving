using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Longest_Common_Prefix
    {
        public string LongestCommonPrefix(string[] strs)
        {
            string subStr = strs[0];
            int lenStr = subStr.Length;

            for (int i=1; i<strs.Length; i++)
            {
                lenStr = Math.Min(strs[i].Length, lenStr);
                for (int j=0; j<lenStr; j++)
                {
                    var a = strs[i][j];
                    if (subStr[j] != a)
                    {
                        lenStr = j < lenStr ? j : lenStr;
                        break;
                    }
                }
            }

            return subStr.Substring(0, lenStr);
        }
    }
}
