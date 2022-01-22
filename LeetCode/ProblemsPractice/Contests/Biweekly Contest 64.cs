using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class Biweekly_Contest_64
    {
        public string KthDistinct(string[] arr, int k)
        {
            var dict = new Dictionary<string, int>();

            foreach (var item in arr)
            {
                if (dict.ContainsKey(item))
                    dict[item]++;
                else
                    dict[item] = 1;
            }

            List<string> res = new List<string>();
            foreach (var item in dict)
            {
                if (item.Value == 1)
                    res.Add(item.Key);
            }

            foreach (var item in res)
            {
                k--;
                if (k == 0)
                    return item;
            }

            return "";
        }
    }
}
