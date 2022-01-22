using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.LinkedList
{
    public class Odd_Even_Linked_List
    {
        public ListNode OddEvenList(ListNode head)
        {
            if (head == null || head.next == null || head.next.next == null)
                return head;

            ListNode evenHead = head.next, oddCur = head, evenCur = head.next;

            while (oddCur != null && oddCur.next != null)
            {
                oddCur.next = oddCur.next.next;
                
                if (oddCur.next == null)
                    break;

                oddCur = oddCur.next;
                evenCur.next = oddCur.next;
                evenCur = evenCur.next;
            }

            oddCur.next = evenHead;
            return head;
        }
    }
}
