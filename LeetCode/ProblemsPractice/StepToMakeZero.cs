using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class StepToMakeZero
    {
        static int step = 0;
        public int NumberOfSteps(int num)
        {

            if (num == 0)
                return step;
            
            step++;
            return NumberOfSteps(num % 2 == 0 ? num / 2 : num - 1);
        }
    }
}
