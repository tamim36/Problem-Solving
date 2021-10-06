using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Minimum_Time_to_Type_Word_Using_Special_Typewriter
    {
        public int MinTimeToType(string word)
        {
            int moves, total_time = word.Length;
            char prevCh = 'a';
            for (int i=0; i<word.Length; i++)
            {
                if (i > 0) prevCh = word[i-1];
                int clockwiseDist = Math.Abs(prevCh - word[i]);
                int counterClockwiseDist = prevCh > word[i] ? Math.Abs(prevCh - (word[i] + 25 + 1)) : Math.Abs((prevCh + 25 + 1) - word[i]);
                moves = clockwiseDist < counterClockwiseDist ? clockwiseDist : counterClockwiseDist;

                total_time += moves;
            }

            return total_time;
        }
    }
}
