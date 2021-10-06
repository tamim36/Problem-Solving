using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Maximum_Units_on_a_Truck
    {
        public int aMaximumUnits(int[][] boxTypes, int truckSize)
        {
            int totalUnits = 0;

            Array.Sort(boxTypes, (x, y) => -x[1].CompareTo(y[1]));


            for (int i = 0; i < boxTypes.Length; i++)
            {
                if (truckSize > 0)
                {
                    int numOfBox = truckSize > boxTypes[i][0] ? boxTypes[i][0] : truckSize;
                    totalUnits += numOfBox * boxTypes[i][1];
                    truckSize -= numOfBox;
                }
            }

            return totalUnits;
        }

        // optimizing bucket sort
        public int MaximumUnits(int[][] boxTypes, int truckSize)
        {
            int[] boxUnits = new int[1001];
            int totalUnits = 0;

            for (int i = 0; i < boxTypes.Length; i++)
            {
                boxUnits[boxTypes[i][1]] += boxTypes[i][0];
            }

            for (int i = 1000; i > 0; i--)
            {
                if (boxUnits[i] != 0 && truckSize > 0)
                {
                    int numOfBox = truckSize > boxUnits[i] ? boxUnits[i] : truckSize;
                    totalUnits += numOfBox * i;
                    truckSize -= numOfBox;
                }
            }

            return totalUnits;
        }
    }
}
