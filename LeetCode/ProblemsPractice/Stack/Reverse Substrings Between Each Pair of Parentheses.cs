using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class Reverse_Substrings_Between_Each_Pair_of_Parentheses
    {
        public string ReverseParentheses(string s)
        {
            Stack<string> part = new Stack<string>();
            string cur = "";

            foreach (char c in s)
            {
                if (c == '(')
                {
                    part.Push(cur);
                    cur = "";
                }
                else if (c == ')')
                {
                    cur = new string(cur.ToCharArray().Reverse().ToArray());
                    cur = part.Count > 0 ? part.Pop() + cur : cur;
                }
                else
                    cur += c.ToString();
            }

            return cur;
        }
    }
}
