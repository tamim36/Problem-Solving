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

// Dynamic Programming
// Knapsack
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

int knapSack_recursion(int W, vector<int>& wt, vector<int>& val, int n) {
    if (n <= 0 || W <= 0)
        return 0;

    if (wt[n - 1] <= W) {
        return max(val[n-1] + knapSack_recursion(W-wt[n-1], wt, val, n - 1), 
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
        return dp[n][W] = max(val[n-1] + knapSack_dp(W-wt[n-1], wt, val, n - 1, dp),
                                         knapSack_dp(W, wt, val, n - 1, dp));
    }
    else {
        return dp[n][W] = knapSack_dp(W, wt, val, n - 1, dp);
    }
}

int knapSack_TopDown(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
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
                                dp_minPathSum(grid, row, col, i, j-1, dp));
    return dp[i][j];
}

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));

    int val = dp_minPathSum(grid, row, col, row-1, col-1, dp);
    return dp[row-1][col-1];
}

// 746
int dp_X[1002];

int recur_minCostClimbingStairs(vector<int>& cost, int idx) {
    if (idx < 0)
        return 0;

    if (dp_X[idx] != -1)
        return dp_X[idx];

    cout << idx << endl;
    dp_X[idx] = cost[idx] + min(recur_minCostClimbingStairs(cost, idx-1),
        recur_minCostClimbingStairs(cost, idx - 2));

    return dp_X[idx];
}

int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    int n = cost.size();
    memset(dp_X, -1, sizeof(dp_X));

    return recur_minCostClimbingStairs(cost, n - 1);
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

    for (int i = 0, idx = 0; i < s.size(); i+=k, idx++) {
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

// 3211
void recurValidString(int n, string curStr, vector<string>& ans) {
    if (curStr.size() == n) {
        ans.push_back(curStr);
        return;
    }

    if (curStr.empty() || curStr.back() == '1')
        recurValidString(n, curStr + "0", ans);

    recurValidString(n, curStr + "1", ans);
}

vector<string> validStrings(int n) {
    vector<string> ans;
    recurValidString(n, "", ans);

    return ans;
}

// 2326
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    queue<pair<int, int>> dir;
    dir.push({0, 1});
    dir.push({1, 0});
    dir.push({0, -1});
    dir.push({-1, 0});

    int r = 0, c = 0;
    vector<vector<int>> ans(m, vector<int>(n, -1));
    for (int i = 0; i < m * n; i++) {
        if (head != NULL) {
            cout << r << " " << c << endl;
            if (r == 2 && c == 0) {
                cout << "" << endl;
            }
            ans[r][c] = head->val;
            head = head->next;
        }
        else {
            return ans;
        }

        int curX = dir.front().first;
        int curY = dir.front().second;
        if (r + curX >= m || c + curY >= n || r + curX < 0 || c + curY < 0 || ans[r + curX][c + curY] != -1) {
            dir.pop();
            dir.push({ curX, curY });
            curX = dir.front().first;
            curY = dir.front().second;
        }

        r += curX;
        c += curY;
    }

    return ans;
}

// 2905
vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
    return {};
}

// 2405
int partitionString(string s) {
    int cnt = 0;
    set<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (st.count(s[i])) {
            st.clear();
            cnt++;
        }
        
        st.insert(s[i]);
    }

    return cnt;
}

// 1561
int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end(), greater<int>());
    int cnt = 0;

    for (int i = 1, j = 0; j < piles.size() / 3; i += 2, j++) {
        cnt += piles[i];
    }

    return cnt;
}

// 2285
long long maximumImportance(int n, vector<vector<int>>& roads) {
    unordered_map<int, int> mp;
    for (int i = 0; i < roads.size(); i++) {
        mp[roads[i][0]]++;
        mp[roads[i][1]]++;
    }

    vector<int> v;
    for (auto kv : mp) {
        v.push_back(kv.second);
    }

    long long ans = 0;
    sort(v.begin(), v.end(), greater());
    for (int i = 0; i < v.size(); i++) {
        ans += ((long long)v[i] * (long long)n);
        n--;
    }

    return ans;
}

// 1310
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> pref(arr.size() + 1), ans;
    pref[0] = 0;

    for (int i = 1; i < arr.size() + 1; i++) {
        pref[i] = pref[i - 1] ^ arr[i - 1];
    }

    for (int i = 0; i < queries.size(); i++) {
        int l = queries[i][0], r = queries[i][1];
        ans.push_back(pref[l] ^ pref[r + 1]);
    }

    return ans;
}

