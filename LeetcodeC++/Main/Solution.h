#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// leetcode.com/rewind/?ref=tamimarefinanik
// https://leetcode.com/rewind/2023/?source=discuss
/*
            2, 6, 8, 3, 4, 5, 1

sub	        1   3   4   5
subindx     1   6   7   4   5
trace       -1   0   1   0   3   4 -1  6*/

// https://leetcode.com/problems/permutations/discuss/1257633/Backtracking-Solution-oror-C%2B%2B-oror-Easy-To-Understand-oror-With-explanation
// https://leetcode.com/tag/backtracking/discuss/3055778/How-to-calculate-runtime-of-backtracking-algorithm-in-interview




#pragma region Bit Manipulation

int count_setBits(int n) {
    int count = 0;

    while (n) {
        count += n & 1;
        n >>= 1;
    }

    return count;
}

int count_setBits_ByFlipping(int n) {
    int count = 0;
    while (n) {
        n = n & n - 1;
        count++;
    }

    return count;
}

// 1178
/* sub   sub - 1    mask
10110   10101       10110 //(sub-1)&mask = 10100, which shows in next row
10100   10011       10110 //same...
10010   10001       10110
10000   01111       10110
00110   00101       10110
00100   00011       10110
00010   00001       10110
00000
*/
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    unordered_map<int, int> mp;
    vector<int> ans;
    
    for (auto word : words) {
        int mask = 0;
        for (auto ch : word)
            mask |= (1 << (ch - 'a'));

        mp[mask]++;
    }

    for (auto puzzle : puzzles) {
        int mask = 0;
        for (auto ch : puzzle)
            mask |= (1 << (ch - 'a'));

        int submask = mask, count = 0;
        int first = (1 << (puzzle[0] - 'a'));
        while (submask) {
            if (first & submask)
                count += mp[submask];

            submask = (submask - 1) & mask;
        }

        ans.push_back(count);
    }

    return ans;
}

// 1734
// a0 = e0 ^ a1
// a0 = tot_a ^ a1 ^ a2 ^ a3 ^ a4
// a0 = tot_a ^ e1 ^ e3
vector<int> decode(vector<int>& encoded) {
    int sz = encoded.size();
    vector<int> ans(sz + 1);
    if (sz < 2)
        return ans;

    int tot_xor_a = 0;

    for (int i = 0; i < sz; i++) {
        tot_xor_a ^= i + 1;
        if (i % 2)
            tot_xor_a ^= encoded[i];
    }

    int ini_val = tot_xor_a ^ (sz + 1);
    ans[0] = ini_val;

    for (int i = 1; i < sz + 1; i++) {
        ans[i] = ans[i - 1] ^ encoded[i - 1];
    }

    return ans;
}

// 260
vector<int> singleNumberIII(vector<int>& nums) {
    int xor_two_num = 0;
    for (int i = 0; i < nums.size(); i++) {
        xor_two_num ^= nums[i];
    }

    int right_bit = 1;
    while (xor_two_num) {
        if (xor_two_num & 1)
            break;

        xor_two_num >>= 1;
        right_bit <<= 1;
    }

    int a = 0, b = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (right_bit & nums[i])
            a ^= nums[i];
        else
            b ^= nums[i];
    }

    return { a, b };
}

#pragma endregion

#pragma region Dynamic Programming (DP)

// Dynamic Programming

// 322
int coinChangeTopDown(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (j - coins[i - 1] >= 0 && dp[i][j - coins[i - 1]] != INT_MAX)
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
}

int coinChangeBottomUp(vector<int>& coins, int idx, int amount, vector<vector<int>>& dp) {
    if (amount == 0)
        return 0;
    if (idx <= 0)
        return INT_MAX;
    if (dp[idx][amount] != INT_MAX)
        return dp[idx][amount];

    if (amount - coins[idx - 1] >= 0) {
        int withVal = coinChangeBottomUp(coins, idx, amount - coins[idx - 1], dp);
        withVal = withVal == INT_MAX ? INT_MAX : withVal + 1;
        int withoutVal = coinChangeBottomUp(coins, idx - 1, amount, dp);
        return dp[idx][amount] = min(withVal, withoutVal);
    }
    else
        return dp[idx][amount] = coinChangeBottomUp(coins, idx - 1, amount, dp);

}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
    int ans = coinChangeBottomUp(coins, n, amount, dp);
    return ans == INT_MAX ? -1 : ans;
}

