using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Minimum_Add_to_Make_Parentheses_Valid
    {
        public int MinAddToMakeValid(string s)
        {
            int totalMove = 0, parentheses = 0;

            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == ')' && parentheses <= 0)
                    totalMove++;

                else if (s[i] == ')' && parentheses >= 0)
                    parentheses--;

                else
                    parentheses++;
            }

            totalMove += parentheses;

            return totalMove;
        }
    }
}
