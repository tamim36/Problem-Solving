using ProblemsPractice.LinkedList;
using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class Weekly_Contest_281
    {
        public bool IsSumEven(int num)
        {
            int digitSum = 0;
            while (num > 0)
            {
                digitSum += (num % 10);
                num /= 10;
            }

            return digitSum % 2 == 0;
        }
        public int CountEven(int num)
        {
            return !IsSumEven(num) && num % 2 == 0 ? (num / 2) - 1 : num / 2;return !IsSumEven(num) && num % 2 == 0 ? (num / 2) - 1 : num / 2;
        }


        public ListNode MergeNodes(ListNode head)
        {
            ListNode curNode = head;
            ListNode resNode = null;
            ListNode resNodeHead = null;
            int sum = 0;

            while (curNode != null)
            {
                if (curNode.val == 0 && sum > 0)
                {
                    if (resNode == null)
                    {
                        resNode = new ListNode(sum);
                        resNodeHead = resNode;
                    }
                    else
                    {
                        resNode.next = new ListNode(sum);
                        resNode = resNode.next;
                    }

                    sum = 0;
                }

                sum += curNode.val;
                curNode = curNode.next;
            }

            return resNodeHead;
        }
    }
}
