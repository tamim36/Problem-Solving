using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Text;

namespace ProblemsPractice.Greedy
{
    // 2191
    public class DuplicateKeyComparer<Tkey> : IComparer<Tkey> where Tkey : IComparable
    {
        public int Compare([AllowNull] Tkey x, [AllowNull] Tkey y)
        {
            int res = x.CompareTo(y);

            return res == 0 ? 1 : res;
        }
    }

    public class MyCustomSortedlist <TKey, TValue> : SortedList<TKey, TValue>
    {
        public virtual void Add(TKey key, TValue value)
        {
            if (value == null)
                throw new ArgumentNullException("value");
            base.Add(key, value);
        }
    }

    public class Sort_the_Jumbled_Numbers
    {
        public int GetMappedValue(int[] mapping, int num)
        {
            int mapped = 0;
            int pos = 1;

            if (num == 0)
                return mapping[num];

            while (num > 0)
            {
                int digit = num % 10;
                mapped += (mapping[digit] * pos);
                pos *= 10;
                num /= 10;
            }

            return mapped;
        }
        public int[] SortJumbled(int[] mapping, int[] nums)
        {
            SortedList<int, int> list = new SortedList<int, int>(new DuplicateKeyComparer<int>());

            foreach (int num in nums)
            {
                list.Add(GetMappedValue(mapping, num), num);
            }

            int[] result = new int[list.Count];
            int indx = 0;
            foreach (var item in list)
            {
                result[indx++] = item.Value;
            }

            // Experimenting stuffs
            ///SortedList<int, string> test = new SortedList<int, string>(new DictionaryTest<int, string>());

            MyCustomSortedlist<int, string> test = new MyCustomSortedlist<int, string>();
            test.Add(5, "tamim");
            test.Add(6, null);












            return result;
        }
    }
}
