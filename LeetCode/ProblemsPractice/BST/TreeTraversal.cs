using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice.BST
{
    public class TreeTraversal
    {
        // 94
        IList<int> list = new List<int>();

        #region BFS (Level Order Traverse)
        // Basic Level order traverse
        public IList<int> BFSTraversal(TreeNode root)
        {
            if (root == null)
                return list;

            Queue<TreeNode> queue = new Queue<TreeNode>();
            queue.Enqueue(root);
            TreeNode curNode = new TreeNode();

            while (queue.Count > 0)
            {
                curNode = queue.Dequeue();
                list.Add(curNode.val);

                if (curNode.left != null)
                    queue.Enqueue(curNode.left);
                if (curNode.right != null)
                    queue.Enqueue(curNode.right);
            }

            return list;
        }

        // Basic BFS with Recursive function
        public IList<int> BFSTraversalRecursive(TreeNode root)
        {
            Queue<TreeNode> queue = new Queue<TreeNode>();
            queue.Enqueue(root);
            BFSTraversalRecursiveMethod(queue, list);
            return list;
        }

        public void BFSTraversalRecursiveMethod(Queue<TreeNode> queue, IList<int> list)
        {
            if (queue.Count == 0)
                return;

            var curNode = queue.Dequeue();
            list.Add(curNode.val);
            if (curNode.left != null)
                queue.Enqueue(curNode.left);
            if (curNode.right != null)
                queue.Enqueue(curNode.right);

            BFSTraversalRecursiveMethod(queue, list);
        }

        // 102
        public IList<IList<int>> LevelOrder(TreeNode root)
        {
            int level = 1, counter = level, nullNode = 0;
            IList<IList<int>> list = new List<IList<int>>();

            if (root == null)
                return list;

            Queue<TreeNode> queue = new Queue<TreeNode>();
            queue.Enqueue(root);
            TreeNode curNode = null;
            IList<int> subList = new List<int>();

            while (queue.Count > 0)
            {
                curNode = queue.Dequeue();
                subList.Add(curNode.val);

                if (--counter == 0)
                {
                    list.Add(subList);
                    subList = new List<int>();

                    level = (level * 2) - nullNode;
                    counter = level;
                    nullNode = 0;
                }

                if (curNode.left != null)
                    queue.Enqueue(curNode.left);
                else if (curNode.left == null)
                    nullNode++;

                if (curNode.right != null)
                    queue.Enqueue(curNode.right);
                else if (curNode.right == null)
                    nullNode++;
            }

            if (subList.Count > 0)
                list.Add(subList);

            return list;
        }

        public IList<IList<int>> LevelOrderCleanCode(TreeNode root)
        {
            IList<IList<int>> list = new List<IList<int>>();

            if (root == null)
                return list;

            Queue<TreeNode> queue = new Queue<TreeNode>();
            queue.Enqueue(root);

            while (queue.Count > 0)
            {
                int size = queue.Count;
                IList<int> subList = new List<int>();
                for (int i = 0; i < size; i++)
                {
                    TreeNode curNode = queue.Dequeue();
                    subList.Add(curNode.val);
                    
                    if (curNode.left != null)
                        queue.Enqueue(curNode.left);
                    if (curNode.right != null)
                        queue.Enqueue(curNode.right);
                }

                list.Add(subList);
            }

            return list;
        }

        #endregion

        #region By Recursion

        public IList<int> InorderTraversal(TreeNode root)
        {
            InorderList(root);
            return list;
        }

        private void InorderList(TreeNode root)
        {
            if (root == null)
                return;
            InorderList(root.left);
            list.Add(root.val);
            InorderList(root.right);
        }

        
        // 144
        public IList<int> PreorderTraversal(TreeNode root)
        {
            PreorderTraversalList(root);
            return list;
        }

        private void PreorderTraversalList(TreeNode root)
        {
            if (root == null)
                return;

            list.Add(root.val);
            PreorderTraversalList(root.left);

            PreorderTraversalList(root.right);
        }

        // 145
        public IList<int> PostorderTraversal(TreeNode root)
        {
            PostorderTraversalList(root);
            return list;
        }

        private void PostorderTraversalList(TreeNode root)
        {
            if (root == null)
                return;

            
            PostorderTraversalList(root.left);

            PostorderTraversalList(root.right);
            list.Add(root.val);
        }

        #endregion

        #region By Stack (Iterative)

        // 94 - follow up with stack
        public IList<int> InorderTraversalIterative(TreeNode root)
        {
            var stack = new Stack<TreeNode>();
            TreeNode cur = root;

            while (cur != null || stack.Count > 0)
            {
                while (cur != null)
                {
                    stack.Push(cur);
                    cur = cur.left;
                }

                cur = stack.Pop();
                list.Add(cur.val);
                cur = cur.right;
            }

            return list;
        }

        public IList<int> PreorderTraversalIterative(TreeNode root)
        {
            Stack<TreeNode> stack = new Stack<TreeNode>();
            var cur = root;

            while (cur != null || stack.Count > 0)
            {
                list.Add(cur.val);
                stack.Push(cur);
                cur = cur.left;

                if (cur == null)
                {
                    while (stack.Count > 0 && cur == null)
                        cur = stack.Pop().right;
                }
            }

            return list;
        }

        // 145
        public IList<int> PostorderTraversalIterative(TreeNode root)
        {
            Stack<TreeNode> st = new Stack<TreeNode>();
            Stack<int> RevPostOrder = new Stack<int>();
            var cur = root;

            while(cur != null || st.Count > 0)
            {
                RevPostOrder.Push(cur.val);
                Console.WriteLine(cur.val);
                st.Push(cur);
                cur = cur.right;

                if (cur == null)
                {
                    while (st.Count > 0 && cur == null)
                        cur = st.Pop().left;
                }
            }

            while(RevPostOrder.Count > 0)
                list.Add(RevPostOrder.Pop());


            return list;
        }

        #endregion

        #region By Morris Traversal (Without Stack or Recursion)
        // 94 By Morris Traversal (without using stack or recursion)
        public IList<int> InorderTraversalMorris(TreeNode root)
        {
            TreeNode current = root;

            while (current != null)
            {
                if (current.left == null)
                {
                    list.Add(current.val);
                    current = current.right;
                }
                else
                {
                    TreeNode predecessor = current.left;
                    // To find predecessor keep going till right node is not null or right is not current.
                    while (predecessor.right != current && predecessor.right != null)
                        predecessor = predecessor.right;

                    if (predecessor.right == null)
                    {
                        predecessor.right = current;
                        current = current.left;
                    }
                    else
                    {
                        predecessor.right = null;
                        list.Add(current.val);
                        current = current.right;
                    }
                }
            }
            
            return list;
        }

        // 144 By Morris Traversal (without using stack or recursion)
        public IList<int> PreorderTraversalMorris(TreeNode root)
        {
            TreeNode current = root;

            while (current != null)
            {
                if (current.left == null)
                {
                    list.Add(current.val);
                    current = current.right;
                }
                else
                {
                    TreeNode predecessor = current.left;
                    while (predecessor.right != null && predecessor.right != current)
                        predecessor = predecessor.right;

                    if (predecessor.right == null)
                    {
                        predecessor.right = current;
                        list.Add(current.val);
                        current = current.left;
                    }
                    else
                    {
                        predecessor.right = null;
                        current = current.right;
                    }
                }
            }

            return list;
        }

        // 145 By Morris Traversal (without using stack or recursion)
        public IList<int> PostorderTraversalMorris(TreeNode root)
        {
            TreeNode current = root;
            while (current != null)
            {
                if (current.right == null)
                {
                    list.Add(current.val);
                    current = current.left;
                }
                else
                {
                    TreeNode predecessor = current.right;
                    while (predecessor.left != null && predecessor.left != current)
                        predecessor = predecessor.left;

                    if (predecessor.left == null)
                    {
                        list.Add(current.val);
                        predecessor.left = current;
                        current = current.right;
                    }
                    else
                    {
                        predecessor.left = null;
                        current = current.left;
                    }
                }
            }

            return list.Reverse().ToList();
        }
        #endregion
    }
}
