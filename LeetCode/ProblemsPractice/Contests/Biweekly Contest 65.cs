using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class Biweekly_Contest_65
    {
        public bool CheckAlmostEquivalent(string word1, string word2)
        {
            int[] ara = new int[26];
            int[] ara2 = new int[26];

            foreach (char ch in word1)
                ara[ch - 'a']++;

            foreach (char ch in word2)
                ara2[ch - 'a']++;

            foreach (char ch in word1)
            {
                if (Math.Abs(ara[ch - 'a'] - ara2[ch - 'a']) > 3)
                    return false;
            }

            foreach (char ch in word2)
            {
                if (Math.Abs(ara[ch - 'a'] - ara2[ch - 'a']) > 3)
                    return false;
            }

            return true;
        }

        public int[] MaximumBeauty(int[][] items, int[] queries)
        {
            Array.Sort(items, (x,y) => x[0].CompareTo(y[0]));
            int[] querySort = (int[])queries.Clone();
            Array.Sort(querySort);
            Dictionary<int, int> ans = new Dictionary<int, int>();
            int j = 0, price = 0, beauty = 0, maxBeauty = 0;
            int[] ansAra = new int[queries.Length];

            foreach (var item in items)
            {
                price = item[0];
                beauty = item[1];

                while (j < querySort.Length && querySort[j] < price)
                {
                    if (!ans.ContainsKey(querySort[j]))
                        ans.Add(querySort[j++], maxBeauty);
                    ++j;
                }

                maxBeauty = Math.Max(beauty, maxBeauty);
            }

            for (int i = 0; i < queries.Length; i++)
            {
                if (!ans.ContainsKey(queries[i]))
                    ansAra[i] = maxBeauty;
                else
                    ansAra[i] = ans[queries[i]];
            }
            
            return ansAra;
        }
    }

    public class Robot
    {
        string direction;
        int curPosX, curPosY, width, height;

        public Robot(int width, int height)
        {
            direction = "East";
            
            
            
            curPosX = 0;
            curPosY = 0;
            this.width = width;
            this.height = height;
        }

        public void Move(int num)
        {
            int totalRound = (2 * (width - 1 + height - 1)) + 1;
            if (num > totalRound)
                num %= totalRound;

            if (num == 0 && curPosX == 0 && curPosY ==0)
                direction = "South";


            while (num != 0)
            {
                if (direction == "East")
                {
                    if (num <= width - 1 - curPosX)
                    {
                        curPosX += num;
                        num -= num;
                    }
                    else
                    {
                        int mov = width - 1 - curPosX;
                        curPosX += mov;
                        num -= mov;
                        direction = "North";
                    }
                }

                else if (direction == "North")
                {
                    if (num <= height - 1 - curPosY)
                    {
                        curPosY += num;
                        num -= num;
                    }
                    else
                    {
                        int mov = height - 1 - curPosY;
                        curPosY += mov;
                        num -= mov;
                        direction = "West";
                    }
                }

                else if (direction == "West")
                {
                    if (num <= curPosX)
                    {
                        curPosX -= num;
                        num -= num;
                    }
                    else
                    {
                        int mov = curPosX;
                        curPosX -= mov;
                        num -= mov;
                        direction = "South";
                    }
                }

                else if (direction == "South")
                {
                    if (num <= curPosY)
                    {
                        curPosY -= num;
                        num -= num;
                    }
                    else
                    {
                        int mov = curPosY;
                        curPosY -= mov;
                        num -= mov;
                        direction = "East";
                    }
                }

            }
            
        }

        public int[] GetPos()
        {
            int[] ans = new int[2];
            ans[0] = curPosX;
            ans[1] = curPosY;
            return ans;
        }

        public string GetDir()
        {
            return direction;
        }
    }
}
