using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class Weekly_Contest_264
    {
        public int CountValidWords(string sentence)
        {
            int count = 0;
            bool isValid = true;
            int hyphen = 0, punc = 0;

            var tokens = sentence.Split(" ");

            foreach (var tok in tokens)
            {
                isValid = true;
                hyphen = 0; punc = 0;

                if (tok.Trim().Length == 0)
                    continue;

                for (int i = 0; i < tok.Length; i++)
                {
                    if (tok[i] >= '0' && tok[i] <= '9')
                    {
                        isValid = false;
                        break;
                    }
                    else if (tok[i] == '-')
                    {
                        if (i == 0 || i == tok.Length - 1 || hyphen == 1)
                        {
                            isValid = false;
                            break;
                        }
                        else if (!((tok[i - 1] >= 'a' && tok[i - 1] <= 'z') && (tok[i + 1] >= 'a' && tok[i + 1] <= 'z')))
                        {
                            isValid = false;
                            break;
                        }

                        else hyphen++;
                    }
                    else if (tok[i] == '!' || tok[i] == ',' || tok[i] == '.')
                    {
                        if (tok.Length > 1)
                        {
                            if (i != tok.Length - 1 || punc == 1 || i == 0)
                            {
                                isValid = false;
                                break;
                            }
                        }
                        else punc++;
                    }
                }

                if (isValid)
                {
                    Console.WriteLine(tok);
                    count++;
                }
                if (!isValid)
                {
                    Console.WriteLine("invalid token : " + tok);
                }
            }

            return count;
        }

        public int NextBeautifulNumber(int n)
        {
            var num1 = new int[]
            {
               0, 1, 22, 122, 212, 221, 333, 1333, 3133, 3313, 3331, 4444, 14444,
            22333, 23233, 23323, 23332, 32233, 32323, 32332, 33223, 33232,
            33322, 41444, 44144, 44414, 44441, 55555, 122333, 123233, 123323,
            123332, 132233, 132323, 132332, 133223, 133232, 133322, 155555,
            212333, 213233, 213323, 213332, 221333, 223133, 223313, 223331,
            224444, 231233, 231323, 231332, 232133, 232313, 232331, 233123,
            233132, 233213, 233231, 233312, 233321, 242444, 244244, 244424,
            244442, 312233, 312323, 312332, 313223, 313232, 313322, 321233,
            321323, 321332, 322133, 322313, 322331, 323123, 323132, 323213,
            323231, 323312, 323321, 331223, 331232, 331322, 332123, 332132,
            332213, 332231, 332312, 332321, 333122, 333212, 333221, 422444,
            424244, 424424, 424442, 442244, 442424, 442442, 444224, 444242,
            444422, 515555, 551555, 555155, 555515, 555551, 666666, 1224444
            };

            //Array.Sort(num1);

            for (int i = 0; i < num1.Length; i++)
            {
                if (num1[i] > n)
                    return num1[i];
            }

            return 0;
        }

        public void permute(String s, String answer)
        {
            if (s.Length == 0)
            {
                Console.Write(answer + "  ");
                return;
            }

            for (int i = 0; i < s.Length; i++)
            {
                char ch = s[i];
                String left_substr = s.Substring(0, i);
                String right_substr = s.Substring(i + 1);
                String rest = left_substr + right_substr;
                permute(rest, answer + ch);
            }
        }
    }
}
