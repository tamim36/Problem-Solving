using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Arrays
{
    public class Product_of_Array_Except_Self
    {
        public int[] ProductExceptSelf(int[] nums)
        {
            int[] ans = new int[nums.Length];
            int product = 1;

            for (int i=0; i<nums.Length; i++)
            {
                ans[i] = product;
                product *= nums[i];
            }

            product = 1;
            for (int i=nums.Length-1; i >= 0; i--)
            {
                ans[i] *= product;
                product *= nums[i];
            }

            return ans;
        }
    }
}
