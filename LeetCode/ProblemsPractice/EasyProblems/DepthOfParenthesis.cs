using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice
{
    public class DepthOfParenthesis
    {
        Stack<char> AllChar = new Stack<char>();
        List<int> BracketCount = new List<int>();
        int count = 0;
        bool flag = true;
        public int MaxDepth(string s)
        {
            BracketCount.Add(0);
            foreach (var c in s)
            {
                AllChar.Push(c);
            }

            while (AllChar.Count != 0)
            {
                char c = AllChar.Pop();
                if (c == ')')
                {
                    count++;
                    flag = true;
                }
                else if (c == '(' && flag == true)
                {
                    BracketCount.Add(count);
                    count--;
                    flag = false;
                }
                else if (c == '(' && flag == false)
                    count--;
            }

            return BracketCount.Max();
        }
    }
}
