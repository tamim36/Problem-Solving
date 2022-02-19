using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Arrays
{
    // 2165
    public class Smallest_Value_of_the_Rearranged_Number
    {
        public long SmallestNumber(long num)
        {
            int[] ara = new int[10];
            bool isPos = num > 0 ? true : false;
            long ans = 0;

            num = Math.Abs(num);

            while (num != 0)
            {
                int digit = (int)(num % 10);
                ara[digit]++;
                num /= 10;
            }


            for (int i = 1, indx = 1; i < 10; i++)
            {
                indx = isPos ? i : 10 - i;

                while (ara[indx]-- > 0)
                {
                    ans = (ans*10) + indx;

                    if (ara[0] > 0 && (isPos && ans > 0 && ans < 10))
                    {
                        while (ara[0]-- > 0)
                            ans *= 10;
                    }
                }
            }

            while (!isPos && ara[0]-- > 0)
                ans *= 10;

            return isPos == true ? ans : (ans * -1);
        }
    }
}
