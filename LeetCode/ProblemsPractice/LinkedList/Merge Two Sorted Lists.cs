using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.LinkedList
{
    public class Merge_Two_Sorted_Lists
    {
        public ListNode MergeTwoLists(ListNode l1, ListNode l2)
        {
            if (l1 == null && l2 == null)
                return l1;

            ListNode ansList = new ListNode();
            var head = ansList;

            while (l1 != null || l2 != null)
            {
                if (l2 == null || l1.val < l2.val)
                {
                    ansList.val = l1.val;
                    l1 = l1.next;
                }
                else
                {
                    ansList.val = l2.val;
                    l2 = l2.next;
                }

                ansList.next = new ListNode();
                ansList = ansList.next;
            }

            Console.WriteLine("output : "+ ansList.val);

            ansList = null;
            return head;
        }
    }
}
