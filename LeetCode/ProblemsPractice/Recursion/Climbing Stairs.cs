using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Recursion
{
    // 70
    public class Climbing_Stairs
    {
        int[] dp = new int[46];
        public int ClimbStairs(int n)
        {
            if (n <= 2)
                return n;
            if (dp[n] > 0)
                return dp[n];
            return dp[n] = ClimbStairs(n - 1) + ClimbStairs(n - 2);
        }

        // for more variation such as {1,3,5} steps or any number of steps
        public int ClimbStairsForMoreSteps(int n)
        {
            int[] steps = new int[] { 1, 2};
            dp[0] = 1;
            int total = 0;

            for (int i = 1; i <= n; i++)
            {
                total = 0;
                foreach (int step in steps)
                {
                    if (i - step >= 0)
                        total += dp[i - step];
                }
                dp[i] = total;
            }
            return dp[n];
        }
    }
}
