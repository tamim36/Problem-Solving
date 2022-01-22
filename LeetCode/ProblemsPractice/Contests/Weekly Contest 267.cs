using ProblemsPractice.LinkedList;
using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class Weekly_Contest_267
    {
        public int TimeRequiredToBuy(int[] tickets, int k)
        {
            int val = tickets[k], time  = 0;

            for (int i = 0; i < tickets.Length; i++)
            {
                if (i < k)
                {
                    if (tickets[i] < val)
                        time += tickets[i];
                    else
                        time += val;
                }

                else if (i == k)
                    time += val;

                else
                {
                    if (tickets[i] <= val - 1)
                        time += tickets[i];
                    else
                        time += (val - 1);
                }
            }

            return time;
        }

        public ListNode ReverseEvenLengthGroups(ListNode head)
        {
            int groups = 2, val = 1;

            for (ListNode cur = head; cur.next != null; cur = cur.next)
            {
                val = 1;
                while (val < groups-1 && cur.next != null)
                {
                    val++;
                    cur = cur.next;
                }

                var st = ReverseNodes(cur.next, groups);
                cur.next = st;

                val = 1;
                while (val <= groups && cur.next != null)
                {
                    val++;
                    cur = cur.next;
                }
                groups *= 2;
            }
            return head;
        }

        public ListNode ReverseNodes(ListNode start, int groups)
        {
            ListNode firstNode = start;
            ListNode secondNode = start;

            while (firstNode.next != null)
            {
                secondNode = firstNode.next;
                firstNode.next = firstNode.next.next;
                secondNode.next = start;
                start = secondNode;
            }

            return start;
        } 
    }
}
