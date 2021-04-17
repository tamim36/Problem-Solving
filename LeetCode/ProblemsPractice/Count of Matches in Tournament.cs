using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Count_of_Matches_in_Tournament
    {
        int count = 0;
        public int NumberOfMatches(int n)
        {
            if (n == 1)
            {
                return count;
            }
            count += n / 2;
            return NumberOfMatches((int)Math.Ceiling((double)n / 2));
        }
    }
}
