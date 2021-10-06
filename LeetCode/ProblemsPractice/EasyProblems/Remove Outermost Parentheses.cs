using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Remove_Outermost_Parentheses
    {
        public string RemoveOuterParentheses(string S)
        {
            char[] result = new char[S.Length];
            int resInd = 0;
            int count = 0;

            foreach (char c in S)
            {
                count += c == '(' ? 1 : -1;

                if ((count > 1 && c == '(') || (count > 0 && c == ')'))
                {
                    result[resInd++] = c;
                } 
            }
            return new String(result, 0, resInd);
        }
    }
}