// Coin Change (Count Ways)
long long int countCoinChangeTopDown(vector<int>& v, int n, int sum) {
    vector<vector<long long int>> dp(n + 1, vector<long long int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (v[i] <= j)
                dp[i][j] = dp[i][j - v[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

long long int countCoinChangeRecursion(vector<int>& v, int n, int sum) {
    if (sum == 0)
        return 1;
    if (n <= 0)
        return 0;

    if (sum - v[n - 1] >= 0)
        return countCoinChangeRecursion(v, n, sum - v[n - 1])
        + countCoinChangeRecursion(v, n - 1, sum);
    else
        return countCoinChangeRecursion(v, n - 1, sum);
}

long long int countCoinChangeBottomUp(vector<int>& v, int n, int sum, vector<vector<long long int>>& dp) {
    if (sum == 0)
        return 1;
    if (n <= 0)
        return 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (sum - v[n - 1] >= 0)
        dp[n][sum] = countCoinChangeBottomUp(v, n, sum - v[n - 1], dp)
        + countCoinChangeBottomUp(v, n - 1, sum, dp);
    else
        dp[n][sum] = countCoinChangeBottomUp(v, n - 1, sum, dp);
    
    return dp[n][sum];
}

long long int countCoinChange(int coins[], int N, int sum) {
    vector<int> vec(coins, coins + N);
    vector<vector<long long int>> dp(N + 1, vector<long long int>(sum + 1, -1));

    return countCoinChangeBottomUp(vec, N, sum, dp);
}

// 0/1 knapsack
int knapSackRecursion(int W, int n, vector<int>& wt, vector<int>& val) {
    if (n <= 0)
        return 0;

    if (wt[n - 1] <= W)
        return max(val[n - 1] + knapSackRecursion(W - wt[n - 1], n - 1, wt, val),
            knapSackRecursion(W, n - 1, wt, val));
    else
        return knapSackRecursion(W, n - 1, wt, val);
}

int knapSack(int W, vector<int>& wt, vector<int>& val) {
    return knapSackRecursion(W, wt.size(), wt, val);
}

// https://www.geeksforgeeks.org/problems/rod-cutting0840/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// rod cutting - unbound knapsack
int cutRodRecursion(vector<int>& p, int n, int len) {
    if (n <= 0)
        return 0;
    if (n <= len)
        return max(p[n - 1] + cutRodRecursion(p, n, len - n), cutRodRecursion(p, n - 1, len));
    else
        return cutRodRecursion(p, n - 1, len);
}

int cutRodDp(vector<int>& p, int n, int len, vector<vector<int>>& dp) {
    if (n <= 0)
        return 0;
    if (dp[n][len] != -1)
        return dp[n][len];

    if (n <= len)
        dp[n][len] = max(p[n - 1] + cutRodDp(p, n, len - n, dp), cutRodDp(p, n - 1, len, dp));
    else
        dp[n][len] = cutRodDp(p, n - 1, len, dp);
    return dp[n][len];
}
// TODO: need to find issue
int cutRodTopDown(vector<int>& p, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int len = n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= len; j++) {
            if (j - i >= 0)
                dp[i][j] = max(p[i - 1] + dp[i][j - i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][len];
}

int cutRod(int price[], int n) {
    vector<int> p(price, price + n);

    return cutRodTopDown(p, n);
}

// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/0
int countPartitions_TopDown(int n, int target, vector<int>& arr) {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            if (j - arr[i - 1] >= 0) 
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][target];
}

int countPartitions(int n, int d, vector<int>& arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    if ((total + d) % 2)
        return 0;
    int target = (total + d) / 2;

    return countPartitions_TopDown(n, target, arr);
}
 
// https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
int GetSubset_minDifference(vector<int>& vec, int sum, int n) {
    int target = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j - vec[i - 1] >= 0)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - vec[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int validHalfSum = 0;
    for (int i = 0; i <= target; i++)
        if (dp[n][i]) validHalfSum = i;

    int ans = sum - 2 * validHalfSum;
    return ans;
}

int minDifference(int arr[], int n) {
    vector<int> vec(arr, arr + n);
    int sum = accumulate(vec.begin(), vec.end(), 0);
    return GetSubset_minDifference(vec, sum, n);
}

// 494

int findTargetSumWays_TopDown(vector<int>& nums, int target) {
    if (target < 0) target *= (-1);
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if ((target + sum) % 2)
        return 0;

    int t = (target + sum) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, -1));

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < t; j++) {
            if (j - nums[i - 1] >= 0)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][t];
}

int findTargetSumWays(vector<int>& nums, int target, int curSum, int n) {
    if (target == curSum && n == 0) 
        return 1;
    if (n <= 0)
        return 0;

    return findTargetSumWays(nums, target, curSum - nums[n - 1], n - 1)
        + findTargetSumWays(nums, target, curSum + nums[n - 1], n - 1);
}

int findTargetSumWays(vector<int>& nums, int target) {
    return findTargetSumWays(nums, target, 0, nums.size());
}
// Count Subset of Given Sum
int CountSubsetsGivenSum_Recursion(vector<int>& nums, int sum, int n) {
    if (sum == 0)
        return 1;
    if (n <= 0 || sum < 0)
        return 0;

    return CountSubsetsGivenSum_Recursion(nums, sum, n - 1)
        + CountSubsetsGivenSum_Recursion(nums, sum - nums[n - 1], n - 1);
}

int CountSubsetsGivenSum_DP(vector<int>& nums, int sum, int n, vector<vector<int>>& dp) {
    if (sum == 0)
        return 1;
    if (n <= 0 || sum < 0)
        return 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (sum - nums[n - 1] >= 0)
        dp[n][sum] = CountSubsetsGivenSum_Recursion(nums, sum, n - 1)
        + CountSubsetsGivenSum_Recursion(nums, sum - nums[n - 1], n - 1);
    else
        dp[n][sum] = CountSubsetsGivenSum_Recursion(nums, sum, n - 1);

    return dp[n][sum];
}

int CountSubsetsGivenSum_Recursion(vector<int>& nums, int sum) {
    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
    return CountSubsetsGivenSum_DP(nums, sum, nums.size(), dp);
}

int CountSubsetsGivenSum_TopDown(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (j - nums[i - 1] >= 0)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < sum + 1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][sum];
}


