using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class MyQueue
    {
        private readonly Stack<int> mainStack, popStack;
        public MyQueue()
        {
            this.mainStack = new Stack<int>();
            this.popStack = new Stack<int>();
        }

        public void Push(int x)
        {
            mainStack.Push(x);
        }

        public int Pop()
        {
            while (mainStack.Count > 0)
                popStack.Push(mainStack.Pop());

            int top = popStack.Pop();

            while (popStack.Count > 0)
                mainStack.Push(popStack.Pop());

            return top;
        }

        public int Peek()
        {
            while (mainStack.Count > 0)
                popStack.Push(mainStack.Pop());

            int top = popStack.Peek();

            while (popStack.Count > 0)
                mainStack.Push(popStack.Pop());

            return top;
        }

        public bool Empty()
        {
            return mainStack.Count > 0 ? false : true;
        }
    }
}
