using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.TwoPointer
{
    public class Merge_Sorted_Array
    {
        public void Merge(int[] nums1, int m, int[] nums2, int n)
        {
            int i = m - 1, j = n - 1, len = nums1.Length - 1;
            
            while (len >= 0)
            {
                if (i < 0)
                    nums1[len--] = nums2[j--];

                else if (j < 0)
                    nums1[len--] = nums1[i--];

                else if (nums1[i] > nums2[j])
                    nums1[len--] = nums1[i--];

                else if (nums1[i] < nums2[j])
                    nums1[len--] = nums2[j--];

                else
                {
                    nums1[len--] = nums2[j--];
                    nums1[len--] = nums1[i--];
                }
            }
        }
    }
}
