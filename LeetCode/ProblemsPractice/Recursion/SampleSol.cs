using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice.Recursion
{
    public class SampleSol
    {
        public int[] MergeSort(int[] ara)
        {
            if (ara.Length == 1)
                return ara;

            int mid = ara.Length / 2;
            int[] left = ara.Take(mid).ToArray();
            int[] right = ara.Skip(mid).ToArray();

            return Merge(MergeSort(left), MergeSort(right));
        }

        public int[] Merge(int[] left, int[] right)
        {
            int i = 0, j = 0, k = 0;
            int[] result = new int[left.Length + right.Length];

            while (i < left.Length && j < right.Length)
            {
                if (left[i] < right[j])
                    result[k++] = left[i++];
                else
                    result[k++] = right[j++];
            }

            return result.Take(k).Concat(left.Skip(i)).Concat(right.Skip(j)).ToArray();
        }

        public int BinarySearch(int[] ara, int left, int right, int k)
        {
            if (left > right)
                return -1;

            int mid = (left + right) / 2;

            if (ara[mid] == k)
                return mid;
            else if (ara[mid] < k)
                return BinarySearch(ara, mid + 1, right, k);
            else
                return BinarySearch(ara, left, mid - 1, k);
        }

        public IList<int> TargetIndices(int[] nums, int target)
        {
            if(nums == null)
                return null;

            IList<int> result = new List<int>();
            nums = MergeSort(nums);

            int pos = BinarySearch(nums, 0, nums.Length, target);
            if (pos == -1)
                return new int[0];

            while(nums[pos - 1] == target)
                pos--;
            while(pos < nums.Length && nums[pos] == target)
                result.Add(pos++);

            return result;
        }
    }
}
