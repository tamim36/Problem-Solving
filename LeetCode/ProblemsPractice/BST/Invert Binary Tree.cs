using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.BST
{
    public class Invert_Binary_Tree
    {
        public TreeNode InvertTree(TreeNode root)
        {
            if (root == null)
                return root;

            InvertRec(root);
            return root;
        }

        private void InvertRec(TreeNode root)
        {
            if (root == null || (root.left == null && root.right == null))
                return;

            TreeNode temp = root.right;
            root.right = root.left;
            root.left = temp;

            InvertRec(root.left);
            InvertRec(root.right);
        }
    }
}
