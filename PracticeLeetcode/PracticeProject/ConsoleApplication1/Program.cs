using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }

    // 307
    public class NumArray
    {
        int[] preSums, nums;
        public NumArray(int[] nums)
        {
            this.nums = nums;
            preSums = new int[nums.Length];
            for (int i = 0; i < nums.Length; i++)
            {
                preSums[i] = nums[i] + (i == 0 ? 0 : preSums[i - 1]);
            }
        }

        public void Update(int index, int val)
        {
            int diff = val - nums[index];
            nums[index] = val;
            for (int i = index; i < preSums.Length; i++)
            {
                preSums[i] += diff;
            }
        }

        public int SumRange(int left, int right)
        {
            return preSums[right] - (left == 0 ? 0 : preSums[left - 1]);
        }
    }

    // 304
    public class NumMatrix
    {
        int[][] mat;
        public NumMatrix(int[][] matrix)
        {
            mat = new int[matrix.Length][];
            for (int i = 0; i < matrix.Length; i++)
            {
                for (int j = 0; j < matrix[0].Length; j++)
                {
                    if (j == 0)
                        mat[i] = new int[matrix[0].Length];
                    mat[i][j] = matrix[i][j]
                                + (j == 0 ? 0 : mat[i][j - 1])
                                + (i == 0 ? 0 : mat[i - 1][j])
                                - (i == 0 || j == 0 ? 0 : mat[i - 1][j - 1]);
                }
            }
        }

        public int SumRegion(int row1, int col1, int row2, int col2)
        {
            return mat[row2][col2]
                            + (row1 > 0 && col1 > 0 ? mat[row1 - 1][col1 - 1] : 0)
                            - (row1 == 0 ? 0 : mat[row1 - 1][col2])
                            - (col1 == 0 ? 0 : mat[row2][col1 - 1]);
        }
    }

    public class Program
    {
        public void AppendToLinkedList(int[] nums, ListNode head)
        {
            while (head.next != null)
            {
                head = head.next;
            }
            
            foreach (int val in nums)
            {
                head.next = new ListNode(val);
                head = head.next;
            }
        }

        public void PrintListNode(ListNode head)
        {
            while (head != null)
            {
                Console.Write(head.val + " -> ");
                head = head.next;
            }
            Console.WriteLine();
        }

        public void PrintPairValue(int[] ara)
        {
            for (int i = 0; i < ara.Length; i++)
            {
                Console.Write(ara[i]);

                if (i < ara.Length - 1)
                    Console.WriteLine(" , " + ara[++i]);
                
            }
        }

        public string MinRemoveToMakeValid(string s)
        {
            Stack<Tuple<char, int>> invalid = new Stack<Tuple<char, int>>();

            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == ')')
                {
                    if (invalid.Count > 0 && invalid.Peek().Item1 == '(')
                        invalid.Pop();
                    else
                        invalid.Push(Tuple.Create(s[i], i));
                }
                else if (s[i] == '(')
                    invalid.Push(Tuple.Create(s[i], i));
            }

            string ans = "";
            for (int i = s.Length-1; i >= 0; i--)
            {
                if (invalid.Count > 0 && i == invalid.Peek().Item2)
                {
                    invalid.Pop();
                }
                else
                    ans += s[i];
            }

            return new string(ans.Reverse().ToArray());
        }

        // 946
        public bool ValidateStackSequences(int[] pushed, int[] popped)
        {
            Stack<int> stk = new Stack<int>();

            for (int i = 0, j=0; i < pushed.Length; i++)
            {
                while(stk.Count > 0 && stk.Peek() == popped[j])
                {
                    stk.Pop();
                    j++;
                }
                
                stk.Push(pushed[i]);
            }

            return stk.Count == 0;
        }

       
        public static void Main(string[] args)
        {

            string j = "aA";
            string s = "LLLLRRRR";
            string a = null;
            int length = 5, middle = 0;
            middle = length / 2 + 1;
            //Nullable<long> check = (long?)a;
            //Console.WriteLine("check ");
            //Console.WriteLine(middle);


            var simpleArray = new int[]
            {
                4,-2,-3,4,1
            };
            var num2 = new int[]
            {
                5,18,13
            };

            var twoDimensionalJaggedArray = new int[][]
            {
                new int[] {5,8},
                new int[] {3,9},
                new int[] {5,12}
            };
            string str = "A well-organized paragraph supports or develops a single controlling idea, which is expressed in a sentence called the topic sentence. A topic sentence has several important functions: it substantiates or supports an essay’s thesis statement; it unifies the content of a paragraph and directs the order of the sentences; and it advises the reader of the subject to be discussed and how the paragraph will discuss it. Readers generally look to the first few sentences in a paragraph to determine the subject and perspective of the paragraph. That’s why it’s often best to put the topic sentence at the very beginning of the paragraph. In some cases, however, it’s more effective to place another sentence before the topic sentence—for example, a sentence linking the current paragraph to the previous one, or one providing background information.";
            string s2 = "c";

            var cls = new Program();


            var ans = cls.SubArrayRanges(simpleArray);

            

            ListNode list1 = new ListNode(1);
            

            /*ListNode list2 = new ListNode(1000000);
            //cls.SwapNodes(list1, 2);


            cls.PrintListNode(list1);
            var ans = cls.LongestBeautifulSubstring("aeaaeiou");
            //cls.PrintListNode(ans);
            Console.WriteLine(ans);*/
            Console.ReadKey();
        }

        public long SubArrayRanges(int[] nums)
        {
            if (nums == null || nums.Length == 0)
                return 0;

            long min = nums[0], max = nums[0], total = 0;
            for (int i = 0; i < nums.Length-1; i++)
            {
                min = nums[i];
                max = nums[i];
                for (int j = i+1; j < nums.Length; j++)
                {
                    min = Math.Min(min, nums[j]);
                    max = Math.Max(max, nums[j]);

                    total += (max - min);
                }
            }

            return total;
        }
      
          
          // This is the interface that allows for creating nested lists.
          // You should not implement it, or speculate about its implementation
          interface NestedInteger {
         
              // @return true if this NestedInteger holds a single integer, rather than a nested list.
              bool IsInteger();
         
              // @return the single integer that this NestedInteger holds, if it holds a single integer
              // Return null if this NestedInteger holds a nested list
              int GetInteger();
         
              // @return the nested list that this NestedInteger holds, if it holds a nested list
              // Return null if this NestedInteger holds a single integer
              IList<NestedInteger> GetList();
          }
 

        // 341
        /*public class NestedIterator
        {
            IList<NestedInteger> nestedList;
            IEnumerator<NestedInteger> it;
            Stack<IEnumerator<NestedInteger>> itStk;
            int cnt = 0;
            public NestedIterator(IList<NestedInteger> nestedList)
            {
                this.nestedList = nestedList;
                it = nestedList.GetEnumerator();
                itStk.Push(it);
            }

            public bool HasNext()
            {
                if (it.MoveNext())
                    return true;
                else
                {
                    itStk.Pop();
                    return false;
                }
            }

            public int Next()
            {
                it = itStk.Peek();
                while(!it.Current.IsInteger())
                {
                    it = it.Current.GetList().GetEnumerator();
                    itStk.Push(it);
                }
                if (it.Current.IsInteger())
                {
                    Console.WriteLine(elem.GetInteger());
                    return elem.GetInteger();
                }
                else
                {
                    while (!itStk.Peek().MoveNext())
                        itStk.Pop();
                    
                    if (itStk.Peek().Current.IsInteger())
                        return itStk.Peek().cu
                }
            }
        }*/

        //1047
        public string RemoveDuplicates(string s)
        {
            var stk = new Stack<char>();
            char[] chAra;

            for (int i = 0; i < s.Length; i++)
            {
                if (stk.Count > 0 && stk.Peek() == s[i])
                    stk.Pop();
                else
                    stk.Push(s[i]);
            }

            chAra = new char[stk.Count];

            for (int i = stk.Count - 1; i >= 0; i--)
                chAra[i] = stk.Pop();

            return new string(chAra);
        }

        //1839
        public int LongestBeautifulSubstring(string word)
        {
            string vowels = "aeiou";
            int j = 0, maxLen = 0, len = 0;

            for (int i = 0; i < word.Length; i++)
            {
                if (word[i] == vowels[j])
                {
                    while (i < word.Length && j < vowels.Length && word[i] == vowels[j])
                    {
                        len++;
                        i++;

                        if (j <= 3 && i < word.Length && word[i] == vowels[j + 1])
                            j++;
                    }
                    i--;
                }
                
                
                if (j == 4 && len > maxLen)
                    maxLen = len;

                j = 0;
                len = 0;
            }

            return maxLen;
        }

        //1413
        public int MinStartValue(int[] nums)
        {
            int minVal = 0, sum = nums[0];
            for (int i = 1; i < nums.Length; i++)
            {
                sum += nums[i];
                minVal = Math.Min(sum, minVal);
            }
            return minVal <= 0 ? Math.Abs(minVal) + 1 : minVal;
        }

        // 424
        public int CharacterReplacement(string s, int k)
        {
            int res = 0, maxf = 0;
            int[] count = new int[128];

            for (int i = 0; i < s.Length; i++)
            {
                maxf = Math.Max(maxf, ++count[s[i]]);

                if (res - maxf < k)
                    res++;
                else
                    --count[s[i - res]];
            }

            return res;
        }

        //2058
        public int[] NodesBetweenCriticalPoints(ListNode head)
        {
            int firstVal = -1, prevVal = 0, i = 0, a = 0, b = 0, c = 0, minDistance = Int32.MaxValue;
            for (ListNode cur = head; cur.next.next != null; cur = cur.next, i++)
            {
                a = cur.val; b = cur.next.val; c = cur.next.next.val;
                if ((a < b && b > c) || (a > b && b < c))
                {
                    if (firstVal == -1) 
                    {
                        firstVal = i;
                        prevVal = i;
                    }
                    else
                    {
                        minDistance = Math.Min(i - prevVal, minDistance);
                        prevVal = i;
                    }
                }
            }

            int[] ans = new int[2];

            if (firstVal == prevVal || minDistance == Int32.MaxValue)
            {
                ans[0] = -1;
                ans[1] = -1;
            }
            else
            {
                ans[0] = minDistance;
                ans[1] = prevVal - firstVal;
            }

            return ans;
        }

        // 0131
        public int MaxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen)
        {
            int firstSum = 0, secondSum = 0, firstIndx = 0;
            int dummy = 0;

            firstSum = sumSubArray(nums, 0, nums.Length, firstLen, out firstIndx);

            firstSum += Math.Max(sumSubArray(nums, 0, firstIndx, secondLen, out dummy), sumSubArray(nums, firstIndx + firstLen, nums.Length, secondLen, out dummy));


            firstIndx = 0;
            secondSum = sumSubArray(nums, 0, nums.Length, secondLen, out firstIndx);

            secondSum += Math.Max(sumSubArray(nums, 0, firstIndx, firstLen, out dummy), sumSubArray(nums, firstIndx + secondLen, nums.Length, firstLen, out dummy));

            return Math.Max(firstSum, secondSum);
        }

        // 8   20  6  2 20 17    6    3 20    8  12 
        // 8   28 34 36 56 73   79    82 102 110 122
        public int sumSubArray(int[] nums, int startIndex, int lastIndex, int k, out int firstIndex)
        {
            int sum = 0, maxSum = 0;
            firstIndex = 0;
            for (int i = startIndex; i < lastIndex; i++)
            {
                sum += nums[i];
                if (i - startIndex >= k - 1)
                {
                    sum -= ((i - startIndex) - k) < 0 ? 0 : nums[i - k];
                    if (sum > maxSum)
                    {
                        maxSum = sum;
                        firstIndex = i - k + 1;
                    }
                }
            }

            maxSum = maxSum == 0 ? sum : maxSum;

            return maxSum;
        }

        //209
        public int MinSubArrayLen(int target, int[] nums)
        {
            Array.Sort(nums);
            int sum = 0;

            for (int i = nums.Length-1; i >= 0; i-- )
            {
                sum += nums[i];
                if (sum >= target)
                    return nums.Length - i;
            }

            return 0;
        }

        // 817
        public int NumComponents(ListNode head, int[] nums)
        {
            HashSet<int> g = new HashSet<int>();
            int cnt = 0;

            for (int i = 0; i < nums.Length; i++)
                g.Add(nums[i]);

            for (var cur = head; cur != null; cur = cur.next)
            {
                if (g.Contains(cur.val))
                {
                    cnt++;
                    while (cur != null && g.Contains(cur.val))
                        cur = cur.next;
                }

                if (cur == null)
                    break;
            }

            return cnt;
        }

        // 1721
        public ListNode SwapNodes(ListNode head, int k)
        {
            ListNode slow = head, fast = head, prevfirst = null;

            

            while (slow.next != null)
            {
                if (prevfirst == null || fast.next == null || fast.next.next == null)
                    --k;
                else
                    k++;


                if (prevfirst == null && k == 1)
                    prevfirst = slow;
                else if (k == 1)
                {
                    if (fast.next != null)
                        slow = slow.next;
                    break;
                }

                slow = slow.next;

                if (fast.next != null && fast.next.next != null)
                    fast = fast.next.next;
            }

            ListNode temp1 = slow.next, temp2 = prevfirst.next;
            slow.next = slow.next.next;
            temp1.next = prevfirst.next.next;
            prevfirst.next = temp1;

            temp2.next = slow.next;
            slow.next = temp2;

            return head;
        }

        // 1669
        public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2)
        {
            /*ListNode cur = list1, prevStart = null, postEnd = null;

            while (b >= 0)
            {
                if (--a == 0)
                    prevStart = cur;
                if (b-- == 0)
                    postEnd = cur.next;
                cur = cur.next;

            }

            cur = prevStart;
            prevStart.next = list2;
            while (cur.next != null)
            {
                cur = cur.next;
            }
            cur.next = postEnd;

            return list1;*/

            ListNode cur = list1, prevStart = null, postEnd = null;

            while (cur.next != null)
            {
                if (--a == 0)
                    prevStart = cur;
                if (b-- == 0)
                {
                    postEnd = cur.next;
                    cur = prevStart;
                    prevStart.next = list2;
                }
                cur = cur.next;

            }
            cur.next = postEnd;
            return list1;
                
        }

        // 203
        public ListNode RemoveElements(ListNode head, int val)
        {
            ListNode cur = head;

            while (cur != null)
            {
                if (cur.val == val)
                {
                    head = head.next;
                    cur = cur.next;
                }

                else if (cur.next != null && cur.next.val == val)
                    cur.next = cur.next.next;

                else
                    cur = cur.next;
            }

            return head;
        }

        // 141
        public bool HasCycle(ListNode head)
        {
            ListNode fast = head, slow = head;

            while (fast != null && fast.next != null && fast.next.next != null)
            {
                slow = slow.next;
                fast = fast.next.next;
                if (slow == fast)
                    return true;
            }
            return false;
        }

        public bool IsPalindrome(ListNode head)
        {
            ListNode Middle = head, fast = head, slow = head;
            
            while (fast.next != null && fast != null)
            {
                slow = slow.next;
                fast = fast.next.next;
                Middle = slow;
            }
            


            ListNode temp = Middle, startMiddle = Middle.next, first = Middle.next, second = Middle.next.next;

            while (second != null)
            {
                first.next = second.next;
                second.next = startMiddle;
                startMiddle = second;
                second = first.next;
            }

            head = startMiddle;


            return true;
        }

        // 21
        public ListNode MergeTwoLists(ListNode l1, ListNode l2)
        {
            ListNode head;
            ListNode curNode;

            if (l1.val < l2.val)
            {
                head = l1;
                l1 = l1.next;
            }
            else
            {
                head = l2;
                l2 = l2.next;
            }
            curNode = head;
            curNode = curNode.next;

            while (l1.next == null && l2.next == null)
            {
                if (l1.val < l2.val)
                {
                    curNode = l1;
                    curNode = curNode.next;
                    l1 = l1.next;
                }
                else
                {
                    curNode = l2;
                    curNode = curNode.next;
                    l2 = l2.next;
                }
            }

            return head;
        }

        public void insertAfter(ListNode prevNode, ListNode newNode)
        {
            newNode.next = prevNode.next;
            prevNode.next = newNode;
        }

        public ListNode MiddleValueLinkedList(ListNode head)
        {
            int length = 0, middle = 0;

            var currentNode = head;
            while (currentNode != null)
            {
                length++;
                currentNode = currentNode.next;
            }

            middle = length / 2 + 1;
            currentNode = head;
            while (middle > 1)
            {
                currentNode = currentNode.next;
                middle--;
            }

            return currentNode;
        }

        public double FindMaxAverage(int[] nums, int k)
        {
            // 643
            double maxAvg = 0;
            int initialSum = 0;

            for (int i = 0; i < k; i++ )
            {
                initialSum += nums[i];
            }

            maxAvg = (double)(initialSum / k);
            for (int i = k; i < nums.Length; i++ )
            {
                initialSum += nums[i] - nums[i - k];
                maxAvg = Math.Max((double)(initialSum/k), maxAvg);
            }

            return maxAvg;
        }

        public IList<string> FindAndReplacePattern(string[] words, string pattern)
        {
            IList<string> MatchingWords = new List<string>();
            IDictionary<char, char> CharMapper = new Dictionary<char, char>();
            HashSet<char> WordTracker = new HashSet<char>();

            foreach (string word in words)
            {
                for (int i = 0; i < pattern.Length; i++)
                {
                    if (!CharMapper.ContainsKey(pattern[i]) && !WordTracker.Contains(word[i])){
                        CharMapper.Add(pattern[i], word[i]);
                        WordTracker.Add(word[i]);
                    }

                    else if (CharMapper[pattern[i]] != word[i])
                        break;

                    if (i == pattern.Length - 1)
                        MatchingWords.Add(word);
                }
                CharMapper.Clear();
            }

            return MatchingWords;
        }

        public static int SumOfBeauties(int[] nums)
        {
            int score = 0;
            for (int i = 1; i < nums.Length - 1; i++ )
            {
                if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                    score++;
            }
            if (score > 0 && score == nums.Length - 2)
                score *= 2;
            return score;
        }

        public static string WrapText(string text, int maxLength)
        {
            int len = text.Length, spaceIndx = 0, indx = 0, charIncrement = 0, count = maxLength-1;
            char[] Output = new char[len + len/maxLength + maxLength];

            for (int i = 0; i < len; i++, count-- )
            {
                if (text[i] == ' ')
                    spaceIndx = i;

                if (count <= 0)
                {
                    indx = spaceIndx + charIncrement++;
                    i = spaceIndx + 1;

                    Output[indx++] = '\r';
                    Output[indx++] = '\n';
                    count = maxLength - 1;
                }
                Output[indx++] = text[i];
            }

            return new string(Output);
        }

        public int ReverseInteger(int number)
        {
            if (number < 10)
                return number;

            int decimalPlace = 1, reverseNumber = 0;

            while (number > 0){
                reverseNumber *= decimalPlace;
                reverseNumber += (number % 10);
                number /= 10;
                decimalPlace = 10;
            }

            return reverseNumber;
        }

        public int LargestSumAfterKNegations(int[] nums, int k)
        {
            int sum = 0;
            Array.Sort(nums);
            for (int i = 0; i < nums.Length; i++ )
            {
                if (k > 0 && nums[i] < 0)
                {
                    k--;
                    nums[i] = -nums[i];
                }
                else if (nums[i] == 0)
                {
                    k = 0;
                    break;
                }
                else
                    break;
            }

            if (k > 0 && k%2==1){
                int minValue = nums.Min();
                int minIndx = Array.IndexOf(nums ,minValue);
                nums[minIndx] = -minValue;
                k = 0;
            }
            foreach (var item in nums)
                sum += item;

            return sum;
        }

        public int LargestPerimeter(int[] nums)
        {
            Array.Sort(nums);
            Array.Reverse(nums);

            foreach (var item in nums)
            {
                Console.WriteLine(item);
            }
            
            for (int i = 0; i < nums.Length - 2; i++ )
            {
                if (nums[i] + nums[i+1] > nums[i+2] && 
                    nums[i+2] + nums[i+1] > nums[i] &&
                    nums[i] + nums[i + 2] > nums[i + 1])
                {
                    return nums[i] + nums[i + 1] + nums[i+2];
                }
            }
            return 0;
        }

        public static bool CanPlaceFlowers(int[] flowerbed, int n)
        {
            int emptyPlot = 1;
            int canPlant = 0;
            foreach (var plot in flowerbed)
            {
                if (plot == 0)
                    emptyPlot++;

                else
                    emptyPlot = 0;

                if (emptyPlot == 3)
                {
                    canPlant++;
                    emptyPlot = 1;
                }
            }

            if (emptyPlot == 2)
                canPlant++;

            if (canPlant >= n)
                return true;

            return false;
        }

        public static bool CheckIfExist(int[] arr)
        {
            HashSet<int> nums = new HashSet<int>();
            bool hasDoubleZero = false;
            foreach (var item in arr)
            {
                if (item == 0 ){
                    if (hasDoubleZero)
                        return true;
                    hasDoubleZero = true;
                }
                else
                    nums.Add(item * 2);
            }

            foreach (var item in arr)
            {
                if (nums.Contains(item))
                {
                    return true;
                }
            }

            return false;
        }
    }
}
