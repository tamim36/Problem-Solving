using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.LinkedList
{
    public class Reverse_Linked_List
    {
        // 206
        public ListNode ReverseList(ListNode head)
        {
            if (head == null || head.next == null)
                return head;

            ListNode firstNode = head;
            ListNode secondNode = head;

            while(firstNode.next != null)
            {
                secondNode = firstNode.next;
                firstNode.next = firstNode.next.next;
                secondNode.next = head;
                head = secondNode;
            }

            return head;
        }
    }
}