// https://leetcode.com/problems/partition-equal-subset-sum/
// Equal Sum Partition
bool canPartition(vector<int>& nums, int curSum, int targetSum, int n, vector<vector<int>>& dp) {
    if (curSum == targetSum)
        return true;
    if (n <= 0 || targetSum < curSum)
        return false;
    if (dp[n][curSum] != -1)
        return dp[n][curSum];

    dp[n][curSum] = canPartition(nums, curSum + nums[n - 1], targetSum, n - 1, dp)
        || canPartition(nums, curSum, targetSum, n - 1, dp);

    return dp[n][curSum];
}

bool canPartition_TopDown(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
        return false;
    int n = nums.size();
    int targetSum = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));
    

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < targetSum + 1; j++) {
            if (j - nums[i - 1] >= 0)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][targetSum];
}


bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
        return false;
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>((sum / 2) + 1, -1));
    return canPartition(nums, 0, sum / 2, n, dp);
}

// 
// Subset Sum problem
// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

bool subSetSum_Recursion(int sum, int n, vector<int>& nums, vector<vector<int>>& dp) {
    if (sum == 0)
        return true;
    if (sum < 0)
        return false;
    if (n < 1)
        return false;
    if (dp[n][sum] != -1)
        return dp[n][sum];

    dp[n][sum] = subSetSum_Recursion(sum - nums[n - 1], n - 1, nums, dp)
        || subSetSum_Recursion(sum, n - 1, nums, dp);

    return dp[n][sum];
}

bool subSetSum_TopDown(int sum, vector<int>& nums) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j - nums[i - 1] == 0)
                dp[i][j] = true;
            else if (j >= nums[i - 1])
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

bool subSetSum(int sum, vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return subSetSum_TopDown(sum, nums);
}

// 
// Knapsack
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

int knapSack_recursion(int W, vector<int>& wt, vector<int>& val, int n) {
    if (n <= 0 || W <= 0)
        return 0;

    if (wt[n - 1] <= W) {
        return max(val[n - 1] + knapSack_recursion(W - wt[n - 1], wt, val, n - 1),
            knapSack_recursion(W, wt, val, n - 1));
    }
    else {
        return knapSack_recursion(W, wt, val, n - 1);
    }
}

int knapSack_dp(int W, vector<int>& wt, vector<int>& val, int n, vector<vector<int>>& dp) {
    if (W <= 0 || n <= 0)
        return 0;

    if (dp[n][W] != -1) {
        return dp[n][W];
    }

    if (wt[n - 1] <= W) {
        return dp[n][W] = max(val[n - 1] + knapSack_dp(W - wt[n - 1], wt, val, n - 1, dp),
            knapSack_dp(W, wt, val, n - 1, dp));
    }
    else {
        return dp[n][W] = knapSack_dp(W, wt, val, n - 1, dp);
    }
}

