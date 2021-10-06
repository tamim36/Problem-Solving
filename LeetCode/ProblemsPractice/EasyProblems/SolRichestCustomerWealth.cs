using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class SolRichestCustomerWealth
    {
        public int MaximumWealth(int[][] accounts)
        {
            int maximamWealth = Int32.MinValue;
            int currentMax = 0;
            foreach (var i_customer in accounts)
            {
                currentMax = 0;
                foreach (var item in i_customer)
                {
                    currentMax += item;
                }
                if (currentMax > maximamWealth)
                {
                    maximamWealth = currentMax;
                }
            }
            return maximamWealth;
        }
    }
}
