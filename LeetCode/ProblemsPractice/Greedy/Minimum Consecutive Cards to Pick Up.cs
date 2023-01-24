using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Minimum_Consecutive_Cards_to_Pick_Up
    {
        // 2260
        public int MinimumCardPickup(int[] cards)
        {
            IDictionary<int, int> map = new Dictionary<int, int>();
            int minDiff = cards.Length + 1;

            for (int i = 0; i < cards.Length; i++)
            {
                if (map.ContainsKey(cards[i]))
                    minDiff = Math.Min(i - map[cards[i]] + 1, minDiff);

                map[cards[i]] = i;
            }
            return minDiff == cards.Length + 1 ? -1 : minDiff;
        }
    }
}
