using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice.Queue
{
    public class Reduce_Array_Size_to_The_Half
    {
        public int MinSetSize(int[] arr)
        {
            Dictionary<int, int> freq = new Dictionary<int, int>();

            foreach (var item in arr)
            {
                if (!freq.ContainsKey(item))
                    freq.Add(item, 1);
                else
                    freq[item]++;
            }

            int count = 0, arrLen = arr.Length;
            foreach (var item in freq.OrderByDescending(x => x.Value).Select(x => x.Value).ToList())
            {
                if (arrLen <= arr.Length / 2)
                    break;
                arrLen -= item;
                count++;
            }

            return count;
        }
    }
}
