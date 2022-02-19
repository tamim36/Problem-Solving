using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace ProblemsPractice.Design
{
    public class ProductOfNumbers
    {
        IList<int> list;
        IList<int> prefixList;
        public ProductOfNumbers()
        {
            list = new List<int>();
            prefixList = new List<int>();
        }

        public void Add(int num)
        {
            if (num == 0)
            {
                list.Clear();
                prefixList.Clear();
                return;
            }
            list.Add(num);
            if (prefixList.Count == 0) prefixList.Add(num);
            else
                prefixList.Add(prefixList.Last() * num);
        }

        public int GetProduct(int k)
        {
            for (int i = 0; i < list.Count; i++)
            {
                Console.WriteLine($"list {i}: {list[i]}  & preList {i}: {prefixList[i]}");
            }
            if (list.Count == 0) return -1;
            else if (prefixList.Count == k) return prefixList.Last();

            int startIndex = prefixList.Count - k - 1;
            if (startIndex < 0) return 0;
            Console.WriteLine(startIndex);
            return prefixList.Last() / prefixList[startIndex];
        }
    }
}
