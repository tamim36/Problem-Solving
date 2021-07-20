using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Goal_Parser_Interpretation
    {
        public string Interpret(string command)
        {
            string s = "";

            for (int j = 0; j < command.Length; j++)
            {
                if (command[j] == '(' && command[j+1] == ')')
                {
                    s += "o";
                    j++;
                }
                else if (command[j] != '(' && command[j] != ')')
                {
                    s += command[j];
                }
            }
            return s ;
        }
    }
}
