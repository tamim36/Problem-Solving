using ProblemsPractice.Arrays;
using ProblemsPractice.Contests;
using ProblemsPractice.EasyProblems;
using ProblemsPractice.Greedy;
using ProblemsPractice.MasterCodingInterviewUdemy;
using ProblemsPractice.TwoPointer;
using ProblemsPractice.SlidingWindow;
using System;
using System.Collections;
using System.Linq;
using ProblemsPractice.LinkedList;
using ProblemsPractice.Stack;
using ProblemsPractice.PrefixSum;
using ProblemsPractice.Queue;
using System.Reflection;
using ProblemsPractice.BST;
using ProblemsPractice.Recursion;
using ProblemsPractice.Sorting;
using ProblemsPractice.Design;
using System.Collections.Generic;

namespace ProblemsPractice
{
    class Program
    {
        static void Main(string[] args)
        {
            string j = "aA";
            string s = "bb";

            var num1 = new int[]
            {
                8,5,1,7,10,12
            };

            var stAr = new string[]
            {
                "623986800","62398680","3","887298","695","794","6888794705","269409","59930972","723091307","726368","8028385786","378585"
            };

            var num2 = new int[]
            {
               789,456,123
            };

            var twoDimensionalJaggedArray = new int[][]
            {
                new int[] {7,1,4,5,6},
                new int[] { 2, 5, 1, 6, 4 },
                new int[] { 1, 5, 4, 3, 2 },
                new int[] { 1, 2, 7, 3, 4 }
            };
            string str = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";
            string s2 = "p#######";
            var strAra = new string[] { "flower", "flow", "floight" };

            // Linked List
            var head = new ListNode(0);
            MyLinkedList.AppendToLinkedList(num1, head);
            //MyLinkedList.PrintListNode(head);

            var head2 = new ListNode(5);
            MyLinkedList.AppendToLinkedList(num2, head2);
            //MyLinkedList.PrintListNode(head2);

            string test = @" ! , . 62   nvtk0wr4f  8 qt3r! w1ph 1l ,e0d 0n 2v 7c.n06huu2n9 s9   ui4 nsr!d7olr -q, 8-8 8,-a b-1 b-a  q-, vqdo!btpmtmui.bb83lf g .!v9 - lg 2fyoykex uy5a 8v whvu8 .y sc5 -0n4 zo pfgju 5u 4 3x,3!wl fv4   s aig cf j1 a i  8m5o1!u n!.1tz87d3 .9    n a3  .xb1p9f b1i a j8s2 cugf l494cx1!hisceovf3 8d93 sg 4r.f1z9w   4 - cb r97jo hln3s h2 o .  8dx08as7l!mcmc isa49afk i1 fk, s e!1 ln rt2vhu 4ks4zq c w o-6  5!.n8ten0 6mk 2k2y3e335,yj h p3 5 - 0  5g1c tr49, , qp9 -v p  7p4v110926wwr h x wklq u zo 16. !8  u63n0c l3 yckifu 1cgz t.i lh w xa l,jt hpi ng - gvtk8 9 j u9qfcd!2  kyu42v dmv.cst6i5fo rxhw4wvp2 1 okc8!  z aribcam0  cp - zp,!e x agj-gb3!om3934 k vnuo056h g7 t - 6j! 8w8fncebuj - lq    inzqhw v39, f e 9. 50 , ru3r mbuab  6  wz dw79.av2xp.gbmy gc s6pi pra4fo9fwq k j-ppy - 3vpf o k4hy3 - !..5s ,2 k5 j p38dtd!i b!fgj,nx qgif ";

            String s5= "212333";
            String answer = "";
            
            var cls = new TreeTraversal();


            //var a = cls.LargestMagicSquare(twoDimensionalJaggedArray);
            //Console.WriteLine(a);
            //MyLinkedList.PrintListNode(a);
            //Console.WriteLine(a);
            /*
            BinarySearchTree bst = new BinarySearchTree();
            bst.Insert(9);
            bst.Insert(4);
            bst.Insert(6);
            bst.Insert(20);
            bst.Insert(170);
            bst.Insert(15);
            bst.Insert(1);
            bst.LookUp(15);
            bst.print2DUtil(bst.Root, 0);
            bst.Remove(20);
            bst.print2DUtil(bst.Root, 0);*/

            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);

            root.left.right = new TreeNode(5);
            root.right.right = new TreeNode(4);

            /*
            root.left.right.left = new TreeNode(5);
            root.left.right.left.left = new TreeNode(4);
            root.left.right.right = new TreeNode(7);
            root.right.right.left = new TreeNode(13);*/
            /*
            var nT = new TreeNode(1);
            nT.left = new TreeNode(11);
            nT.right = new TreeNode(3);
            nT.left.left = new TreeNode(41);
            nT.left.right = new TreeNode(2);
            nT.left.right.left = new TreeNode(7);
            nT.left.right.right = new TreeNode(4);*/
            IList<(int, int)> sortedList = new List<(int, int)> ();
            sortedList.Add((10, 20));
            sortedList.Add((22, 30));
            sortedList.Add((30, 32));
            MyCalendar mc = new MyCalendar(sortedList);
            var ans = mc.Book(5, 10);

            //var scls = new MediumBSTProblems();

            //var a = scls.LcaDeepestLeaves(nT);
            
            //DesignProblemsCalling(new string[0], new int[0]);
        }

        static void DesignProblemsCalling(string[] Methods, int[] Params)
        {
            string Path = @"D:\WorkStation\Problem-Solving\LeetCode\ProblemsPractice\bin\Debug\netcoreapp3.1\ProblemsPractice.dll";

            Assembly assembly = Assembly.LoadFrom(Path);
            Type type = assembly.GetTypes().Where(x => x.Name == "MyCircularDeque").FirstOrDefault();

            var clsParams = new object[] {3};
            var cls = Activator.CreateInstance(type, clsParams);

            var mParam = new object[] {1};
            string methodName = "insertLast";
            methodName = string.Concat(methodName[0].ToString().ToUpper(), methodName.AsSpan(1));
            var method = type.GetMethod(methodName);
            var res = method.Invoke(cls, mParam);

        }
    }
}
