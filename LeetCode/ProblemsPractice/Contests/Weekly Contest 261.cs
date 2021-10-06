using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class Weekly_Contest_261
    {
        public int MinimumMoves(string s)
        {
            int moves = 0;

            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == 'X')
                {
                    i += 2;
                    moves++;
                }
            }

            return moves;
        }

        public int[] MissingRolls(int[] rolls, int mean, int n)
        {
            int[] missingRolls = new int[n];
            int total = (rolls.Length + n) * mean;
            int sumRolls = 0;

            foreach (int item in rolls)
            {
                sumRolls += item;
            }

            int sumMissingRolls = total - sumRolls;

            if (sumMissingRolls > n * 6 || sumMissingRolls <= 0 || sumMissingRolls < n)
                return new int[0];


            int remainRolls = n;

            for (int i = 0; i < n; i++)
            {
                int avgMiss = (int)Math.Ceiling((decimal)sumMissingRolls / remainRolls);
                missingRolls[i] = avgMiss;
                sumMissingRolls -= avgMiss;
                remainRolls--;
            }

            return missingRolls;
        }
    }
}
