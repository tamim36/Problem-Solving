using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class Biweekly_Contest_63
    {
        public int MinMovesToSeat(int[] seats, int[] students)
        {
            int count = 0;

            Array.Sort(seats);
            Array.Sort(students);

            for (int i = 0; i < seats.Length; i++)
            {
                count += Math.Abs(seats[i] - students[i]);
            }

            return count;
        }

        public bool WinnerOfGame(string colors)
        {
            int count = 0;

            for (int i = 1; i < colors.Length - 1; i++)
            {
                if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
                    count++;
                else if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
                    count--;
            }
            return count > 0;
        }
    }
}
