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
