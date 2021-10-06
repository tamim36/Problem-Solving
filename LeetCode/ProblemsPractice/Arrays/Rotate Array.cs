using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Arrays
{
    public class Rotate_Array
    {
        public void Rotate(int[] nums, int k)
        {
            k %= nums.Length;
            int[] kArray = new int[k];

            for (int i=nums.Length-1, j=0; i>=0; i--, j++)
            {
                if (i + k >= nums.Length)
                    kArray[(i + k) % nums.Length] = nums[i];
                else
                    nums[i + k] = nums[i];
            }

            for (int i=0; i<k; i++)
            {
                nums[i] = kArray[i];
            }
        }

    }
}
