using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Arrays
{
    public class Intersection_of_Two_Arrays_II
    {
        public int[] Intersect(int[] nums1, int[] nums2)
        {
            Array.Sort(nums1);
            Array.Sort(nums2);

            List<int> ansAra = new List<int>();

            for (int i = 0, j = 0 ; i < nums1.Length && j < nums2.Length;)
            {
                if (nums1[i] == nums2[j])
                {
                    ansAra.Add(nums1[i]);
                    i++;
                    j++;
                }
                else if (nums1[i] > nums2[j])
                    j++;

                else
                    i++;
            }

            return ansAra.ToArray();
        }
    }
}
