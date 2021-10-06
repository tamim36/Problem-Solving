using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice
{
    public class SolKidsWithCandies
    {
        public IList<bool> KidsWithCandies(int[] candies, int extraCandies)
        {
            return candiesEnumerable(candies, extraCandies).ToList();
        }

        private static IEnumerable<bool> candiesEnumerable(int[] candies, int extraCandies)
        {
            var maxCandies = candies.Max();
            foreach (var candy in candies)
            {
                yield return (candy + extraCandies) >= maxCandies;
            }
        }
    }
}
