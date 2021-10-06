using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.EasyProblems
{
    public class Best_Time_to_Buy_and_Sell_Stock_II
    {
        public int MaxProfit(int[] prices)
        {
            int minPrice = prices[0], profit = 0;

            for (int i=1; i<prices.Length; i++)
            {
                if (prices[i] < prices[i - 1])
                    minPrice = prices[i];
                else
                {
                    profit += prices[i] - minPrice;
                    minPrice = prices[i];
                }
            }

            return profit;
        }
    }
}
