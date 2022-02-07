using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Queue
{
    //641
    public class MyCircularDeque
    {
        private int len;
        private static int currentLen;
        private Node Front;
        private Node Rear;
        public MyCircularDeque(int k)
        {
            len = k;
            currentLen = 0;
            Front = null;
            Rear = null;
        }

        public bool InsertFront(int value)
        {
            if (currentLen >= len) return false;

            currentLen++;
            Node node = new Node(value);
            if (currentLen == 1)
            {
                Front = node;
                Rear = node;
            }
            else
            {
                node.next = Front;
                Front = node;
            }

            return true;
        }

        public void InsertLast(int value)
        {
           // if (currentLen >= len) return false;

            currentLen++;
            Node node = new Node(value);
            if (currentLen == 1)
            {
                Front = node;
                Rear = node;
            }
            else
            {
                Rear.next = node;
                Rear = Rear.next;
            }

           // return true;
        }

        public bool DeleteFront()
        {
            if (currentLen <= 0) return false;

            Front = Front.next;
            currentLen--;
            return true;
        }

        public bool DeleteLast()
        {
            if (currentLen <= 0) return false;
            else if (currentLen == 1)
            {
                Front = null;
                Rear = null;
            }
            else
            {
                Node cur = Front;
                for (int i = 0; i < currentLen-2; i++)
                    cur = cur.next;

                cur.next = null;
                Rear = cur;
            }

            --currentLen;
            return true;
        }

        public int GetFront()
        {
            return currentLen > 0 ? Front.val : -1;
        }

        public int GetRear()
        {
            return currentLen > 0 ? Rear.val : -1;
        }

        public bool IsEmpty()
        {
            return currentLen==0;
        }

        public bool IsFull()
        {
            return currentLen==len;
        }
    }

    public class Node
    {
        public int val { get; set; }
        public Node next { get; set; }

        public Node(int val = 0, Node next = null)
        {
            this.val = val;
            this.next = next;
        }
    }
}
