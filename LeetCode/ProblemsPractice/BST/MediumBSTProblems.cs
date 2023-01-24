using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice.BST
{
    public class MediumBSTProblems
    {
        // 1123
        int[] LcaLevel;
        public TreeNode LcaDeepestLeaves(TreeNode root)
        {
            LcaLevel = new int[1001];
            return dfsLcaDeepestLeaves(root, 1);
        }

        private TreeNode dfsLcaDeepestLeaves(TreeNode root, int level)
        {
            if (root == null)
                return root;

            LcaLevel[root.val] = level;
            var left = dfsLcaDeepestLeaves(root.left, level + 1);

            var right = dfsLcaDeepestLeaves(root.right, level + 1);



            if (left != null && right != null)
            {
                if (LcaLevel[left.val] == LcaLevel[right.val])
                {
                    LcaLevel[root.val] = LcaLevel[left.val];
                    return root;
                }
                else
                    return LcaLevel[left.val] > LcaLevel[right.val] ? left : right;
            }
            else
                return left != null ? left : right != null ? right : root;
        }

        // 235
        public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
        {
            if (root == null || root.val == p.val || root.val == q.val)
                return root;

            TreeNode left = null;
            TreeNode right = null;

            if (Math.Min(p.val, q.val) < root.val)
                left = LowestCommonAncestor(root.left, p, q);
            if (Math.Max(p.val, q.val) > root.val)
                right = LowestCommonAncestor(root.right, p, q);

            if (left != null && right != null)
                return root;
            if (left != null)
                return left;
            if (right != null)
                return right;

            return null;
        }

        // 236
        public TreeNode LowestCommonAncestora(TreeNode root, TreeNode p, TreeNode q)
        {
            return dfsLCA(root, p, q);
        }

        private TreeNode dfsLCA(TreeNode root, TreeNode p, TreeNode q)
        {
            if (root == null)
                return null;

            if (root.val == p.val || root.val == q.val)
                return root;

            TreeNode left = dfsLCA(root.left, p, q);
            TreeNode right = dfsLCA(root.right, p, q);

            if (left != null && right != null)
                return root;
            if (left != null)
                return left;
            if (right != null)
                return right;

            return null;
        }

        // 199
        IList<int> rightSideViewList;
        int maxRightSideViewLevel = 0;
        public IList<int> RightSideView(TreeNode root)
        {
            rightSideViewList = new List<int>();
            if (root == null)
                return rightSideViewList;
            dfsRightSideView(root, 1);
            return rightSideViewList;
        }

        private void dfsRightSideView(TreeNode root, int level)
        {
            if (root == null)
                return;
            
            if (level > maxRightSideViewLevel)
            {
                maxRightSideViewLevel = level;
                rightSideViewList.Add(root.val);
            }

            dfsRightSideView(root.right, level + 1);
            dfsRightSideView(root.left, level + 1);
        }

        // 1008
        public TreeNode BstFromPreorder(int[] preorder)
        {
            return dfsBstFromPreorder(preorder, 0, preorder.Length - 1);
        }

        private TreeNode dfsBstFromPreorder(int[] preorder, int startIdx, int endIdx)
        {
            if (startIdx > endIdx ||  startIdx >= preorder.Length)
                return null;

            TreeNode root = new TreeNode(preorder[startIdx]);
            int index = -1;
            for (int i = startIdx; i <= Math.Min(endIdx, preorder.Length); i++)
            {
                if (preorder[startIdx] < preorder[i])
                {
                    index = i - 1;
                    break;
                }
            }
            if (index == -1)
                index = endIdx;

            root.left = dfsBstFromPreorder(preorder, startIdx+1, index);
            root.right = dfsBstFromPreorder(preorder, index+1, endIdx);
            return root;
        }

        // 669
        public TreeNode TrimBST(TreeNode root, int low, int high)
        {
            if (root == null)
                return null;

            root.left = TrimBST(root.left, low, high);
            root.right = TrimBST(root.right, low, high);

            if (root.val < low || root.val > high)
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
                newNode.right = root.right;
                newNode.left = root.left;
                return newNode;
            }
            return root;
        }

        // 701
        public TreeNode InsertIntoBST(TreeNode root, int val)
        {
            if (root == null) return new TreeNode(val);

            if (val > root.val)
                root.right = InsertIntoBST(root.right, val);

            else
                root.left = InsertIntoBST(root.left, val);

            return root;
        }

        // 1305
        public IList<int> GetAllElements(TreeNode root1, TreeNode root2)
        {
            var list1 = InOrderTraverse(root1, new List<int>());
            var list2 = InOrderTraverse(root2, new List<int>());

            var res = new List<int>();
            int len = list1.Count + list2.Count;
            for (int i = 0, j = 0; i + j < len;)
            {
                if (i < list1.Count && j < list2.Count)
                {
                    if (list1[i] < list2[j])
                        res.Add(list1[i++]);
                    else
                        res.Add(list2[j++]);
                }
                else if (i < list1.Count)
                    res.Add(list1[i++]);
                else
                    res.Add(list2[j++]);
            }

            return res;
        }

        private IList<int> InOrderTraverse(TreeNode root, IList<int> list)
        {
            if (root == null)
                return list;

            InOrderTraverse(root.left, list);
            list.Add(root.val);
            InOrderTraverse(root.right, list);
            return list;
        }

        // 257
        public string TreePaths = "";
        public IList<string> PathValues;
        public IList<string> BinaryTreePaths(TreeNode root)
        {
            PathValues = new List<string>();
            IList<string> list = PreOrderTraversePaths(root, new List<string>());
            return list;
        }

        private IList<string> PreOrderTraversePaths(TreeNode root, List<string> list)
        {
            if (root == null)
                return list;
            PathValues.Add(root.val.ToString());
            PreOrderTraversePaths(root.left, list);
            PreOrderTraversePaths(root.right, list);

            if (root != null && root.left == null && root.right == null)
            {
                list.Add(string.Join("->", PathValues.ToArray()));
                PathValues.RemoveAt(PathValues.Count - 1);
            }
            else if (root != null)
                PathValues.RemoveAt(PathValues.Count - 1);

            return list;
        }

        // 112
        bool hasPathSum = false;
        public bool HasPathSum(TreeNode root, int targetSum)
        {
            dfsPathSum(root, 0, targetSum);
            return hasPathSum;
        }

        private void dfsPathSum(TreeNode root, int sum, int targetSum)
        {
            if (hasPathSum || root == null)
                return;
            if ((root.left == null && root.right == null) && sum + root.val == targetSum)
            {
                hasPathSum = true;
                return;
            }
            dfsPathSum(root.left, sum + root.val, targetSum);
            dfsPathSum(root.right, sum + root.val, targetSum);
            return;
        }

        // 112
        public bool HasPathSumByStack(TreeNode root, int targetSum)
        {
            if (root == null)
                return false;
            Stack<(TreeNode, int)> stk = new Stack<(TreeNode, int)>();
            stk.Push((root, root.val));

            while (stk.Count > 0)
            {
                var (node, sum) = stk.Pop();
                if (node.left == null && node.right == null && sum == targetSum)
                    return true;
                if (node.right != null)
                    stk.Push((node.right, sum + node.right.val));
                if (node.left != null)
                    stk.Push((node.left, sum + node.left.val));
            }

            return false;
        }

        // 113
        IList<IList<int>> res;
        public IList<IList<int>> PathSum(TreeNode root, int targetSum)
        {
            res = new List<IList<int>>();
            dfsPathSumII(root, new List<int>(), 0, targetSum);
            return res;
        }

        private void dfsPathSumII(TreeNode root, List<int> list, int sum, int targetSum)
        {
            if (root == null)
            {
                //list.RemoveAt(list.Count - 1);
                return;
            }

            list.Add(root.val);

            dfsPathSumII(root.left, list, sum + root.val, targetSum);
            dfsPathSumII(root.right, list, sum + root.val, targetSum);

            if (root.left == null && root.right == null)
            {
                if (sum + root.val == targetSum)
                    res.Add(new List<int>(list));

                list.RemoveAt(list.Count - 1);
                return;
            }
            else if (root != null)
            {
                list.RemoveAt(list.Count - 1);
            }
        }

        // 129
        int resSumNumbers = 0;
        public int SumNumbers(TreeNode root)
        {
            dfsSumNumbers(root, "");
            return resSumNumbers;
        }

        private void dfsSumNumbers(TreeNode root, string paths)
        {
            if (root == null)
                return;

            if (root.left == null && root.right == null)
            {
                resSumNumbers += Convert.ToInt32(paths + root.val);
                return;
            }
            dfsSumNumbers(root.left, paths + root.val);
            dfsSumNumbers(root.right, paths + root.val);
        }

        // 124
        int maxPath = -10001;
        public int MaxPathSum(TreeNode root)
        {
            int x = dfsMaxPathSums(root);
            return maxPath;
        }

        private int dfsMaxPathSums(TreeNode root)
        {
            if (root == null)
                return 0;

            int leftMax = Math.Max(dfsMaxPathSums(root.left), 0);
            int rightMax = Math.Max(dfsMaxPathSums(root.right), 0);
            int curMaxPath = root.val + leftMax + rightMax;
            maxPath = Math.Max(maxPath, curMaxPath);
            return root.val + Math.Max(leftMax, rightMax);
        }

        // 560 
        public int SubarraySum(int[] nums, int k)
        {
            IDictionary<int, int> prefixSum = new Dictionary<int, int>();
            prefixSum.Add(0, 1);

            int curSum = 0, count = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                curSum += nums[i];
                if (prefixSum.ContainsKey(curSum - k))
                    count += prefixSum[curSum - k];

                prefixSum.TryGetValue(curSum, out int curVal);
                prefixSum[curSum] = curVal + 1;
            }

            return count;
        }

        // 437
        Dictionary<int, int> prefixSum;
        int countPathSum = 0, curPathSum = 0;
        public int xPathSum(TreeNode root, int targetSum)
        {
            prefixSum = new Dictionary<int, int>();
            prefixSum.Add(0, 1);
            dfsCalculatePathSum(root, targetSum);
            return countPathSum;
        }

        private void dfsCalculatePathSum(TreeNode root, int targetSum)
        {
            if (root == null)
                return;

            curPathSum += root.val;
            if (prefixSum.ContainsKey(curPathSum - targetSum))
                countPathSum += prefixSum[curPathSum - targetSum];

            prefixSum.TryGetValue(curPathSum, out int xCount);
            prefixSum[curPathSum] = xCount + 1;

            dfsCalculatePathSum(root.left, targetSum);
            dfsCalculatePathSum(root.right, targetSum);

            prefixSum.TryGetValue(curPathSum, out int yCount);
            prefixSum[curPathSum] = yCount - 1;
            curPathSum -= root.val;
        }

        int[] occurancePalPath;
        int countPalPath = 0;
        public int PseudoPalindromicPaths(TreeNode root)
        {
            occurancePalPath = new int[10];
            dfsPseudoPalindromicPath(root);
            return countPalPath;
        }

        private void dfsPseudoPalindromicPath(TreeNode root)
        {
            if (root == null)
                return;

            occurancePalPath[root.val]++;
            if (root.left == null && root.right == null)
            {
                int countOdd = 0;
                for (int i = 0; i < occurancePalPath.Length; i++)
                    countOdd += (occurancePalPath[i] % 2);

                if (countOdd <= 1)
                    countPalPath++;
            }

            dfsPseudoPalindromicPath(root.left);
            dfsPseudoPalindromicPath(root.right);

            if (root != null)
                occurancePalPath[root.val]--;
        }

        // 105
        public TreeNode BuildTree(int[] preorder, int[] inorder)
        {
            return dfsBuildTreePreIn(0, 0, inorder.Length, preorder, inorder);
        }

        private TreeNode dfsBuildTreePreIn(int preStart, int inStart, int inEnd, int[] preorder, int[] inorder)
        {
            if (inEnd < inStart || preStart >= preorder.Length)
                return null;

            TreeNode root = new TreeNode(preorder[preStart]);
            int index = 0;
            for (index = inStart; index < inEnd; index++)
            {
                if (inorder[index] == preorder[preStart])
                    break;
            }

            root.left = dfsBuildTreePreIn(preStart + 1, inStart, index - 1, preorder, inorder);
            root.right = dfsBuildTreePreIn(preStart + index - inStart + 1, index + 1, inEnd, preorder, inorder);

            return root;
        }

        // 106
        public TreeNode BuildTreePostIn(int[] inorder, int[] postorder)
        {
            return dfsBuildTreePostIn(postorder.Length - 1, 0, inorder.Length - 1, inorder, postorder);
        }

        private TreeNode dfsBuildTreePostIn(int postStart, int inStart, int inEnd, int[] inorder, int[] postorder)
        {
            if (inStart > inEnd || postStart < 0 || inStart >= inorder.Length)
                return null;

            TreeNode root = new TreeNode(postorder[postStart]);
            int index = 0;
            for (index = inStart; index < inEnd; index++)
            {
                if (postorder[postStart] == inorder[index])
                    break;
            }

            root.left = dfsBuildTreePostIn(postStart - (inEnd - index) - 1, inStart, index - 1, inorder, postorder);
            root.right = dfsBuildTreePostIn(postStart - 1, index + 1, inEnd, inorder, postorder);

            return root;
        }

        // 889
        public TreeNode ConstructFromPrePost(int[] preorder, int[] postorder)
        {
            return dfsBuildTreePrePost(0, 0, postorder.Length - 1, preorder, postorder);
        }

        private TreeNode dfsBuildTreePrePost(int preStart, int postStart, int postEnd, int[] preorder, int[] postorder)
        {
            if (postStart > postEnd || preStart >= preorder.Length || postStart < 0 || postEnd < 0)
                return null;

            if (postStart == postEnd && preorder[preStart] != postorder[postStart])
                return null;

            bool isExistInPost = false;
            for (int i=postStart; i < postEnd; i++)
            {
                if (postorder[i] == preorder[preStart])
                {
                    isExistInPost = true;
                    break;
                }
            }

            if (!isExistInPost)
                return null;

            TreeNode root = new TreeNode(preorder[preStart]);

            int index = 0, nextNode = preStart + 1;
            bool found  = false;
            if (nextNode < preorder.Length)
            {
                for (index = postStart; index <= postEnd; index++)
                {
                    if (preorder[nextNode] == postorder[index])
                    {
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
                index = -10;

            root.left = dfsBuildTreePrePost(preStart + 1, postStart, index, preorder, postorder);
            int elem = index - postStart + 1;
            //elem = elem == 0 ? 1 : elem;
            root.right = dfsBuildTreePrePost(preStart + elem + 1, index+1, postEnd, preorder, postorder);

            return root;
        }

        // 108
        public TreeNode SortedArrayToBST(int[] nums)
        {
            return dfsBuildTreeSorted(0, nums.Length-1, nums);
        }

        private TreeNode dfsBuildTreeSorted(int start, int end, int[] nums)
        {
            if (start >= nums.Length || end < 0 || start > end)
                return null;

            int mid = (start + end) / 2;
            TreeNode root = new TreeNode(nums[mid]);

            root.left = dfsBuildTreeSorted(start, mid - 1, nums);
            root.right = dfsBuildTreeSorted(mid + 1, end, nums);

            return root;
        }
    }
}