int knapSack_TopDown(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}

int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    int res = knapSack_TopDown(W, wt, val, n);
    return res;
}

// 64
int dp_minPathSum(vector<vector<int>>& grid, int row, int col, int i, int j, vector<vector<int>>& dp) {
    if (i >= row || j >= col || i < 0 || j < 0)
        return INT_MAX;

    if (i == 0 && j == 0)
        return grid[i][j];

    if (dp[i][j] != 0)
        return dp[i][j];

    dp[i][j] = grid[i][j] + min(dp_minPathSum(grid, row, col, i - 1, j, dp),
        dp_minPathSum(grid, row, col, i, j - 1, dp));
    return dp[i][j];
}

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));

    int val = dp_minPathSum(grid, row, col, row - 1, col - 1, dp);
    return dp[row - 1][col - 1];
}

// 746
int dp_X[1002];

int recur_minCostClimbingStairs(vector<int>& cost, int idx) {
    if (idx < 0)
        return 0;

    if (dp_X[idx] != -1)
        return dp_X[idx];

    cout << idx << endl;
    dp_X[idx] = cost[idx] + min(recur_minCostClimbingStairs(cost, idx - 1),
        recur_minCostClimbingStairs(cost, idx - 2));

    return dp_X[idx];
}

int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    int n = cost.size();
    memset(dp_X, -1, sizeof(dp_X));

    return recur_minCostClimbingStairs(cost, n - 1);
}

#pragma endregion

#pragma region Leetcode Contest

// Weekly Contest 419
int dfs_khLargestPerfectSubtree(TreeNode* root, vector<int>& values) {
    if (!root)
        return 0;

    int right = dfs_khLargestPerfectSubtree(root->right, values);
    int left = dfs_khLargestPerfectSubtree(root->left, values);

    int count_nodes = 0;
    if (right == left) {
        count_nodes = (left + right) + 1;
        values.push_back(count_nodes);
    }

    return count_nodes;
}

int kthLargestPerfectSubtree(TreeNode* root, int k) {
    vector<int> values;

    int val = dfs_khLargestPerfectSubtree(root, values);
    sort(values.begin(), values.end(), greater<int>());
    return k > values.size() ? -1 : values[k - 1];
}

vector<long long> findXSum(vector<int>& nums, int k, int x) {
    unordered_map<int, int> freq;
    vector<long long> ans;
    set<pair<long long, int>, greater<pair<long long, int>>> top, bottom;
    long long xsum = 0;

    for (int i = 0; i < nums.size(); i++) {
        long long cnt = freq[nums[i]];
        if (cnt) {
            if (auto it = bottom.find({ cnt, nums[i] }); it != end(bottom))
                bottom.erase(it);
            else {
                top.erase({cnt, nums[i]});
                xsum -= (cnt * nums[i]);
            }
        }

        freq[nums[i]]++;
        top.insert({ cnt + 1, nums[i] });
        xsum += ((cnt + 1) * nums[i]);

        if (top.size() > x) {
            auto it_top = prev(end(top));
            xsum -= (it_top->first * it_top->second);
            bottom.insert({it_top->first, it_top->second});
            top.erase(it_top);
        }

        if (i >= k) {
            cnt = freq[nums[i - k]];
            if (auto it = bottom.find({ cnt, nums[i-k] }); it != end(bottom))
                bottom.erase(it);
            else {
                it = top.find({ cnt, nums[i - k] });
                xsum -= (it->first * it->second);
                top.erase(it);
            }

            if (cnt > 1)
                bottom.insert({cnt - 1, nums[i-k]});

            --freq[nums[i - k]];
            if (top.size() < x) {
                if (auto it = begin(bottom); it != end(bottom)) {
                    xsum += (it->first * it->second);
                    top.insert({it->first, it->second});
                    bottom.erase(it);
                }
            }

        }
        
        if (i + 1 >= k)
            ans.push_back(xsum);
    }

    return ans;
}

// Biweekly Contest 129
int cntArr = 0;
unordered_set<string> stableSet;
bool checkStabilityArr(vector<int>& arr, int limit) {
    int ones = 0, zeros = 0;

    for (int i = 0; i < limit; i++) {
        if (arr[i]) ones++;
        else zeros++;
    }

    if (zeros == 0 || ones == 0)
        return false;

    for (int i = limit; i < arr.size(); i++) {
        if (arr[i]) ones++;
        else zeros++;

        if (arr[i - limit]) ones--;
        else zeros--;

        if (zeros == 0 || ones == 0)
            return false;
    }

    return true;
}

