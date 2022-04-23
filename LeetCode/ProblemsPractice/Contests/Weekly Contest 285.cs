using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class Weekly_Contest_285
    {
        public int CountCollisions(string directions)
        {
            int count = 0, right = 0;
            char prv = directions[0];
            // "SSRSSRLL - 4 RSLLRSRSSRL-12 RRRRLLRRLSSRR"
            
            for (int i = 1; i < directions.Length; i++)
            {
                if (prv == 'R') right++;
                if ((prv != directions[i]) 
                    && ((prv == 'R' && directions[i] == 'L')
                    || (prv == 'R' && directions[i] == 'S')
                    || (prv == 'S' && directions[i] == 'L')))
                {
                    count += 2;
                    if (prv == 'S' || directions[i] == 'S')
                        count--;
                    prv = 'S';
                    count += right > 1 ? right - 1 : 0;
                    right = 0;
                }
                else
                    prv = directions[i];
            }

            return count;
        }

        public int CountHillValley(int[] nums)
        {
            int count = 0;
            int prv = 1, nxt = 1;
            for (int i = 1; i < nums.Length-1; i+=nxt)
            {
                prv = 1; nxt = 1;
                while (nums[i] == nums[i + nxt] && i + nxt < nums.Length-1) { nxt++; }
                if ((nums[i - prv] > nums[i] && nums[i] < nums[i + nxt]) || (nums[i - prv] < nums[i] && nums[i] > nums[i + nxt]))
                    count++;
            }

            return count;
        }
    }
}
