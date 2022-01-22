using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class Crawler_Log_Folder
    {
        public int MinOperations(string[] logs)
        {
            int count = 0;
            foreach (string log in logs)
            {
                count = log == "../" && count > 0 ? --count : log != "./" && log != "../" ? ++count : count;
            }

            return count;
        }
    }
}
