using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Minimum_Number_of_Buckets
    {
        // 2086
        public int MinimumBuckets(string street)
        {
            int count = 0;
            int len = street.Length;
            int[] ara = new int[len];

            for (int i = 0; i < len; i++)
            {
                if (street[i] == 'H')
                {
                    if ((i < len - 1 && ara[i+1] == 1) || (i > 0 && ara[i-1] == 1))
                    {
                        continue;
                    }
                    else if (i < len-1 && street[i+1] == '.')
                    {
                        ara[i + 1] = 1;
                        count++;
                    }
                    else if (i > 0 && street[i-1] == '.')
                    {
                        ara[i - 1] = 1;
                        count++;
                    }
                    else
                    {
                        return -1;
                    }
                }
            }

            return count;
        }
    }
}
