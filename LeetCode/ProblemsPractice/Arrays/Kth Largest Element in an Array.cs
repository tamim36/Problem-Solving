using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Arrays
{
    public class Kth_Largest_Element_in_an_Array
    {
        public int FindKthLargest(int[] nums, int k)
        {
            if (nums.Length == 1)
                return nums[0];

            Array.Sort(nums, (x, y) => y.CompareTo(x));

            return nums[k];
        }
    }
}
