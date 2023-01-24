using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Recursion
{
    public class BasicRecursion
    {
        public int FindFactorial(int num)
        {
            if (num <= 1)
                return 1;
            return num * FindFactorial(num - 1);
        }

        // 0 1 1 2 3 5 8 13 21
        public int Fibonacci(int index)
        {
            int num1 = 0, num2 = 1;
            return FibonacciRecursive(num1, num2, index);
        }

        public int FibonacciIterative(int num1, int num2, int index)
        {
            int val = 0;
            for (int i = 1; i < index; i++)
            {
                val = num1 + num2;
                num1 = num2;
                num2 = val;
            }
            return val;
        }

        int result = 0;
        private int FibonacciRecursive(int num1, int num2, int index)
        {
            if (index == 1)
                return num1 + num2;

            return FibonacciRecursive(num2, num1+num2, --index);
        }

        public int fib(int n)
        {
            if (n <= 2)
                return 1;
            return fib(n - 1) + fib(n-2);
        }
    }
}
