using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Sum_of_Beauty_in_the_Array
    {
        public int SumOfBeauties(int[] nums)
        {
            int leftMax = int.MaxValue, totalScore = 0;
            int[] scoreAra = new int[nums.Length];

            leftMax = nums[0];
            for (int i=1; i < nums.Length-1; i++)
            {
                if (leftMax < nums[i])
                {
                    scoreAra[i] = 2;
                    leftMax = nums[i];
                }
                    
                else if (nums[i - 1] < nums[i])
                    scoreAra[i]++;

            }

            int rightMin = nums[nums.Length - 1];
            for (int i=nums.Length -2; i > 0; i--)
            {
                if (scoreAra[i] == 2 && nums[i] >= rightMin) scoreAra[i]--;

                if (scoreAra[i] == 1 && nums[i] >= nums[i + 1]) scoreAra[i]--;

                if (nums[i] < rightMin) rightMin = nums[i];

                totalScore += scoreAra[i];
            }

            return totalScore;
        }
    }
}
