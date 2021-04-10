using System;
using System.Collections.Generic;
using System.Linq;

namespace HackerearthCodemonk
{
    public class Program
    {
        static void Main(string[] args)
        {
            int test_case = Int32.Parse(Console.ReadLine());

            while (test_case-- != 0)
            {
                string[] inp_str = Console.ReadLine().Split(" ");
                int len = Convert.ToInt32(inp_str[0]);
                int rotate = Convert.ToInt32(inp_str[1]) % len;

                int[] arr = Console.ReadLine().Split(" ").Select(x => Convert.ToInt32(x)).ToArray();

                IList<int> AnsList = new List<int>();



                int endIndex = arr.Length;
                int startIndex = endIndex - rotate;

                for (int i = startIndex; i < endIndex; i++)
                {
                    AnsList.Add(arr[i]);
                    if (i == arr.Length - 1)
                    {
                        i = -1;
                        endIndex = startIndex;
                    }
                }

                foreach (var item in AnsList)
                {
                    Console.Write(item + " ");
                }
                Console.WriteLine();
            }
        }
    }
}
