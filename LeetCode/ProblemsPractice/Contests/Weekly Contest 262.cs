using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class Weekly_Contest_262
    {
        public IList<int> TwoOutOfThree(int[] nums1, int[] nums2, int[] nums3)
        {
            IList<int> ansArray = new List<int>();
            int[] CountNums = new int[101];

            GetFrequecny(nums1, CountNums);
            GetFrequecny(nums2, CountNums);
            GetFrequecny(nums3, CountNums);

            for (int i=1; i<CountNums.Length; i++)
            {
                if (CountNums[i] > 1)
                    ansArray.Add(i);
            }

            return ansArray;
        }

        public void GetFrequecny(int[] nums, int[] CountNums)
        {
            HashSet<int> uniqueVal = new HashSet<int>();

            for (int i = 0; i < nums.Length; i++)
            {
                if (!uniqueVal.Contains(nums[i]))
                {
                    CountNums[nums[i]]++;
                    uniqueVal.Add(nums[i]);
                }
            }
        }

        ////////////////////////////// 2nd qs ///////////////////////
        public int MinOperations(int[][] grid, int x)
        {
            int totalElem = grid.Length * grid[0].Length;
            int[] nums = new int[totalElem];
            int[] steps = new int[totalElem]; 
            int minStep = int.MaxValue;

            int k = 0;
            for (int i=0; i<grid.Length; i++)
            {
                for (int j = 0; j < grid[0].Length; j++)
                {
                    nums[k++] = grid[i][j]; 
                }
            }

            Array.Sort(nums);
            for (int i=1; i<nums.Length; i++)
            {
                if ((nums[i] - nums[i - 1]) % x != 0)
                    return -1;

                steps[i] = steps[i - 1] + ((nums[i] - nums[i - 1]) / x * i);
            }

            for (int i = nums.Length-2; i >= 0; i--)
            {
                steps[i] = steps[i - 1] + ((nums[i] - nums[i - 1]) / x * i);
            }

            for (int i = 0, j = steps.Length - 1; i < j; i++, j--)
            {
                minStep = Math.Min(minStep, steps[i] + steps[j]);
            }

            return minStep;
        }
    }
}
