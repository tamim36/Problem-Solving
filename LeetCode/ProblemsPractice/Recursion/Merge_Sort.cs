using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice.Recursion
{
    public class Merge_Sort
    {
        public int[] MergeSort(int[] ara)
        {
            if (ara == null || ara.Length == 1)
                return ara;

            int length = ara.Length;
            int mid = length / 2;
            int[] left = ara.Take(mid).ToArray();
            int[] right = ara.Skip(mid).Take(length-mid).ToArray();


            return Merge(
                MergeSort(left),
                MergeSort(right)
                );
        }

        public int[] Merge(int[] left, int[] right)
        {
            int[] result = new int[left.Length + right.Length];
            int i = 0, j = 0, k = 0;

            while (i < left.Length && j < right.Length)
            {
                if (left[i] < right[i])
                    result[k++] = left[i++];
                else
                    result[k++] = right[j++];
            }

            result = result.Take(k).Concat(left.Skip(i)).Concat(right.Skip(j)).ToArray();
            return result;
        }
    }
}
