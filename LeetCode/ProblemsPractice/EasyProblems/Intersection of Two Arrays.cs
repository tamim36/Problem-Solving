using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace ProblemsPractice.EasyProblems
{
    public class Intersection_of_Two_Arrays
    {
        public int[] Intersections(int[] nums1, int[] nums2)
        {
            return nums1.Intersect(nums2).ToArray();
        }

        // By using two pointers
        public int[] Intersection(int[] nums1, int[] nums2)
        {
            Array.Sort(nums1);
            Array.Sort(nums2);
            int i = 0, j = 0;
            HashSet<int> ans = new HashSet<int>();

            while (i != nums1.Length && j != nums2.Length)
            {
                if (nums1[i] == nums2[j])
                {
                    ans.Add(nums1[i]);
                    i++;
                    j++;
                }

                else if (nums1[i] < nums2[j])
                    i++;

                else
                    j++;
            }
            return ans.ToArray();
        }
    }
}
