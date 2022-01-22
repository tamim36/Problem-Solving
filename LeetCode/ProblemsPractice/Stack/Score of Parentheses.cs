using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class Score_of_Parentheses
    {
        public int ScoreOfParentheses(string s)
        {
            int cur = 0;
            Stack<int> score = new Stack<int>();

            foreach (char c in s)
            {
                if (c == '(')
                {
                    score.Push(cur);
                    cur = 0;
                }
                else
                {
                    cur = cur == 0 ? 1 : 2 * cur;
                    cur += score.Pop();
                }
            }

            return cur;
        }
    }
}
