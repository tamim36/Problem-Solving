using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.MasterCodingInterviewUdemy
{
    // Two string array if common element true otherwise false
    // [a, b] , [a] return true
    public class _4_5_FindCommonTwoArray
    {
        public bool FindCommon(char[] ara1, char[] ara2)
        {
            HashSet<char> CommonAra = new HashSet<char>();

            foreach (char c in ara1)
            {
                CommonAra.Add(c);
            }

            foreach (char c in ara2)
            {
                if (CommonAra.Contains(c))
                    return true;
            }

            return false;
        }
    }
}
