using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.BST
{
    // 563
    public class Binary_Tree_Tilt
    {
        int res = 0;
        public int FindTilt(TreeNode root)
        {
            if (root == null)
                return 0;

            int x = FindTiltByRec(root);
            return res;
        }

        private int FindTiltByRec(TreeNode root)
        {
            if (root == null)
                return 0;
            
            int left = FindTiltByRec(root.left);
            int right = FindTiltByRec(root.right);

            res += Math.Abs(left - right);
            return left+right+root.val;
        }
    }
}