// 1829
vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int maxNum = (1 << maximumBit) - 1, xorSum = maxNum;
    vector<int> ans;
    
    for (int i = 0; i < nums.size(); i++)
        xorSum ^= nums[i];
    ans.push_back(xorSum);

    for (int i = nums.size() - 1; i > 0; i--) {
        xorSum ^= nums[i];
        ans.push_back(xorSum);
    }

    return ans;
}

// 2044
int maxOr = 0, countMaxOr = 0;
void recur_countMaxOrSubsets(vector<int>& nums, vector<int>& sofar, int idx) {

    int cur = 0;
    for (int j = 0; j < sofar.size(); j++) {
        cur |= sofar[j];
    }

    if (cur > maxOr) {
        maxOr = cur;
        countMaxOr = 1;
    }
    else if (cur == maxOr)
        countMaxOr++;

    for (int i = idx; i < nums.size(); i++) {
        sofar.push_back(nums[i]);
        recur_countMaxOrSubsets(nums, sofar, i + 1);
        sofar.pop_back();
    }
}

int countMaxOrSubsets(vector<int>& nums) {
    vector<int> sofar;
    recur_countMaxOrSubsets(nums, sofar, 0);
    return countMaxOr;
}

// 861
int matrixScore(vector<vector<int>>& grid) {
    int rs = grid.size(), cs = grid[0].size();

    // ensure first column must be one
    for (int r = 0; r < rs; r++) {
        if (!grid[r][0]) {
            for (int c = 0; c < cs; c++) {
                grid[r][c] ^= 1;
            }
        }
    }

    for (int c = 1; c < cs; c++) {
        int cnt = 0;
        for (int r = 0; r < rs; r++) {
            if (grid[r][c])
                cnt++;
        }

        if (cnt < (rs + 1) / 2) {
            for (int r = 0; r < rs; r++)
                grid[r][c] ^= 1;
        }
    }

    int tot = 0;
    for (int r = 0; r < rs; r++) {
        int num = 0;
        for (int c = 0; c < cs; c++) {
            if (grid[r][c])
                num |= (1 << (cs - c - 1));
        }

        tot += num;
    }

    return tot;
}

// 2317
int maximumXOR(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
        ans |= nums[i];

    return ans;
}

// 1442
int countTriplets(vector<int>& arr) {
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        int a = 0;
        for (int j = i+1; j < arr.size(); j++) {
            a ^= arr[j - 1];
            int b = 0;
            for (int k = j; k < arr.size(); k++) {
                b ^= arr[k];
                if (a == b)
                    cnt++;
            }
        }
    }

    return cnt;
}

// 2997
int minOperations(vector<int>& nums, int k) {
    int xor_sum = k;

    for (int i = 0; i < nums.size(); i++) {
        xor_sum ^= nums[i];
    }

    return count_setBits_ByFlipping(xor_sum);
}

// 3192
int minOperations_2(vector<int>& nums) {
    int steps = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (!(steps % 2) && !nums[i])
            steps++;
        else if (steps % 2 && nums[i])
            steps++;
    }

    return steps;
}


int minOperations(vector<int>& nums) {
    int n = nums.size();
    int operations = 0;

    for (int i = 0; i <= n - 3; ++i) {
        if (nums[i] == 0) {
            nums[i] = 1 - nums[i];
            nums[i + 1] = 1 - nums[i + 1];
            nums[i + 2] = 1 - nums[i + 2];
            ++operations;
        }
    }

    for (int i = n - 2; i < n; ++i) {
        if (nums[i] == 0) {
            return -1; 
        }
    }

    return operations;
}


int minimumOperations(vector<int>& nums) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 3 != 0)
            cnt++;
    }

    return cnt;
}


// 2433
vector<int> findArray(vector<int>& pref) {
    if (!pref.size())
        return pref;

    vector<int> arr(pref.size(), 0);
    arr[0] = pref[0];

    for (int i = 1; i < pref.size(); i++) {
        arr[i] = pref[i] ^ pref[i - 1];
    }

    return arr;
}

