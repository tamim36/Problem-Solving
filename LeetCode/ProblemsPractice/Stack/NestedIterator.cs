using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    // This is the interface that allows for creating nested lists.
    // You should not implement it, or speculate about its implementation
    interface NestedInteger
    {

        // @return true if this NestedInteger holds a single integer, rather than a nested list.
        bool IsInteger();

        // @return the single integer that this NestedInteger holds, if it holds a single integer
        // Return null if this NestedInteger holds a nested list
        int GetInteger();

        // @return the nested list that this NestedInteger holds, if it holds a nested list
        // Return null if this NestedInteger holds a single integer
        IList<NestedInteger> GetList();
    }

    // 341
    public class NestedIterator
    {
        /*IEnumerator<NestedInteger> it;
        Stack<IEnumerator<NestedInteger>> itStk;
        public NestedIterator(IList<NestedInteger> nestedList)
        {
            it = nestedList.GetEnumerator();
            itStk = new Stack<IEnumerator<NestedInteger>>();
            itStk.Push(it);
        }

        public bool HasNext()
        {
            if (it.MoveNext())
            {
                if (it.Current.IsInteger())
                    return true;
                // it means list
                else
                {
                    it = it.Current.GetList().GetEnumerator();
                    itStk.Push(it);
                    return HasNext();
                }
            }

            else
            {
                if (itStk.Count > 0)
                {
                    itStk.Pop();
                    if (itStk.Count > 0)
                        it = itStk.Peek();
                    return HasNext();
                }
                    
                return false;
            }
        }

        public int Next()
        {
            return itStk.Peek().Current.GetInteger();
        }*/
    }
}
