using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Sorting
{
    public class SortingAlgorithm
    {
        public void BubbleSort(int[] nums)
        {
            int temp = 0;
            bool isSwapped = false;

            for (int i = 0; i < nums.Length; i++)
            {
                isSwapped = false;
                for (int j = 1; j < nums.Length - i; j++)
                {
                    if (nums[j-1] > nums[j])
                    {
                        temp = nums[j-1];
                        nums[j-1] = nums[j];
                        nums[j] = temp;
                        isSwapped = true;
                    }
                }
                if (!isSwapped)
                    break;
            }
        }

        public void SelectionSort(int[] nums)
        {
            int minIndex = 0;

            for (int i = 0; i < nums.Length-1; i++)
            {
                minIndex = i;
                for (int j = i; j < nums.Length; j++)
                {
                    if (nums[j] < nums[minIndex])
                        minIndex = j;
                }
                int temp = nums[minIndex];
                nums[minIndex] = nums[i];
                nums[i] = temp;
            }
        }

        public void InsertionSort(int[] nums)
        {
            for (int i = 1; i < nums.Length; i++)
            {
                int j = i;
                int temp = nums[i];
                while (j > 0 && nums[j-1] > temp)
                {
                    nums[j] = nums[j-1];
                    j--;
                }

                nums[j] = temp;
            }
        }
    }
}
