using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.TwoPointer
{
    public class Duplicate_Zeros
    {
        public void DuplicateZeros(int[] arr)
        {
            IList<int> zerosPos = new List<int>();
            int arrLen = arr.Length, zPointer = 0;
            int indx = arrLen - 1, newInd = 0;

            for (int i=0; i<=indx; i++)
            {
                if (arr[i] == 0)
                {
                    zerosPos.Add(i);
                    indx--;
                }
            }
            indx++;
            zPointer = zerosPos.Count - 1;

            while (zPointer >= 0)
            {
                if (indx == zerosPos[zPointer])
                {
                    newInd = indx + zPointer + 1;
                    if (newInd < arrLen)
                        arr[newInd] = arr[indx];

                    zPointer--;
                    newInd = indx + zPointer + 1;
                    if (newInd < arrLen)
                        arr[newInd] = arr[indx];
                }
                else if (indx > zerosPos[zPointer])
                {
                    newInd = indx + zPointer + 1;
                    if (newInd < arrLen)
                        arr[newInd] = arr[indx];
                }
                indx--;
            }

            foreach (var item in arr)
            {
                Console.Write(item + " ");
            }
        }
    }
}
