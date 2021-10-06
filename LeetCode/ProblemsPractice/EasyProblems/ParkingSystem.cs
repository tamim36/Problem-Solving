using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class ParkingSystem
    {
        private static int bigSlot, mediumSlot, smallSlot;
        public ParkingSystem(int big, int medium, int small)
        {
            bigSlot = big;
            mediumSlot = medium;
            smallSlot = small;
        }

        public bool AddCar(int carType)
        {
            if (carType == 1)
            {
                if (bigSlot > 0)
                {
                    bigSlot--;
                    return true;
                }
            }

            if (carType == 2)
            {
                if (mediumSlot > 0)
                {
                    mediumSlot--;
                    return true;
                }
            }

            if (carType == 3)
            {
                if (smallSlot > 0)
                {
                    smallSlot--;
                    return true;
                }
            }

            return false;
        }
    }
}
