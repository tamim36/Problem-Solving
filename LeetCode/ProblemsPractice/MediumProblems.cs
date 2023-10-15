using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice
{
    public class MediumProblems
    {
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
