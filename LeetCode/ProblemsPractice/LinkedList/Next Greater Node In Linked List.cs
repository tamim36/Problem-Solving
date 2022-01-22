using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace ProblemsPractice.LinkedList
{
    public class Next_Greater_Node_In_Linked_List
    {
        public int[] NextLargerNodes(ListNode head)
        {
            ListNode first, second, temp;
            first = null;
            second = head;

            while(second != null)
            {
                temp = second.next;
                second.next = first;
                first = second;
                second = temp;
            }
            head = first;

            IList<int> ans = new List<int>();
            Stack<int> maxNums = new Stack<int>();
            maxNums.Push(0);
            maxNums.Push(head.val);
            ans.Add(0);

            for (temp = head.next; temp != null; temp = temp.next)
            {
                while(maxNums.Peek() != 0 && maxNums.Peek() <= temp.val)
                {
                    maxNums.Pop();
                }
                
                ans.Add(maxNums.Peek());
                maxNums.Push(temp.val);
            }
            

            return ans.Reverse().ToArray();
        }
    }
}