// 645
vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(n + 1, 0);
    vector<int> ans(2, 0);

    for (int i = 0; i < n; i++) {
        ans[1] ^= (i + 1) ^ nums[i];
        if (++count[nums[i]] == 2)
            ans[0] = nums[i];
    }

    ans[1] ^= ans[0];
    return ans;
}

string toHex(int b) {

    long long num = b;
    if (num == 0)
        return "0";
    int xor_val = 0;
    long long c = pow(2, 32) - 1;
    if (num < 0) {
        num *= -1;
        c ^= num;
        c += 1;
        num = c;
    }

    string hex = "0123456789abcdef";
    string res = "";
    int rem = 0;
    while (num) {
        rem = num % 16;
        res += hex[rem];
        num /= 16;
    }

    reverse(res.begin(), res.end());
    return res;
}

// 
vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    unordered_map<int, int> balls, colors;
    vector<int> res;

    for (int i = 0; i < queries.size(); i++) {
        int b = queries[i][0], c = queries[i][1];

        if (balls[b]) {
            colors[balls[b]]--;
            if (!colors[balls[b]]) {
                //cout << "remo col: " << c << endl;
                colors.erase(balls[b]);
            }
        }

        balls[b] = c;
        colors[c]++;
        res.push_back(colors.size());
    }

    return res;
}

vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
    vector<int> occ, res;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == x)
            occ.push_back(i);
    }

    for (int i = 0; i < queries.size(); i++) {
        if (queries[i] > occ.size())
            res.push_back(-1);
        else
            res.push_back(occ[queries[i] - 1]);
    }

    return res;
}

//
int duplicateNumbersXOR(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int res = -1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            if (res == -1)
                res = nums[i];
            else
                res ^= nums[i];
        }
    }

    return res == -1 ? 0 : res;
}

// 67
string addBinary(string a, string b) {
    int carry = 0;
    string res = "";
    int minLen = min(a.size(), b.size());
    int i = a.size() - 1, j = b.size() - 1;

    for (; i >= 0 || j >= 0; i--, j--) {
        int ai = i >= 0 ? a[i] - '0' : 0;
        int bi = j >= 0 ? b[j] - '0' : 0;

        int r = 0;
        if (ai && bi) {
            if (carry)
                r = 1;
            else
                carry = 1;
        }
        else if (ai || bi) {
            if (!carry) {
                r = 1;
                carry = 0;
            }
        }
        else {
            if (carry) {
                r = 1;
                carry = 0;
            }
        }

        res.push_back(r + '0');
    }

    if (carry)
        res.push_back('1');

    reverse(res.begin(), res.end());
    return res;
}

// 190
uint32_t reverseBits(uint32_t n) {
    if (n == 0)
        return n;
    
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);

    return n;
}

uint32_t reverseBits2(uint32_t n) {
    if (n == 0)
        return n;
    uint32_t rev = 0;
    int i = 0;

    while (n) {
        rev <<= 1;
        if (n & 1) 
            rev |= 1;
        i++;
        n >>= 1;
    }

    return rev << (32 - i);
}

// 389
char findTheDifference(string s, string t) {
    long long sbit = 0;

    for (auto c : s)
        sbit ^= c;
    for (auto c : t)
        sbit ^= c;

    return sbit;
}

// 1009
int bitwiseComplement(int n) {
    if (n == 0) return 1;
    int bit_num = log2(n) + 1;
    int all_one = pow(2, bit_num) - 1;
    int xor_val = all_one ^ n;
    cout << "Bit_Num: " << bit_num << " all_one: " << all_one << endl;
    return xor_val;
}


int height(TreeNode* root) {
    return root == nullptr ? -1 : 1 + height(root->left);
}

int countNodes(TreeNode* root) {
    int nodes = 0;
    int h = height(root);
    while (root != nullptr) {
        if (height(root->right) == h - 1) {
            nodes += 1 << h;
            root = root->right;
        }
        else {
            nodes += 1 << (h - 1);
            root = root->left;
        }
        h--;
    }
    return nodes;
}

// 136
int singleNumber(vector<int>& nums) {
    int xor_val = 0;
    for (int i = 1; i < nums.size(); i++)
        xor_val ^= nums[i];

    return xor_val;
}

bool divideArray(vector<int>& nums) {
    if (nums.size() % 2)
        return false;

    int xor_val = 0;
    for (int i = 1; i < nums.size(); i++)
        xor_val ^= nums[i];

    if (!xor_val)
        return true;

    return false;
}

