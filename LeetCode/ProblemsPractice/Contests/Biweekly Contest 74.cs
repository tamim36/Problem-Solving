using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class DescComp<T> : IComparer<T> where T : IComparable
    {
        public int Compare([AllowNull] T x, [AllowNull] T y)
        {
            return y.CompareTo(x);
        }
    }

    public class Biweekly_Contest_74
    {
        // 1962
        public int MinStoneSum(int[] piles, int k)
        {
            SortedDictionary<int, int> pq = new SortedDictionary<int, int>(Comparer<int>
                                                                        .Create((x, y) => y.CompareTo(x)));
            int sum = 0;
            foreach (int n in piles)
            {
                sum += n;
                if (!pq.ContainsKey(n))
                    pq.Add(n, 1);
                else pq[n]++;
            }
            int num = 0;
            while (k > 0)
            {
                k--;
                num = pq.First().Key;

                if (--pq[num] <= 0)
                    pq.Remove(num);

                int newVal = (int)Math.Ceiling((decimal)num / 2);
                sum -= (num - newVal);
                num = newVal;
                if (!pq.ContainsKey(num))
                    pq.Add(num, 1);
                else pq[num]++;
            }
            return sum;
        }
        // 2208
        public int HalveArray(int[] nums)
        {
            double sum = 0;
            SortedDictionary<double, int> pq = new SortedDictionary<double, int>(Comparer<double>
                                                                        .Create((x,y) => y.CompareTo(x)));
            foreach (int n in nums)
            {
                sum += n;
                if (!pq.ContainsKey(n))
                    pq.Add(n, 1);
                else pq[n]++;
            }

            double halfSum = (double)sum / 2;
            double curSum = 0;

            int count = 0;
            double num = 0;
            while (pq.Count > 0 && curSum < halfSum)
            {
                num = pq.First().Key;

                if (--pq[num] <= 0)
                    pq.Remove(num);
                num = num / 2;
                if (!pq.ContainsKey(num))
                    pq.Add(num, 1);
                else pq[num]++;

                curSum += num;
                count++;
            }

            return count;
        }

        public long MaximumSubsequenceCount(string text, string pattern)
        {
            long total = 0, fst = 0, snd = 0;
            foreach (char c in text)
            {
                if (c == pattern[1])
                {
                    snd++;
                    total += fst;
                }
                if (c == pattern[0])
                    fst++;
            }

            total += Math.Max(fst, snd);
            return total;
        }

        public bool DivideArray(int[] nums)
        {
            Array.Sort(nums);
            for (int i = 0; i < nums.Length - 1; i+=2)
            {
                if (nums[i] != nums[i + 1])
                    return false;
            }
            return true;
        }
    }
}
