using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class BrowserHistory
    {
        Stack<string> backwardStack;
        Stack<string> forwardStack;
        public BrowserHistory(string homepage)
        {
            backwardStack = new Stack<string>();
            forwardStack = new Stack<string>();
            backwardStack.Push(homepage);
        }

        public void Visit(string url)
        {
            backwardStack.Push(url);
            forwardStack.Clear();
        }

        public string Back(int steps)
        {
            while (steps-- > 0 && backwardStack.Count > 1)
                forwardStack.Push(backwardStack.Pop());

            return backwardStack.Peek();
        }

        public string Forward(int steps)
        {
            while (steps-- > 0 && forwardStack.Count > 0)
                backwardStack.Push(forwardStack.Pop());

            return backwardStack.Peek();
        }
    }
}