// 2351
char repeatedCharacter(string s) {
    // using bit masking
    int appear = 0;
    for (auto c : s) {
        int mask = (1 << (c - 'a'));
        if (appear & mask)
            return c;
        appear |= mask;
    }

    return '0';
}

// 3128
long long numberOfRightTriangles(vector<vector<int>>& grid) {
    int rsz = grid.size(), csz = grid[0].size();
    vector<int> rowSum(rsz, 0), colSum(csz, 0);

    for (int r = 0; r < rsz; r++) {
        for (int c = 0; c < csz; c++) {
            rowSum[r] += grid[r][c];
            colSum[c] += grid[r][c];
        }
    }

    long long cnt = 0;

    for (int r = 0; r < rsz; r++) {
        for (int c = 0; c < csz; c++) {
            if (grid[r][c]) {
                cnt += ((rowSum[r] - 1) * (colSum[c] - 1));
            }
        }
    }

    return cnt;
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
        if (!checkStabilityArr(sofar, limit+1))
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

            if (grid[i][j+1] == 'W') white++;
            else black++;

            if (grid[i+1][j] == 'W') white++;
            else black++;

            if (grid[i+1][j+1] == 'W') white++;
            else black++;

            if (white == 3 || black == 3)
                return true;
        }
    }

    return false;
}

// 2917
int findKOr(vector<int>& nums, int k) {
    vector<int> bits(32, 0);

    for (auto num : nums) {
        int idx = 0;
        while (num) {
            if (num & 1)
                bits[idx]++;

            idx++;
            num = num >> 1;
        }
    }

    long long pos = 1;
    int val = 0;
    for (int i = 0; i < bits.size(); i++) {
        if (bits[i] >= k)
            val += pos * 1;
        pos *= 2;
    }

    return val;
}

struct BitComparator {
    bool operator()(int a1, int a2) const {
        int bit1 = count_setBits_ByFlipping(a1);
        int bit2 = count_setBits_ByFlipping(a2);
        return bit1 == bit2 ? a1 < a2 : bit1 < bit2;
    }
};

// 1356
vector<int> sortByBits(vector<int>& arr) {
    sort(begin(arr), end(arr), BitComparator());
    return arr;
}

int subsetXORSum(vector<int>& nums) {
    int res = 0;
    for (auto i = 1; i < (1 << nums.size()); ++i) {
        int total = 0;
        for (auto j = 0; j < nums.size(); ++j)
            if (i & (1 << j))
                total ^= nums[j];
        res += total;
    }
    return res;
}


// 1863
int xorSumSubsetCount = 0;
void getSubsetsXORSum(int curIdx, vector<int>& sofar, vector<int>& nums) {
    int curTotal = 0;
    for (int i = 0; i < sofar.size(); i++)
        curTotal = (curTotal ^ sofar[i]);

    xorSumSubsetCount += curTotal;
    for (int i = curIdx; i < nums.size(); i++) {
        sofar.push_back(nums[i]);
        getSubsetsXORSum(i + 1, sofar, nums);
        sofar.pop_back();
    }
}

int subsetXORSum2(vector<int>& nums) {
    vector<int> sofar;
    getSubsetsXORSum(0, sofar, nums);
    return xorSumSubsetCount;
}

// 2220
int minBitFlips(int start, int goal) {
    int bitDifference = start ^ goal;
    return count_setBits_ByFlipping(bitDifference);
}

// 338
vector<int> countBits(int n) {
    vector<int> res(n + 1);

    for (int i = 0; i <= n; i++) {
        res[i] = count_setBits_ByFlipping(i);
    }

    return res;
}

// 2859
int sumIndicesWithKSetBits(vector<int>& nums, int k) {
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (count_setBits(i) == k)
            sum += nums[i];
    }

    return sum;
}

// 784
void recur_letterCasePermutation(int curIdx, string s, vector<string>& res) {
    if (curIdx >= s.size()) {
        res.push_back(s);
        return;
    }

    if (isdigit(s[curIdx])) {
        recur_letterCasePermutation(curIdx + 1, s, res);
    }
    else {
        char lowerCase = tolower(s[curIdx]);
        char upperCase = toupper(s[curIdx]);

        string lower = s;
        string upper = s;
        lower[curIdx] = lowerCase;
        upper[curIdx] = upperCase;
        recur_letterCasePermutation(curIdx + 1, lower, res);
        recur_letterCasePermutation(curIdx + 1, upper, res);
    }
}

