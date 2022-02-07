using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Queue
{
    public class Reveal_Cards_In_Increasing_Order
    {
        public int[] DeckRevealedIncreasing(int[] deck)
        {
            Array.Sort(deck);
            int[] res = new int[deck.Length];
            Queue<int> q = new Queue<int>();

            for (int i = 0; i < deck.Length; i++)
                q.Enqueue(i);

            int indx = 0;
            while(q.Count > 0)
            {
                res[q.Dequeue()] = deck[indx++];
                if (q.Count > 0)
                    q.Enqueue(q.Dequeue());
            }

            return res;
        }
    }
}
