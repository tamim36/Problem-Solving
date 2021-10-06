using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Partition_Labels
    {
        public IList<int> PartitionLabels(string s)
        {
            int[] CharIndex = new int[150];
            IList<int> LengthList = new List<int>();
            int PartitionLen = 0, StartIndex = -1;

            for (int i=0; i<s.Length; i++)
            {
                CharIndex[s[i]] = i;
            }

            for (int i=0; i<s.Length; i++)
            {
                if (CharIndex[s[i]] > PartitionLen)
                    PartitionLen = CharIndex[s[i]];

                if (i >= PartitionLen)
                {
                    LengthList.Add(i - StartIndex);
                    PartitionLen = 0;
                    StartIndex = i;
                }  
            }

            return LengthList;
        }
    }
}
