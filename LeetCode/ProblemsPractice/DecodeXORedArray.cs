using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice
{
    public class DecodeXORedArray
    {
        public int[] Decode(int[] encoded, int first)
        {
            IList<int> arr = new List<int>();
            int xor;

            arr.Add(first);

            foreach (var item in encoded)
            {
                xor = first ^ item;
                arr.Add(xor);
                first = xor;
            }

            return arr.ToArray();
        }
    }
}
