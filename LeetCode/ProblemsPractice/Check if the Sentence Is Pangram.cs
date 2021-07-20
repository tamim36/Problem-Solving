using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Check_if_the_Sentence_Is_Pangram
    {
        public bool CheckIfPangram(string sentence)
        {
            int[] charAra = new int[130];
            foreach (char c in sentence)
            {
                charAra[c]++;
            }
            for (int i = 97; i <= 122; i++)
            {
                if (charAra[i] == 0)
                    return false;
            }
            return true;
        }
    }
}
