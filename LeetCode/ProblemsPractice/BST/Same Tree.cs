using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.BST
{
    // 100
    public class Same_Tree
    {
        bool isSame = true;
        public bool IsSameTree(TreeNode p, TreeNode q)
        {
            if (p == null && q == null)
                return true;
            if (p == null || q == null || p.val != q.val)
                return false;

            PreOrderTraverse(p, q);
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

            PreOrderTraverse(p.left, q.left);
            PreOrderTraverse(p.right, q.right);
        }
    }
}
