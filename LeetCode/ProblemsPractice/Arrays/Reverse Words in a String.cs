using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Arrays
{
    public class Reverse_Words_in_a_String
    {
        public string ReverseWords(string s)
        {
            StringBuilder sb = new StringBuilder(s);

            sb = ReverseString(sb, 0, sb.Length-1);

            for (int end = 0, start = 0; end < sb.Length; end++ )
            {
                if (sb[end] == ' ')
                {
                    sb = ReverseString(sb, start, end-1);
                    start = end + 1;
                }

                else if (end == sb.Length - 1)
                {
                    sb = ReverseString(sb, start, end);
                    start = end + 1;
                }
            }

            int j = 0;
            for (int i=0; i < sb.Length; i++)
            {
                if (j==0 && sb[i] != ' ')
                    sb[j++] = sb[i];

                else if (j>0 && i < sb.Length-1 && sb[i] == ' ' && sb[i+1] != ' ')
                    sb[j++] = sb[i];

                else if (i > 0 && sb[i] != ' ')
                    sb[j++] = sb[i];
            }

            sb.Length = j;
            return sb.ToString();
        }

        public StringBuilder ReverseString(StringBuilder sb, int start, int end)
        {

            for (int i = start, j = end; i < j; i++, j--)
            {
                char temp = sb[i];
                sb[i] = sb[j];
                sb[j] = temp;
            }

            return sb;
        }
    }
}
