using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Arrays
{
    public class Best_Time_to_Buy_and_Sell_Stock
    {
        public int MaxProfit(int[] prices)
        {
            int minPrice = int.MaxValue, maxProfit = int.MinValue;

            foreach (int price in prices)
            {
                if (minPrice < price)
                    maxProfit = (price - minPrice) > maxProfit ? (price - minPrice) : maxProfit;

                else if (price < minPrice)
                    minPrice = price;

            }
            
            return maxProfit == int.MinValue ? 0 : maxProfit;
        }
    }
}
