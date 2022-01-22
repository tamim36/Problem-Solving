using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.SlidingWindow
{
    public class Maximum_Sum_of_Two_Non_Overlapping_Subarrays
    {
        public int maxSumTwoNoOverlap(int[] A, int L, int M)
        {
            for (int i = 1; i < A.Length; ++i)
                A[i] += A[i - 1];
            int res = A[L + M - 1], Lmax = A[L - 1], Mmax = A[M - 1];
            Console.WriteLine($"res: A[L+M-1] = A[{L+M-1}] \tLmax: A[L-1] = A[{L-1}] \tMmax A[M-1] = A[{M-1}]\n");
            for (int i = L + M; i < A.Length; ++i)
            {
                Console.WriteLine($"Math.Max(Lmax, A[i] - A[i - L - M]) = {Lmax}, A[{i - M}] - A[{i - L - M}]");
                Lmax = Math.Max(Lmax, A[i - M] - A[i - L - M]);
                Console.WriteLine($"Math.Max(Mmax, A[i - L] - A[i - L - M]) = {Mmax}, A[{i - L}] - A[{i - L - M}]");
                Mmax = Math.Max(Mmax, A[i - L] - A[i - L - M]);
                Console.WriteLine($"res = Math.Max(res:{res}, Math.Max(Lmax{Lmax} + A[i]:{i} - A[i - M]:{i-M}, Mmax:{Mmax} + A[i]:{i} - A[i - L]:{i-L}))\n");
                res = Math.Max(res, Math.Max(Lmax + A[i] - A[i - M], Mmax + A[i] - A[i - L]));
            }
            return res;
        }
    }
}
