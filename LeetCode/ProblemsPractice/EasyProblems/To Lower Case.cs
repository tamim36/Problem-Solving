using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class To_Lower_Case
    {
        public string ToLowerCase(string str)
        {
            string result = str.ToLowerExtensionMethod();
            return result;
        }
    }

    public static class ExtensionHelper
    {
        public static string ToLowerExtensionMethod(this string inputStr)
        {
            char[] charArray = inputStr.ToCharArray();
            for (int i = 0; i < charArray.Length; i++)
            {
                if (charArray[i] >= 'A' && charArray[i] <= 'Z')
                {
                    charArray[i] = (char)(charArray[i] + 32); 
                }
            }

            return new string(charArray);
        }
    }
}
