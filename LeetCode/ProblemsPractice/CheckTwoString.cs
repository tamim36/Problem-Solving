using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class CheckTwoString
    {
        public bool ArrayStringsAreEqual(string[] word1, string[] word2)
        {
            string firstString = "";
            string secondString = "";

            foreach (var word in word1)
            {
                firstString += word;
            }

            foreach (var word in word2)
            {
                secondString += word;
            }

            return firstString == secondString;
        }
    }
}
