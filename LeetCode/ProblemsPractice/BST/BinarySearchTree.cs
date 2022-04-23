using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.BST
{
    public class Node
    {
        public Node Left { get; set; }
        public Node Right { get; set; }
        public int Value { get; set; }

        public Node(int val)
        {
            this.Left = null;
            this.Right = null;
            this.Value = val;
        }
    }

    public class BinarySearchTree
    {
        static readonly int COUNT = 10;
        public Node Root { get; set; }

        public BinarySearchTree()
        {
            this.Root = null;
        }

        public void Insert(int val)
        {
            if (Root == null)
                Root = new Node(val);
            else
            {
                Node curNode = this.Root;
                while (curNode != null)
                {
                    if (val > curNode.Value)
                    {
                        if (curNode.Right == null)
                        {
                            curNode.Right = new Node(val);
                            break;
                        }
                        curNode = curNode.Right;
                    }
                    else
                    {
                        if (curNode.Left == null)
                        {
                            curNode.Left = new Node(val);
                            break;
                        }
                        curNode = curNode.Left;
                    }
                }
            }
        }

        public Node LookUp(int val)
        {
            Node curNode = this.Root;
            while (curNode != null)
            {
                if (curNode.Value == val)
                    return curNode;

                curNode = val > curNode.Value ? curNode.Right : curNode.Left;
            }

            return null;
        }

        public void print2DUtil(Node root, int space)
        {
            // Base case
            if (root == null)
                return;

            // Increase distance between levels
            space += COUNT;

            // Process right child first
            print2DUtil(root.Right, space);

            // Print current node after space
            // count
            Console.Write("\n");
            for (int i = COUNT; i < space; i++)
                Console.Write(" ");
            Console.Write(root.Value + "\n");

            // Process left child
            print2DUtil(root.Left, space);
        }

        public void Remove(int val)
        {
            Node curNode = this.Root;
            Node parent = null;
            while (curNode != null)
            {
                if (val < curNode.Value)
                {
                    parent = curNode;
                    curNode = curNode.Left;
                }
                else if (val > curNode.Value)
                {
                    parent = curNode;
                    curNode = curNode.Right;
                }
                else if (val == curNode.Value)
                {
                    // No right child || for one chile or no child
                    if (curNode.Right == null)
                    {
                        if (parent == null)
                        {
                            this.Root = curNode.Left;
                        }
                        else if (curNode.Value > parent.Value)
                            parent.Right = curNode.Left;
                        else
                            parent.Left = curNode.Left;
                    }
                    else if (curNode.Right.Left == null)
                    {
                        if (parent == null)
                            this.Root = curNode.Right;
                        else
                        {
                            curNode.Right.Left = curNode.Left;

                            if (curNode.Value > parent.Value)
                                parent.Right = curNode.Right;
                            else
                                parent.Left = curNode.Right;
                        }
                    }

                    // right child that has a left child || 2 child exists
                    else
                    {
                        // fint the RIght child's left most child
                        var leftMost = curNode.Right.Left;
                        var leftMostParent = curNode.Right;

                        while (leftMost.Left != null)
                        {
                            leftMostParent = leftMost;
                            leftMost = leftMost.Left;
                        }

                        // Parent's left subtree is now leftmost's right subtree
                        leftMostParent.Left = leftMost.Right;
                        leftMost.Left = curNode.Left;
                        leftMost.Right = curNode.Right;

                        // check if it is root or not 
                        if (parent == null)
                            this.Root = leftMost;
                        else
                        {
                            if (curNode.Value > parent.Value)
                                parent.Right = leftMost;
                            else
                                parent.Left = leftMost;
                        }
                    }
                }
            }
        }




        // 450 - Unsolved
        public TreeNode RemoveLeetcode(TreeNode root, int key)
        {
            TreeNode curNode = root;
            TreeNode parent = null;
            Console.WriteLine("root left : " + root.left);
            while (curNode != null)
            {
                if (key < curNode.val)
                {
                    parent = curNode;
                    curNode = curNode.left;
                }
                else if (key > curNode.val)
                {
                    parent = curNode;
                    curNode = curNode.right;
                }
                else if (key == curNode.val)
                {
                    // No right child || for one chile or no child
                    if (curNode.right == null)
                    {
                        if (parent == null)
                        {
                            root = curNode.left;
                        }
                        else if (curNode.val > parent.val)
                            parent.right = curNode.left;
                        else
                            parent.left = curNode.left;
                    }
                    else if (curNode.right.left == null)
                    {
                        curNode.right.left = curNode.left;

                        if (parent == null)
                            root = curNode.right;
                        else if (curNode.val > parent.val)
                            parent.right = curNode.right;
                        else
                            parent.left = curNode.right;
                    }

                    // right child that has a left child || 2 child exists
                    else
                    {
                        // fint the RIght child's left most child
                        var leftMost = curNode.right.left;
                        var leftMostParent = curNode.right;

                        while (leftMost.left != null)
                        {
                            leftMostParent = leftMost;
                            leftMost = leftMost.left;
                        }

                        // Parent's left subtree is now leftmost's right subtree
                        leftMostParent.left = leftMost.right;
                        leftMost.left = curNode.left;
                        leftMost.right = curNode.right;

                        // check if it is root or not 
                        if (parent == null)
                            root = leftMost;
                        else
                        {
                            if (curNode.val > parent.val)
                                parent.right = leftMost;
                            else
                                parent.left = leftMost;
                        }
                    }

                    break;
                }
            }

            return root;
        }
    }
}
