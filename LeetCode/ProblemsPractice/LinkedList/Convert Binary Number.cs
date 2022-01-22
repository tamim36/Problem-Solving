using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.LinkedList
{
    public class Convert_Binary_Number
    {
        public int GetDecimalValue(ListNode head)
        {
            int length = 0, deciVal = 0;
            ListNode currentNode = head;

            while (currentNode != null)
            {
                length++;
                currentNode = currentNode.next;
            }

            currentNode = head;
            while (currentNode != null)
            {
                length--;
                deciVal = currentNode.val << length;
                currentNode = currentNode.next;
            }

            return deciVal;
        }
    }
}
