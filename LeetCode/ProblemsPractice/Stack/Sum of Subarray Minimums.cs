using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class Sum_of_Subarray_Minimums
    {
        // 907
        public int SumSubarrayMins(int[] arr)
        {
            int len = arr.Length;
            Stack<int> stk = new Stack<int>();
            int[] left = new int[len];
            int[] right = new int[len];

            for (int i=0; i < len; i++)
            {
                left[i] = i + 1;
                right[i] = len - i;
            }

            // Previous Less Elements
            for (int i=0; i < len; i++)
            {
                while (stk.Count > 0 && arr[stk.Peek()] > arr[i])
                    stk.Pop();

                left[i] = stk.Count == 0 ? i + 1 : i - stk.Peek();
                stk.Push(i);
            }

            stk.Clear();

            // Next Less Elements
            for (int i = 0; i < len; i++)
            {
                while (stk.Count > 0 && arr[stk.Peek()] > arr[i])
                    right[stk.Peek()] = i - stk.Pop();

                stk.Push(i);
            }

            long ans = 0;
            long mod = 1000000007;

            for (int i = 0; i < len; i++)
                ans = (ans + (long)arr[i] * left[i] * right[i]) % mod;

            return (int)ans;
        }

        public int SumSubarrayMinsOptimized(int[] A)
        {
            Stack<int> s = new Stack<int>();
            int n = A.Length, j, PLE;
            long res = 0, mod = (long)1e9 + 7;
            for (int NLE = 0; NLE <= n; NLE++)
            {
                while (s.Count > 0 && A[s.Peek()] > (NLE == n ? 0 : A[NLE]))
                {
                    j = s.Pop();
                    PLE = s.Count == 0 ? -1 : s.Peek();
                    res = (res + (long)A[j] * (NLE - j) * (j - PLE)) % mod;

                }
                s.Push(NLE);
            }
            return (int)res;
        }
    }
}
