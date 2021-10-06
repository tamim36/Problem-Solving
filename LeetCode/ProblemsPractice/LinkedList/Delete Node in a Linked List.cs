using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.LinkedList
{
    public class Delete_Node_in_a_Linked_List
    {
        public void DeleteNode(ListNode node)
        {
            while (node.next.next != null)
            {
                node.val = node.next.val;
                node = node.next;
            }
            node.val = node.next.val;
            node.next = null;
        }
    }
}
