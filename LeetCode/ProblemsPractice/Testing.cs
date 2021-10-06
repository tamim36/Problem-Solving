using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Testing
    {
        public string WrapText(string LargeText, int Width)
        {
            char[] LargeTextArray = LargeText.ToCharArray();
            int CurrentLength = 0, SpacePos = 0;
            for (int i=0; i<LargeTextArray.Length; i++, CurrentLength++)
            {
                if (LargeTextArray[i] == ' ')
                    SpacePos = i;

                if (CurrentLength >= Width)
                {
                    LargeTextArray[SpacePos] = '\n';
                    CurrentLength = CurrentLength - (SpacePos%Width);
                }
            }

            return new string(LargeTextArray);
        }
    }
}
