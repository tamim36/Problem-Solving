using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    // 2178
    public class Maximum_Split_of_Positive_Even_Integers
    {
        public IList<long> MaximumEvenSplit(long finalSum)
        {
            IList<long> result = new List<long>();

            if (finalSum % 2 == 1)
                return result;

            for (int curSum = 2; curSum <= finalSum; curSum += 2)
            {
                finalSum -= curSum;
                result.Add(curSum);
            }

            result[result.Count -1] += finalSum;
            return result;
        }
    }
}
