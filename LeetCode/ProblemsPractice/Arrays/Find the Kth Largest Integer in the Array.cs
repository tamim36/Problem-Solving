using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace ProblemsPractice.Arrays
{
    public class Find_the_Kth_Largest_Integer_in_the_Array
    {
        public string KthLargestNumber(string[] nums, int k)
        {
            if (nums.Length == 1)
                return nums[0];
            Array.Sort(nums, (x,y) => 
            {
                if (x.Length != y.Length)
                    return y.Length.CompareTo(x.Length);
                else if (x.Equals(y))
                    return 0;
                else
                {
                    for (int i = 0; i < x.Length; i++)
                    {
                        if (x[i] != y[i])
                            return (int)(y[i] - '0').CompareTo((int)(x[i] - '0'));
                    }
                    return 0;
                }
            });

            return nums[k-1];
        }
    }
}