vector<string> letterCasePermutation(string s) {
    vector<string> res;
    if (s.empty())
        return res;

    recur_letterCasePermutation(0, s, res);
    return res;
}

// 713
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    long long preProd = 1;
    int cnt = 0;

    for (int i = 0, j = 0; i < nums.size(); i++) {
        if (preProd * nums[i] >= k)
            preProd /= nums[j++];
        if (preProd * nums[i] < k) {
            cnt += (i - j + 1);
            preProd *= nums[i];
        }
    }

    return cnt;
}

// 1720
vector<int> decode(vector<int>& encoded, int first) {
    int n = encoded.size();
    vector<int> arr (n+1);
    arr[0] = first;

    for (int i = 1; i < n + 1; i++)
        arr[i] = encoded[i - 1] ^ arr[i - 1];

    return arr;
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

// 93
bool isvalidIpAddress(string address, int idx, int sofarCnt, int tot_sz) {
    if (address.size() == 0) return false;
    if (((4 - sofarCnt) * 3) < (tot_sz - idx)) return false;

    if (address.size() > 1 && address[0] == '0') return false;
    //cout << address << endl;
    int val = stoi(address);
    if (val > 255) return false;
    return true;
}

string vectorToIpAddress(vector<string> sofar) {
    string ipAddress = "";
    int row = 0;
    while (row < sofar.size()) {
        for (int i = 0; i < sofar[row].size(); i++) {
            ipAddress.push_back(sofar[row][i]);
        }

        row++;
        if (row < sofar.size())
            ipAddress.push_back('.');
    }
    return ipAddress;
}

void recur_restoreIpAddresses(int curIdx, string s, vector<string>& sofar, vector<string>& results) {
    if (curIdx == s.size() && sofar.size() == 4) {
        string ipAddress = vectorToIpAddress(sofar);
        results.push_back(ipAddress);
        return;
    }
    if (sofar.size() == 4) return;

    for (int i = curIdx; i < curIdx + 3 && i < s.size(); i++) {
        string newstr = s.substr(curIdx, i - curIdx + 1);
        if (!isvalidIpAddress(newstr, i + 1, sofar.size() + 1, s.size()))
            continue;
        //cout << newstr << endl;
        sofar.push_back(newstr);
        recur_restoreIpAddresses(i + 1, s, sofar, results);
        sofar.pop_back();
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> results, sofar;
    recur_restoreIpAddresses(0, s, sofar, results);
    return results;
}

// 79
bool recur_exist(int row, int col, string sofar, vector<vector<int>>& vis, vector<vector<char>>& board, string word) {
    if (sofar == word) {
        return true;
    }
    if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0)
        return false;

    int idx = sofar.size() - 1;
    if (idx > 0 && idx < sofar.size() && idx < word.size() && sofar[idx] != word[idx])
        return false;

    int dx[] = { 1, -1, 0,  0 };
    int dy[] = { 0,  0, 1, -1 };

    for (int i = 0; i < 4; i++) {
        int r = row + dx[i], c = col + dy[i];
        if (r >= board.size() || r < 0 || c >= board[0].size() || c < 0 || vis[r][c])
            continue;

        vis[r][c] = 1;
        sofar.push_back(board[r][c]);
        if (recur_exist(r, c, sofar, vis, board, word)) return true;
        sofar.pop_back();
        vis[r][c] = 0;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            string a = string(1, word[0]);
            cout << a << endl;
            if (board[i][j] == word[0]) {
                
                vis[i][j] = 1;
                if (recur_exist(i, j, string(1, word[0]), vis, board, word))
                    return true;
                vis[i][j] = 0;
            }
        }
    }

    return false;
}

