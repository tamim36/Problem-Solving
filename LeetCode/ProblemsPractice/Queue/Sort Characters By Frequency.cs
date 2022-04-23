using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice.Queue
{
    public class Sort_Characters_By_Frequency
    {
        public string FrequencySort(string s)
        {
            int[] freq = new int[123];

            foreach (char c in s)
                freq[c]++;

            SortedDictionary<int, List<char>> kvp = new SortedDictionary<int, List<char>>();

            for (int i=0; i < freq.Length; i++)
            {
                if (freq[i] > 0)
                {
                    if (!kvp.ContainsKey(freq[i]))
                        kvp.Add(freq[i], new List<char>());

                    kvp[freq[i]].Add((char)i);
                }
            }

            char[] sorted = new char[s.Length];
            int indx = 0;

            foreach (var item in kvp.Reverse())
            {
                foreach (var ch in item.Value)
                {
                    for (int i=0; i<item.Key; i++)
                        sorted[indx++] = ch;
                }
            }

            return new string(sorted);
        }
    }
}
