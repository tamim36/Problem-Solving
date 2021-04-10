using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class GasStation
    {
        public int CanCompleteCircuit(int[] gas, int[] cost)
        {
            int tank = 0;
            int circular = 0;
            int startIndex = 0;
            bool getAns = false;

            for (int i = 0; i < gas.Length; i++)
            {
                tank = 0;
                circular = 0;
                if (gas[i] >= cost[i])
                {
                    startIndex = i;
                    int costTravel = 0;
                    for (int j = 0, indx = startIndex; j < gas.Length; j++, indx++)
                    {
                        tank = tank - costTravel + gas[indx];
                        costTravel = cost[indx];
                        if (indx == gas.Length - 1)
                            indx = -1;
                        circular++;

                        if (tank < costTravel)
                            break;
                        if (circular == gas.Length)
                        {
                            getAns = true;
                            break;
                        }
                    }
                }
                if (getAns)
                    break;
            }

            if (getAns)
                return startIndex;
            else
                return -1;
        }
    }
}
