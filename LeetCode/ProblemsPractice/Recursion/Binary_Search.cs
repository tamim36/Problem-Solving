using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Recursion
{
    public class Binary_Search
    {
        public int BinarySearch(int[] ara, int left, int right, int x)
        {
            if (left > right)
                return -1;

            int mid = (left + right) / 2;

            if (ara[mid] == x)
                return mid;

            if (x > ara[mid])
                return BinarySearch(ara, mid + 1, right, x);

            else
                return BinarySearch(ara, left, mid - 1, x);
        }
    }
}
