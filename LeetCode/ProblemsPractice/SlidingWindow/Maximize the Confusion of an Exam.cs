using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.SlidingWindow
{
    public class Maximize_the_Confusion_of_an_Exam
    {
        public int MaxConsecutiveAnswers(string answerKey, int k)
        {
            int maxLen = 0, change = k, cur = 0, j=0;

            // try change F
            for (int i = 0; i < answerKey.Length; i++)
            {
                if (answerKey[i] == 'F') change--;

                while (change < 0)
                {
                    if (answerKey[j++] == 'F') change++;
                }

                cur = i - j + 1;
                maxLen = Math.Max(cur, maxLen);
            }

            change = k; cur = 0; j = 0;
            for (int i = 0; i < answerKey.Length; i++)
            {
                if (answerKey[i] == 'T') change--;

                while (change < 0)
                {
                    if (answerKey[j++] == 'T') change++;
                }
                cur = i - j + 1;
                maxLen = Math.Max(cur, maxLen);
            }

            return maxLen;
        }
    }
}
