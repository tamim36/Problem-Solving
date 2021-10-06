using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.TwoPointer
{
    public class Long_Pressed_Name
    {
        public bool IsLongPressedName(string name, string typed)
        {
            int i = 0, j = 0;

            if (typed.Length < name.Length)
                return false;

            while(i < name.Length || j < typed.Length)
            {
                if (j < typed.Length && i < name.Length && name[i] == typed[j])
                {
                    i++;
                    j++;
                }

                else if (i > 0 && j < typed.Length && name[i - 1] == typed[j])
                    j++;
                else
                    return false;
            }

            return true;
        }
    }
}
