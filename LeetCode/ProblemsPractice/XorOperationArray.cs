using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class XorOperationArray
    {
        public int XorOperation(int n, int start)
        {
            int prevVal = start;
            int xorVal = 0;

            for (int i = 1; i < n; i++)
            {
                int curVal = start + 2 * i;
                xorVal = prevVal ^ curVal;
                prevVal = xorVal;
            }
            return xorVal;
        }
    }
}
