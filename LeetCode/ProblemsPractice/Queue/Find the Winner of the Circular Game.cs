using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Queue
{
    public class Find_the_Winner_of_the_Circular_Game
    {
        public int FindTheWinner(int n, int k)
        {
            Queue<int> q = new Queue<int>();

            for (int i = 1; i <= n; i++)
                q.Enqueue(i);
            
            int count = k;
            while (q.Count > 1)
            {
                count--;
                if (count <= 0)
                {
                    q.Dequeue();
                    
                    count = k % q.Count;
                    count = count == 0 ? q.Count : count;
                }
                else
                    q.Enqueue(q.Dequeue());
            }
            return q.Dequeue();
        }

        public int OptFindTheWinner(int n, int k)
        {
            int res = 0;
            for (int i = 1; i <= n; ++i)
                res = (res + k) % i;
            return res + 1;
        }
    }
}
