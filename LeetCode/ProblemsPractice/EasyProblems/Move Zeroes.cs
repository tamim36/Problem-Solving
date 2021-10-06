using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.EasyProblems
{
    public class Move_Zeroes
    {
        public void MoveZeroes(int[] nums)
        {
            int pos = 0;
            foreach (int num in nums)
            {
                if (num != 0)
                    nums[pos++] = num;
            }

            for (int i=pos; i<nums.Length; i++)
            {
                nums[pos++] = 0;
            }
        }
    }
}
