using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class How_Many_Numbers_Are_Smaller_Than_the_Current_Number
    {
        public int[] SmallerNumbersThanCurrent(int[] nums)
        {
            int[] resAra = new int[nums.Length];
            
            for (int i = 0; i < nums.Length; i++)
            {
                int num = nums[i];
                int count = 0;
                for (int j = 0; j < nums.Length; j++)
                {
                    if (i != j && nums[i] > nums[j])
                    {
                        count++;
                    }
                }
                resAra[i] = count;
            }
            return resAra;
        }
    }
}
