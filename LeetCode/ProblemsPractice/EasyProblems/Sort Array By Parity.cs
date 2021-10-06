using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice
{
    public class Sort_Array_By_Parity
    {
        public int[] SortArrayByParity(int[] nums)
        {
            LinkedList<int> parityAra = new LinkedList<int>();
            foreach (var num in nums)
            {
               _ = num % 2 == 0 ? parityAra.AddFirst(num) : parityAra.AddLast(num);
            }

            return parityAra.ToArray();
        }
    }
}
