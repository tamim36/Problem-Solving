using ProblemsPractice.BST;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;

namespace ProblemsPractice
{
    public class MediumProblems
    {

        // 1038 538
        public int rec_ConvertBST(TreeNode root, int val)
        {
            if (root == null) return 0;

            int rVal = rec_ConvertBST(root.right, val);
            val = rVal == 0 ? val : rVal;
            val += root.val;
            root.val = val;
            int lVal = rec_ConvertBST(root.left, val);
            val = lVal == 0 ? val : lVal;

            return val;
        }

        public TreeNode ConvertBST(TreeNode root)
        {
            rec_ConvertBST(root, 0);
            return root;
        }

        // 77
        public IList<IList<int>> Combine(int n, int k)
        {
            IList<IList<int>> ans = new List<IList<int>>();
            IList<int> sofar = new List<int>();

            recur_combine(n, k, 1, sofar, ans);
            return ans;
        }

        public void recur_combine(int n, int k, int cur, IList<int> sofar, IList<IList<int>> ans)
        {
            if (sofar.Count == k)
            {
                ans.Add(new List<int>(sofar));
                return;
            }

            for (int i = cur; i <= n; i++)
            {
                sofar.Add(i);

                recur_combine(n, k, i + 1, sofar, ans);

                if (sofar.Any())
                    sofar.RemoveAt(sofar.Count - 1);
            }
        }

        // 2850
        public int MinimumMoves(int[][] grid)
        {
            int[] starter = new int[9];
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    starter[i*3 +j] = grid[i][j];
                }
            }

            var target = new int[] { 1, 1, 1, 1, 1, 1, 1, 1, 1};
            Queue<int[]> q = new Queue<int[]>();
            ISet<string> visited = new HashSet<string>();

            q.Enqueue(starter);
            visited.Add(ArrayToString(starter));

            int moves = 0;
            while (q.Any())
            {
                int sz = q.Count;
                for (int i = 0; i < sz; i++)
                {
                    int[] cur = q.Dequeue();
                    if (cur.SequenceEqual(target))
                        return moves;

                    for (int j = 0; j < 9; j++)
                    {
                        if (cur[j] > 1)
                        {
                            foreach (var adj in getAdjacentsMimimumMoves(j))
                            {
                                int[] newState = (int[])cur.Clone();
                                newState[j]--;
                                newState[adj]++;

                                string state = ArrayToString(newState);
                                if (!visited.Contains(state))
                                {
                                    q.Enqueue(newState);
                                    visited.Add(state);
                                }
                            }
                        }
                    }
                }
                moves++;
            }


