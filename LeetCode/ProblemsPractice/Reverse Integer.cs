using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Reverse_Integer
    {
        public int Reverse(int x)
        {
            Int64 a = 0;
            int pos = 1;
            while (x != 0)
            {
                a *= pos;
                a += (x % 10);
                pos = 10;
                x /= 10;
            }
            if (Int32.MaxValue < a || Int32.MinValue > a)
            {
                return 0;
            }
            return Convert.ToInt32(a);
        }
    }
}
