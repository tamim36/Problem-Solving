using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Recursion
{
    public class Fibonacci_Number
    {
        // 509
        int[] dp = new int[31];
        public int Fib(int n)
        {
            if (dp[n] > 0)
                return dp[n];

            if (n < 2)
            {
                dp[n] = n;
                return dp[n];
            }

            dp[n] = Fib(n - 1) + Fib(n - 2);
            return dp[n];
        }
    }
}
