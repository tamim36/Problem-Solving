using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    // 2182
    public class Construct_String_With_Repeat_Limit
    {
        public string RepeatLimitedString(string s, int repeatLimit)
        {
            int[] freq = new int[130];
            char[] chars = new char[s.Length];
            foreach (char c in s)
                freq[c]++;

            Stack<int> stk = new Stack<int>();
            int indx = 0;

            for (int i = 129; i >= 0; i--)
            {
                int rem = repeatLimit;
                while (freq[i] > 0)
                {
                    char c = (char)i;
                    chars[indx++] = (char)i;
                    rem--;
                    freq[i]--;
                    if (stk.Count > 0 && stk.Peek() != i)
                    {
                        i = stk.Pop() + 1;
                        rem = 0;
                        break;
                    }
                    if (rem == 0 && freq[i] > 0)
                    {
                        stk.Push(i);
                        break;
                    }
                }
                if (stk.Count > 0 && i == 0 && chars[indx - 1] != (char)stk.Peek())
                {
                    i = stk.Pop() + 1;
                    rem = 0;
                }
            }

            return new string(chars, 0, indx);
        }
        

    }
}
