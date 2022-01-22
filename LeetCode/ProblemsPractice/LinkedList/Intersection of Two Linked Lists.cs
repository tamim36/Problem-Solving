using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.LinkedList
{
    public class Intersection_of_Two_Linked_Lists
    {
        public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
        {
            ListNode curA = headA, curB = headB, intersectNode = null;

            // negate all value of headA
            while (curA != null)
            {
                curA.val *= -1;
                curA = curA.next;
            }

            while (curB != null)
            {
                if (curB.val < 0)
                {
                    intersectNode = curB;
                    break;
                }
                curB = curB.next;
            }

            curA = headA;
            while (curA != null)
            {
                curA.val *= -1;
                curA = curA.next;
            }

            return intersectNode;
        }
    }
}