// 36
bool check_isValidSudoku_by_Grid(int row, int col, vector<vector<int>>& rowValues, vector<vector<int>>& colValues, vector<vector<char>>& board) {
    unordered_set<int> st;

    for (int r = row; r < row + 3 && r < 9; r++) {
        for (int c = col; c < col + 3 && c < 9; c++) {
            int val = board[r][c] != '.' ? board[r][c] - '0' : 0;
            if (val > 0) {
                if (++rowValues[r][val] == 2 || ++colValues[c][val] == 2)
                    return false;

                if (st.count(val))
                    return false;

                st.insert(val);
            }
        }
    }

    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> rowValues(9, vector<int>(10, 0)), colValues(9, vector<int>(10, 0));

    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            if (!check_isValidSudoku_by_Grid(i, j, rowValues, colValues, board))
                return false;
        }
    }

    return true;
}

// 22
void iterative_generateParenthesis(int n, vector<string>& results, unordered_set<string>& st) {
    int curIdx = 1;

    queue<string> sofar;
    sofar.push("()");
    string parenthesis = "()";
    while (curIdx < n) {
        int sz = sofar.size();
        for (int i = 0; i < sz; i++) {
            string cur_pt = sofar.front(); sofar.pop();

            for (int j = 0; j < cur_pt.size(); j++) {
                string new_pt = cur_pt;
                new_pt.insert(j, parenthesis);
                if (!st.count(new_pt)) {
                    sofar.push(new_pt);
                    st.insert(new_pt);

                    if (new_pt.size() == n * 2) {
                        results.push_back(new_pt);
                    }
                }
            }
        }

        curIdx++;
    }

}

vector<string> generateParenthesis(int n) {
    if (n == 1)
        return { "()" };

    vector<string> results;
    unordered_set<string> st;
    iterative_generateParenthesis(n, results, st);

    return results;
}

