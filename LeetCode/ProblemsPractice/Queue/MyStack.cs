using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Queue
{
    // 225
    public class MyStack
    {
        Queue<int> q1;
        Queue<int> q2;
        public MyStack()
        {
            q1 = new Queue<int>();
            q2 = new Queue<int>();
        }

        public void Push(int x)
        {
            if (q1.Count == 0)
            {
                q1.Enqueue(x);
                while (q2.Count > 0)
                    q1.Enqueue(q2.Dequeue());
            }
            else
            {
                q2.Enqueue(x);
                while (q1.Count > 0)
                    q2.Enqueue(q1.Dequeue());
            }
        }

        public int Pop()
        {
            if (q1.Count > 0)
                return q1.Dequeue();
            else
                return q2.Dequeue();
        }

        public int Top()
        {
            if (q1.Count > 0)
                return q1.Peek();
            else
                return q2.Peek();
        }

        public bool Empty()
        {
            return q1.Count == 0 && q2.Count == 0;
        }
    }
}