void recursionPermutationArr(int zero, int one, int limit, vector<int>& sofar, int idx, int tot_sz) {
    if (sofar.size() >= limit + 1) {
        if (!checkStabilityArr(sofar, limit + 1))
            return;
    }

    if (sofar.size() == tot_sz) {
        string str = "";
        for (int i = 0; i < tot_sz; i++) {
            str += sofar[i] + '0';
        }

        if (stableSet.count(str))
            return;

        cout << str << endl;
        stableSet.insert(str);
        cntArr++;
        return;
    }

    for (int i = idx; i < tot_sz; i++) {
        if (zero) {
            sofar.push_back(0);
            zero--;
            recursionPermutationArr(zero, one, limit, sofar, idx + 1, tot_sz);
            zero++;
            sofar.pop_back();
        }

        if (one) {
            sofar.push_back(1);
            one--;
            recursionPermutationArr(zero, one, limit, sofar, idx + 1, tot_sz);
            one++;
            sofar.pop_back();
        }
    }
}

int numberOfStableArrays(int zero, int one, int limit) {
    vector<int> sofar;

    recursionPermutationArr(zero, one, limit, sofar, 0, zero + one);

    return cntArr;
}

bool canMakeSquare(vector<vector<char>>& grid) {


    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            int black = 0, white = 0;
            if (grid[i][j] == 'W') white++;
            else black++;

            if (grid[i][j + 1] == 'W') white++;
            else black++;

            if (grid[i + 1][j] == 'W') white++;
            else black++;

            if (grid[i + 1][j + 1] == 'W') white++;
            else black++;

            if (white == 3 || black == 3)
                return true;
        }
    }

    return false;
}

// BiWeekly Contest 138
// 3273
long long minDamage(int power, vector<int>& damage, vector<int>& health) {
    vector<pair<int, int>> dt;
    int n = damage.size();

    long long totDamage = 0;
    for (int i = 0; i < n; i++) {
        totDamage += damage[i];
        dt.push_back({ damage[i], ceil((double)health[i] / power) });
    }

    sort(dt.begin(), dt.end(), [](pair<int, int> pi, pair<int, int> pj) {
        return (1ll * pi.second * pj.first) < (1ll * pi.first * pj.second);
        });

    long long minDamage = 0;
    for (int i = 0; i < dt.size(); i++) {
        minDamage += (dt[i].second * totDamage * 1ll);
        totDamage -= dt[i].first;
    }

    return minDamage;

}

string stringHash(string s, int k) {
    string result = "";

    for (int i = 0, idx = 0; i < s.size(); i += k, idx++) {
        int hashedVal = 0;
        for (int j = 0; j < k; j++) {
            hashedVal += s[i + j] - 'a';
        }

        hashedVal %= 26;
        result += ('a' + hashedVal);
    }

    return result;
}

int generateKey(int num1, int num2, int num3) {
    int ans = 0, idx = 0;

    while (num1 > 0 || num2 > 0 || num3 > 0) {
        num1 = num1 == 0 ? 9 : num1;
        num2 = num2 == 0 ? 9 : num2;
        num3 = num3 == 0 ? 9 : num3;
        int n1 = num1 % 10;
        int n2 = num2 % 10;
        int n3 = num3 % 10;

        int v = min(min(n1, n2), n3);
        ans += (v * (pow(10, idx)));

        num1 = num1 / 10;
        num2 = num2 / 10;
        num3 = num3 / 10;

        idx++;
    }

    return ans;
}

// weekly contest 392
string getSmallestString(string s, int k) {

    for (int i = 0; i < s.size() && k > 0; i++) {
        int minV = min(s[i] - 'a', 'z' - s[i] + 1);
        if (minV <= k) {
            s[i] = 'a';
            minV -= k;
        }
        else {
            s[i] = s[i] - k;
            break;
        }
    }

    return s;
}

int longestMonotonicSubarray(vector<int>& nums) {
    int inc = 1, dec = 1, mxInc = 1, mxDec = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] < nums[i]) {
            inc++;
        }
        else {
            mxInc = max(mxInc, inc);
            inc = 0;
        }

        if (nums[i - 1] > nums[i])
            dec++;
        else {
            mxDec = max(mxDec, dec);
            dec = 0;
        }
    }

    return max(mxInc, mxDec);
}


#pragma endregion





#endif 