// 17
void recur_letterCombinations(int curIdx, string digits, string sofar, vector<string>& results, unordered_map<int, vector<char>>& mp) {
    if (sofar.size() == digits.size()) {
        results.push_back(sofar);
        return;
    }

    for (auto ch : mp[digits[curIdx] - '0']) {
        sofar.push_back(ch);

        recur_letterCombinations(curIdx + 1, digits, sofar, results, mp);

        sofar.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> results;
    if (digits.empty())
        return results;

    unordered_map<int, vector<char>> mp;
    mp.insert({ 2, {'a','b','c'} });
    mp.insert({ 3, {'d','e','f'} });
    mp.insert({ 4, {'g','h','i'} });
    mp.insert({ 5, {'j','k','l'} });
    mp.insert({ 6, {'m','n','o'} });
    mp.insert({ 7, {'p','q','r','s'} });
    mp.insert({ 8, {'t','u','v'} });
    mp.insert({ 9, {'w','x','y','z'} });

    
    recur_letterCombinations(0, digits, "", results, mp);

    return results;
}

// 51
bool validQueenPos(int row, int col, vector<pair<int, int>>& sofar) {
    int dx[] = { 1, 1, -1, -1 };
    int dy[] = { 1, -1, 1, -1 }; // for corners

    for (int i = 0; i < sofar.size(); i++) {
        int rq = sofar[i].first, cq = sofar[i].second;

        // check row & col
        if (rq == row || cq == col)
            return false;

        // check corner
        int diff = abs(rq - row);
        for (int d = 0; d < 4; d++) {
            int dxd = dx[d] * diff;
            int dyd = dy[d] * diff;

            if (dxd + rq == row && dyd + cq == col)
                return false;
        }
    }

    return true;
}

void backtrack_solveNQueen(int curRow, int n, vector<pair<int, int>>& sofar, vector<vector<pair<int, int>>>& results) {
    if (sofar.size() == n)
        results.push_back(sofar);

    for (int row = curRow, col = 0; col < n && row < n; col++) {
        if (validQueenPos(row, col, sofar)) {
            sofar.push_back({row, col});
            backtrack_solveNQueen(curRow + 1, n, sofar, results);
        }
    }

    if (!sofar.empty())
        sofar.pop_back();
}

vector<vector<string>> solveNQueens(int n) {
    string test = "...huiuhiuhiuhiuhiuhiuh.";
    test[1] = 'Q';


    vector<vector<int>> board (n, vector<int>(n, 0));
    vector<pair<int, int>> sofar;
    vector<vector<pair<int, int>>> results;

    backtrack_solveNQueen(0, n, sofar, results);

    int resSz = results.size();
    string str(n, '.');
    vector<vector<string>> ans(resSz, vector<string>(n, str));

    for (int ansNo = 0; ansNo < resSz; ansNo++) {
        for (int rowCol = 0; rowCol < results[ansNo].size(); rowCol++) {
            int row = results[ansNo][rowCol].first, col = results[ansNo][rowCol].second;

            ans[ansNo][row][col] = 'Q';
        }
    }

    return ans;
}

// 90
void recur_subsetWithDup(int curIdx ,vector<int>& nums, vector<int>& sofar, vector<vector<int>>& results) {
    results.push_back(sofar);

    for (int i = curIdx; i < nums.size(); i++) {
        if (i > curIdx && nums[i] == nums[i - 1])
            continue;

        sofar.push_back(i);

        recur_subsetWithDup(i + 1, nums, sofar, results);

        sofar.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> sofar;
    vector<vector<int>> results;
    sort(nums.begin(), nums.end());
    recur_subsetWithDup(0, nums, sofar, results);

    return results;
}

// 216
void recur_combinationSum3(int curIdx, int k, int n, vector<int>& sofar, vector<vector<int>>& ans) {
    if (n < 0) return;
    if (n == 0) {
        if (sofar.size() == k)
            ans.push_back(sofar);
        return;
    }

    for (int i = curIdx; i <= 9; i++) {
        sofar.push_back(i);

        recur_combinationSum3(i + 1, k, n - i, sofar, ans);

        sofar.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> sofar;
    vector<vector<int>> ans;

    recur_combinationSum3(1, k, n, sofar, ans);

    return ans;
}

// 40
string vectorTostring(vector<int> vec) {
    sort(vec.begin(), vec.end());
    string s = "";
    for (auto val : vec)
        s += to_string(val);

    return s;
}

void recur_combinationSum2(int curIdx, int curSum, vector<int>& candidates, 
                            int target, vector<int> sofar, vector<vector<int>>& ans, set<string>& isExist, set<string>& checker) {
    if (curSum >= target) {
        if (curSum == target) {
            string val = vectorTostring(sofar);
            if (!isExist.count(val)) {
                ans.push_back(sofar);
                isExist.insert(val);
            }
        }
        return;
    }

    for (int i = curIdx; i < candidates.size(); i++) {
        curSum += candidates[i];
        sofar.push_back(candidates[i]);
        if (!checker.count(vectorTostring(sofar)))
            recur_combinationSum2(i + 1, curSum, candidates, target, sofar, ans, isExist, checker);

        

        checker.insert(vectorTostring(sofar));
        curSum -= sofar.back();
        sofar.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> sofar;
    set<string> isExist;
    set<string> checker;
    recur_combinationSum2(0, 0, candidates, target, sofar, ans, isExist, checker);
    return ans;
}

// 173
class BSTIterator {
private:
    queue<int> q;

    void recursiveInorder(TreeNode* root) {
        if (!root) return;

        recursiveInorder(root->left);
        q.push(root->val);
        recursiveInorder(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        recursiveInorder(root);
    }

    int next() {
        int val = q.front();
        q.pop();
        return val;
    }

    bool hasNext() {
        return !q.empty();
    }
};

// 1156
int maxRepOpt1_2(string str, int res = 0) {
    for (auto ch = 'a'; ch <= 'z'; ++ch) {
        int i = 0, j = 0, gap = 0;
        while (i < str.size()) {
            gap += str[i++] != ch;
            if (gap > 1) gap -= str[j++] != ch;
        }
        res = max(res, min(i - j, (int)count_if(begin(str), end(str), [&](char ch1) { return ch1 == ch; })));
    }
    return res;
}

int maxRepOpt1_WA(string text) {
    unordered_map<char, int> ump;

    int cur_len = 0;
    bool isRepAvl = true;
    for (int i = 0, j = i + 1; i < text.size(); i++) {

        int len = 1;
        int prev_idx = -1;
        while (j < text.size() && (text[i] == text[j] || isRepAvl)) {
            if (text[i] != text[j]) {
                isRepAvl = false;

                prev_idx = j;
                len--;
            }
            j++;
            len++;
        }

        cur_len = len;
        int alreadyExist = 0;
        if (ump[text[i]]) alreadyExist = 1;

        ump[text[i]] = max(cur_len + alreadyExist, alreadyExist + ump[text[i]]);

        isRepAvl = true;
    }

    int mx = 0;
    for (auto kvp : ump) {
        mx = max(mx, kvp.second);
    }

    return mx;
}

#endif 
