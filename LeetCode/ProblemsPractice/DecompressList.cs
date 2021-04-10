using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice
{
    public class DecompressList
    {
        public int[] DecompressRLElist(int[] nums)
        {
            int freq, val;
            var resList = new List<int>();
            for (int i = 0; i < nums.Length; i+=2)
            {
                freq = nums[i];
                val = nums[i + 1];

                resList.AddRange(Enumerable.Repeat(val, freq));
            }

            return resList.ToArray();
        }
    }
}
