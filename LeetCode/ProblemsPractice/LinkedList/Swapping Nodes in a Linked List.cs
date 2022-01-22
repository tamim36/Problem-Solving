using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.LinkedList
{
    public class Swapping_Nodes_in_a_Linked_List
    {
        public ListNode SwapNodes(ListNode head, int k)
        {
            ListNode pre_left, pre_right, left, right, dummy;
            pre_left = pre_right = dummy = new ListNode(next: head);
            left = right = head;

            for (int i=0; i < k-1; i++)
            {
                pre_left = left;
                left = left.next;
            }

            ListNode finisher = left;

            while (finisher.next != null)
            {
                pre_right = right;
                right = right.next;
                finisher = finisher.next;
            }

            pre_left.next = right;
            pre_right.next = left;

            ListNode temp = left.next;
            left.next = right.next;
            right.next = temp;

            return dummy.next;
        }
    }
}
