using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Find_Numbers_with_Even_Number_of_Digits
    {
        public int CountDigits(int num, int digit)
        {
            if(num / 10 == 0)
            {
                return ++digit;
            }

            return CountDigits(num/10, ++digit);
        }
        public int FindNumbers(int[] nums)
        {
            int evenCounter = 0;
            foreach (int num in nums)
            {
                evenCounter += num.ToString().Length % 2 == 0 ? 1 : 0;
            }
            return evenCounter;
        }
    }
}
