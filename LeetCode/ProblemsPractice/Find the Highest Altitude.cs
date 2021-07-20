using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Find_the_Highest_Altitude
    {
        public int LargestAltitude(int[] gain)
        {
            int maxAlt = 0;
            int currentAlt = 0;

            foreach (var g in gain)
            {
                int nextAlt = currentAlt + g;
                maxAlt = nextAlt > maxAlt ? nextAlt : maxAlt;
                currentAlt = nextAlt;
            }

            return maxAlt;
        }
    }
}
