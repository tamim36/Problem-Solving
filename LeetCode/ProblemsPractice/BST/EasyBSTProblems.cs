using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.BST
{
    public class EasyBSTProblems
    {
        // 230. Kth Smallest Element in a BST
        int KthMin = 0, count = 0;
        public int KthSmallest(TreeNode root, int k)
        {
            KthMin = root.val;
            KthSmallByDFS(root, k);
            return KthMin;
        }

        private void KthSmallByDFS(TreeNode root, int k)
        {
            if (root == null)
                return;

            KthSmallByDFS(root.left, k);
            if (k == ++count)
            {
                KthMin = root.val;
                return;
            }

            KthSmallByDFS(root.right, k);

        }

        // 938. Range Sum of BST
        int rangeSum = 0;
        public int RangeSumBST(TreeNode root, int low, int high)
        {
            rangeSumByDFS(root, low, high);
            return rangeSum;
        }

        private void rangeSumByDFS(TreeNode root, int low, int high)
        {
            if (root == null)
                return;

            if (root.val >= low && root.val <= high)
                rangeSum += root.val;

            rangeSumByDFS(root.left, low, high);
            rangeSumByDFS(root.right, low, high);
        }

        // 700. Search in a Binary Search Tree
        public TreeNode SearchBST(TreeNode root, int val)
        {
            if (root == null)
                return null;
            else if (root.val == val)
                return root;

            if (root.val < val)
                return SearchBST(root.right, val);
            else if (root.val > val)
                return SearchBST(root.left, val);

            return null;
        }

        // 653. Two Sum IV - Input is a BST
        bool isFind = false;
        HashSet<int> values = new HashSet<int>();
        public bool FindTarget(TreeNode root, int k)
        {
            checkByRec(root, k);
            return isFind;
        }

        private void checkByRec(TreeNode root, int k)
        {
            if (root == null || isFind)
                return;

            if (values.Contains(k - root.val))
            {
                isFind = true;
                return;
            }

            values.Add(root.val);
            checkByRec(root.left, k);
            checkByRec(root.right, k);
        }

        //530. Minimum Absolute Difference in BST
        int minDiff = int.MaxValue;
        int prevVal = int.MaxValue;
        public int GetMinimumDifference(TreeNode root)
        {
            GetMinDiffByDfs(root);
            return minDiff;
        }

        private void GetMinDiffByDfs(TreeNode root)
        {
            if (root == null)
                return;

            GetMinDiffByDfs(root.left);
            if (prevVal == 0 || prevVal == 1)
                return;

            minDiff = Math.Min(minDiff, prevVal == int.MaxValue ? minDiff : root.val-prevVal);
            prevVal = root.val;
            GetMinDiffByDfs(root.right);
        }
    }
}