            return moves;
        }

        public IList<int> getAdjacentsMimimumMoves(int index)
        {
            IList<int> adj = new List<int>();
            if (index % 3 != 0) adj.Add(index - 1);
            if (index % 3 != 2) adj.Add(index + 1);
            if (index / 3 != 0) adj.Add(index - 3);
            if (index / 3 != 2) adj.Add(index + 3);
            return adj;
        }

        public string ArrayToString(int[] ara)
        {
            string res = "";
            foreach (int num in ara)
            {
                res += num;
            }
            return res;
        }

        // 47
        public IList<IList<int>> PermuteUnique(int[] nums)
        {
            IList<IList<int>> res = new List<IList<int>>();
            recur_permuteUnique(res, 0, nums);
            return res;
        }

        private void recur_permuteUnique(IList<IList<int>> res, int idx, int[] nums)
        {
            if (idx == nums.Length)
            {
                res.Add(nums.ToList());
                return;
            }

            ISet<int> visited = new HashSet<int>();
            for (int i = idx; i < nums.Length; i++)
            {
                if (!visited.Add(nums[i]))
                {
                    continue;
                }

                var tmp = nums[idx];
                nums[idx] = nums[i];
                nums[i] = tmp;

                recur_permuteUnique(res, idx + 1, nums);

                tmp = nums[idx];
                nums[idx] = nums[i];
                nums[i] = tmp;
            }
        }

        // 2389
        public int[] AnswerQueries(int[] nums, int[] queries)
        {
            Array.Sort(nums);
            int[] answer = new int[queries.Length];

            for (int i = 1; i < nums.Length; i++)
            {
                nums[i] += nums[i - 1];
            }

            for (int i = 0; i < queries.Length; i++)
            {
                answer[i] = binarySearchAnswerQueries(nums, queries[i]);
            }

            return answer;
        }

        public int binarySearchAnswerQueries(int[] nums, int val)
        {
            int left = 0, right = nums.Length;

            while (left < right)
            {
                int mid = left + (right - left) / 2;

                if (val < nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }

            return left;
        }

        // 1658
        public int MinOperations(int[] nums, int x)
        {
            int sz = nums.Length;
            int rem = nums.Sum();
            rem -= x;

            if (rem == 0) return sz;
            if (rem < 0) return -1;

            IDictionary<int, int> map = new Dictionary<int, int>();
            map.Add(0, -1);

            int curSum = 0, res = int.MinValue;
            for (int i = 0; i < sz; i++)
            {
                curSum += nums[i];

                if (map.ContainsKey(curSum - rem))
                    res = Math.Max(res, i - map[curSum - rem]);

                map.Add(curSum, i);
            }

            return res == int.MinValue ? -1 : sz - res;
        }

        // 417
        public IList<IList<int>> PacificAtlantic(int[][] heights)
        {
            IList<IList<int>> ans = new List<IList<int>>();
            int m = heights.Length, n = heights[0].Length;
            bool[][] pacific = new bool[m][];
            bool[][] atlantic = new bool[m][];

            for (int i = 0; i < m; i++)
            {
                pacific[i] = new bool[n];
                atlantic[i] = new bool[n];
            }

            for (int i = 0; i < m; i++)
            {
                dfs_PacificAtlantic(heights, pacific, int.MinValue, i, 0);
                dfs_PacificAtlantic(heights, atlantic, int.MinValue, i, n-1);
            }

            for (int i = 0; i < n; i++)
            {
                dfs_PacificAtlantic(heights, pacific, int.MinValue, 0, i);
                dfs_PacificAtlantic(heights, atlantic, int.MinValue, m-1, i);
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (atlantic[i][j])
                        Console.Write($"x ");
                    else Console.Write($"o ");
                }
                Console.WriteLine();
            }

            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (pacific[i][j] && atlantic[i][j])
                        ans.Add(new List<int>() { i, j});
            
            return ans;
        }

        int[][] dir = new int[][] { new int[] { 0, 1 }, new int[] { 0, -1 }, new int[] { 1, 0 }, new int[] { -1, 0 } };
        public void dfs_PacificAtlantic(int[][] heights, bool[][] visited, int height, int x, int y)
        {
            if (visited[x][y]) return;
            visited[x][y] = true;
            Console.WriteLine("height: " + height + " ; Height x y: " + heights[x][y]);
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dir[i][0], yy = y + dir[i][1];
                
                if (xx >= 0 && xx < heights.Length && yy >= 0 && yy < heights[0].Length
                    && heights[x][y] <= heights[xx][yy] && !visited[xx][yy])
                    dfs_PacificAtlantic(heights, visited, heights[x][y], xx, yy);
            }
        }
        /*
        public void dfs_PacificAtlantic(int[][] matrix, bool[][] visited, int height, int x, int y)
        {
            int n = matrix.Length, m = matrix[0].Length;
            if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || matrix[x][y] < height)
                return;
            visited[x][y] = true;
            foreach (int[] d in dir)
            {
                dfs_PacificAtlantic(matrix, visited, matrix[x][y], x + d[0], y + d[1]);
            }
        }*/

        // 1306
        public bool CanReach(int[] arr, int idx)
        {
            return 0 <= idx && idx < arr.Length
                && arr[idx] <= 0 && ((arr[idx] = -arr[idx]) == 0
                || CanReach(arr, idx - arr[idx]) || CanReach(arr, idx + arr[idx]));  
        }

        // 2685
        public int CountCompleteComponents(int n, int[][] edges)
        {
            IList<IList<int>> adj = new List<IList<int>>(n);
            for (int i = 0; i < n; i++)
                adj.Add(new List<int>());

            int[] vis = new int[n];
            Queue<int> q = new Queue<int>();
            int cnt = 0;

            foreach (var edge in edges)
            {
                adj[edge[0]].Add(edge[1]);
                adj[edge[1]].Add(edge[0]);
            }

            for (int i = 0; i < n; i++)
            {
                if (vis[i] == 1) continue;

                q.Enqueue(i);
                vis[i] = 1;
                int conNodes = adj[i].Count;
                bool isConnected = true;
                int numNodes = 0;

                while (q.Count > 0)
                {
                    int cur = q.Dequeue();
                    numNodes++;

                    if (isConnected && adj[cur].Count != conNodes)
                        isConnected = false;

                    foreach (var nei in adj[cur])
                    {
                        if (vis[nei] == 1) continue;
                        q.Enqueue(nei);
                        vis[nei] = 1;
                    }
                }

                if (numNodes - 1 == conNodes && isConnected)
                    cnt++;
            }

            return cnt;
        }

        // 406
        public int[][] ReconstructQueue(int[][] people)
        {
            List<int[]> sorted = people.OrderByDescending(x => x[0]).ThenBy(x => x[1]).ToList();
            List<int[]> res = new List<int[]>(people.Length);

            foreach (int[] item in sorted)
                res.Insert(item[1], item);

            return res.ToArray();
        }

        // 2398
        public int MaximumRobots(int[] chargeTimes, int[] runningCosts, long budget)
        {
            LinkedList<int> timesSorted = new LinkedList<int>();
            long sum = 0;
            int i = 0, n = runningCosts.Length;
            for (int j = 0; j < n; j++)
            {
                sum += runningCosts[j];
                while (timesSorted.Count > 0 && chargeTimes[timesSorted.Last()] < chargeTimes[j])
                    timesSorted.RemoveLast();
                timesSorted.AddLast(j);

                if (chargeTimes[timesSorted.First()] + (j - i + 1) * sum > budget)
                {
                    if (timesSorted.First() == i)
                        timesSorted.RemoveFirst();
                    sum -= runningCosts[i++];
                }
            }
            return n - i;
        }

        public bool CheckDistances(string s, int[] distance)
        {
            int[] charIdx = new int[26];
            for (int i = 0; i < charIdx.Length; i++)
                charIdx[i] = -1;
            for (int i = 0; i < s.Length; i++)
            {
                if (charIdx[s[i] - 'a'] != 0)
                {
                    int prevIdx = charIdx[s[i] - 'a'];
                    int dis = i - prevIdx - 1;
                    Console.WriteLine($"dis {dis} & char {s[i]}");
                    if (distance[s[i] - 'a'] != dis)
                        return false;
                }
                else
                    charIdx[s[i] - 'a'] = i;
            }
            return true;
        }

        //2295
        public int[] ArrayChange(int[] nums, int[][] operations)
        {
            int[] index = new int[10000];
            for (int i = 0; i < nums.Length; i++)
                index[nums[i]] = i;

            for (int i = 0; i < operations.Length; i++)
            {
                int first = operations[i][0];
                int second = operations[i][1];

                nums[index[first]] = second;
                index[second] = index[first];
                index[first] = 0;
            }
            return nums;
        }

        // 2232
        public string MinimizeResult(string expression)
        {
            List<string> qr = new List<string>();
            while(true)
                    qr.Add(new string(' ', (int)Math.Pow(10, 6)));

            var str = expression.Split('+');
            int[] num1 = new int[str[0].Length];
            int[] num2 = new int[str[1].Length];
            int total_num1 = 0, total_num2 = 0;

            for (int i = 0; i < num1.Length; i++)
            {
                num1[i] = str[0][i] - '0';
                total_num1 = (total_num1 * 10) + num1[i];
            }

            for (int i = 0; i < num2.Length; i++)
            {
                num2[i] = str[1][i] - '0';
                total_num2 = (total_num2 * 10) + num2[i];
            }

            int prod_num1 = 1, prod_num2 = 1, add_num1 = total_num1, add_num2 = total_num2;
            int minVal = int.MaxValue, indx_i = 0, indx_j = 0;

            for (int i = 0; i < num1.Length; i++)
            {
                if (i > 0)
                {
                    if (i == 1) prod_num1 = 0;
                    prod_num1 = (prod_num1 * 10) + num1[i - 1];
                    add_num1 = add_num1 - (num1[i - 1] * (int)Math.Pow(10, (num1.Length - i)));
                }

                for (int j = 0; j < num2.Length; j++)
                {
                    if (j > 0)
                    {
                        if (j == 1)
                        {
                            add_num2 = 0;
                            prod_num2 = total_num2;
                        }
                        add_num2 = (add_num2 * 10) + num2[j - 1];
                        prod_num2 = prod_num2 - (num2[j - 1] * (int)Math.Pow(10, (num2.Length - j)));
                    }

                    long curVal = prod_num1 * (add_num1 + add_num2) * prod_num2;
                    if (curVal < minVal)
                    {
                        indx_i = i;
                        indx_j = j;
                        minVal = (int)curVal;
                    }
                }
                prod_num2 = 1;
                add_num2 = total_num2;
            }

            string ans = "";
            if (indx_j == 0)
                indx_j = expression.Length;
            else
                indx_j = indx_j + num1.Length + 1;

            ans = expression.Substring(0, indx_i) + "(" + 
                expression.Substring(indx_i, indx_j - indx_i) + ")" + expression.Substring(indx_j);

            return ans;
        }

        // 2270
        public int WaysToSplitArray(int[] nums)
        {
            long[] leftPrefix = new long[nums.Length];
            long[] rightPrefix = new long[nums.Length];

            for (int i = 0; i < nums.Length; i++)
                leftPrefix[i] = nums[i] + (i == 0 ? 0 : leftPrefix[i - 1]);

            for (int j = nums.Length - 1; j >= 0; j--)
                rightPrefix[j] = nums[j] + (j == nums.Length - 1 ? 0 : rightPrefix[j + 1]);

            int count = 0;
            for (int i = 0; i < nums.Length-1; i++)
            {
                if (leftPrefix[i] >= rightPrefix[i+1])
                    count++;
            }

            return count;
        }

        // 316  1081
        public string RemoveDuplicateLetters(string s)
        {
            string res = "";
            int[] lastIndex = new int[26];
            Stack<char> stk = new Stack<char>();
            int[] visited = new int[26];

            for (int i = 0; i < s.Length; i++)
                lastIndex[s[i] - 'a'] = i; 

            for (int i=0; i < s.Length; i++)
            {
                while (stk.Count > 0 
                    && stk.Peek() > s[i]
                    && visited[s[i] - 'a'] == 0
                    && lastIndex[stk.Peek() - 'a'] >= i)
                    visited[stk.Pop() - 'a'] = 0;

                if (visited[s[i] - 'a'] == 0)
                {
                    stk.Push(s[i]);
                    visited[s[i] - 'a'] = 1;
                }
            }

            while (stk.Count > 0)
                res += stk.Pop();

            return new string(res.Reverse().ToArray());
        }
    }
}
