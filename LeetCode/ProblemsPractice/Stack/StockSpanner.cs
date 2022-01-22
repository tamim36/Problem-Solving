using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class StockSpanner
    {
        int[] prices, idxVal;
        int curr;
        public StockSpanner()
        {
            prices = new int[1001];
            idxVal = new int[1001];
            curr = 0;
        }

        public int Next(int price)
        {
            int span = 0, i = 0;
            for (i = curr-1; i >= 0 && price > prices[i]; i--)
            {
                if (idxVal[i] > 1)
                    i = i - idxVal[i] + 1;
            }
            prices[curr] = price;
            span = curr - i;
            idxVal[curr++] = span;
            return span;
        }
    }
}
