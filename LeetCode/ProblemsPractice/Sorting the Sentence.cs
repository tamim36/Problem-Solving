using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Sorting_the_Sentence
    {
        public string SortSentence(string s)
        {
            var words = s.Split(" ");
            string sentence = "";
            var wordIndx = new SortedDictionary<int, string>();
            foreach (var word in words)
            {
                wordIndx.Add((int)word[word.Length - 1] - (int)'0', word.Remove(word.Length - 1, 1));
            }

            foreach (var item in wordIndx)
            {
                sentence += item.Value + " ";
            }
            Console.WriteLine(sentence);

            return sentence.Trim();
        }
    }
}
