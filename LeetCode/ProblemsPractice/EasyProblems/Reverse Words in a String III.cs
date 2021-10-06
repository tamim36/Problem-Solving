using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice.EasyProblems
{
    public class Reverse_Words_in_a_String_III
    {
        public string ReverseWords(string s)
        {
            char[] sentence = s.ToCharArray();
            int i = 0;
            for (int k = 0; k < sentence.Length; k++)
            {
                if (sentence[k] == ' ' || (k+1 == sentence.Length && ++k == sentence.Length) )
                {
                    for (int j = k - 1; i < j; i++, j--)
                    {
                        char c = sentence[i];
                        sentence[i] = sentence[j];
                        sentence[j] = c;
                    }
                    i = k+1;
                }
            }

            return new string(sentence);
        }

        public string ReverseWordsByFunc(string s)
        {
            return string.Join(" ", s.Split(" ").Select(x => new string(x.ToCharArray().Reverse().ToArray())));
        }
    }
}
