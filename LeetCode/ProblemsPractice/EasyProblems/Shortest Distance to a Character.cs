using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.EasyProblems
{
    public class Shortest_Distance_to_a_Character
    {
        public int[] ShortestToChar(string s, char c)
        {
            IList<int> pos = new List<int>();

            for (int i=0; i<s.Length; i++)
            {
                if (s[i] == c)
                    pos.Add(i);
            }

            int k = 0, prev = int.MaxValue, cur = 0;
            int[] ara = new int[s.Length];
            for (int i=0; i<s.Length; i++)
            {
                if (pos[k] == i && k < pos.Count)
                {
                    ara[i] = 0;
                    k++;
                    continue;
                }
                if (k > 0)
                    prev = i - pos[k - 1]; 
                cur = pos[k] - i;
                ara[i] = Math.Abs(Math.Min(cur, prev));
            }
            return ara;
        }
    }
}
