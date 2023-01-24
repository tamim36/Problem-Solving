using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.BST
{
    // 104
    public class Maximum_Depth_of_Binary_Tree
    {
        public int MaxDepth(TreeNode root)
        {
            if (root == null)
                return 0;
            Queue<TreeNode> q = new Queue<TreeNode>();
            TreeNode cur = root;
            q.Enqueue(cur);
            int maxLevel = 0;
            int nodes = 0;

            while (q.Count > 0)
            {
                nodes = q.Count;
                maxLevel++;
                for (int i = 0; i < nodes; i++)
                {
                    cur = q.Dequeue();
                    if (cur.left != null)
                        q.Enqueue(cur.left);
                    if (cur.right != null)
                        q.Enqueue(cur.right);
                }
            }

            return maxLevel;
        }
    }
}
