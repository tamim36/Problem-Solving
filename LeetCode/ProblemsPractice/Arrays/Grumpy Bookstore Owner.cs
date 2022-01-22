using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Arrays
{
    public class Grumpy_Bookstore_Owner
    {
        public int MaxSatisfied(int[] customers, int[] grumpy, int minutes)
        {
            int count = 0, maxCus = 0, stIndx = 0, endIndx = 0;

            for (int i = 0; i < grumpy.Length; i++)
            {
                count += grumpy[i] == 1 ? customers[i] : 0;

                if (i >= minutes - 1)
                {
                    if (i >= minutes)
                        count -= grumpy[i - minutes] == 1 ? customers[i - minutes] : 0;

                    if (count > maxCus)
                    {
                        maxCus = count;
                        stIndx = i - minutes + 1;
                        endIndx = i;
                    }
                }
            }

            count = 0;
            for (int i = 0; i < customers.Length; i++)
                count += grumpy[i] == 0
                                    || (i >= stIndx && i <= endIndx)
                                    ? customers[i] : 0;
            return count;
        }
    }
}
