using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Shuffle_String
    {
        public string RestoreString(string s, int[] indices)
        {
            char[] ans = new char[indices.Length];

            for (int i=0; i<indices.Length; i++)
            {
                ans[indices[i]] = s[i];
            }

            return new string(ans);
        }
    }
}
