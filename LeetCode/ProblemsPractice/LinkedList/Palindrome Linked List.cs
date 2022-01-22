using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.LinkedList
{
    public class Palindrome_Linked_List
    {
        public bool IsPalindrome(ListNode head)
        {
            if (head.next == null)
                return true;

            ListNode fast = head, Middle = head, slow = head;

            while (fast != null && fast.next != null  && fast.next.next != null)
            {
                slow = slow.next;
                fast = fast.next.next;
                Middle = slow;
            }



            ListNode startMiddle = Middle.next, first = Middle.next, second = Middle.next.next;

            while (second != null)
            {
                first.next = second.next;
                second.next = startMiddle;
                startMiddle = second;
                second = first.next;
            }

            Middle.next = startMiddle;
            Middle = Middle.next;

            while(Middle != null)
            {
                if (head.val != Middle.val)
                    return false;

                Middle = Middle.next;
                head = head.next;
            }
            return true;
        }
    }
}
