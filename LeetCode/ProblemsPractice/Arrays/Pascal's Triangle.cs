using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Arrays
{
    public class Pascal_s_Triangle
    {
        public IList<IList<int>> Generate(int numRows)
        {
            IList<IList<int>> ansList = new List<IList<int>>();

            for (int i=0; i<numRows; i++)
            {
                IList<int> rowsList = new List<int>();
                for (int j=0; j<=i; j++)
                {
                    if (j == 0 || j == i)
                        rowsList.Add(1);
                    else
                        rowsList.Add(ansList[i - 1][j - 1] + ansList[i - 1][j]);
                        
                }
                ansList.Add(rowsList);
            }
            return ansList;
        }
    }
}
