using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class Weekly_Contest_263
    {
        public bool AreNumbersAscending(string s)
        {
            int num = 0, prevNum = -1;

            for (int i=0; i<s.Length; i++)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    num *= 10;
                    num += s[i] - '0';
                }
                if ((s[i] == ' ' || i == s.Length - 1) && num > 0)
                {
                    if (num > prevNum)
                    {
                        prevNum = num;
                        num = 0;
                    }
                    else
                        return false;
                }
            }
            return true;
        }
    }

    public class Bank
    {
        private long[] balance;
        private int n = 0;
        public Bank(long[] balance)
        {
            this.balance = balance;
            this.n = balance.Length;
        }

        public bool Transfer(int account1, int account2, long money)
        {
            if (account1 > n || account2 > n)
                return false;

            if (Withdraw(account1, money) && Deposit(account2, money))
                return true;
            else
                return false;
        }

        public bool Deposit(int account, long money)
        {
            if (account > n)
                return false;

            balance[account - 1] += money;
            return true;
        }

        public bool Withdraw(int account, long money)
        {
            if (account > n)
                return false;

            if (balance[account - 1] >= money)
            {
                balance[account - 1] -= money;
                return true;
            }
            else
                return false;
        }
    }
}
