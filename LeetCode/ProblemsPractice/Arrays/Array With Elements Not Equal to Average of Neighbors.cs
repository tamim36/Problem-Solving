using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Arrays
{
    public class Array_With_Elements_Not_Equal_to_Average_of_Neighbors
    {
        public int[] RearrangeArray(int[] nums)
        {
            Array.Sort(nums);
            bool check = false;

            for (int i = 1; i < nums.Length-1; i++)
            {
                float avg = (float)(nums[i - 1] + nums[i + 1]) / 2;
                if (avg == (float)nums[i])
                {
                    check = true;
                    if (i != nums.Length - 2)
                    {
                        int temp = nums[nums.Length - 1];
                        nums[nums.Length - 1] = nums[i];
                        nums[i] = temp;
                    }
                    else
                    {
                        int temp = nums[0];
                        nums[0] = nums[i];
                        nums[i] = temp;
                    }
                }

                if (nums.Length - 2 == i && check)
                {
                    check = false;
                    i = 0;
                }
            }

            return nums;
        }
    }
}
