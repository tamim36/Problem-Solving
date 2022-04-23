using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.BST
{
    // 101

    public class Symmetric_Tree
    {
        bool isSame = true;

        public bool IsSymmetric(TreeNode root)
        {
            if (root == null)
                return isSame;

            PreOrderTraverse(root.left, root.right);
            return isSame;
        }

        private void PreOrderTraverse(TreeNode p, TreeNode q)
        {
            if (p == null && q == null)
                return;

            if (p == null || q == null || p.val != q.val)
            {
                isSame = false;
                return;
            }

            PreOrderTraverse(p.left, q.right);
            PreOrderTraverse(p.right, q.left);
        }
    }
}
