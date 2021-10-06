using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Arrays
{
    public class Contains_Duplicate
    {
        public bool ContainsDuplicate(int[] nums)
        {
            IDictionary<long, int> boolDict = new Dictionary<long, int>();
            foreach (int num in nums)
            {
                if (boolDict.ContainsKey(num))
                    return true;
                else
                    boolDict.Add(num, 1);
            }
            return false;
        }
    }
}
