﻿using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.BST
{
    internal class Delete_Node_in_a_BST
    {
        // 450
        public TreeNode DeleteNode(TreeNode root, int key)
        {
            TreeNode curNode = root;
            TreeNode parent = null;
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

        public TreeNode DeleteNodeRecursive(TreeNode root, int key)
        {
            if (root == null)
                return null;

            if (key < root.val)
                root.left = DeleteNodeRecursive(root.left, key);

            else if (key > root.val)
                root.right = DeleteNodeRecursive(root.right, key);

            else
            {
                if (root.left == null)
                    return root.right;
                else if (root.right == null)
                    return root.left;

                TreeNode newNode = root.right, parent = null;
                while (newNode.left != null)
                {
                    parent = newNode;
                    newNode = newNode.left;
                }
                if (parent == null)
                {
                    newNode.left = root.left;
                    return newNode;
                }

                parent.left = newNode.right;
                newNode.left = root.left;
                newNode.right = root.right;
                return newNode;
            }
            return root;
        }
    }
}
