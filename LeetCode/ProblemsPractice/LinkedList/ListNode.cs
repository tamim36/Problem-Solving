using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.LinkedList
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }

    public static class MyLinkedList
    {
        public static void AppendToLinkedList(int[] nums, ListNode head)
        {
            while (head.next != null)
            {
                head = head.next;
            }

            foreach (int val in nums)
            {
                head.next = new ListNode(val);
                head = head.next;
            }
        }

        public static void PrintListNode(ListNode head)
        {
            while (head.next != null)
            {
                Console.Write(head.val + " -> ");
                head = head.next;
            }
            Console.Write(head.val);
            Console.WriteLine();
        }
    }
}
