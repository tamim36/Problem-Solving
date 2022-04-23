using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Queue
{
    // 973
    public class K_Closest_Points_to_Origin
    {
        public int[][] KClosest(int[][] points, int k)
        {
            SortedDictionary<double, List<int>> distances = new SortedDictionary<double, List<int>>();

            for (int i = 0; i < points.Length; i++)
            {
                int x = points[i][0], y = points[i][1];
                double dis = Math.Sqrt((x * x) + (y * y));

                if (distances.ContainsKey(dis))
                    distances[dis].Add(i);
                else
                    distances.Add(dis, new List<int>() { i});
            }

            int[][] res = new int[k][];
            int idx = 0;
            foreach (var distance in distances)
            {
                foreach (var indexList in distance.Value)
                {
                    if (idx >= k)
                        break;

                    int x = points[indexList][0], y = points[indexList][1];
                    res[idx++] = new int[] { x, y };
                }
            }

            return res;
        }
    }
}
