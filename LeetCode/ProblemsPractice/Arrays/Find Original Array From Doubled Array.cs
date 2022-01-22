using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace ProblemsPractice.Arrays
{
    public class Find_Original_Array_From_Doubled_Array
    {
        public int[] FindOriginalArray(int[] changed)
        {
            if (changed.Length % 2 == 1)
                return new int[0];

            var ansList = new List<int>();

            Array.Sort(changed);
            var dictArr = new Dictionary<int, int>();

            for (int i = 0; i < changed.Length; i++)
            {
                if (!dictArr.ContainsKey(changed[i]))
                    dictArr[changed[i]] = 0;
                else
                    dictArr[changed[i]]++;
            }

            for (int i=0; i < changed.Length; i++)
            {
                if (!dictArr.ContainsKey(changed[i] * 2))
                    return new int[0];

                else
                {
                    dictArr[changed[i]]--;
                    dictArr[changed[i] * 2]--;
                    ansList.Add(changed[i]);
                }
            }

            return ansList.ToArray();
        }
    }
}
