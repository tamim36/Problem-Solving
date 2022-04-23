using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.BST
{
    public class Binary_Tree_Zigzag_Level_Order_Traversal
    {
        // 103
        public IList<IList<int>> ZigzagLevelOrder(TreeNode root)
        {
            IList<IList<int>> result = new List<IList<int>>();
            if (root == null)
                return result;

            LinkedList<TreeNode> doublyList = new LinkedList<TreeNode>();
            doublyList.AddFirst(root);
            int level = 0;

            while (doublyList.Count > 0)
            {
                IList<int> subList = new List<int>();
                TreeNode curNode = null;
                int size  = doublyList.Count;

                if (level % 2 == 0)
                {
                    for (int i = 0; i < size; i++)
                    {
                        curNode = doublyList.First.Value;
                        doublyList.RemoveFirst();
                        subList.Add(curNode.val);

                        if (curNode.left != null)
                            doublyList.AddLast(curNode.left);
                        if (curNode.right != null)
                            doublyList.AddLast(curNode.right);
                    }
                }
                else
                {
                    for (int i = 0; i < size; i++)
                    {
                        curNode = doublyList.Last.Value;
                        doublyList.RemoveLast();
                        subList.Add(curNode.val);

                        if (curNode.right != null)
                            doublyList.AddFirst(curNode.right);
                        if (curNode.left != null)
                            doublyList.AddFirst(curNode.left);
                    }
                }
                result.Add(subList);
                level++;
            }
            return result;
        }
    }
}
