using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class BalancedString
    {
        public int BalancedStringSplit(string s)
        {
            int rlCounter = 0;
            int ansCounter = 0;
            Queue<char> q = new Queue<char>();
            foreach (var c in s)
            {
                q.Enqueue(c);
            }

            while(q.Count != 0)
            {
                if (q.Dequeue() == 'R')
                {
                    rlCounter++;
                }
                else
                {
                    rlCounter--;
                }
                if (rlCounter == 0)
                    ansCounter++;
            }
            return ansCounter;
        }
    }
}
