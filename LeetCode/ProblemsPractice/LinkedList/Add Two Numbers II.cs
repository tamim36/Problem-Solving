using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.LinkedList
{
    public class Add_Two_Numbers_II
    {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2)
        {
            Stack<int> l1Stack = new Stack<int>();
            Stack<int> l2Stack = new Stack<int>();

            for (ListNode cur = l1; cur != null; cur = cur.next)
                l1Stack.Push(cur.val);

            for (ListNode cur = l2; cur != null; cur = cur.next)
                l2Stack.Push(cur.val);

            int carry = 0, num, num1, num2;
            ListNode tail = null, pre = new ListNode(0);
            while (l1Stack.Count > 0 || l2Stack.Count > 0)
            {
                num1 = l1Stack.Count > 0 ? l1Stack.Pop() : 0;
                num2 = l2Stack.Count > 0 ? l2Stack.Pop() : 0;

                num = carry + num1 + num2;
                if (num > 9)
                    carry = 1;
                else
                    carry = 0;

                pre = new ListNode(num%10, tail);
                tail = pre;
            }

            if (carry == 1)
                pre = new ListNode(1, tail);

            return pre; 
        }
    }
}
