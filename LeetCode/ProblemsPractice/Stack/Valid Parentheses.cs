using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    // 20
    public class Valid_Parentheses
    {
        public bool IsValid(string s)
        {
            Stack<char> bracketStack = new Stack<char>();

            foreach (char bracket in s)
            {
                if (bracket == '(' || bracket == '{' || bracket == '[')
                    bracketStack.Push(bracket);
                else if (bracketStack.Count == 0)
                    return false;
                else if ((bracket == ')' && bracketStack.Peek() == '(') || (bracket == '}' && bracketStack.Peek() == '{') || (bracket == ']' && bracketStack.Peek() == '['))
                    bracketStack.Pop();
                else
                    return false;
            }

            return bracketStack.Count == 0;
        }
    }
}
