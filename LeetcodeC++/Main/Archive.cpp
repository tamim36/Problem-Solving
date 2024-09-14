#pragma once
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>


// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

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

struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int>& v) const {
        return v.first * 31 + v.second;
    }
};






// check 378 follow up question
// study on this https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/313347/A*-search-in-Python



/*
* 2d vector initialize with size and 0
* vector<vector<int>> vis(r, vector<int>(c, 0));
*
* unordered_set<char> vw({'a', 'e', 'i', 'o', 'u'});
*
* if (*rbegin(setTimes) + (j - i + 1) * sum > budget) {
            sum -= costs[i];
            setTimes.erase(setTimes.find(times[i++]));
        }
*
*
* // Sorting
* // string sorting
*
* string ss = "hello";
    sort(begin(ss), end(ss));
*
*
* vector<vector<int>>& tasks
* sort(begin(tasks), end(tasks), [](const auto &t1, const auto &t2){
        return t1[1] < t2[1];
    });

  sort(people.begin(), people.end(), [](vector<int> v1, vector<int>v2) {
        return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
        });

  vector<pair<char, int>> vec;
  sort(vec.begin(), vec.end(), [](pair<char, int> p1, pair<char, int> p2) {
            return p1.second > p2.second;
            });


            // method inside another method
            int minOperationsOn(vector<int>& nums) {
    int n = nums.size();
    int one = 0;
    for (int i = 0; i < n; i++) one += nums[i] == 1;
    if (one) return n - one;
    stack<int> la, ra, lg, rg;
    auto good = [&]() {
        int g = 0;
        if (!la.empty()) g = gcd(g, lg.top());
        if (!ra.empty()) g = gcd(g, rg.top());
        return g == 1;
    };
    auto add = [&](int x) {
        ra.push(x);
        rg.push(gcd((rg.empty() ? 0 : rg.top()), x));
    };
    auto remove = [&]() {
        if (la.empty()) {
            while (!ra.empty()) {
                int x = ra.top(); la.push(x); ra.pop(), rg.pop();
                lg.push(gcd((lg.empty() ? 0 : lg.top()), x));
            }
        }
        la.pop(), lg.pop();
    };
    int ans = n;
    for (int l = 0, r = 0; r < n; r++) {
        add(nums[r]);
        while (l < n and good()) {
            ans = min(ans, r - l);
            remove(), l++;
        }
    }
    if (ans == n) return -1;
    return n + ans - 1;
}

    // short hand syntax technique
    queue<pair<int, int>> q;
    auto [r, c] = q.front();

*/



// relisource interview question
void fill2d() {
    /*
        1  2  3  4  5
        14 15 16 17 6
        13 20 19 18 7
        12 11 10 9  8
    */

    // assuming ara is blank filled with 0
    vector<vector<int>> ara(4, vector<int>(5, 0));
    int len = ara.size(), height = ara[0].size();

    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    queue<pair<int, int>> q_direction;

    q_direction.push({ 0, 1 });
    q_direction.push({ 1, 0 });
    q_direction.push({ 0, -1 });
    q_direction.push({ -1, 0 });

    int cur_val = 1;

    while (cur_val <= len * height) {
        int cur_position_x = q.front().first;
        int cur_position_y = q.front().second;
        q.pop();

        // changing direction
        if (cur_position_x >= len || cur_position_y >= height || cur_position_x < 0 || cur_position_y < 0
            || ara[cur_position_x][cur_position_y] != 0) {
            pair<int, int> cur_direction = q_direction.front();
            q_direction.pop();
            q_direction.push(cur_direction);

            // update cur position
            cur_position_x -= cur_direction.first;
            cur_position_y -= cur_direction.second;
        }
        else {
            ara[cur_position_x][cur_position_y] = cur_val;
            cur_val++;
        }


        // pushing next index
        int cur_dir_x = q_direction.front().first;
        int cur_dir_y = q_direction.front().second;
        q.push({ cur_position_x + cur_dir_x, cur_position_y + cur_dir_y });
    }
}



// 1261
class FindElements {
private:
    unordered_set<int> values;
    void recoverTree(TreeNode* root) {
        if (!root) return;

        if (root->val == -1) root->val = 0;

        values.insert(root->val);

        if (root->left) root->left->val = (root->val * 2) + 1;
        if (root->right) root->right->val = (root->val * 2) + 2;

        recoverTree(root->left);
        recoverTree(root->right);
    }

public:
    FindElements(TreeNode* root) {
        recoverTree(root);
    }

    bool find(int target) {
        return values.count(target);
    }
};

// 1038 538
int value_to_bstToGst = 0;
TreeNode* bstToGst(TreeNode* root) {
    if (!root)
        return root;

    bstToGst(root->right);
    value_to_bstToGst += root->val;
    root->val = value_to_bstToGst;
    bstToGst(root->left);

    return root;
}

// 39
void recur_combinationSum(int curSum, int curIdx, vector<int>& candidates, int target, vector<int>& sofar, vector<vector<int>>& ans) {
    if (curSum >= target) {
        if (curSum == target)
            ans.push_back(sofar);

        return;
    }

    for (int i = curIdx; i < candidates.size(); i++) {
        curSum += candidates[i];
        sofar.push_back(candidates[i]);

        recur_combinationSum(curSum, i, candidates, target, sofar, ans);

        sofar.pop_back();
        curSum -= candidates[i];
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> sofar;
    vector<vector<int>> ans;

    recur_combinationSum(0, 0, candidates, target, sofar, ans);

    return ans;
}

// 77
void recur_combine(int n, int k, int cur, vector<int>& sofar, vector<vector<int>>& ans) {
    if (sofar.size() == k) {
        ans.push_back(sofar);
        return;
    }

    for (int i = cur; i <= n; i++) {
        sofar.push_back(i);

        recur_combine(n, k, i + 1, sofar, ans);

        sofar.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<int> sofar;
    vector<vector<int>> ans;

    recur_combine(n, k, 1, sofar, ans);
    return ans;
}

// 49
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (auto str : strs) {
        string key = str;
        sort(key.begin(), key.end());

        mp[key].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto kvp : mp) {
        ans.push_back(kvp.second);
    }

    return ans;
}

int minimumMoves(vector<vector<int>>& grid) {
    // Base Case
    int t = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[i][j] == 0)
                t++;
    if (t == 0)
        return 0;

    int ans = INT_MAX;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (grid[i][j] == 0)
            {
                for (int ni = 0; ni < 3; ++ni)
                {
                    for (int nj = 0; nj < 3; ++nj)
                    {
                        int d = abs(ni - i) + abs(nj - j);
                        if (grid[ni][nj] > 1)
                        {
                            grid[ni][nj]--;
                            grid[i][j]++;
                            ans = min(ans, d + minimumMoves(grid));
                            grid[ni][nj]++;
                            grid[i][j]--;
                        }
                    }
                }
            }
        }
    }
    return ans;
}


string arrayToString(vector<int>& arr) {
    string arr_str = "";
    for (auto val : arr) {
        arr_str += to_string(val);
    }

    return arr_str;
}

vector<int> getNeighborsForOneDArray(int index) {
    vector<int> neighbors;
    if ((index + 1) % 3 != 0) neighbors.push_back(index + 1);
    if ((index % 3) != 0) neighbors.push_back(index - 1);
    if (index <= 5) neighbors.push_back(index + 3);
    if (index >= 3) neighbors.push_back(index - 3);

    return neighbors;
}

int minimumMoves(vector<vector<int>>& grid) {
    vector<int> one_d_grid(9);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            one_d_grid[i * 3 + j] = grid[i][j];
        }
    }

    unordered_set<string> unique_states;
    queue<string> q;
    string gridStr = arrayToString(one_d_grid);
    q.push(gridStr);
    unique_states.insert(gridStr);

    int moves = 0;
    while (!q.empty()) {
        int sz = q.size();

        for (int i = 0; i < sz; i++) {
            string cur_state = q.front(); q.pop();
            bool isValid = true;
            for (int k = 0; k < 9; k++) {
                if (cur_state[k] - '0' > 1) {
                    isValid = false;
                    for (auto nei : getNeighborsForOneDArray(k)) {
                        string new_state = cur_state;
                        new_state[k] = (int)new_state[k] - 1;
                        new_state[nei] = (int)new_state[nei] + 1;

                        if (!unique_states.count(new_state)) {
                            q.push(new_state);
                            unique_states.insert(new_state);
                        }
                    }
                }
            }
            if (isValid)
                return moves;
        }
        moves++;
    }

    return moves;
}

string arrayToString2(vector<int> arr) {
    string str = "";
    for (auto& val : arr) {
        str += to_string(val);
    }
    return str;
}

vector<int> getAdjacentCells(int index) {
    vector<int> adj;
    if (index % 3 != 0) adj.push_back(index - 1);
    if (index % 3 != 2) adj.push_back(index + 1);
    if (index / 3 != 0) adj.push_back(index - 3);
    if (index / 3 != 2) adj.push_back(index + 3);
    return adj;
}

int minimumMoves2(vector<vector<int>>& grid) {
    vector<int> start(9);
    int moves = 0;
    vector<int> target = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            start[i * 3 + j] = grid[i][j];
        }
    }

    queue<vector<int>> Q;
    unordered_set<string> visited;
    Q.push(start);
    visited.insert(arrayToString(start));
    while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
            vector<int> cur = Q.front();
            Q.pop();
            if (cur == target) return moves;
            for (int j = 0; j < 9; j++) {
                if (cur[j] > 1) {
                    for (auto& adj : getAdjacentCells(j)) {
                        vector<int> newState = cur;
                        newState[j]--;
                        newState[adj]++;
                        string state = arrayToString(newState);
                        if (visited.find(state) == visited.end()) {
                            visited.insert(state);
                            Q.push(newState);
                        }
                    }
                }
            }
        }
        moves++;
    }
    return moves;
}


int minimumMoves_bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0,  0, 1, -1 };

    vector<vector<int>> dis(3, vector<int>(3, 0));
    int tot = 0;
    int cnt = q.size();

    while (!q.empty() && cnt) {
        int x1 = q.front().first, y1 = q.front().second; q.pop();


        queue<pair<int, int>> child_q;
        bool isFound = false;
        for (int i = 0; i < 4; i++) {
            int x2 = x1 + dx[i], y2 = y1 + dy[i];

            if (x2 >= 3 || x2 < 0 || y2 >= 3 || y2 < 0)
                continue;

            child_q.push({ x2, y2 });
            dis[x2][y2] = dis[x2][y2] == 0 ? dis[x1][y1] + 1 : min(dis[x1][y1] + 1, dis[x2][y2]);
            if (!grid[x2][y2]) {
                grid[x2][y2] = 1;
                tot += dis[x2][y2];
                cnt--;

                if (--grid[x1][y1] > 1) {
                    q.push({ x1, y1 });
                }
                isFound = true;
                break;
            }
        }

        if (!isFound) {
            while (!child_q.empty())
            {
                q.push(child_q.front()); child_q.pop();
            }
        }
    }

    return tot;

}

int minimumMoves3(vector<vector<int>>& grid) {
    int total_moves = 0;
    bool isAllOne = false;

    queue<pair<int, int>> ones;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 1) {
                ones.push({ i, j });
            }
        }
    }

    return minimumMoves_bfs(grid, ones);
}

// 47
void recur_permuteUnique(unordered_map<int, int>& umap, vector<vector<int>>& ans, vector<int>& soFar, int n) {
    if (soFar.size() == n) {
        ans.push_back(soFar);
        return;
    }

    for (auto kvp : umap) {
        if (!kvp.second)
            continue;

        umap[kvp.first]--;
        soFar.push_back(kvp.first);
        recur_permuteUnique(umap, ans, soFar, n);
        umap[kvp.first]++;
        soFar.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    unordered_map<int, int> umap;
    for (auto num : nums)
        umap[num]++;

    vector<vector<int>> ans;
    vector<int> soFar;
    recur_permuteUnique(umap, ans, soFar, nums.size());

    return ans;
}

// 2389
int ansQuery_BinarySearch(vector<int>& nums, int val) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > val)
            right = mid;
        else
            left = mid + 1;
    }

    return left - 1;
}

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<int> prefix, ans;

    for (int i = 0; i < n; i++) {
        int val = nums[i];
        val += prefix.empty() ? 0 : prefix.back();
        prefix.push_back(val);
    }

    for (auto q : queries) {
        ans.push_back(ansQuery_BinarySearch(prefix, q));
    }

    return ans;
}

int lastRemaining(int n) {
    bool isHeadRemove = true;
    int head = 1;
    int step = 1;

    int items = n;

    while (items > 1) {
        if (isHeadRemove || items % 2 == 1) {
            head = head + step;
        }

        step *= 2;
        isHeadRemove = !isHeadRemove;
        items /= 2;
    }

    return head;
}


// 300 lis, lis_path, template
vector<int> path_of_lis(vector<int>& nums) {
    int n = nums.size();
    vector<int> trace(n, -1), subIndx, subArr;
    subIndx.push_back(0);
    subArr.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > subArr[subArr.size() - 1]) {
            trace[i] = subIndx[subIndx.size() - 1];
            subIndx.push_back(i);
            subArr.push_back(nums[i]);
        }
        else {
            int idx = lower_bound(subArr.begin(), subArr.end(), nums[i]) - subArr.begin();
            if (idx != 0)
                trace[i] = subIndx[idx - 1];

            subIndx[idx] = i;
            subArr[idx] = nums[i];
        }
    }

    vector<int> path;
    int val = subIndx[subIndx.size() - 1];
    //path.push_back(val);

    while (val != -1) {
        path.push_back(nums[val]);
        val = trace[val];
    }

    reverse(path.begin(), path.end());

    return path;
}


// 300 lis, template
int lis_binarySearch(vector<int>& vec, int num) {
    int left = 0, right = vec.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (vec[mid] >= num)
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int lengthOfLIS(vector<int>& nums) {
    int sz = nums.size();
    if (sz <= 1)
        return sz;

    vector<int> lis;
    lis.push_back(nums[0]);

    for (int i = 1; i < sz; i++) {
        if (lis.back() < nums[i])
            lis.push_back(nums[i]);
        else {
            int idx = lis_binarySearch(lis, nums[i]);
            lis[idx] = nums[i];
        }
    }

    return lis.size();
}

// 334
bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3)
        return false;

    int a = nums[0], b = INT32_MAX;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > b)
            return true;
        else if (nums[i] > a && nums[i] < b)
            b = nums[i];
        else if (nums[i] < a)
            a = nums[i];
    }

    return false;
}

// 300
int lengthOfLIS2(vector<int>& nums) {
    int sz = nums.size(), mxLenLis = 1;
    vector<int> lis(sz, 1);

    for (int i = 1; i < sz; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
                mxLenLis = max(mxLenLis, lis[i]);
            }
        }
    }

    return mxLenLis;
}

void recurPermutation4(vector<int>& nums, vector<vector<int>>& result, int i, int n) {
    if (i == n) {
        result.push_back(nums);
        return;
    }

    for (int j = i; j <= n; j++) {
        swap(nums[i], nums[j]);
        recurPermutation4(nums, result, i + 1, n);
        swap(nums[i], nums[j]);
    }

}

vector<vector<int>> permute4(vector<int>& nums) {
    vector<vector<int>> result;
    recurPermutation4(nums, result, 0, nums.size() - 1);

    return result;
}

// 78
void backtrack_subset(vector<vector<int>>& ansList, vector<int>& tmpList, vector<int>& nums, int start) {
    ansList.push_back(tmpList);

    for (int i = start; i < nums.size(); i++) {
        tmpList.push_back(nums[i]);

        backtrack_subset(ansList, tmpList, nums, i + 1);

        tmpList.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ansList;
    sort(nums.begin(), nums.end());
    vector<int> tmpList;
    backtrack_subset(ansList, tmpList, nums, 0);
    return ansList;
}

// 1657
bool closeStrings(string word1, string word2) {
    unordered_map<int, int> occurrence_count, w1_count, w2_count;
    if (word1.size() != word2.size())
        return false;

    for (auto c : word1)
        w1_count[c - 'a']++;

    for (auto cnt1 : w1_count)
        occurrence_count[cnt1.second]++;

    for (auto c : word2) {
        if (!w1_count[c - 'a'])
            return false;
        w2_count[c - 'a']++;
    }

    for (auto cnt2 : w2_count)
        occurrence_count[cnt2.second]--;

    for (auto occ : occurrence_count)
        if (occ.second != 0)
            return false;


    return true;
}

// 2095
ListNode* deleteMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    if (!head->next)
        return head->next;

    while (slow->next && fast->next && fast->next->next && fast->next->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }


    slow->next = slow->next->next;
    return head;
}

// 1071
int getGcDofStrings(int a, int b) {
    if (a % b == 0)
        return b;
    return getGcDofStrings(b % a, a);
}

string gcdOfStrings(string str1, string str2) {
    int sz1 = str1.size(), sz2 = str2.size();
    int ansLen = getGcDofStrings(sz1, sz2);
    string ans = "";

    for (int i = 0, j = 0, x = 0; i < max(sz1, sz2); i++, j++) {
        if (j == sz2)
            j = 0;
        if (i < sz1 && j < sz2 && str1[i] != str2[j])
            return "";

        if (i < ansLen)
            ans += str1[i];


        if (i >= ansLen && i < sz1 && str1[i] != ans[i % ansLen]) {
            return "";
        }
        if (i >= ansLen && i < sz2 && str2[i] != ans[i % ansLen]) {
            return "";
        }

    }

    return ans;
}

string mergeAlternately(string word1, string word2) {
    string ans = "";
    int i = 0;

    while (i < word1.size() || i < word2.size()) {
        if (i < word1.size())
            ans += word1[i];
        if (i < word2.size())
            ans += word2[i];
        i++;
    }

    return ans;
}

string mergeAlternately2(string word1, string word2) {
    string ans = "";

    for (int i = 0, x = 0, y = 0; i < word1.size() + word2.size(); i++) {
        if (i % 2 == 0) {
            if (x < word1.size())
                ans += word1[x++];
            else
                ans += word2[y++];
        }
        else {
            if (y < word2.size())
                ans += word2[y++];
            else
                ans += word1[x++];
        }
    }

    return ans;
}

void recurPermutation(vector<int>& nums, vector<vector<int>>& result, int i, int n) {
    if (i == n) {
        result.push_back(nums);
        return;
    }

    for (int j = i; j <= n; j++) {
        swap(nums[i], nums[j]);
        recurPermutation(nums, result, i + 1, n);
        swap(nums[i], nums[j]);
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    recurPermutation(nums, result, 0, nums.size() - 1);

    return result;
}

void recursePermute(vector<int>& sofar, vector<int>& nums, vector<vector<int>>& ans, int sz) {
    if (sz == sofar.size()) {
        ans.push_back(sofar);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        sofar.push_back(nums[i]);
        vector<int> new_choices(nums);
        new_choices.erase(new_choices.begin() + i);

        recursePermute(sofar, new_choices, ans, sz);

        sofar.pop_back();
    }
}

vector<vector<int>> permute3(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> sofar;
    recursePermute(sofar, nums, ans, nums.size());
    return ans;
}

vector<vector<int>> permute2(vector<int>& nums) {
    int sz = nums.size();
    vector<vector<int>> ans;
    if (sz <= 1) {
        ans.push_back(nums);
        return ans;
    }

    vector<int> vec;
    vec.push_back(nums[0]);
    ans.push_back(vec);


    for (int i = 1; i < sz; i++) {
        vector<vector<int>> tmp;
        while (!ans.empty()) {
            auto v = ans.back();
            ans.pop_back();

            for (int j = 0; j <= i; j++) {
                vector<int> vt(v);
                vt.insert(vt.begin() + j, nums[i]);
                tmp.push_back(vt);
            }
        }
        ans = tmp;
    }

    return ans;
}

// https://leetcode.com/problems/largest-number/discuss/53298/Python-different-solutions-(bubble-insertion-selection-merge-quick-sorts)
string largestNumber(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            string a = to_string(nums[j]) + to_string(nums[j + 1]), b = to_string(nums[j + 1]) + to_string(nums[j]);
            if (a < b) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    string ans = "";
    for (int i = 0; i < n; i++)
        ans += to_string(nums[i]);

    return ans;
}

// 179
// https://leetcode.com/problems/largest-number/discuss/53298/Python-different-solutions-(bubble-insertion-selection-merge-quick-sorts)
/*
string largestNumber2(vector<int>& nums) {
    int n = nums.size();
    vector<string> nStr(n);

    for (int i = 0; i < n; i++) {
        nStr.push_back(to_string(nums[i]));
    }

    sort(nStr.begin(), nStr.end(), [](const string s1, const string s2) {
        if (s1 + s2 > s2 + s1)
            return s1;
        else
            return s2;
        });
    string ans = "";

    for (int i = n - 1; i >= 0; i--) {
        ans += nStr[i];
    }

    return ans;
}*/

// 1615
int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<vector<int>> adj(n);
    vector<vector<int>> isConn(n, vector<int>(n, 0));

    for (int i = 0; i < roads.size(); i++) {
        int x = roads[i][0], y = roads[i][1];
        adj[y].push_back(x);
        adj[x].push_back(y);
        isConn[x][y] = 1, isConn[y][x] = 1;
    }

    int max_rank = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cur_rank = adj[i].size() + adj[j].size();
            if (isConn[i][j])
                cur_rank--;

            max_rank = max(max_rank, cur_rank);
        }
    }



    return max_rank;
}


// 849
int maxDistToClosest(vector<int>& seats) {
    int cur = 1, mx = 0;
    bool st = true;

    for (auto seat : seats) {
        if (seat) {
            if (st)
                mx = max(cur - 1, mx), st = false;
            else
                mx = max(cur / 2, mx);

            cur = 1;
        }
        else
            cur++;
    }

    return max(cur - 1, mx);
}

/*
int recurMinOperations(vector<int>& nums, int x, int l, int r) {
    if (x < 0) return 10001;
    else if (x == 0) return 0;
    else
        return min(1 + (l < nums.size()) ? recurMinOperations(nums, x-nums[l], l+1, r) : 10001,
            1 + (r >= 0) ? recurMinOperations(nums, x-nums[r], l, r-1) : 10001);
}*/

// 1658

int minOperations(vector<int>& nums, int x) {
    long long tot = accumulate(nums.begin(), nums.end(), 0);
    int sz = nums.size();
    long long rem = tot - x;
    int maxWindow = 0, curWindow = 0, curSum = 0;

    if (tot == x) return sz;
    if (tot > x) return -1;

    curSum = nums[0];
    for (int i = 0, j = 1; j < sz; ) {
        if (curSum == rem)
            maxWindow = max(maxWindow, j - i);

        if (curSum <= rem)
            curSum += nums[j];
        if (curSum > rem)
            curSum -= nums[i++];
        if (curSum == rem)
            maxWindow = max(maxWindow, j - i + 1);
    }

    return maxWindow == 0 ? -1 : sz - maxWindow;
}

int recurMinOperations(vector<int>& nums, vector<vector<int>>& dp, int x, int l, int r) {
    if (l >= nums.size() || r < 0)
        return 10001;
    if (dp[l][r] >= 0)
        return dp[l][r];
    else if (x < 0) return 10001;
    else if (x == 0) return 0;
    else {
        dp[l][r] = min(1 + recurMinOperations(nums, dp, (l < nums.size()) ? x - nums[l] : -1, l + 1, r), 1 + recurMinOperations(nums, dp, (r >= 0) ? x - nums[r] : -1, l, r - 1));
        return dp[l][r];
    }
}

int minOperations_dp_MLError(vector<int>& nums, int x) {
    long long tot = accumulate(nums.begin(), nums.end(), 0);
    int sz = nums.size();
    // cout << sz << endl;

    if (tot == x) return sz;
    if (x > tot) return -1;

    vector<vector<int>> dp(sz, vector<int>(sz, -1));
    int ops = recurMinOperations(nums, dp, x, 0, sz - 1);
    return ops > 10001 ? -1 : ops;
}

// 2487
ListNode* removeNodes2(ListNode* head) {
    ListNode dummy(INT_MAX);
    vector<ListNode*> st{ &dummy };

    for (auto cur = head; cur != nullptr; cur = cur->next) {
        while (st.back()->val < cur->val)
            st.pop_back();
        st.back()->next = cur;
        st.push_back(cur);
    }

    return dummy.next;
}

ListNode* removeNodes(ListNode* head) {
    if (!head) return head;

    head->next = removeNodes(head->next);
    return head->next && head->val < head->next->val ? head->next->next : head->next;
}

// 1382
void inOrderBalancedTree(TreeNode* root, vector<int>& v) {
    if (!root)
        return;
    inOrderBalancedTree(root->left, v);
    v.push_back(root->val);
    inOrderBalancedTree(root->right, v);
}

TreeNode* buildTreeToBalanceBST(vector<int>& v, int l, int r) {
    if (l < 0 || r > v.size() || l > r)
        return NULL;

    int mid = l + (r - l) / 2;
    TreeNode* root = new TreeNode(v[mid]);
    root->left = buildTreeToBalanceBST(v, l, mid - 1);
    root->right = buildTreeToBalanceBST(v, mid + 1, r);
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> v;
    inOrderBalancedTree(root, v);

    int l = 0, r = v.size() - 1;

    TreeNode* a = buildTreeToBalanceBST(v, l, r);

    return a;
}

// 18
string vectorToString(vector<int>& v) {
    string res = "";
    for (auto i : v)
        res += i;
    return res;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    unordered_set<string> ust;

    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            long long rest = (target * 1ll) - (nums[i] + nums[j]);
            int low = j + 1, high = n - 1;

            while (low < high) {
                if (nums[low] + nums[high] > rest)
                    high--;
                else if (nums[low] + nums[high] < rest)
                    low++;
                else {
                    vector<int> temp = { nums[i], nums[j], nums[low], nums[high] };
                    sort(temp.begin(), temp.end());
                    string vs = vectorToString(temp);
                    if (!ust.count(vs))
                        ans.push_back(temp);
                    ust.insert(vs);
                    low++;
                }
            }
        }
    }

    return ans;
}

// 417
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int r = heights.size(), c = heights[0].size();
    vector<vector<int>> vec(r, vector<int>(c, 0));
    vector<vector<int>> ans;
    queue<pair<int, int>> q;

    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    // for pacific ocean represent 1
    for (int i = 0; i < r; i++)
        q.push({ i, 0 });

    for (int i = 0; i < c; i++)
        q.push({ 0, i });

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        vec[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];

            if (xx >= 0 && xx < r && yy >= 0 && yy < c
                && !vec[xx][yy] && heights[x][y] <= heights[xx][yy])
                q.push({ xx, yy });
        }
    }

    for (int i = 0; i < r; i++)
        q.push({ i, c - 1 });
    for (int i = 0; i < c; i++)
        q.push({ r - 1, i });

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (vec[x][y] == 1)
            ans.push_back({ x, y });
        vec[x][y] = 2;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];

            if (xx >= 0 && xx < r && yy >= 0 && yy < c
                && vec[xx][yy] != 2 && heights[x][y] <= heights[xx][yy])
                q.push({ xx, yy });
        }
    }

    return ans;
}

// 1306
unordered_set<int> visCanReach;
bool canReach(vector<int>& arr, int start) {
    if (start >= arr.size() || start < 0) return false;
    else if (arr[start] == 0) return true;
    else if (visCanReach.count(start)) return false;
    visCanReach.insert(start);

    return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
}

// 2875
int binarySearchMinSizeSubArray(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int minSizeSubarray(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int cnt = 0;

    while (target > 0) {
        int findIdx = binarySearchMinSizeSubArray(nums, target);
        if (nums[findIdx] > target)
            return -1;

        cnt += (target / nums[findIdx]);
        target %= nums[findIdx];
    }

    return target == 0 ? cnt : -1;
}

// 2874
long long maximumTripletValue(vector<int>& nums) {
    int sz = nums.size();
    vector<int> pre_max(sz, 0), suf_max(sz, 0);

    pre_max[0] = nums[0];
    for (int i = 1; i < sz; i++)
        pre_max[i] = max(pre_max[i - 1], nums[i]);

    suf_max[sz - 1] = nums[sz - 1];
    for (int i = sz - 2; i >= 0; i--)
        suf_max[i] = max(suf_max[i + 1], nums[i]);

    long long res = 0;
    for (int j = 1; j < sz - 1; j++) {
        res = max(res, ((pre_max[j - 1] - nums[j]) * 1LL * suf_max[j + 1]));
    }

    return res;
}

// 2895
int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
    sort(processorTime.begin(), processorTime.end());
    sort(tasks.begin(), tasks.end(), greater<int>());

    int max_time = 0;
    for (int i = 0; i < processorTime.size(); i++) {
        max_time = max(processorTime[i] + tasks[i * 4], max_time);
    }
    return max_time;
}

// 2894
int differenceOfSums(int n, int m) {
    int k = n / m;
    int num2 = ((k * (1 + k)) / 2) * m;
    int tot_sum = (n * (n + 1)) / 2;
    int num1 = tot_sum - num2;
    return num1 - num2;
}

int differenceOfSums_BruteForce(int n, int m) {
    int total_sum = (n * (n + 1)) / 2, num1 = 0, num2 = 0;

    for (int i = m; i <= n; i += m)
        num2 += i;
    num1 = total_sum - num2;
    return num1 - num2;
}

TreeNode* prevNode = new TreeNode(INT_MIN);
TreeNode* firstNode = NULL;
TreeNode* secNode = NULL;
TreeNode* lastNode = NULL;

void SwapNodeVal(TreeNode* node1, TreeNode* node2) {
    if (!node1 || !node2) {
        cout << "dhukse" << endl;
        return;
    }

    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;
}

// 2811
bool isSpliArray = false;
bool recurCanSplitArray(vector<int>& nums, vector<vector<int>>& dp, int start, int end, int sum, int m) {
    if (isSpliArray)
        return true;

    if (dp[start][end - 1] != -1)
        return dp[start][end] == 1 ? true : false;

    if (sum < m) {
        dp[start][end - 1] = 0;
        return false;
    }

    if (end - start <= 2) {
        isSpliArray = true;
        dp[start][end - 1] = 1;
        return true;
    }
    bool left = recurCanSplitArray(nums, dp, start + 1, end, sum - nums[start], m);
    bool right = recurCanSplitArray(nums, dp, start, end - 1, sum - nums[end - 1], m);

    if (left || right)
        dp[start][end - 1] = 1;
    else
        dp[start][end - 1] = 0;

    return dp[start][end - 1];
}


bool canSplitArray(vector<int>& nums, int m) {
    int sz = nums.size();
    if (sz <= 2)
        return true;
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum < m)
        return false;

    vector<vector<int>> dp(sz, vector<int>(sz, -1));
    return recurCanSplitArray(nums, dp, 0, sz, sum, m);
}


// 2685
// by disjoint set union
int findParent_CountCompleteComponents(int x, vector<int>& parent) {
    if (x == parent[x])
        return x;
    return parent[x] = findParent_CountCompleteComponents(parent[x], parent);
}

void union_CountCompleteComponents(int u, int v, vector<int>& size, vector<int>& parent) {
    if (size[u] < size[v]) {
        parent[u] = v;
        size[v] += size[u];
    }
    else {
        parent[v] = u;
        size[u] += size[v];
    }
}

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<int> parent(n), size(n, 1);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        int u1 = findParent_CountCompleteComponents(u, parent);
        int v1 = findParent_CountCompleteComponents(v, parent);

        if (u1 != v1)
            union_CountCompleteComponents(u1, v1, size, parent);
    }

    int z = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            int z1 = size[i];
        }
    }

    return 0;
}

void dfsCountCompleteComponents(vector<vector<int>>& graph, int cur, vector<int>& vis, int& node, int& edge) {
    if (vis[cur]) return;

    vis[cur] = 1;
    node++;
    edge += graph[cur].size();

    for (auto neigh : graph[cur]) {
        if (vis[neigh]) continue;

        dfsCountCompleteComponents(graph, neigh, vis, node, edge);
    }
}

int countCompleteComponents4(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0);

    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    queue<int> q;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i])
            continue;
        int node = 0, edge = 0;
        dfsCountCompleteComponents(adj, i, vis, node, edge);
        cnt += node * (node - 1) == edge;
    }

    return cnt;
}


int countCompleteComponents1(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0);

    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    queue<int> q;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            q.push(i);
            vis[i] = 1;
            int con_nodes = adj[i].size();
            bool is_connected = true;
            int num_of_nodes = 0;

            while (!q.empty())
            {
                int cur = q.front(); q.pop();
                num_of_nodes++;

                if (is_connected && adj[cur].size() != con_nodes)
                    is_connected = false;

                for (auto nei : adj[cur]) {
                    if (!vis[nei]) {
                        q.push(nei);
                        vis[nei] = 1;
                    }
                }
            }
            if (num_of_nodes - 1 == con_nodes && is_connected)
                cnt++;
        }
    }

    return cnt;
}

// 94
vector<int> inorderTraversal(TreeNode* root) {
    // by morris traversal
    TreeNode* cur = root;
    vector<int> ans;
    while (cur) {
        if (!cur->left) {
            ans.push_back(cur->val);
            cur = cur->right;
        }
        else {
            TreeNode* predeccessor = cur->left;
            while (predeccessor->right != cur && predeccessor->right != NULL)
                predeccessor = predeccessor->right;

            if (predeccessor->right == cur) {
                predeccessor->right = NULL;
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else {
                predeccessor->right = cur;
                cur = cur->left;
            }
        }
    }

    return ans;
}

void recoverTreeInOrder(TreeNode* root) {
    if (!root) return;
    recoverTreeInOrder(root->left);

    cout << "val: " << endl;

    if (firstNode == NULL && prevNode && prevNode->val > root->val) {
        firstNode = prevNode;
        secNode = root;
    }
    else if (firstNode && prevNode->val > root->val)
        secNode = root;

    prevNode = root;
    recoverTreeInOrder(root->right);
}

void recoverTree(TreeNode* root) {
    if (!root) return;
    recoverTreeInOrder(root);

    if (!secNode)
        secNode = prevNode;

    SwapNodeVal(firstNode, secNode);
}

// 1381
class CustomStack {
    vector<int> vec;
    int top = -1, sz = 0;
public:
    CustomStack(int maxSize) : vec(maxSize, -1) {
        sz = maxSize;
    }

    void push(int x) {
        if (top >= sz - 1)
            return;

        vec[++top] = x;
    }

    int pop() {
        if (top < 0)
            return -1;
        return vec[top--];
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, sz); i++) {
            vec[i] += val;
        }
    }
};

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int left[10], right[10];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + j + 1];

    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

// 2391
int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int m = 0, g = 0, p = 0;

    for (int i = garbage.size() - 1; i >= 0; i--) {
        for (auto c : garbage[i]) {
            switch (c)
            {
            case 'M':
                m++;
                break;
            case 'P':
                p++;
                break;
            case 'G':
                g++;
                break;
            }
        }

        m += m > 0 ? travel[i - 1] : 0;
        p += p > 0 ? travel[i - 1] : 0;
        g += g > 0 ? travel[i - 1] : 0;
    }

    return m + p + g;
}

// 24                          1 3 4            2 3 4   
ListNode* swapTwoNodes(ListNode* node1, ListNode* node2) {
    node1->next = node1->next->next;
    node2->next = node1;
    return node2;
}

ListNode* swapPairs(ListNode* head) {
    ListNode* newHead = new ListNode(0);
    newHead->next = head;

    ListNode* cur = newHead;

    while (cur && cur->next)
    {
        cur->next = swapTwoNodes(cur->next, cur->next->next);
        cur = cur->next->next;
    }


    return newHead->next;
}

ListNode* swapPairs2(ListNode* head) {
    ListNode* newHead = new ListNode(0);
    newHead->next = head;

    ListNode* cur = newHead;

    while (cur && cur->next)
    {
        // 0 -> 1 -> 2 -> 3 -> 4
        // 0 2 3 4             1 3 4
        auto temp = cur->next; // 1

        cur->next = cur->next->next;
        temp->next = cur->next->next;
        auto temp2 = cur->next;
        temp2->next = temp;
        cur->next = temp2;
        cur = cur->next->next;
    }


    return newHead->next;
}

// 2808
int minimumSeconds(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]].push_back(i);
    }

    int n = nums.size() - 1;
    int mn = INT32_MAX;
    for (auto kvp : mp) {
        int sz = kvp.second.size() - 1;
        int mx_cnt = ((kvp.second[0] - 0) + (n - kvp.second[sz]) + 1) / 2;
        for (int i = 1; i <= sz; i++) {
            int cnt = ((kvp.second[i] - kvp.second[i - 1]) / 2);
            mx_cnt = max(mx_cnt, cnt);
        }
        mn = min(mx_cnt, mn);
    }

    return mn;
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* cur = head;
    ListNode* temp = NULL;

    while (cur && cur->next) {
        int gcd_val = gcd(cur->val, cur->next->val);
        temp = cur->next;
        ListNode* node = new ListNode(gcd_val);

        node->next = temp;
        cur->next = node;
        cur = cur->next->next;
    }

    return head;
}

int accountBalanceAfterPurchase(int purchaseAmount) {
    double r = round((double)purchaseAmount / 10);
    cout << r << endl;
    int rnd = round(r);
    rnd *= 10;

    return 100 - rnd;
}

// 1769
vector<int> minOperations(string boxes) {
    int n = boxes.size();

    vector<int> pre(n, 0), post(n, 0);
    int oneCnt = 0;

    for (int i = 1; i < n; i++) {
        if (boxes[i - 1] == '1')
            ++oneCnt;

        pre[i] = pre[i - 1] + oneCnt;
    }

    oneCnt = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (boxes[i + 1] == '1')
            ++oneCnt;

        post[i] = post[i + 1] + oneCnt;
    }

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        ans[i] = pre[i] + post[i];
    }

    return ans;
}

// 206
ListNode* recursive_reverseList(ListNode* head, ListNode* newHead) {
    if (head == NULL)
        return newHead;
    ListNode* temp = head->next;
    head->next = newHead;
    newHead = head;
    recursive_reverseList(temp, newHead);
}

ListNode* reverseList(ListNode* head) {
    ListNode* newHead = NULL;
    return recursive_reverseList(head, newHead);
}

ListNode* reverseList2(ListNode* head) {
    ListNode* cur = head;
    ListNode* prev = NULL;
    ListNode* temp = head;

    while (cur->next) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    return cur;
}

// 142
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (!fast || !fast->next)
        return NULL;

    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}

// 160
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return 0;

    ListNode* nodeA = headA;
    ListNode* nodeB = headB;

    while (nodeA != nodeB) {
        nodeA = nodeA->next ? nodeA->next : headB;
        nodeB = nodeB->next ? nodeB->next : headA;
    }

    return nodeA;
}

// 876
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// 111
int minDepth(TreeNode* root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    left = left == 0 ? INT_MAX : left;
    right = right == 0 ? INT_MAX : right;

    return 1 + min(left, right);
}

// 104
int maxDepth(TreeNode* root) {
    if (!root)
        return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


// 2529
int maximumCount(vector<int>& nums) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > 0)
            right = mid;
        else
            left = mid + 1;
    }

    int posNumbers = nums.size() - left;

    while (left > 0 && nums[left - 1] >= 0) {
        left--;
    }


    return max(left, posNumbers);
}

//198
int rob(vector<int>& nums) {
    int odd = nums[0], eve = 0;

    for (int i = 0; i < nums.size(); i++) {
        if ((i + 1) % 2)
            odd = nums[i] + max(odd, (eve - nums[i - 1]));
        else
            eve = nums[i] + max(eve, (odd - nums[i - 1]));
    }

    return max(odd, eve);
}

// 2786

long long maxScore(vector<int>& n, int x) {
    long long odd = n[0] - (n[0] % 2) ? 0 : x;
    long long eve = n[0] - (n[0] % 2) ? x : 0;

    for (int i = 1; i < n.size(); i++) {
        if (n[i] % 2)
            odd = n[i] + max(odd, eve - x);
        else
            eve = n[i] + max(eve, odd - x);
    }

    return max(odd, eve);
}

long long maxScore2(vector<int>& nums, int x) {
    long long val = 0;
    vector<int> vec;
    vec.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++) {
        int last = vec.back(); vec.pop_back();

        if (last % 2 == nums[i] % 2) {
            vec.push_back(last + nums[i]);
        }
        else {
            vec.push_back(last);
            vec.push_back(nums[i]);
        }
    }

    val += nums[0];
    for (int i = 1; i < vec.size(); i++) {
        if (i % 2 && nums[i] - x > 0)
            val += nums[i];
    }

    return val;
}

string sortVowels(string s) {
    unordered_set<char> vow{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    vector<int> vec;

    for (auto c : s) {
        if (vow.count(c))
            vec.push_back(int(c));
    }

    sort(vec.begin(), vec.end());
    int v = 0;
    string ans = "";

    for (auto c : s) {
        if (vow.count(c))
            ans += char(vec[v++]);
        else
            ans += c;
    }

    return ans;
}


bool isGood(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    if (n == 1)
        return false;

    for (int i = 0; i < n - 1; i++)
        if (nums[i] != i + 1)
            return false;

    if (nums[n - 1] != nums[n - 2] && nums[n - 1] != n - 1)
        return false;

    return true;
}


int maxResult(vector<int>& nums, int k) {
    deque<int> dq;
    int res[6];

    for (int i = 0; i < nums.size(); i++)
    {
        while (!dq.empty() && i - dq.front() > k)
            dq.pop_front();

        res[i] = dq.empty() ? nums[i] : nums[i] + res[dq.front()];

        while (!dq.empty() && res[dq.back()] < res[i])
            dq.pop_back();
        dq.push_back(i);
    }


    return res[nums.size() - 1];
}

// 45
int jump(vector<int>& nums) {
    int cnt = 0, n = nums.size();
    if (n <= 2)
        return n;

    for (int i = 0; i < n; i++) {
        int len = i + nums[i] + 1;
        len = min(len, n);
        if (len == n)
            return cnt + 1;
        int mx = -1;
        for (int j = i + 1; j < len; j++) {
            if (j + nums[j] >= mx) {
                mx = j + nums[j];
                i = j - 1;
            }
        }
        cnt++;
    }
    return cnt - 1;
}

int minimumBeautifulSubstrings2(string s) {
    int n = s.length();
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        for (int j = i, cur = 0; j < n; j++) {
            cur = cur * 2 + s[j] - '0';
            if (15625 % cur == 0)
                dp[j + 1] = min(dp[j + 1], dp[i] + 1);
        }
    }
    return dp[n] > n ? -1 : dp[n];
}

int minimumBeautifulSubstrings(string s) {
    vector<string> pats{ "11110100001001", "110000110101", "1001110001", "1111101", "11001", "101", "1" };
    int cnt = 0;

    for (int i = 0; i < pats.size(); i++) {
        while (true) {
            size_t pos = s.find(pats[i]);

            if (pos != string::npos && (pos == 0 || s[pos - 1] != '0')) {
                s.replace(s.find(pats[i]), pats[i].length(), "2");
                cnt++;
            }
            else
                break;
        }
    }
    for (auto c : s)
        if (c == '0')
            return -1;

    return cnt == 0 ? -1 : cnt;
}

// https://leetcode.com/contest/biweekly-contest-108/problems/partition-string-into-minimum-beautiful-substrings/

// 6469
vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
    unordered_set<int> st;
    for (auto num : nums)
        st.insert(num);

    for (int i = 0; i < moveFrom.size(); i++) {
        if (st.count(moveFrom[i])) {
            st.erase(moveFrom[i]);
            st.insert(moveTo[i]);
        }
    }

    vector<int> ans;

    for (auto s : st)
        ans.push_back(s);

    sort(ans.begin(), ans.end());
    return ans;
}

struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int>& v) const {
        return v.first * 31 + v.second;
    }
};

vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
    vector<long long> vec(5, 0);
    vector<vector<int>> grid(m, vector<int>(n, 0));

    for (auto v : coordinates)
        grid[v[0]][v[1]] = 1;

    for (int i = 0; i < m - 1; i++) {

        for (int j = 0; j < n - 1; j++) {
            int cnt = 0;
            if (grid[i][j]) cnt++;
            if (grid[i + 1][j]) cnt++;
            if (grid[i][j + 1]) cnt++;
            if (grid[i + 1][j + 1]) cnt++;
            vec[cnt]++;
        }

    }
    return vec;
}

vector<long long> countBlackBlocks_2(int m, int n, vector<vector<int>>& coordinates) {
    vector<long long> vec(5, 0);
    unordered_set<pair<int, int>, pair_hash> st;

    for (auto v : coordinates)
        st.insert({ v[0], v[1] });

    for (int i = 0; i < m - 1; i++) {

        for (int j = 0; j < n - 1; j++) {
            int cnt = 0;
            if (st.count({ i, j })) cnt++;
            if (st.count({ i + 1, j })) cnt++;
            if (st.count({ i, j + 1 })) cnt++;
            if (st.count({ i + 1, j + 1 })) cnt++;
            vec[cnt]++;
        }

    }
    return vec;
}

// 6913
int alternatingSubarray(vector<int>& nums) {
    int len = -1, n = nums.size();
    bool isGet = false;

    for (int i = 0; i < n; i++) {
        int cur = 1;
        isGet = false;
        int j = i + 1;
        for (; j < n; j++) {
            if ((nums[j] - nums[j - 1]) == cur) {
                isGet = true;
                cur = cur * (-1);
            }
            else
                break;
        }
        len = isGet ? max(len, j - i) : len;
    }

    return len;
}

// 934
int shortestBridge(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> cal(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    vector<pair<int, int>> one_group;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                q.push({ i, j });
                cal[i][j] = 0;
                i = m;
                break;
            }
        }
    }

    while (!q.empty())
    {
        auto top = q.front(); q.pop();
        one_group.push_back(top);

        for (int i = 0; i < 4; i++) {
            int x = top.first + dx[i], y = top.second + dy[i];
            if (x < 0 || y < 0 || x >= m || y >= n)
                continue;
            else if (grid[x][y] && cal[x][y] == -1) {
                q.push({ x, y });
                cal[x][y] = 0;
            }
        }
    }

    for (auto one : one_group)
        q.push(one);

    int cnt = -1;
    while (!q.empty()) {
        int sz = q.size();
        cnt++;

        while (sz--) {
            auto top = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int x = top.first + dx[i], y = top.second + dy[i];
                if (x < 0 || y < 0 || x >= m || y >= n)
                    continue;
                if (cal[x][y] == -1) {
                    if (!grid[x][y]) {
                        q.push({ x, y });
                        cal[x][y] = 0;
                    }
                    else
                        return cnt;
                }
            }
        }
    }
    return cnt;
}


class UnionFindTemplate
{
    vector<int> parent, rank;
public:
    UnionFindTemplate() {

    }

    int find(int u) {
        if (u = parent[u])
            return u;

        return parent[u] = find(parent[u]);
    }

    void combine(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (rank[u] > rank[v]) {      // shoshomoi chotor abbu change hye jabe
            parent[v] = u;
            rank[u] += rank[v];       // can be used rank[u]++  otherwise this can be overflown easily
        }
        else {
            parent[u] = v;
            rank[v] += rank[u];
        }
    }
};

// 1765
vector<vector<int>> highestPeak(vector<vector<int>>& maze) {
    int m = maze.size(), n = maze[0].size();
    vector<vector<int>> ans(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    int steps = 0;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            if (maze[i][j])
                q.push({ i, j }), ans[i][j] = 0;
    }

    while (!q.empty()) {
        int sz = q.size();
        steps++;

        while (sz--) {
            auto top = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int x = top.first + dx[i], y = top.second + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    q.push({ x, y });
                    ans[x][y] = steps;
                }
            }
        }
    }

    return ans;
}

// 1926
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size(), n = maze[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    int steps = 0;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    q.push({ entrance[0], entrance[1] });
    vis[entrance[0]][entrance[1]] = 1;

    while (!q.empty()) {
        int sz = q.size();
        steps++;

        while (sz--) {
            auto top = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int x = top.first + dx[i], y = top.second + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && maze[x][y] == '.') {
                    q.push({ x, y });
                    vis[x][y] = 1;
                    if ((x != entrance[0] || y != entrance[1]) && (x == 0 || y == 0 || x == m - 1 || y == n - 1))
                        return steps;
                }
            }
        }
    }

    return -1;
}

// 310
vector<int> dfs_findMHT(vector<vector<int>>& graph, vector<bool>& vis, int cur) {
    vector<int> longestPath, path;
    vis[cur] = true;

    for (auto adj : graph[cur])
        if (!vis[adj])
            if (size(path = dfs_findMHT(graph, vis, adj)) > size(longestPath))
                longestPath = move(path);

    vis[cur] = false;
    longestPath.push_back(cur);
    return longestPath;
}

vector<int> findMinHeightTrees_byDFS(int n, vector<vector<int>>& edges) {
    vector<int> vec;
    int sz = vec.size();
    int sz1 = size(vec);
    if (n == 1) return { 0 };
    vector<vector<int>> graph(n);
    vector<bool> vis(n);

    for (auto edge : edges)
        graph[edge[0]].push_back(edge[1]),
        graph[edge[1]].push_back(edge[0]);

    auto path = dfs_findMHT(graph, vis, dfs_findMHT(graph, vis, 0)[0]);
    if (size(path) % 2)
        return { path[size(path) / 2] };

    return { path[size(path) / 2], path[size(path) / 2 - 1] };
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return { 0 };
    vector<int> indg(n, 0);
    vector<vector<int>> adj(n);
    queue<int> q;
    int cnt = n;

    for (auto edge : edges) {
        int a = edge[0], b = edge[1];
        indg[a]++, indg[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (indg[i] == 1) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int sz = q.size();
        if (cnt <= 2) {
            while (!q.empty())
            {
                ans.push_back(q.front()); q.pop();
            }
            break;
        }

        for (int i = 0; i < sz; i++) {
            int top = q.front(); q.pop();
            cnt--;

            for (auto node : adj[top]) {
                if (--indg[node] == 1)
                    q.push(node);
            }
        }

    }

    return ans;
}

// 1466
int minReorder(int n, vector<vector<int>>& connections) {
    unordered_set<pair<int, int>, pair_hash> st;
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0);

    for (auto v : connections) {
        st.insert({ v[0], v[1] });
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }

    queue<int> q;
    int cnt = 0;
    q.push(0);

    while (!q.empty()) {
        int top = q.front(); q.pop();
        vis[top] = 1;

        for (auto node : adj[top]) {
            if (!vis[node]) {
                q.push(node);
                if (!st.count({ top, node }))
                    cnt++;
            }
        }
    }
    return cnt;
}

// 133
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
void dfs_toCloneGraph(Node* node, Node* root, unordered_map<int, Node*>& mp, unordered_set<int>& vis) {
    if (!node || node->neighbors.empty() || vis.count(node->val))
        return;

    vis.insert(node->val);
    for (Node* neigh : node->neighbors) {
        if (!mp.count(neigh->val)) {
            Node* newNode = new Node(neigh->val);
            mp[newNode->val] = newNode;
            root->neighbors.push_back(newNode);
            dfs_toCloneGraph(neigh, mp[neigh->val], mp, vis);
        }
        else
            root->neighbors.push_back(mp[neigh->val]);


    }
}

Node* cloneGraph(Node* node) {
    if (!node)
        return node;
    Node* root = new Node(node->val);
    if (node->neighbors.empty())
        return root;

    unordered_map<int, Node*> mp;
    unordered_set<int> vis;
    mp[root->val] = root;
    vis.insert(root->val);
    dfs_toCloneGraph(node, root, mp, vis);
    return root;
}

Node* cloneGraph_BFS(Node* node) {
    if (!node)
        return node;
    Node* root = new Node(node->val);
    if (node->neighbors.empty())
        return root;

    queue<Node*> q, nq;
    unordered_map<int, Node*> mp;
    mp[root->val] = root;
    q.push(node);
    nq.push(root);

    while (!q.empty())
    {
        Node* top = q.front(); q.pop();
        Node* newTop = nq.front(); nq.pop();

        for (Node* neigh : top->neighbors) {
            if (!mp.count(neigh->val)) {
                Node* newNode = new Node(neigh->val);
                mp[newNode->val] = newNode;
                newTop->neighbors.push_back(newNode);
                q.push(neigh);
                nq.push(newNode);
            }
            else {
                newTop->neighbors.push_back(mp[neigh->val]);
            }
        }
    }

    return root;
}

// 1129
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<vector<int>> redAdj(n), blueAdj(n);
    vector<int> path(n, -1), visNode(n, 0);
    queue<pair<int, int>> q; // node, color
    int cnt = 0;

    for (auto r : redEdges) { if (r[0] || r[1]) redAdj[r[0]].push_back(r[1]); }
    for (auto b : blueEdges) { if (b[0] || b[1]) blueAdj[b[0]].push_back(b[1]); }

    q.push({ 0, 1 });
    q.push({ 0, 0 });
    path[0] = 0;
    visNode[0]++;

    while (!q.empty()) {
        int sz = q.size();
        cnt++;
        for (int i = 0; i < sz; i++) {
            int cur = q.front().first; int isRed = q.front().second; q.pop();

            if (cur == 3) {
                cout << cur << endl;
            }

            if (isRed) {
                for (int child : redAdj[cur]) {
                    if (visNode[child] < 2) {
                        q.push({ child, 0 });
                        visNode[child]++;
                        if (path[child] == -1) path[child] = cnt;
                    }
                }
            }
            else {
                for (int child : blueAdj[cur]) {
                    if (visNode[child] < 2) {
                        q.push({ child, 1 });
                        visNode[child]++;
                        if (path[child] == -1) path[child] = cnt;
                    }
                }
            }
        }
    }

    return path;
}

// 210
bool dfsFindOrder(int n, vector<vector<int>>& adj, stack<int>& stk,
    vector<int>& vis, vector<int>& curPath, int cur) {
    if (curPath[cur]) return false;
    if (vis[cur]) return true;

    curPath[cur] = vis[cur] = 1;
    for (int i = 0; i < adj[cur].size(); i++) {
        if (!dfsFindOrder(n, adj, stk, vis, curPath, adj[cur][i]))
            return false;
    }

    stk.push(cur);
    curPath[cur] = 0;
    return true;
}

vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<int> vis(n, 0), curPath(n, 0);
    vector<vector<int>> adj(n);
    stack<int> stk;

    for (auto v : prerequisites)
        adj[v[1]].push_back(v[0]);

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!vis[i] && !dfsFindOrder(n, adj, stk, vis, curPath, i))
            return ans;
    }

    while (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}

vector<int> findOrder_BFS(int n, vector<vector<int>>& prerequisites) {
    vector<int> indg(n, 0);
    vector<vector<int>> adj(n);
    queue<int> q;

    for (auto v : prerequisites) {
        adj[v[1]].push_back(v[0]);
        indg[v[0]]++;
    }

    for (int i = 0; i < n; i++)
        if (!indg[i]) q.push(i);

    int cnt = 0;
    vector<int> ans;
    vector<int> emptyVec;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        indg[cur]--; cnt++;

        for (auto neigh : adj[cur])
            if (!--indg[neigh])
                q.push(neigh);
    }

    return cnt == n ? ans : emptyVec;
}

// 207
bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<int> vis(n), indg(n, 0);
    vector<vector<int>> adj(n);
    queue<int> q;

    for (auto v : prerequisites)
        adj[v[1]].push_back(v[0]);

    for (auto childs : adj)
        for (auto child : childs)
            indg[child]++;

    for (int i = 0; i < n; i++) {
        if (!indg[i]) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        vis[cur] = 1;

        for (auto neigh : adj[cur])
            if (!--indg[neigh] && !vis[neigh]) {
                q.push(neigh);
                vis[neigh] = 1;
            }
    }

    int tot = 0;
    for (int i = 0; i < n; i++)
        if (vis[i]) tot++;

    return tot == n;
}

bool dfsCanFinish(int n, vector<vector<int>>& adj, int cur, vector<int>& vis, unordered_set<int>& st) {
    if (st.count(cur))
        return false;

    vis[cur] = 1;
    st.insert(cur);

    for (int i = 0; i < adj[cur].size(); i++) {
        int neigh = adj[cur][i];
        if (!dfsCanFinish(n, adj, neigh, vis, st))
            return false;
    }
    st.erase(st.find(cur));
    return true;
}

bool canFinish_dfs(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n);
    for (auto v : prerequisites)
        adj[v[1]].push_back(v[0]);

    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            unordered_set<int> st;
            if (!dfsCanFinish(n, adj, i, vis, st))
                return false;
        }
    }

    return true;
}

vector<int> topoSort(int V, vector<int> adj[])
{
    // bfs approach code here
    stack<int> stk;
    vector<int> vis(V, 0), indg(V, 0), ans;
    queue<int> q;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++)
            indg[adj[i][j]]++;
    }

    for (int i = 0; i < V; i++) {
        if (!indg[i]) {
            q.push(i);
            ans.push_back(i);
            indg[i]--;
        }
    }

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        int sz = adj[cur].size();

        for (int x = 0; x < sz; x++) {
            int child = adj[cur][x];
            if (!--indg[child]) {
                q.push(child);
                ans.push_back(child);
            }
        }
    }

    return ans;
}

void dfsTopoSort(vector<int> adj[], vector<int>& vis, stack<int>& stk, int cur) {
    if (vis[cur])
        return;

    vis[cur] = 1;
    for (int i = 0; i < adj[cur].size(); i++) {
        if (!vis[adj[cur][i]]) dfsTopoSort(adj, vis, stk, adj[cur][i]);
    }

    stk.push(cur);
}

vector<int> topoSort_dfs(int V, vector<int> adj[])
{
    // code here
    stack<int> stk;
    vector<int> vis(V, 0), ans;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) dfsTopoSort(adj, vis, stk, i);
    }

    while (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}

bool isSimilar(string str1, string str2) {
    if (str1.size() != str2.size())
        return false;

    vector<int> charVec(123, 0);

    for (auto c : str1)
        charVec[c]++;

    for (auto c : str2) {
        if (charVec[c] > 0)
            charVec[c]--;
        else
            return false;
    }
    return true;
}


// 886
bool dfsIsPossibleBipartition(vector<int>& color, vector<vector<int>>& graph, int cur, int col) {

    color[cur] = col;
    for (int i = 0; i < graph[cur].size(); i++) {
        if (!color[graph[cur][i]] &&
            !dfsIsPossibleBipartition(color, graph, graph[cur][i], -col))
            return false;
        else if (color[graph[cur][i]] != -col)
            return false;
    }

    return true;
}

bool possibleBipartition_dfsVersion(int n, vector<vector<int>>& dislikes) {
    vector<int> color(n + 1, 0);
    vector<vector<int>> edges(n + 1);
    queue<int> q;

    for (auto dis : dislikes) {
        edges[dis[0]].push_back(dis[1]);
        edges[dis[1]].push_back(dis[0]);
    }

    for (int i = 1; i < n + 1; i++) {
        if (!color[i] && !dfsIsPossibleBipartition(color, edges, i, 1))
            return false;
    }

    return true;
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<int> color(n + 1, 0);
    vector<vector<int>> edges(n + 1);
    queue<int> q;

    for (auto dis : dislikes) {
        edges[dis[0]].push_back(dis[1]);
        edges[dis[1]].push_back(dis[0]);
    }

    for (int i = 1; i < n + 1; i++) {
        if (!color[i]) { q.push(i); color[i] = 1; }

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int cur_col = color[cur];

            for (int j = 0; j < edges[cur].size(); j++) {
                int child = edges[cur][j];
                if (!color[child]) { q.push(child); color[child] = -cur_col; }
                else if (cur_col == color[child]) return false;
            }
        }
    }

    return true;
}

// 785
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, 0);

    queue<int> q;
    int val = pow(2, 2);

    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int x = q.front(); q.pop();
                int x_col = color[x];

                for (int i = 0; i < graph[x].size(); i++) {
                    int y = graph[x][i];
                    if (!color[y]) {
                        q.push(y);
                        color[y] = (-1) * x_col;
                    }
                    else if (color[y] == x_col) return false;
                }
            }
        }

    }

    return true;
}

// 2718
long long matrixSumQueries(int n, vector<vector<int>>& q) {
    int row = n, col = n;
    long long sum = 0;
    vector<int> row_vis(n, 0), col_vis(n, 0);

    for (int i = q.size() - 1; i >= 0; i--) {
        int type = q[i][0], ind = q[i][1], val = q[i][2];

        if (type && !col_vis[ind]) {
            sum += col * val;
            row--;
            col_vis[ind] = 1;
        }

        else if (!type && !row_vis[ind]) {
            sum += row * val;
            col--;
            row_vis[ind] = 1;
        }
    }

    return sum;
}

// 2717
int semiOrderedPermutation(vector<int>& nums) {
    int f_idx = 0, l_idx = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1)
            f_idx = i;

        if (nums[i] == n)
            l_idx = i;

        if (f_idx && l_idx)
            break;
    }

    int ans = f_idx + n - l_idx - 1;

    return f_idx > l_idx ? ans - 1 : ans;
}

// 1091
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int lvl = 0, n = grid.size();
    if (grid[0][0] || grid[n - 1][n - 1]) return -1;
    if (n < 1) return 1;

    vector<vector<int>> vis(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    vis[0][0] = 1;

    int dx[] = { 1,1, 1,-1,-1,-1,0, 0 };
    int dy[] = { 1,0,-1, 1, 0,-1,1,-1 };

    while (!q.empty()) {
        int qsz = q.size();
        lvl++;
        while (qsz--)
        {
            auto [r, c] = q.front(); q.pop();
            for (int i = 0; i < 8; i++) {
                int rd = r + dx[i], cd = c + dy[i];

                if (rd >= 0 && cd >= 0 && rd < n && cd < n && !vis[rd][cd] && !grid[rd][cd]) {
                    if (rd == n - 1 && cd == n - 1)
                        return lvl + 1;
                    q.emplace(rd, cd);
                    vis[rd][cd] = 1;
                }
            }
        }
    }

    return -1;
}

// 994
int orangesRotting(vector<vector<int>>& grid) {
    int mx = -1, m = grid.size(), n = grid[0].size(), fresh = 0;
    vector<vector<int>> mat(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q.emplace(i, j);
                mat[i][j] = 0;
            }
            else if (grid[i][j]) fresh++;
        }
    }

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int rx = r + dx[i], cy = c + dy[i];

            if (rx >= 0 && cy >= 0 && rx < m && cy < n && grid[rx][cy] && mat[rx][cy] == -1) {
                mat[rx][cy] = mat[r][c] + 1;
                mx = max(mx, mat[rx][cy]);
                q.emplace(rx, cy);
                fresh--;
            }
        }
    }

    return fresh > 0 ? -1 : mx;
}

// 1162

int maxDistance(vector<vector<int>>& grid) {
    int mx = -1, m = grid.size(), n = grid[0].size();
    vector<vector<int>> mat(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                q.emplace(i, j);
                mat[i][j] = 0;
            }
        }
    }

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int rx = r + dx[i], cy = c + dy[i];

            if (rx >= 0 && cy >= 0 && rx < m && cy < n && !grid[rx][cy] && mat[rx][cy] == -1) {
                mat[rx][cy] = mat[r][c] + 1;
                mx = max(mx, mat[rx][cy]);
                q.emplace(rx, cy);
            }
        }
    }

    return mx;
}

// 542
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dis(m, vector<int>(n, -1));
    queue<pair<int, int>> q;


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!mat[i][j]) {
                q.emplace(i, j);
                dis[i][j] = 0;
            }
        }
    }

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int x = r + dx[i], y = c + dy[i];
            if (x >= 0 && y >= 0 && x < m && y < n && dis[x][y] == -1) {
                q.emplace(x, y);
                dis[x][y] = dis[r][c] + 1;
            }
        }
    }

    return dis;
}

// 802

bool dfsEventualSafeNodes(vector<vector<int>>& graph, int n, vector<int> vis, int cur) {
    if (vis[cur] == 0) return false;
    if (vis[cur] == 1) return true;

    vis[cur] = 0;

    for (int i = 0; i < graph[cur].size(); i++) {
        if (!dfsEventualSafeNodes(graph, n, vis, graph[cur][i]))
            return false;
    }
    vis[cur] = 1;
    return true;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n, -1);

    for (int i = 0; i < n; i++) {
        if (vis[i] == -1)
            dfsEventualSafeNodes(graph, n, vis, i);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 1) ans.push_back(i);
    }

    return ans;
}

long long minimumCost(string s) {
    int n = s.size();
    vector<long long> ps(n);
    long long ss = 0;
    for (int i = 1; i < n; i += 1) {
        if (s[i - 1] != s[i]) {
            ps[i] += (ps[i - 1] + i);
        }
        else ps[i] = ps[i - 1];
    }
    long long ans = 1e14;
    for (int i = n - 2; i >= 0; i -= 1) {
        if (s[i] != s[i + 1]) ss += (n - i - 1);
        ans = min(ans, ps[i] + ss);
    }
    return min(ans, ss);
}

// Weekly Contest 347
int cntDiagonalVal(vector<vector<int>>& grid, int m, int n, int r, int c, int inc) {
    unordered_set<int> st;

    r = r + inc, c = c + inc;

    while ((r >= 0 && c >= 0) && (r < m && c < n)) {
        st.insert(grid[r][c]);
        r = r + inc, c = c + inc;
    }

    return st.size();
}

vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
    int cnt = 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            int top = cntDiagonalVal(grid, m, n, r, c, -1);
            int bottom = cntDiagonalVal(grid, m, n, r, c, 1);

            ans[r][c] = abs(top - bottom);
        }
    }

    return ans;
}

string removeTrailingZeros(string num) {
    string ans = "";
    int pos = 0;
    int sz = num.size();

    for (int i = num.size() - 1; i >= 0; i--) {
        if (num[i] != '0') {
            pos = i;
            break;
        }
    }

    ans = num.substr(sz - pos);
    return ans;
}

// 733
void dfsFloodFill(vector<vector<int>>& image, int m, int n, int sr, int sc, int color, int cur) {
    if (sr < 0 || sc < 0 || sr >= m || sc >= n) return;
    if (image[sr][sc] != cur) return;
    image[sr][sc] = color;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4; i++)
        dfsFloodFill(image, m, n, sr + dx[i], sc + dy[i], color, cur);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int cur = image[sr][sc];
    int m = image.size(), n = image[0].size();

    if (cur != color)
        dfsFloodFill(image, m, n, sr, sc, color, cur);

    return image;
}

// 200
void dfsNumIsland(vector<vector<char>>& grid, int m, int n, vector<vector<int>>& vis, int i, int j) {
    if (i < 0 || j < 0 || i >= m || j >= n) return;
    int val = grid[i][j] - '0';
    if (!val || vis[i][j]) return;

    vis[i][j] = 1;
    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    for (int x = 0; x < 4; x++) {
        dfsNumIsland(grid, m, n, vis, dx[x] + i, dy[x] + j);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int cnt = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = grid[i][j] - '0';
            if (val && !vis[i][j]) {
                dfsNumIsland(grid, m, n, vis, i, j);
                cnt++;
            }
        }
    }

    return cnt;
}

bool recur_PunishmentNumber(string str, int target) {
    if (str == "" && target == 0) return true;
    else if (target < 0) return false;

    bool ans = false;

    for (int i = 0; i < str.size(); i++) {
        string left = str.substr(0, i + 1);
        string right = str.substr(i + 1);
        int num = stoi(left);

        if (recur_PunishmentNumber(right, target - num)) {
            ans = true;
            break;
        }
    }

    return ans;
}

int punishmentNumber(int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        int val = i * i;
        if (recur_PunishmentNumber(to_string(val), i)) {
            sum += val;
        }
    }

    return sum;
}

long taskOfPairing(vector<long> freq) {
    int cnt = 0;
    cnt += freq[0] / 2;
    freq[0] = freq[0] % 2;

    for (int i = 1; i < freq.size(); i++) {
        if (freq[i] > 0) {
            freq[i] = freq[i] + freq[i - 1];
            cnt += freq[i] / 2;
            freq[i] = freq[i] % 2;
        }
    }

    return cnt;
}

vector<long> findSum(vector<int> numbers, vector<vector<int>> queries) {
    int n = numbers.size();
    vector<long long> pref(n), zeros(n);

    pref.push_back(numbers[0]);
    if (numbers[0] == 0) zeros.push_back(1);
    else zeros.push_back(0);

    for (int i = 1; i < n; i++) {
        pref[i] = numbers[i] + pref[i - 1];
        zeros[i] = numbers[i] == 0 ? zeros[i - 1] + 1 : zeros[i - 1];
    }

    for (int i = 0; i < n; i++) {
        cout << "p " << pref[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "z " << zeros[i] << " ";
    }
    cout << endl;

    vector<long> ans;
    for (auto v : queries) {
        int l = v[0], r = v[1], x = v[2];

        long val = 0;
        if (l == 0) {
            val = pref[r] + (x * zeros[r]);
        }
        else {
            val = pref[r] - pref[l - 1] + (x * (zeros[r] - zeros[l - 1]));
        }

        ans.push_back(val);
    }
    return ans;
}


string findSubstring(string s, int k) {
    unordered_set<char> vow = { 'a', 'e', 'i', 'o', 'u' };
    int cnt = 0, mx = 0;

    for (int i = 0; i < k; i++) {
        if (vow.count(s[i])) cnt++;
    }

    if (cnt == k)
        return s.substr(0, k);

    mx = cnt;
    int idx = 0;
    for (int i = k; i < s.size(); i++) {
        if (vow.count(s[i - k])) cnt--;
        if (vow.count(s[i])) cnt++;

        if (cnt > mx) {
            mx = cnt;
            idx = i - k + 1;
        }
    }

    if (cnt > mx) {
        idx = s.size() - k + 1;
    }
    if (mx == 0)
        return "Not found!";

    return s.substr(idx, k);
}


int minLength(string s) {
    stack<char> stk;
    stk.push(s[0]);

    for (int i = 1; i < s.size(); i++) {
        char a = stk.top();
        char b = s[i];

        while (!stk.empty() && (a == 'A' && b == 'B') || (a == 'C' && b == 'D')) {
            stk.pop();
            a = stk.top();
            if (i < s.size() - 1)
                b = s[++i];
            else
                break;
        }
        stk.push(b);
    }

    return stk.size();
}

int punishmentNumber2(int n) {
    int punishment = 0;

    for (int i = 2; i <= n; i++) {
        int square = i * i;
        string str = to_string(square);
        int sum = 0;

        if (i == 9 || i == 10) {
            cout << endl;
        }

        for (int j = 1; j < str.length(); j++) {
            string s1 = str.substr(0, j);
            string s2 = str.substr(j);

            int a = stoi(s1);
            int b = stoi(s2);

            if (a + b == i) {
                punishment += square;
                break;
            }
        }
    }

    return punishment + 1;
}

int minLength2(string s) {
    int len = s.size();
    string temp = "";
    bool isRmv = false;

    while (true) {
        for (int i = 1; i < s.size(); i++) {
            if ((s[i - 1] == 'A' && s[i] == 'B') || (s[i - 1] == 'C' && s[i] == 'D')) {
                isRmv = true;
                i++;
            }
            else {
                temp += s[i - 1];
            }
        }
        s = temp;
        if (!isRmv) break;
    }

    return s.size();
}

// 1254
void dfsClosedIsland(vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n, int i, int j) {
    if (i < 0 || j < 0 || i >= m || j >= n) return;
    if (grid[i][j] || vis[i][j]) return;
    vis[i][j] = 1;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    for (int x = 0; x < 4; x++) {
        dfsClosedIsland(grid, vis, m, n, dx[x] + i, dy[x] + j);
    }
}

int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int a = 0;

    for (int i = 0, r = 0; i < n; i++) {
        if (!vis[r][i] && !grid[r][i])
            dfsClosedIsland(grid, vis, m, n, r, i);

        if (i == n - 1 && r != m - 1) {
            r = m - 1;
            i = -1;
        }

    }

    for (int i = 0, c = 0; i < m; i++) {
        if (!vis[i][c] && !grid[i][c])
            dfsClosedIsland(grid, vis, m, n, i, c);

        if (i == m - 1 && c != n - 1) {
            c = n - 1;
            i = -1;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && !grid[i][j]) {
                dfsClosedIsland(grid, vis, m, n, i, j);
                a++;
            }
        }
    }

    return a;
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

    vector<vector<int>> edges(n);
    int mx = 0;

    for (int i = 0; i < n; i++) {
        if (i == headID) continue;
        //edges[i].push_back(manager[i]);
        edges[manager[i]].push_back(i);
    }

    queue<int> q;
    q.push(headID);
    while (!q.empty())
    {
        int sz = q.size();

        for (int i = 0; i < sz; i++) {
            int m = q.front(); q.pop();

            for (int j = 0; j < edges[m].size(); j++) {
                int e = edges[m][j];
                q.push(e);
                informTime[e] += informTime[m];
                mx = max(informTime[e], mx);
            }
        }
    }

    return mx;

}

// Weekly Contest 345
int mvMov = 0;
void dfsMaxMoves(vector<vector<int>>& grid, int m, int n, int r, int c, int prev, int mov) {
    if (r < 0 || c < 0 || r >= m || c >= n || !grid[r][c] || grid[r][c] <= prev) return;
    cout << prev << "  ";
    prev = grid[r][c];
    grid[r][c] = 0;

    int dx[] = { -1, 0, 1 };
    int dy[] = { 1, 1, 1 };
    ++mov;
    mvMov = max(mov, mvMov);
    for (int i = 0; i < 3; i++)
        dfsMaxMoves(grid, m, n, r + dx[i], c + dy[i], prev, mov);
}

int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++) {
        dfsMaxMoves(grid, m, n, i, 0, 0, 0);
    }
    return mvMov - 1;
}

int maxMovesBFS(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int mx = 0, lvl = 0;;

    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        q.push({ i, 0 });

        while (!q.empty())
        {
            int sz = q.size();
            lvl++;
            for (int j = 0; j < sz; j++) {
                auto top = q.front(); q.pop();
                int a = top.first, b = top.second;
                if (a == 1 && b == 60)
                    cout << endl;
                if (!grid[a][b])
                    continue;
                int prev = grid[a][b];
                grid[a][b] = 0;

                int dx[] = { -1, 0, 1 };
                int dy[] = { 1, 1, 1 };

                for (int i = 0; i < 3; i++) {
                    int r = a + dx[i], c = b + dy[i];

                    if (a == 1 && b == 60) {

                        if (r >= 0 && c >= 0 && r < m && c < n) {
                            cout << "r " << r << "  c  " << c << " m " << m << " n " << n << endl;
                        }
                    }


                    if (r >= 0 && c >= 0 && r < m && c < n && grid[r][c] && grid[r][c] > prev) {
                        q.push({ r, c });
                    }
                }
            }
        }

        mx = max(lvl - 1, mx);
        if (mx == n - 1) return mx;
        lvl = 0;
    }
    return mx;
}

vector<int> circularGameLosers(int n, int k) {
    vector<int> fnd(n, 0);

    int cur = 0, ind = 0;
    while (true)
    {
        if (++fnd[cur] == 2) break;
        ind++;
        cur = (cur + ind * k) % n;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!fnd[i]) ans.push_back(i + 1);
    }
    return ans;
}


int matrixSum(vector<vector<int>>& nums) {
    vector<vector<int>> srt;

    for (auto& v : nums) {
        sort(v.begin(), v.end());
    }

    int cnt = 0;
    for (int i = 0; i < nums[0].size(); i++) {
        for (int j = 0; j < nums.size(); j++)
            cnt += nums[j][i];
    }

    return cnt;
}

int countSeniors(vector<string>& details) {
    int cnt = 0;
    for (auto& p : details) {
        int a = p[11] - '0';
        int b = p[12] - '0';

        if (a == 6 && b > 0 || a > 6) cnt++;
    }

    return cnt;
}

// 1376
int numOfMinutes2(int n, int headID, vector<int>& manager, vector<int>& informTime) {

    vector<vector<int>> edges(n);
    int mx = 0;

    for (int i = 0; i < n; i++) {
        if (i == headID) continue;
        //edges[i].push_back(manager[i]);
        edges[manager[i]].push_back(i);
    }

    queue<int> q;
    q.push(headID);
    while (!q.empty())
    {
        int sz = q.size();

        for (int i = 0; i < sz; i++) {
            int m = q.front(); q.pop();

            for (int j = 0; j < edges[m].size(); j++) {
                int e = edges[m][j];
                q.push(e);
                informTime[e] += informTime[m];
                mx = max(informTime[e], mx);
            }
        }
    }

    return mx;

}

// 1020
void dfsNumEnclaves(vector<vector<int>>& grid, int m, int n, int r, int c) {
    if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != 1) return;
    grid[r][c] = 2;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4; i++)
        dfsNumEnclaves(grid, m, n, r + dx[i], c + dy[i]);
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n;) {
            dfsNumEnclaves(grid, m, n, r, c);

            if (r == 0 || r == m - 1 || c == n - 1) c++;
            else c = n - 1;
        }
    }

    int ans = 0;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 1) ans++;
        }
    }

    return ans;
}

// 130
void dfsMarkVis(vector<vector<char>>& board, vector<vector<int>>& vis, int r, int c, int m, int n, bool isMarkX) {
    if (r < 0 || c < 0 || r >= m || c >= n) return;
    if (board[r][c] == 'X' || vis[r][c]) return;
    vis[r][c] = 1;
    if (isMarkX) board[r][c] = 'X';

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4; i++)
        dfsMarkVis(board, vis, r + dx[i], c + dy[i], m, n, isMarkX);

    return;
}

void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n;) {
            cout << "first r " << r << " c " << c << endl;
            if (board[r][c] == 'O' && !vis[r][c])
                dfsMarkVis(board, vis, r, c, m, n, false);

            if (r == 0 || r == m - 1 || c == n - 1) c++;
            else c = n - 1;
        }
    }

    for (int r = 1; r < m - 1; r++) {
        for (int c = 1; c < n - 1; c++) {
            cout << "r " << r << " c " << c << endl;
            if (board[r][c] == 'O' && !vis[r][c])
                dfsMarkVis(board, vis, r, c, m, n, true);
        }
    }
}

// 1061
int find_smallestEquivalentString(vector<int>& par, int val) {
    if (par[val] == val)
        return val;

    return par[val] = find_smallestEquivalentString(par, par[val]);
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
    vector<int> par(26);
    for (int i = 0; i < 26; i++) par[i] = i;

    for (int i = 0; i < s1.length(); i++) {
        int a = find_smallestEquivalentString(par, s1[i] - 'a');
        int b = find_smallestEquivalentString(par, s2[i] - 'a');

        if (a < b) par[b] = a;
        else
            par[a] = b;
    }

    string ans = "";
    for (int i = 0; i < baseStr.size(); i++) {
        ans += par[find_smallestEquivalentString(par, baseStr[i] - 'a')] + 'a';
    }

    return ans;
}

// 2673
int minInc = 0;
int dfsToMinIncrements(TreeNode* root) {
    if (!root) return 0;

    int cur = root->val;
    int l = cur + dfsToMinIncrements(root->left);
    int r = cur + dfsToMinIncrements(root->right);

    minInc += abs(l - r);
    return max(l, r);
}

int resDfs = 0;
int dfsminIncrements2(vector<int>& cost, int i) {
    if (i >= cost.size()) return 0;

    int l = dfsminIncrements2(cost, 2 * i + 1);
    int r = dfsminIncrements2(cost, 2 * i + 2);

    resDfs += abs(l - r);

    return cost[i] + max(l, r);
}

int minIncrements2(int n, vector<int>& cost) {
    dfsminIncrements2(cost, 0);
    return resDfs;
}

int minIncrements(int n, vector<int>& cost) {
    int idx = 0;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(cost[idx++]);
    q.push(root);

    while (idx < n) {
        TreeNode* cur = q.front(); q.pop();
        cur->left = new TreeNode(cost[idx++]);
        cur->right = new TreeNode(cost[idx++]);
        q.push(cur->left);
        q.push(cur->right);
    }

    int ans = dfsToMinIncrements(root);
    return ans;
}

// Weekly Contest 344

vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    vector<int> vec(n, 0), ans;
    int cnt = 0;

    for (auto& q : queries) {
        int idx = q[0], col = q[1];
        if (idx > 0 && vec[idx] != 0 && vec[idx] == vec[idx - 1]) cnt--;
        if (idx < n - 1 && vec[idx] != 0 && vec[idx] == vec[idx + 1]) cnt--;

        vec[idx] = col;

        if (idx > 0 && vec[idx] == vec[idx - 1]) cnt++;
        if (idx < n - 1 && vec[idx] == vec[idx + 1]) cnt++;

        ans.push_back(cnt);
    }

    return ans;
}

class FrequencyTracker {
    unordered_map<int, int> k, v;
public:
    FrequencyTracker() {

    }

    void add(int number) {
        if (v[k[number]] && !--v[k[number]])
            v.erase(v.find(k[number]));

        v[++k[number]]++;
    }

    void deleteOne(int num) {
        if (!k[num])
            return;

        if (v[k[num]] && !--v[k[num]])
            v.erase(v.find(k[num]));

        int val = --k[num];
        if (!val)
            k.erase(k.find(num));

        v[val]++;
    }

    bool hasFrequency(int frequency) {
        if (v[frequency])
            return true;
        return false;
    }
};

vector<int> distinctDifferenceArray(vector<int>& nums) {
    unordered_set<int> pref;
    unordered_map<int, int> suf;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
        suf[nums[i]]++;

    for (int i = 0; i < nums.size(); i++) {
        if (!--suf[nums[i]]) suf.erase(suf.find(nums[i]));
        pref.insert(nums[i]);
        int diff = pref.size() - suf.size();
        ans.push_back(diff);
    }

    return ans;
}

// 1202

int find(vector<int>& ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}
string smallestStringWithSwaps2(string s, vector<vector<int>>& pairs) {
    vector<int> ds(s.size(), -1);
    vector<vector<int>> m(s.size());
    for (auto& p : pairs) {
        auto i = find(ds, p[0]), j = find(ds, p[1]);
        if (i != j)
            ds[j] = i;
    }

    for (auto i = 0; i < s.size(); ++i) {
        int val = find(ds, i);
        m[val].push_back(i);
    }

    for (auto& ids : m) {
        string ss = "";
        for (auto id : ids)
            ss += s[id];
        sort(begin(ss), end(ss));
        for (auto i = 0; i < ids.size(); ++i)
            s[ids[i]] = ss[i];
    }
    return s;
}

int find_smallestStringWithSwaps(vector<int>& par, int val) {
    if (par[val] == val)
        return val;
    return par[val] = find_smallestStringWithSwaps(par, par[val]);
}

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.size();
    if (n == 1 || pairs.empty())
        return s;

    vector<int> par(n);
    unordered_set<int> unique_idx;

    for (int i = 0; i < n; i++)
        par[i] = i;

    for (auto& p : pairs) {
        if (!unique_idx.count(p[0]))
            unique_idx.insert(p[0]);

        if (!unique_idx.count(p[1]))
            unique_idx.insert(p[1]);

        int a = find_smallestStringWithSwaps(par, p[0]);
        int b = find_smallestStringWithSwaps(par, p[1]);

        if (a != b)
            par[a] = b;
    }

    unordered_map<int, vector<int>> mp;
    for (auto& idx : unique_idx) {
        int p_idx = find_smallestStringWithSwaps(par, idx);
        mp[p_idx].push_back(idx);
    }

    char* ans = s.data();
    for (auto& kv : mp) {
        vector<char> chrs;
        vector<int> idx_sort;

        for (int i = 0; i < kv.second.size(); i++) {
            chrs.push_back(s[kv.second[i]]);
            idx_sort.push_back(kv.second[i]);
        }

        sort(idx_sort.begin(), idx_sort.end());
        sort(chrs.begin(), chrs.end());

        for (int i = 0; i < idx_sort.size(); i++) {
            ans[idx_sort[i]] = chrs[i];
        }
    }

    string ansstr = "";
    for (int i = 0; i < s.size(); i++) {
        ansstr += ans[i];
    }

    return ansstr;
}

/*
vector<int> idx_char;
vector<int> dfs_smallestStringWithSwaps(string s, vector<vector<int>>& edges, vector<int>& vis, int idx) {
    string strdfs = "";
    if (vis[idx]) return ;

    vis[idx] = 1;

    for (int i = 0; i < edges[idx].size(); i++)
        strdfs += s[edges[idx][i]] + dfs_smallestStringWithSwaps(s, edges, vis, i);

    return strdfs;
}

string smallestStringWithSwapss(string s, vector<vector<int>>& pairs) {
    int n = s.size();
    vector<vector<int>> edges(n);
    vector<int> vis(n, 0);

    for (auto& p : pairs) {
        edges[p[0]].push_back(p[1]);
        edges[p[1]].push_back(p[0]);
    }

    string tok = "";
    string total = "";
    for (int i = 0; i < edges.size(); i++) {
        string strdfs = "";
        if (!vis[i] && !edges[i].empty())
            tok += dfs_smallestStringWithSwaps(s, edges, vis, i);
    }

    return tok;
}*/

// 990
int find_equationsPossible(vector<int>& par, int val) {
    if (val == par[val])
        return val;

    return par[val] = find_equationsPossible(par, par[val]);
}

bool equationsPossible(vector<string>& equations) {
    vector<int> par(26), rank(26);
    for (int i = 0; i < 26; i++) par[i] = i, rank[i] = 1;

    sort(equations.begin(), equations.end(), [](const auto& s1, const auto& s2) {
        return s1[1] > s2[1];
        });

    for (auto& eq : equations) {
        int a = eq[0] - 'a', b = eq[3] - 'a';
        char x = eq[1];
        int ap = find_equationsPossible(par, a);
        int bp = find_equationsPossible(par, b);

        if (ap == bp && x == '!')
            return false;
        if (x == '=') {
            // make union by rank
            if (rank[ap] > rank[bp])
                par[bp] = ap, rank[ap]++;
            else
                par[ap] = bp, rank[bp]++;
        }
    }

    return true;
}

// 947
unordered_map<int, int> f;
int islands = 0;

int find(int x) {
    if (!f.count(x)) f[x] = x, islands++;
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) f[x] = y, islands--;
}

int removeStones(vector<vector<int>>& stones) {
    for (int i = 0; i < stones.size(); ++i)
        uni(stones[i][0], ~stones[i][1]);
    return stones.size() - islands;
}

int removeStonesBFS(vector<vector<int>>& stones) {
    int n = stones.size();
    unordered_set<pair<int, int>, pair_hash> vis;
    unordered_map<int, vector<int>> row, col;

    unordered_set<int> vx;
    auto x = vx.insert(3).second;

    for (int i = 0; i < stones.size(); i++) {
        int x = stones[i][0], y = stones[i][1];
        row[x].push_back(y);
        col[y].push_back(x);
    }

    int sum = 0, val = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        int x = stones[i][0], y = stones[i][1];
        if (!vis.count({ x, y })) {
            q.push({ x, y });
            vis.insert({ x, y });
            val = 0;

            while (!q.empty()) {
                int a = q.front().first, b = q.front().second; q.pop();
                val++;

                for (int j = 0; j < row[a].size(); j++) {
                    if (!vis.count({ a, row[a][j] })) {
                        q.push({ a, row[a][j] });
                        vis.insert({ a, row[a][j] });
                    }
                }
                for (int j = 0; j < col[b].size(); j++) {
                    if (!vis.count({ col[b][j], b })) {
                        q.push({ col[b][j], b });
                        vis.insert({ col[b][j], b });
                    }
                }
            }

            sum += val - 1;
        }
    }

    return sum;
}

// 58
int lengthOfLastWord(string s) {
    int len = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ' ' && len > 0)
            return len;
        else if (s[i] != ' ')
            len++;
    }

    return len;
}

// Weekly Contest 343

int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int r = mat.size(), c = mat[0].size(), maxi = INT_MAX;
    vector<vector<int>> vis(r, vector<int>(c, 0));
    unordered_map<int, pair<int, int>> mp;

    vector<int> row(r, 0), col(c, 0);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            mp[mat[i][j]] = make_pair(i, j);
        }
    }

    int i = 0;
    for (i = 0; i < arr.size(); i++) {
        auto& p = mp[arr[i]];
        vis[p.first][p.second] = i;

        row[p.first]++;
        col[p.second]++;

        if (row[p.first] == c || col[p.second] == r)
            return i;
    }

    return i;
}

int isWinner(vector<int>& p1, vector<int>& p2) {
    int sum = 0;
    int t1 = 0, t2 = 0;

    for (int i = 0; i < p1.size(); i++) {
        sum += t1-- > 0 ? p1[i] * 2 : p1[i];
        sum -= t2-- > 0 ? p2[i] * 2 : p2[i];

        if (p1[i] == 10) t1 = 2;
        if (p2[i] == 10) t2 = 2;
    }

    return sum == 0 ? 0 : sum > 0 ? 1 : 2;
}


// Biweekly Contest 103
int tot = 0;
int findMaxFish_dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return 0;
    if (vis[r][c] || grid[r][c] == 0) return 0;
    vis[r][c] = 1;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    tot += grid[r][c];

    for (int i = 0; i < 4; i++)
        findMaxFish_dfs(grid, vis, r + dx[i], c + dy[i]);

    return tot;
}

int findMaxFish(vector<vector<int>>& grid) {
    int r = grid.size(), c = grid[0].size(), maxi = INT_MAX;
    vector<vector<int>> vis(r, vector<int>(c, 0));

    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[0].size(); c++) {
            if (!vis[r][c] && grid[r][c] > 0) {
                int len = findMaxFish_dfs(grid, vis, r, c);
                if (len != 0)
                    maxi = max(maxi, len);
                tot = 0;
            }
        }
    }

    return maxi;
}

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    vector<int> ans;
    unordered_set<int> st_a, st_b;

    int cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == B[i]) {
            cnt++;
            st_a.insert(A[i]);
            st_b.insert(B[i]);
        }
        else {
            st_a.insert(A[i]);
            if (st_a.count(B[i])) cnt++;

            st_b.insert(B[i]);
            if (st_b.count(A[i])) cnt++;
        }


        ans.push_back(cnt);
    }

    return ans;
}

int maximizeSum(vector<int>& nums, int k) {
    int mx = 0;
    for (int i = 0; i < nums.size(); i++) {
        mx = max(mx, nums[i]);
    }

    int sum = 0;
    while (k--)
    {
        sum += mx++;
    }
    return sum;
}

// 721
string accountsMerge_find(unordered_map<string, string>& parent, string email) {
    if (!parent.count(email)) {
        parent[email] = email;
        return email;
    }

    if (parent[email] == email)
        return email;
    return parent[email] = accountsMerge_find(parent, parent[email]);
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

    unordered_map<string, string> parent;
    int parent_idx = -1, res_idx = 0;

    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].size() <= 2) {
            string email = accounts[i][1];
            parent[email] = email;
        }
        else {
            for (int j = 2; j < accounts[i].size(); j++) {
                string email1 = accounts[i][j - 1];
                string email2 = accounts[i][j];

                email1 = accountsMerge_find(parent, email1);
                email2 = accountsMerge_find(parent, email2);

                if (email1 != email2)
                    parent[email1] = email2;
            }
        }
    }

    unordered_set<string> new_par;
    for (auto& kvp : parent) {
        new_par.insert(accountsMerge_find(parent, kvp.second));
    }

    int idx = 0;

    unordered_map<string, int> key_mapper;
    for (auto& s : new_par)
        key_mapper[s] = idx++;

    vector<vector<string>> res(idx);
    unordered_set<string> vis;

    for (int i = 0; i < accounts.size(); i++) {
        string name = accounts[i][0];

        for (int j = 1; j < accounts[i].size(); j++) {
            string email = accounts[i][j];
            if (!vis.count(email)) {
                int index = key_mapper[accountsMerge_find(parent, email)];

                if (res[index].empty())
                    res[index].push_back({ name });

                res[index].push_back(email);
                vis.insert(email);
            }
        }
    }


    for (int i = 0; i < res.size(); i++) {
        sort(res[i].begin() + 1, res[i].end());
    }

    return res;
}

// 1319
int makeConnected_helperDfs(vector<vector<int>>& graph, vector<int>& vis, int node) {
    if (vis[node]) return 0;

    vis[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        makeConnected_helperDfs(graph, vis, graph[node][i]);
    }

    return 1;
}

int makeConnected_DFS(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;
    vector<int> vis(n, 0);
    vector<vector<int>> graph(n);
    int component = 0;

    for (auto& edge : connections) {
        int u = edge[0];
        int v = edge[1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        component += makeConnected_helperDfs(graph, vis, i);
    }

    return component - 1;
}

int makeConnected_find(vector<int>& parent, int u) {
    if (parent[u] == u)
        return u;

    return parent[u] = makeConnected_find(parent, parent[u]);
}

int makeConnected_union(vector<int>& parent, vector<int>& rank, int u, int v) {
    u = makeConnected_find(parent, u);
    v = makeConnected_find(parent, v);

    if (u == v) return 0;

    if (rank[u] > rank[v]) {
        parent[v] = u;
        rank[u] += rank[v];
    }
    else {
        parent[u] = v;
        rank[v] += rank[u];
    }

    return 1;
}

// 1319
int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;
    vector<int> parent(n, 0), rank(n, 0);
    int component = 0;

    for (int i = 0; i < n; i++) {
        rank[i] = 1;
        parent[i] = i;
    }

    for (auto& edge : connections) {
        int u = edge[0];
        int v = edge[1];

        component += makeConnected_union(parent, rank, u, v);
    }

    return n - component - 1;
}

int find_gcd(int a, int b) {
    return a == b ? b : find_gcd(b % a, a);
}

int minOperationsOn(vector<int>& nums) {
    int n = nums.size();
    int one = 0;
    for (int i = 0; i < n; i++) one += nums[i] == 1;
    if (one) return n - one;
    stack<int> la, ra, lg, rg;
    auto good = [&]() {
        int g = 0;
        if (!la.empty()) g = gcd(g, lg.top());
        if (!ra.empty()) g = gcd(g, rg.top());
        return g == 1;
    };
    auto add = [&](int x) {
        ra.push(x);
        rg.push(gcd((rg.empty() ? 0 : rg.top()), x));
    };
    auto remove = [&]() {
        if (la.empty()) {
            while (!ra.empty()) {
                int x = ra.top(); la.push(x); ra.pop(), rg.pop();
                lg.push(gcd((lg.empty() ? 0 : lg.top()), x));
            }
        }
        la.pop(), lg.pop();
    };
    int ans = n;
    for (int l = 0, r = 0; r < n; r++) {
        add(nums[r]);
        while (l < n and good()) {
            ans = min(ans, r - l);
            remove(), l++;
        }
    }
    if (ans == n) return -1;
    return n + ans - 1;
}

int minOperations(vector<int>& nums) {
    int minv = INT32_MAX, ones = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) ones++;
    }

    if (ones) return n - ones;

    for (int i = 0; i < n; i++) {
        int g = nums[i];
        for (int j = i + 1; j < n; j++) {
            g = find_gcd(g, nums[j]);
            if (g == 1) {
                minv = min(minv, (j - i + n - 1));
                break;
            }
        }
    }

    return minv == INT32_MAX ? -1 : minv;
}

vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    map<int, int> mp;
    vector<int> ans;


    for (int i = 0; i < k; i++)
        if (nums[i] < 0)
            mp[nums[i]]++;
    int xval = x;

    for (auto& kv : mp) {
        xval -= kv.second;
        if (xval <= 0) {
            cout << kv.first << endl;
            ans.push_back(kv.first);
            break;
        }
    }

    if (xval > 0)
        ans.push_back(0);

    int n = nums.size();
    for (int i = 1; i + k - 1 < n; i++) {
        if (nums[i - 1] < 0) mp[nums[i - 1]]--;
        if (nums[i + k - 1] < 0) mp[nums[i + k - 1]]++;

        int xval = x;
        for (auto& kv : mp) {
            xval -= kv.second;
            if (xval <= 0) {
                cout << kv.first << endl;
                ans.push_back(kv.first);
                break;
            }
        }
        if (xval > 0)
            ans.push_back(0);
    }

    return ans;
}

int sumOfMultiples(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
            sum += i;
    }
    return sum;
}

int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
    return (arrivalTime + delayedTime) % 24;
}

// 654. Maximum Binary Tree
TreeNode* dfsconstructMaximumBinaryTree(vector<int>& nums, int st, int end) {
    if (st > end || st >= nums.size() || end < 0)
        return NULL;
    int indx = st;
    for (int i = st; i <= end; i++) {
        if (nums[i] > nums[indx])
            indx = i;
    }

    TreeNode* root = new TreeNode(nums[indx]);
    root->left = dfsconstructMaximumBinaryTree(nums, st, indx - 1);
    root->right = dfsconstructMaximumBinaryTree(nums, indx + 1, end);
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return dfsconstructMaximumBinaryTree(nums, 0, nums.size() - 1);
}

/// 105
TreeNode* dfsToBuildTree(int preStart, int inStart, int inEnd, vector<int>& pre, vector<int>& in) {
    if (inStart >= inEnd || preStart >= pre.size())
        return NULL;

    TreeNode* root = new TreeNode(pre[preStart]);
    if (inEnd - inStart == 1)
        return root;


    int idx = 0;
    for (idx = inStart; idx < inEnd; idx++) {
        if (pre[preStart] == in[idx])
            break;
    }
    cout << "root: " << root->val << " ; left: {" << preStart + 1 << "," << inStart << "," << idx << "}" << endl;
    cout << "root: " << root->val << " ; right: {" << preStart + 1 + idx - inStart << "," << idx + 1 << "," << inEnd << "}" << endl;
    root->left = dfsToBuildTree(preStart + 1, inStart, idx, pre, in);
    root->right = dfsToBuildTree(preStart + 1 + idx - inStart, idx + 1, inEnd, pre, in);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return dfsToBuildTree(0, 0, inorder.size(), preorder, inorder);
}

// 2336
class SmallestInfiniteSet {
    set<int> st;
public:
    SmallestInfiniteSet() {
        st.insert(1);
    }

    int popSmallest() {
        auto it = st.begin();
        int val = *it;

        if (st.size() == 1) {
            st.insert(val + 1);
        }

        st.erase(it);
        return val;
    }

    void addBack(int num) {
        if (*rbegin(st) > num)
            st.insert(num);
    }
};

// 547
int fpFindCircleNum(vector<int>& parent, int x) {
    return parent[x] == x ? x : fpFindCircleNum(parent, parent[x]);
}

int findCircleNum(vector<vector<int>>& isCon) {
    int n = isCon.size();
    vector<int> parent(n, 0);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cnt = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (isCon[r][c] && r != c) {
                int x = fpFindCircleNum(parent, r);
                int y = fpFindCircleNum(parent, c);
                if (x != y) parent[y] = x;
            }
        }
    }

    unordered_set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(fpFindCircleNum(parent, i));

    return st.size();
}

// 684
// template union find
int findParent(vector<int>& parent, int x) {
    return parent[x] == x ? x : findParent(parent, parent[x]);
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent(n + 1, 0);

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    vector<int> res(2, 0);
    for (int i = 0; i < n; i++) {
        int x = findParent(parent, edges[i][0]);
        int y = findParent(parent, edges[i][1]);

        if (x != y)
            parent[y] = x;
        else {
            res[0] = x;
            res[1] = y;
        }
    }

    return res;
}

// Graph Algorithms
// https://structy.net/problems/minimum-island
int dfsTominimumIsland(vector<vector<char>>& grid, vector<vector<int>>& vis, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return 0;
    if (vis[r][c] || grid[r][c] != 'L') return 0;
    vis[r][c] = 1;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    int size = 1;

    for (int i = 0; i < 4; i++)
        size += dfsTominimumIsland(grid, vis, r + dx[i], c + dy[i]);

    return size;
}

int minimumIsland(vector<vector<char>> grid) {
    int r = grid.size(), c = grid[0].size(), mini = INT_MAX;
    vector<vector<int>> vis(r, vector<int>(c, 0));

    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[0].size(); c++) {
            if (!vis[r][c] && grid[r][c] == 'L') {
                int len = dfsTominimumIsland(grid, vis, r, c);
                if (len != 0)
                    mini = min(mini, len);
            }
        }
    }

    return mini;
}

// https://structy.net/problems/island-count
void dfsToMarkLand(vector<vector<char>>& grid, vector<vector<int>>& vis, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return;
    if (vis[r][c] || grid[r][c] != 'L') return;
    vis[r][c] = 1;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4; i++)
        dfsToMarkLand(grid, vis, r + dx[i], c + dy[i]);
}

int islandCount(vector<vector<char>> grid) {
    int r = grid.size(), c = grid[0].size(), cnt = 0;
    vector<vector<int>> vis(r, vector<int>(c, 0));

    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[0].size(); c++) {
            if (!vis[r][c] && grid[r][c] == 'L') {
                dfsToMarkLand(grid, vis, r, c);
                cnt++;
            }
        }
    }

    return cnt;
}

// Shortest Path BFS
int shortestPath(vector<tuple<string, string>> edges, string nodeA, string nodeB) {
    if (nodeA == nodeB) return 0;
    unordered_map<string, vector<string>> adj;

    for (auto edge : edges) {
        string a = get<0>(edge), b = get<1>(edge);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<pair<string, int>> q;
    unordered_set<string> vis;
    q.push({ nodeA, 0 });
    vis.insert(nodeA);

    while (!q.empty()) {
        auto top = q.front(); q.pop();
        string curNode = top.first; int dis = top.second;

        for (auto neighbor : adj[curNode]) {
            if (vis.count(neighbor))
                continue;

            if (neighbor == nodeB)
                return dis + 1;

            q.push({ neighbor, dis + 1 });
            vis.insert(neighbor);
        }
    }

    return 0;
}

// largest component
// https://structy.net/problems/largest-component
int dfs_largestComponent(unordered_map<int, vector<int>>& graph, unordered_set<int>& vis, int src) {
    if (vis.count(src))
        return 0;

    vis.insert(src);
    int size = 1;
    for (auto node : graph[src])
        size += dfs_largestComponent(graph, vis, node);

    return size;
}

int largestComponent(unordered_map<int, vector<int>> graph) {
    unordered_set<int> vis;

    int mx = 0;
    for (auto kv : graph) {
        if (!vis.count(kv.first)) {
            mx = max(mx, dfs_largestComponent(graph, vis, kv.first));
        }
    }

    return mx;
}

// connected component
// https://structy.net/problems/connected-components-count

int dfs_connectedComponentsCount(unordered_map<int, vector<int>>& graph, unordered_set<int>& vis, int src) {
    if (vis.count(src))
        return 0;

    vis.insert(src);
    for (auto node : graph[src])
        dfs_connectedComponentsCount(graph, vis, node);

    return 1;
}

int connectedComponentsCount(unordered_map<int, vector<int>> graph) {
    unordered_set<int> vis;

    int count = 0;
    for (auto kv : graph) {
        if (!vis.count(kv.first)) {
            count += dfs_connectedComponentsCount(graph, vis, kv.first);
        }
    }

    return count;
}

// undirected graph
// https://structy.net/problems/undirected-path
unordered_set<string> is_path_vis;
bool is_path_undirectedtPath(unordered_map<string, vector<string>> adj, string src, string dst) {
    if (src == dst) return true;

    is_path_vis.insert(src);

    for (auto v : adj[src]) {
        if (!is_path_vis.count(v) && is_path_undirectedtPath(adj, v, dst))
            return true;
    }

    return false;
}

bool undirectedPath(vector<tuple<string, string>> edges, string src, string dst) {
    unordered_map<string, vector<string>> adj;

    for (auto edge : edges) {
        adj[get<0>(edge)].push_back(get<1>(edge));
        adj[get<1>(edge)].push_back(get<0>(edge));
    }

    return is_path_undirectedtPath(adj, src, dst);
}

// directed graph
bool has_path(vector<vector<int>> graph, int src, int des) {
    if (src == des) return true;

    for (auto node : graph[src]) {
        if (has_path(graph, node, des))
            return true;
    }

    return false;
}

bool bfs_graph(vector<vector<int>> graph, int source) {
    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int curNode = q.front(); q.pop();
        cout << curNode << endl;

        for (int node : graph[curNode])
            q.push(node);
    }


    return true;
}

void dfs_graph_recursion_helper(vector<vector<int>> graph, int source) {
    cout << source << endl;

    for (int node : graph[source])
        dfs_graph_recursion_helper(graph, node);
}

bool dfs_graph_recursion(vector<vector<int>> graph, int source) {
    dfs_graph_recursion_helper(graph, source);

    return true;
}

bool dfs_graph(vector<vector<int>> graph, int source) {
    stack<int> stk;
    stk.push(source);

    while (!stk.empty()) {
        int curNode = stk.top(); stk.pop();
        cout << curNode << endl;

        for (int node : graph[curNode])
            stk.push(node);
    }
    return true;
}

// 206 
ListNode* reverse_recursion(ListNode* head, ListNode* newHead) {
    if (!head)
        return newHead;
    ListNode* next = head->next;
    head->next = newHead;
    return reverse_recursion(next, head);
}

ListNode* reverseList_Recursion(ListNode* head) {
    return reverse_recursion(head, NULL);
}

// 206
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next)
        return head;
    ListNode* cur = head;
    ListNode* rev = head;
    ListNode* temp = head;
    cur = cur->next;
    temp->next = NULL;

    while (cur)
    {
        rev = cur;
        cur = cur->next;
        rev->next = temp;
        temp = rev;
    }

    return rev;
}


map<int, map<int, multiset<int>>> stmap;
void storeDatabyDfs(TreeNode* root, int row, int col) {
    if (!root) return;

    if (col == 0) {
        int a = root->val;
    }

    map<int, multiset<int>> temp;
    multiset<int> set;
    if (stmap[col].find(row) != stmap[col].end())
        set = stmap[col][row];
    set.insert(root->val);
    if (stmap.find(col) != stmap.end())
        temp = stmap[col];
    temp[row] = set;
    stmap[col] = temp;

    storeDatabyDfs(root->left, row + 1, col - 1);
    storeDatabyDfs(root->right, row + 1, col + 1);
}

// Weekly Contest 341
int maxDivScore(vector<int>& nums, vector<int>& divisors) {
    unordered_map<int, int> divisorScores;
    unordered_map<int, int> vis;

    for (int i = 0; i < divisors.size(); i++) {
        if (!divisors[i]) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] % divisors[i] == 0) {
                    divisorScores[divisors[i]]++;
                }
            }
        }
        vis[divisors[i]] = 1;
    }

    int maxScore = 0;
    int result = divisors[0];

    for (int i = 0; i < divisors.size(); i++) {
        if (divisorScores[divisors[i]] >= maxScore) {
            if (divisorScores[divisors[i]] > maxScore) {
                maxScore = divisorScores[divisors[i]];
                result = divisors[i];
            }
            else if (divisors[i] < result)
                result = divisors[i];
        }
    }

    return result;
}

int addMinimum(string word) {
    int cnt = 0;
    int sz = word.size();

    for (int i = 0; i < sz; i++) {
        // a ab ac abc
        if (word[i] == 'a') {
            // ab 
            if (i + 1 < sz && word[i + 1] == 'b') {
                // abc
                if (i + 2 < sz && word[i + 2] == 'c') {
                    i = i + 2;
                }
                else {
                    cnt++;
                    i++;
                }
            }
            // ac
            else if (i + 1 < sz && word[i + 1] == 'c') {
                cnt++;
                i++;
            }
            // aa
            else {
                cnt += 2;
            }
        }

        // b ba bc 
        else if (word[i] == 'b') {
            if (i + 1 < sz && word[i + 1] == 'c') {
                i++;
                cnt++;
            }
            else {
                cnt += 2;
            }
        }

        // c
        else if (word[i] == 'c') {
            cnt += 2;
        }
    }

    return cnt;
}

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int ones = 0, row = 0, cnt = 0;

    for (int i = 0; i < mat.size(); i++) {
        cnt = 0;
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j]) cnt++;
        }
        if (cnt > ones) {
            ones = cnt;
            row = i;
        }
    }

    return { ones, row };
}

// biweekly contest 102
TreeNode* replaceValueInTree(TreeNode* root) {
    queue<TreeNode*> q;
    root->val = 0;
    q.push(root);


    while (!q.empty()) {
        int sz = q.size();
        if (sz == 1) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) {
                node->left->val = 0;
                q.push(node->left);
            }

            if (node->right) {
                node->right->val = 0;
                q.push(node->right);
            }
        }
        else {
            int sum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                sum += node->left ? node->left->val : 0;
                sum += node->right ? node->right->val : 0;
                q.push(node);
            }
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                int cur = 0;
                cur += node->left ? node->left->val : 0;
                cur += node->right ? node->right->val : 0;
                cur = sum - cur;
                if (node->left) {
                    node->left->val = cur;
                    q.push(node->left);
                }

                if (node->right) {
                    node->right->val = cur;
                    q.push(node->right);
                }
            }
        }
    }

    return root;
}

vector<long long> findPrefixScore(vector<int>& nums) {
    int sz = nums.size();
    vector<long long> ans(sz, 0);
    long long mx = 0;

    for (int i = 0; i < sz; i++) {
        mx = max(mx, (nums[i] * 1ll));
        long long pre = i > 0 ? ans[i - 1] : 0;
        ans[i] = pre + (nums[i] * 1ll) + mx;
    }

    return ans;
}

vector<int> findColumnWidth(vector<vector<int>>& grid) {
    vector<int> ans;

    for (int i = 0; i < grid[i].size(); i++) {
        int mx = 0;
        for (int j = 0; j < grid.size(); j++) {
            string val = to_string(grid[j][i]);
            int sz = val.size();
            mx = max(mx, sz);
        }
        ans.push_back(mx);
    }

    return ans;
}

// 547
int findCircleNum(vector<vector<int>>& isConnected) {
    return 0;
}

// 684
// template union find
int findParent(vector<int>& parent, int x) {
    return parent[x] == x ? x : findParent(parent, parent[x]);
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent(n + 1, 0);

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    vector<int> res(2, 0);
    for (int i = 0; i < n; i++) {
        int x = findParent(parent, edges[i][0]);
        int y = findParent(parent, edges[i][1]);

        if (x != y)
            parent[y] = x;
        else {
            res[0] = x;
            res[1] = y;
        }
    }

    return res;
}

// 841
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int roomNo = rooms.size() - 1;
    unordered_set<int> vis;
    vector<int> keys(rooms[0]);
    vis.insert(0);

    while (!keys.empty())
    {
        int key = keys.back(); keys.pop_back();

        if (!vis.count(key)) {
            for (int k : rooms[key]) {
                if (!vis.count(k))
                    keys.push_back(k);
            }

            vis.insert(key);
            roomNo--;
        }
    }

    if (!roomNo) return true;
    return false;
}

// 2616
bool isValidMinimizeMax(vector<int>& nums, int p, int x) {
    for (int i = 0; p > 0 && i < nums.size() - 1; i++) {
        if ((nums[i + 1] - nums[i]) <= x) {
            p--;
            i++;
        }
    }
    if (p <= 0)
        return true;
    else
        return false;
}

int minimizeMax(vector<int>& nums, int p) {
    if (!p || nums.empty())
        return 0;

    sort(nums.begin(), nums.end());

    int sz = nums.size(), left = 0, right = (nums[sz - 1] - nums[0] + 1);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isValidMinimizeMax(nums, p, mid))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

// 1557
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    unordered_set<int> sources;
    vector<int> vis(n, 0);
    for (auto& edge : edges) {
        int src = edge[0], des = edge[1];
        if (!vis[src])
            sources.insert(src);
        if (sources.count(des))
            sources.erase(sources.find(des));
        vis[src] = 1;
        vis[des] = 1;
    }

    vector<int> ans;
    for (auto& s : sources)
        ans.push_back(s);

    return ans;
}

long long getDistanceVal(vector<long long>& prefixSum, int i, unordered_map<int, int>& index_map) {
    if (prefixSum.size() == 1)
        return prefixSum[0];

    int prefixInd = index_map[i] + 1;
    long long preVal = 0;
    if (prefixInd)
        preVal = (i * prefixInd * 1ll) - prefixSum[prefixInd - 1];

    int rem_sz = prefixSum.size() - prefixInd;
    long long postVal = prefixSum[prefixSum.size() - 1] - prefixSum[prefixInd - 1] - (i * rem_sz * 1ll);

    return preVal + postVal;
}

vector<long long> distance(vector<int>& nums) {
    // prefix-sum
    unordered_map<int, vector<long long>> mp;
    unordered_map<int, int> in_pre;

    for (int i = 0; i < nums.size(); i++) {
        int sz = mp[nums[i]].size();
        long long val = 0;
        if (!mp[nums[i]].empty())
            val = mp[nums[i]][sz - 1];

        mp[nums[i]].push_back(val + i);
        in_pre[i] = sz;
    }

    vector<long long> ansVec;
    for (int i = 0; i < nums.size(); i++) {
        long long val_ans = getDistanceVal(mp[nums[i]], i, in_pre);
        ansVec.push_back(val_ans);
    }

    return ansVec;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int diagonalPrime(vector<vector<int>>& nums) {
    int mx = 0;
    int SIZE = nums.size();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i == j || i + j == SIZE - 1) && isPrime(nums[i][j]))
                mx = max(mx, nums[i][j]);
        }
    }

    return mx;
}

//62
// dp solution
int uniquePaths(int m, int n) {
    int dp[101][101];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }


    return dp[m - 1][n - 1];
}


// time limit exceeded
int uniquePathstle(int m, int n) {
    if (m == 1 || n == 1)
        return 1;

    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({ 0, 0 });

    while (!q.empty()) {
        auto top = q.front(); q.pop();
        if (top.first == m - 1 && top.second == n - 1) {
            cnt++;
            continue;
        }

        if (top.first < m - 1)
            q.push({ top.first + 1, top.second });
        if (top.second < n - 1)
            q.push({ top.first, top.second + 1 });
    }

    return cnt;
}


//797
vector<vector<int>> allPathsSourceTargets(vector<vector<int>>& graph) {
    // edges cases:
    if (graph.empty()) {
        return {};
    }

    // build di-graph
    unordered_map<int, vector<int>> d;
    for (int i = 0; i < graph.size(); i++) {
        d[i] = graph[i]; // one-way link
    }

    // apply DFS on DAG
    int n = graph.size();
    vector<pair<int, vector<int>>> stack = { {0, {0}} };
    vector<vector<int>> res;
    while (!stack.empty()) {
        int node = stack.back().first;
        vector<int> path = stack.back().second;
        stack.pop_back();
        // check leaf
        if (node == n - 1) {
            res.push_back(path);
        }
        // traverse rest
        for (int nei : d[node]) {
            path.push_back(nei);
            stack.push_back({ nei, path });
            path.pop_back();
        }
    }
    return res;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    queue<vector<int>> q;
    int des = graph.size() - 1, src = 0;
    q.push({ 0 });

    while (!q.empty()) {
        auto top = q.front(); q.pop();
        int curDes = top[top.size() - 1];
        if (curDes == des) {
            ans.push_back(top);
            continue;
        }
        for (auto edge : graph[curDes]) {
            top.push_back(edge);
            q.push(top);
            top.pop_back();
        }
    }
    return ans;
}

//997
int findJudge(int n, vector<vector<int>>& trust) {
    vector<vector<int>> adj(n + 1);

    for (auto t : trust) {
        int s = t[0], d = t[1];
        adj[s].push_back(d);
    }

    int judge = 0;
    for (int i = 1; i < adj.size(); i++) {
        if (!adj[i].size()) {
            judge = i;
            break;
        }
    }
    if (!judge) return -1;
    for (int i = 1; i < adj.size(); i++) {
        if (judge == i)
            continue;
        if (adj[i].empty())
            return -1;

        bool hasConn = false;
        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == judge) {
                hasConn = true;
                break;
            }
        }
        if (!hasConn)
            return -1;
    }

    return judge;
}

//695
int dfsTomaxAreaOfIsland(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return 0;
    if (vis[r][c] || !grid[r][c]) return 0;
    vis[r][c] = 1;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    int size = 1;

    for (int i = 0; i < 4; i++)
        size += dfsTomaxAreaOfIsland(grid, vis, r + dx[i], c + dy[i]);

    return size;
}

int maxAreaOfIsland(vector<vector<int>> grid) {
    int r = grid.size(), c = grid[0].size(), maxi = 0;
    // 2d_vector 2dvector vect2d
    vector<vector<int>> vis(r, vector<int>(c, 0));

    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[0].size(); c++) {
            if (!vis[r][c] && grid[r][c]) {
                maxi = max(maxi, dfsTomaxAreaOfIsland(grid, vis, r, c));
            }
        }
    }

    return maxi;
}

int findCenter(vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> adj;
    int n = 0;
    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
        n = max(n, edge[0]);
        n = max(n, edge[1]);
    }

    for (auto kv : adj) {
        if (adj[kv.first].size() == n - 1)
            return kv.first;
    }

    return -1;
}

// weekly contest
int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0;
    for (int i = 0; i < reward1.size(); i++) {
        pq.push(reward1[i] - reward2[i]);
        sum += reward2[i];
        if (pq.size() > k)
            pq.pop();
    }

    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }

    return sum;
}

int miceAndCheese2(vector<int>& reward1, vector<int>& reward2, int k) {
    vector<int> v;
    long long sum = 0;
    for (int i = 0; i < reward1.size(); i++) {
        v.push_back(reward1[i] - reward2[i]);
        sum += reward2[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < k; i++)
        sum += v[i];

    return sum;
}

vector<vector<int>> findMatrix(vector<int>& nums) {
    unordered_map<int, int> m;
    vector<vector<int>> ans;

    for (auto num : nums) m[num]++;

    while (!m.empty()) {
        vector<int> v;
        for (auto it = m.cbegin(); it != m.cend();)
        {
            v.push_back(it->first);
            m[it->first]--;
            if (it->second == 0)
            {
                m.erase(it++);
            }
            else
            {
                ++it;
            }
        }
        ans.push_back(v);
    }

    return ans;
}

int findTheLongestBalancedSubstring(string s) {
    int zero = 0, ones = 0, mx = 0;

    for (auto c : s) {
        if (c == '0') {
            if (ones > 0) zero = 0;
            zero++;
            ones = 0;
        }
        else if (c == '1') {
            ones++;
        }

        if (zero >= ones)
            mx = max(mx, ones * 2);
    }
    return mx;
}


unordered_set<int> vis;
vector<vector<int>> adjacencyList(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto edge : edges) {
        int a = edge[0], b = edge[1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return adj;
}

bool is_has_validPath(vector<vector<int>> adj, int src, int dst) {
    if (src == dst) return true;
    if (vis.count(src)) return false;

    vis.insert(src);

    for (auto node : adj[src])
        if (is_has_validPath(adj, node, dst))
            return true;

    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    auto adj = adjacencyList(n, edges);
    return is_has_validPath(adj, source, destination);
}

// Graph Algorithms
// https://structy.net/problems/minimum-island
int dfsTominimumIsland(vector<vector<char>>& grid, vector<vector<int>>& vis, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return 0;
    if (vis[r][c] || grid[r][c] != 'L') return 0;
    vis[r][c] = 1;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    int size = 1;

    for (int i = 0; i < 4; i++)
        size += dfsTominimumIsland(grid, vis, r + dx[i], c + dy[i]);

    return size;
}

int minimumIsland(vector<vector<char>> grid) {
    int r = grid.size(), c = grid[0].size(), mini = INT_MAX;
    vector<vector<int>> vis(r, vector<int>(c, 0));

    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[0].size(); c++) {
            if (!vis[r][c] && grid[r][c] == 'L') {
                int len = dfsTominimumIsland(grid, vis, r, c);
                if (len != 0)
                    mini = min(mini, len);
            }
        }
    }

    return mini;
}

// https://structy.net/problems/island-count
void dfsToMarkLand(vector<vector<char>>& grid, vector<vector<int>>& vis, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return;
    if (vis[r][c] || grid[r][c] != 'L') return;
    vis[r][c] = 1;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4; i++)
        dfsToMarkLand(grid, vis, r + dx[i], c + dy[i]);
}

int islandCount(vector<vector<char>> grid) {
    int r = grid.size(), c = grid[0].size(), cnt = 0;
    vector<vector<int>> vis(r, vector<int>(c, 0));

    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[0].size(); c++) {
            if (!vis[r][c] && grid[r][c] == 'L') {
                dfsToMarkLand(grid, vis, r, c);
                cnt++;
            }
        }
    }

    return cnt;
}

// Shortest Path BFS
int shortestPath(vector<tuple<string, string>> edges, string nodeA, string nodeB) {
    if (nodeA == nodeB) return 0;
    unordered_map<string, vector<string>> adj;

    for (auto edge : edges) {
        string a = get<0>(edge), b = get<1>(edge);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<pair<string, int>> q;
    unordered_set<string> vis;
    q.push({ nodeA, 0 });
    vis.insert(nodeA);

    while (!q.empty()) {
        auto top = q.front(); q.pop();
        string curNode = top.first; int dis = top.second;

        for (auto neighbor : adj[curNode]) {
            if (vis.count(neighbor))
                continue;

            if (neighbor == nodeB)
                return dis + 1;

            q.push({ neighbor, dis + 1 });
            vis.insert(neighbor);
        }
    }

    return 0;
}

// largest component
// https://structy.net/problems/largest-component
int dfs_largestComponent(unordered_map<int, vector<int>>& graph, unordered_set<int>& vis, int src) {
    if (vis.count(src))
        return 0;

    vis.insert(src);
    int size = 1;
    for (auto node : graph[src])
        size += dfs_largestComponent(graph, vis, node);

    return size;
}

int largestComponent(unordered_map<int, vector<int>> graph) {
    unordered_set<int> vis;

    int mx = 0;
    for (auto kv : graph) {
        if (!vis.count(kv.first)) {
            mx = max(mx, dfs_largestComponent(graph, vis, kv.first));
        }
    }

    return mx;
}

// connected component
// https://structy.net/problems/connected-components-count

int dfs_connectedComponentsCount(unordered_map<int, vector<int>>& graph, unordered_set<int>& vis, int src) {
    if (vis.count(src))
        return 0;

    vis.insert(src);
    for (auto node : graph[src])
        dfs_connectedComponentsCount(graph, vis, node);

    return 1;
}

int connectedComponentsCount(unordered_map<int, vector<int>> graph) {
    unordered_set<int> vis;

    int count = 0;
    for (auto kv : graph) {
        if (!vis.count(kv.first)) {
            count += dfs_connectedComponentsCount(graph, vis, kv.first);
        }
    }

    return count;
}

// undirected graph
// https://structy.net/problems/undirected-path
unordered_set<string> is_path_vis;
bool is_path_undirectedtPath(unordered_map<string, vector<string>> adj, string src, string dst) {
    if (src == dst) return true;

    is_path_vis.insert(src);

    for (auto v : adj[src]) {
        if (!is_path_vis.count(v) && is_path_undirectedtPath(adj, v, dst))
            return true;
    }

    return false;
}

bool undirectedPath(vector<tuple<string, string>> edges, string src, string dst) {
    unordered_map<string, vector<string>> adj;

    for (auto edge : edges) {
        adj[get<0>(edge)].push_back(get<1>(edge));
        adj[get<1>(edge)].push_back(get<0>(edge));
    }

    return is_path_undirectedtPath(adj, src, dst);
}

// directed graph
bool has_path(vector<vector<int>> graph, int src, int des) {
    if (src == des) return true;

    for (auto node : graph[src]) {
        if (has_path(graph, node, des))
            return true;
    }

    return false;
}

bool bfs_graph(vector<vector<int>> graph, int source) {
    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int curNode = q.front(); q.pop();
        cout << curNode << endl;

        for (int node : graph[curNode])
            q.push(node);
    }


    return true;
}

void dfs_graph_recursion_helper(vector<vector<int>> graph, int source) {
    cout << source << endl;

    for (int node : graph[source])
        dfs_graph_recursion_helper(graph, node);
}

bool dfs_graph_recursion(vector<vector<int>> graph, int source) {
    dfs_graph_recursion_helper(graph, source);

    return true;
}

bool dfs_graph(vector<vector<int>> graph, int source) {
    stack<int> stk;
    stk.push(source);

    while (!stk.empty()) {
        int curNode = stk.top(); stk.pop();
        cout << curNode << endl;

        for (int node : graph[curNode])
            stk.push(node);
    }
    return true;
}

// 206 
ListNode* reverse_recursion(ListNode* head, ListNode* newHead) {
    if (!head)
        return newHead;
    ListNode* next = head->next;
    head->next = newHead;
    return reverse_recursion(next, head);
}

ListNode* reverseList_Recursion(ListNode* head) {
    return reverse_recursion(head, NULL);
}

// 206
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next)
        return head;
    ListNode* cur = head;
    ListNode* rev = head;
    ListNode* temp = head;
    cur = cur->next;
    temp->next = NULL;

    while (cur)
    {
        rev = cur;
        cur = cur->next;
        rev->next = temp;
        temp = rev;
    }

    return rev;
}

// 2130
int pairSum(ListNode* head) {
    if (!head) return 0;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* temp = NULL;
    ListNode* revHead = NULL;
    int sum = 0;

    while (fast->next) {
        fast = fast->next->next;

        temp = slow->next;
        slow->next = revHead;
        revHead = slow;
        slow = temp;
    }

    while (slow->next) {
        sum = max(sum, slow->val + revHead->val);
        slow = slow->next;
        revHead = revHead->next;
    }

    return sum;
}

// 535
class Encode_and_Decode_TinyURL {
public:
    unordered_map<string, string> long_short, short_long;
    long long val = 0;
    string tinyUrl = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (!long_short.count(longUrl)) {
            string short_url = tinyUrl + to_string(val++);
            long_short[longUrl] = short_url;
            short_long[short_url] = longUrl;
        }

        return long_short[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short_long[shortUrl];
    }
};

// 1315
int sumEvenGrandparent(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int sum = 0;

    while (!q.empty())
    {
        TreeNode* cur = q.front(); q.pop();
        if (!(cur->val % 2)) {
            sum += cur->left ? cur->left->left ? cur->left->left->val : 0 : 0;
            sum += cur->left ? cur->left->right ? cur->left->right->val : 0 : 0;
            sum += cur->right ? cur->right->left ? cur->right->left->val : 0 : 0;
            sum += cur->right ? cur->right->right ? cur->right->right->val : 0 : 0;
        }

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    return sum;
}

int findIndex(vector<int>& nums, int val) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= val)
            right = mid;
        else
            left = mid + 1;
    }

    return left - 1;
}

vector<long long> minOperations(vector<int>& nums, vector<int>& q) {
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    vector<long long> pfx(sz);
    pfx[0] = nums[0];

    for (int i = 1; i < sz; i++) {
        pfx[i] = pfx[i - 1] + nums[i];
    }

    vector<long long> ans(sz);
    long long val = 0;
    for (int i = 0; i < q.size(); i++) {
        int idx = findIndex(nums, q[i]);
        if (idx >= 0) {
            val = ((idx + 1) * q[i]) - pfx[idx];
            val += ((pfx[sz - 1] - pfx[idx]) - ((sz - idx - 1) * 1ll * q[i]));
        }
        else {
            val = pfx[sz - 1] - (sz * q[i]);
        }

        ans.push_back(val);
    }

    return ans;
}

int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int sum = 0;

    sum += min(numOnes, k);
    k -= numOnes;

    if (k > 0 && numZeros > 0) k -= numZeros;

    if (k > 0) sum -= (k * 1);

    return sum;
}

// 1302
int deepestLeavesSum(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int sum = 0, sz = 0;

    while (!q.empty())
    {
        sz = q.size();
        sum = 0;

        for (int i = 0; i < sz; i++) {
            TreeNode* cur = q.front(); q.pop();
            sum += cur->val;

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }

    return sum;
}


// 2149
vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> v(nums.size());

    for (int i = 0, ev = 0, od = 1; i < nums.size(); i++) {
        if (nums[i] >= 0) {
            v[ev] = nums[i];
            ev += 2;
        }
        else {
            v[od] = nums[i];
            od += 2;
        }
    }
    return v;
}

int findSmallestInteger(vector<int>& nums, int value) {
    set<int> s;
    long long mx = INT_MIN, mn = INT_MAX;
    unordered_map<int, long long> mp;

    for (auto num : nums) {
        long long posv = 0;
        if (num >= 0) posv = num % value;
        else {
            num %= value;
            //cout << num << endl;
            if (num < 0) { num += value; posv = num; }
        }

        if (s.count(posv) && value == 1) posv = mx + 1;

        int key = posv;
        if (s.count(posv)) posv = mp[posv] + value;
        while (s.count(posv))
        {
            posv += value;
        }
        mx = max(mx, posv);
        mn = min(mn, posv);
        //cout << "in  " << posv << endl;
        mp[key] = posv;
        s.insert(posv);
    }

    int prev = -1, cnt = 0;
    for (auto num : s) {
        if (++prev != num) return prev;
        cnt = num;
    }
    return ++cnt;
}

vector<int> evenOddBit(int n) {
    int binaryNum[32];

    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    int odd = 0, even = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        if (binaryNum[j]) {
            if (j % 2) even++;
            else odd++;
        }
    }

    vector<int> ans = { even, odd };
    return ans;
}

// bi weekly 100
long long findScore(vector<int>& nums) {
    long long ans = 0;
    vector<pair<int, int>> valueIndex;
    unordered_set<int> indx;

    for (int i = 0; i < nums.size(); i++)
        valueIndex.push_back({ nums[i], i });

    sort(valueIndex.begin(), valueIndex.end(), [](pair<int, int> p1, pair<int, int> p2) {
        if (p1.first == p2.first) return p1.second < p2.second;
        else return p1.first < p2.first;
        });

    for (auto p : valueIndex) {
        if (!indx.count(p.second)) {
            ans += p.first;
            indx.insert(p.second);
            if (p.second > 0) indx.insert(p.second - 1);
            if (p.second < nums.size() - 1) indx.insert(p.second + 1);
        }
    }

    return ans;
}

int maximizeGreatness(vector<int>& nums) {
    return 0;
}

int distMoney(int money, int children) {
    money -= children;
    if (money < 0) return -1;

    int v = children;
    int ans = 0;
    while (money >= 7 && v--)
    {
        money -= 7;
        ans++;
    }
    if (money > 0 && v == 0) ans--;
    if (money == 3 && v == 1) ans--;
    if (ans <= 0) return 0;
    return ans;
}

int minV = INT_MAX;
bool isValidMaxValue(vector<vector<int>>& mat, int mid, int t) {
    if (mid == 1)
        if (minV <= t)
            return true;
        else
            return false;

    for (int row = mid - 1.; row < mat.size(); row++) {
        for (int col = mid - 1; col < mat[0].size(); col++) {
            /*int a = mat[row][col];
            int b = (row - mid) >= 0 ? mat[row - mid][col] : 0;
            int c = (col - mid) >= 0 ? mat[row][col - mid] : 0;
            int d = (row - mid) >= 0 && (col - mid) >= 0 ? mat[row - mid][col - mid] : 0;
            int val = a - b - c + d;*/
            int val = mat[row][col]
                - ((row - mid) >= 0 ? mat[row - mid][col] : 0)
                - ((col - mid) >= 0 ? mat[row][col - mid] : 0)
                + ((row - mid) >= 0 && (col - mid) >= 0 ? mat[row - mid][col - mid] : 0);

            if (val <= t) return true;
        }
    }

    return false;
}

// 1292
int maxSideLength(vector<vector<int>>& mat, int threshold) {
    // 2d prefix sum

    for (int row = 0; row < mat.size(); row++) {
        for (int col = 0; col < mat[row].size(); col++) {
            minV = min(minV, mat[row][col]);
            mat[row][col] += (row > 0 ? mat[row - 1][col] : 0)
                + (col > 0 ? mat[row][col - 1] : 0)
                - (row > 0 && col > 0 ? mat[row - 1][col - 1] : 0);
        }
    }

    int left = 0, right = min(mat.size(), mat[0].size()) + 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isValidMaxValue(mat, mid, threshold))
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left - 1;
}

// 2589
int findMinimumTime(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const auto& t1, const auto& t2) {
        return t1[1] < t2[2];
        });

    vector<int> v(2001);
    int cnt = 0;

    for (auto task : tasks) {
        int st = task[0], end = task[1], d = task[2];

        for (int i = st; i <= end; i++) {
            if (v[i]) d--;
            else if (i + d - 1 == end) {
                v[i] = 1;
                cnt++;
                d--;
            }
        }
    }

    return cnt;
}

// weekly contest

int maxScore(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());

    unsigned long long pfx = 0;

    for (int i = 0; i < nums.size(); i++) {
        pfx += nums[i];
        if (pfx <= 0) return i;
    }

    return nums.size();
}

int vowelStrings(vector<string>& words, int left, int right) {
    int cnt = 0;
    unordered_set<char> st{ 'a', 'e', 'i', 'o', 'u' };
    for (int i = left; i <= right; i++) {
        string word = words[i];
        if (st.count(word[0]) && st.count(word[word.size() - 1]))
            cnt++;
    }
    return cnt;
}

// 2424. Longest Uploaded Prefix
class LUPrefix {
    unordered_set<int> st;
    int cur = 0;
public:
    LUPrefix(int n) {

    }

    void upload(int video) {
        st.insert(video);

        while (st.find(cur + 1) != st.end())
            st.erase(++cur);
    }

    int longest() {
        return cur;
    }
};


long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

int findValidSplit(vector<int>& nums) {
    long long suff = 1;
    for (int i = 1; i < nums.size(); i++) {
        suff *= nums[i];
    }
    long long pref = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        long long gcdv = gcd(pref, suff);
        if (gcdv == 1) return i - 1;
        else {
            pref *= nums[i];
            suff /= nums[i];
        }
    }

    return -1;
}

long long kthLargestLevelSum(TreeNode* root, int k) {
    if (root == NULL) return -1;
    queue<TreeNode*> q;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    q.push(root);
    pq.push(root->val);

    while (!q.empty()) {
        int sz = q.size();
        long long lvlS = 0;

        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) {
                q.push(node->left);
                lvlS += node->left->val;
            }
            if (node->right) {
                q.push(node->right);
                lvlS += node->right->val;
            }
        }
        pq.push(lvlS);
        if (pq.size() > k) pq.pop();
    }
    return pq.top() == 0 ? -1 : pq.top();
}

int passThePillow(int n, int time) {
    int rem = time % (n - 1);
    int rnd = time / (n - 1);

    if (rnd % 2)
        return 1 + (n - 1 - rem);
    else
        return 1 + rem;
}

// ByWeekly Contest 99

long ColoredCells(int n) {
    return (long)(n - 1) * 2 * n + 1;
}

int splitNum(int num) {
    vector<int> v;

    while (num > 0) {
        v.push_back(num % 10);
        num /= 10;
    }
    sort(v.begin(), v.end());

    int num1 = 0, num2 = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i % 2) {
            num1 = (num1 * 10) + v[i];
        }
        else {
            num2 = (num2 * 10) + v[i];
        }
    }
    return num1 + num2;
}

int testcode() {
    string num1 = "123456789012345678901234567890";
    string num2 = "1234567890";

    /*boost::multiprecision::cpp_int n1(num1);
    boost::multiprecision::cpp_int n2(num2);

    boost::multiprecision::cpp_int rem = n1 % n2;

    if (rem == 0) {
        std::cout << num1 << " is divisible by " << num2 << std::endl;
    }
    else {
        std::cout << num1 << " is not divisible by " << num2 << std::endl;
    }*/

    return 2;
}

// 1552
bool isMaxDistance(vector<int>& pos, int mid, int m) {
    int cnt = 1, prev = pos[0];

    for (int i = 1; i < pos.size() && (m - cnt) <= (pos.size() - i); i++) {
        if (pos[i] - prev >= mid) {
            prev = pos[i];
            ++cnt;
        }
    }

    return cnt >= m;
}

int maxDistance(vector<int>& pos, int m) {
    if (m == 2) {
        return *max_element(pos.begin(), pos.end()) - *min_element(pos.begin(), pos.end());
    }

    sort(pos.begin(), pos.end());
    int left = 1, right = pos[pos.size() - 1];

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (!isMaxDistance(pos, mid, m))
            right = mid;
        else
            left = mid + 1;
    }
    return left - 1;
}

int rangeSum(vector<int>& nums, int n, int left, int right) {
    // priority queue less
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mqueue;
    for (int i = 0; i < n; i++)
        mqueue.push({ nums[i], i + 1 });

    int ans = 0, mod = 1e9 + 7;
    for (int i = 1; i <= right; i++) {
        auto p = mqueue.top();
        mqueue.pop();
        if (i >= left)
            ans = (ans + p.first) % mod;
        if (p.second < n) {
            p.first += nums[p.second++];
            mqueue.push(p);
        }
    }
    return ans;

    /*
    another solution
    vector<int> sums { };
    for (int i = 0; i < n; i++) {
        int prefixSum = 0;
        for (int j = i; j < n; j++) {
            prefixSum += nums[j];
            sums.push_back(prefixSum);
        }
    }
    sort(begin(sums), end(sums));
    // accumulate func er data return based on third arguments
    int res = accumulate(sums.begin() + left - 1, sums.begin() + right, 0LL) % 1000000007;
    return res;
    */
}

// 6367
int maxNumOfMarkedIndices(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    sort(nums.begin(), nums.end());
    int cnt = 0, n = nums.size();

    for (int i = 0, j = (n + 1) / 2; i < (n + 1) / 2; i++) {
        while (j < n) {
            if (2 * nums[i] <= nums[j]) {
                cnt += 2;
                j++;
                break;
            }
            else
                j++;
        }
    }

    return cnt;
}

// 6368
vector<int> divisibilityArray(string word, int m) {
    vector<int> ans;
    int num = 0, dig = 0, rem = 0;

    for (auto c : word) {
        dig = c - '0';
        num = rem * 10 + dig;
        if (num % m == 0) ans.push_back(1);
        else ans.push_back(0);
    }
    return ans;

}

// 6369
vector<int> leftRigthDifference(vector<int>& nums) {
    int rSum = 0, lSum = 0;
    for (auto num : nums) rSum += num;

    vector<int> ans;
    for (auto num : nums) {
        rSum -= num;
        ans.push_back(abs(rSum - lSum));
        lSum += num;
    }
    return ans;
}

// 23
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* ansList = new ListNode(-100001);

    for (int i = 0; i < lists.size(); i++) {
        ListNode* ansHead = ansList;
        ListNode* cur = lists[i];

        while (cur) {
            // for the rest of the nodes
            if (!ansHead->next) {
                ansHead->next = cur;
                break;
            }
            // for middle nodes
            else if (cur->val <= ansHead->next->val) {
                auto temp = ansHead->next;
                ansHead->next = cur;
                cur = cur->next;
                ansHead->next->next = temp;
                ansHead = ansHead->next;
            }
            else {
                ansHead = ansHead->next;
            }
        }
    }
    return ansList->next;
}

// 540
bool isRight(vector<int>& nums, int mid) {
    if (nums[mid] == nums[mid + 1]) {
        if (mid % 2 == 0) return false;
        else return true;
    }
    else {
        if (mid % 2 == 1) return false;
        else return true;
    }
}

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    int left = 0, right = n;

    while (right - left) {
        int mid = left + (right - left) / 2;

        if (isRight(nums, mid))
            right = mid;
        else
            left = mid + 1;
    }

    return nums[left];
}

// 1760
bool isValidminimumSize(vector<int>& nums, int mid, int op) {
    int cnt = 0;

    for (auto num : nums) {
        if (num > mid) cnt += (num - 1) / mid;
    }

    return cnt <= op;
}

int minimumSize(vector<int>& nums, int maxOperations) {
    int left = 1, right = *max_element(nums.begin(), nums.end());

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isValidminimumSize(nums, mid, maxOperations))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    do {
        if (!fast || !fast->next) return NULL;
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// 287
// by using floyd's cycle detection algorithm
int findDuplicate(vector<int>& nums) {
    int fast = 0, slow = 0;

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (fast != slow);

    slow = 0;
    while (fast != slow) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

// 2498
int maxJump(vector<int>& stones) {
    int mx = 0, n = stones.size();

    for (int i = 1; i < n - 1; i++) {
        mx = max(mx, max(stones[i] - stones[i - 1], stones[i + 1] - stones[i - 1]));
    }
    // for last element
    mx = max(mx, (stones[n - 1] - stones[n - 2]));

    return mx;
}

// 378
int binarySearchToCountSmaller(vector<int>& vec, int val) {
    int left = 0, right = vec.size();

    if (vec[left] > val) return left;
    if (vec[right - 1] < val) return right;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] > val)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

bool isThereMorethanKth(vector<vector<int>>& mat, int k, int mid) {
    int cnt = 0;

    for (int i = 0; i < mat.size(); i++) {
        cnt += binarySearchToCountSmaller(mat[i], mid);

        if (cnt >= k) return true;
    }

    return false;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0], high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isThereMorethanKth(matrix, k, mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

// 2517
int isValidMaxTastiness(vector<int>& price, int val, int k) {
    int count = 1, prev_val = price[0];
    for (int i = 1; i < price.size(); i++) {
        if (abs(prev_val - price[i]) >= val) {
            prev_val = price[i];
            count++;
        }
        if (count >= k) return true;
    }
    return false;
}

int maximumTastiness(vector<int>& price, int k) {
    int left = 1, right = 1000000000;
    sort(price.begin(), price.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isValidMaxTastiness(price, mid, k)) {
            left = mid + 1;
        }
        else
            right = mid;
    }
    return left - 1;
}

// 2358
int maximumGroups(vector<int>& grades) {
    int left = 0, right = 1000, n = grades.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mid * (mid + 1) / 2 > n)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

// 852
int peakIndexInMountainArray(vector<int>& arr) {
    int left = 1, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= arr[mid + 1])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

long long minCost(vector<int>& b1, vector<int>& b2) {
    unordered_map<int, int> cnt;
    for (auto c : b1) cnt[c]++;
    for (auto c : b2) cnt[c]--;
    vector<int> vec;

    for (auto& [k, v] : cnt) {
        if (v % 2) return -1;

        for (int i = 0; i < abs(v) / 2; i++)
            vec.push_back(k);
    }

    int minX = min(*min_element(b1.begin(), b1.end()), *min_element(b2.begin(), b2.end()));
    sort(vec.begin(), vec.end());

    long long res = 0;
    for (int i = 0; i < vec.size() / 2; i++)
        res += min(vec[i], minX * 2);

    return res;
}

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int> v, ans;
    unordered_map<char, int> vowel;
    vowel['a'] = 1;
    vowel['e'] = 1;
    vowel['i'] = 1;
    vowel['o'] = 1;
    vowel['u'] = 1;


    int sum = 0;
    for (auto word : words) {
        if (vowel[word[0]] && vowel[word[word.size() - 1]])
            sum += 1;

        v.push_back(sum);
    }


    for (auto q : queries) {
        if (q[0] == 0)
            ans.push_back(v[q[1]]);
        else
            ans.push_back(v[q[1]] - v[q[0] - 1]);
    }
    return ans;
}

long long pickGifts(vector<int>& gifts, int k) {
    long long ans = 0;
    priority_queue<int> q;

    for (auto gift : gifts) q.push(gift);

    for (int i = 0; i < k; i++) {
        int top = q.top(); q.pop();
        top = pow(top, 0.5);
        q.push(top);
    }

    while (!q.empty()) {
        ans += q.top();
        q.pop();
    }
    return ans;
}

// 953
bool isAlienSorted(vector<string>& words, string order) {
    vector<int> oDict(26, 0);

    for (int i = 0; i < order.size(); i++)
        oDict[order[i] - 'a'] = i;

    for (int i = 1; i < words.size(); i++) {
        string a = words[i - 1], b = words[i];
        for (int j = 0; j < a.size(); j++) {
            if (j >= b.size())
                return false;
            if (a[j] != b[j]) {
                if (oDict[a[j] - 'a'] > oDict[b[j] - 'a'])
                    return false;
                else
                    break;
            }
        }
    }

    return true;
}

// 1071
string modOfStrings(string a, string b) {
    if (a.size() < b.size()) return a;
    int rem = a.size() % b.size();
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i % b.size()]) return "f";
    }

    return rem == 0 ? "" : a.substr(a.size() - rem, rem);
}

string gcdOfStrings(string a, string b) {
    if (a == "f" || b == "f") return "";
    return b == "" ? a : gcdOfStrings(b, modOfStrings(a, b));
}

// 6339
long long putMarbles(vector<int>& weights, int k) {
    if (k == 1 || weights.size() == k) return 0;

    long long mx = 0, mn = 0;
    vector<int> pair_sum;

    for (int i = 1; i < weights.size(); i++) {
        pair_sum.push_back(weights[i] + weights[i - 1]);
    }

    sort(pair_sum.begin(), pair_sum.end());
    for (int i = 0; i < k - 1; i++) mn += pair_sum[i];
    for (int i = pair_sum.size() - 1; i > pair_sum.size() - k; i--) mx += pair_sum[i];
    return mx - mn;
}

// 1539
int findKthPositive(vector<int>& arr, int k) {
    if (k < arr[0]) return k;
    int n = arr.size();
    if (k > arr[n - 1] - n) return k + n;
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] - (mid + 1) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    //int res = (k - (arr[left - 1] - left)) + arr[left - 1];
    return k + left;
}

int isValidSpecial(int x, vector<int>& nums) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (x <= nums[mid])
            right = mid;
        else
            left = mid + 1;
    }
    // here left = minimum index
    int diff = nums.size() - left;
    if (x == diff) return 1;
    else if (x < diff) return 2; // increase x value
    else return 0; // decrease x value
}

// 1608
int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if (nums[nums.size() - 1] == 0) return -1;
    int left = 1, right = nums.size() + 1;
    int mid = -1;
    while (left < right) {
        mid = left + (right - left) / 2;
        int val = isValidSpecial(mid, nums);
        if (val == 1) return mid;
        else if (val == 0)
            right = mid;
        else
            left = mid + 1;
    }

    return -1;
}

bool bsToFindElem(int num, vector<int>& arr) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == num)
            return true;
        else if (arr[mid] > num)
            right = mid;
        else
            left = mid + 1;
    }
    return false;
}

// 888
vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    vector<int> v(2);
    int aSum = 0, bSum = 0;
    for (auto num : aliceSizes) aSum += num;
    for (auto num : bobSizes) bSum += num;
    sort(bobSizes.begin(), bobSizes.end());

    //int dif = abs(aSum - bSum);
    // x + (dif/2) = y
    // 2y = bSum - aSum + x + x
    for (auto x : aliceSizes) {
        int y = (bSum - aSum + x + x) / 2;
        if (bsToFindElem(y, bobSizes) && (aSum - x + y) == (bSum - y + x)) {
            v[0] = x;
            v[1] = y;
            break;
        }
    }

    return v;
}

// 268
// using binary search
int missingNumber(vector<int>& nums) {
    int left = 0, right = nums.size();
    sort(nums.begin(), nums.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > mid) right = mid;
        else left = mid + 1;
    }
    return left;
}

// 1385
bool bsToFindDistanceValue(int down, int up, vector<int>& arr2, int d) {
    int left = 0, right = arr2.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr2[mid] > up)
            right = mid;
        else if (arr2[mid] < down)
            left = mid + 1;
        else
            return false;
    }
    return true;
}

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    sort(arr2.begin(), arr2.end());
    int count = 0;
    for (auto num : arr1) {
        int down = min((num - d), (num + d));
        int up = max((num - d), (num + d));
        if (bsToFindDistanceValue(down, up, arr2, d)) count++;
    }

    return count;
}


struct comparePQ {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

// 1337
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparePQ> pq;
    vector<int> ans;
    for (int i = 0; i < mat.size(); i++) {
        int count = 0;
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] == 1) count++;
        }
        pq.push({ count, i });
    }

    for (int i = 0; i < k; i++) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

int binary_max_subSeq_sum(int q, vector<int>& nums) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > q)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

// 2389
vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());

    // makes nums array as prefix sum
    for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
    }

    vector<int> ans;
    for (auto q : queries) {
        ans.push_back(binary_max_subSeq_sum(q, nums));
    }
    return ans;
}

bool isSmallesDivisor(int divisor, vector<int>& nums, int threshold) {
    int res = 0;
    for (auto num : nums) {
        res += ceil(double(num) / double(divisor));
        if (res > threshold)
            return false;
    }

    return res <= threshold;
}

// 149
int maxPoints(vector<vector<int>>& points) {
    int mx = 0;
    int sz = points.size();
    for (int i = 0; i < sz - 1; i++) {
        int x1 = points[i][0], y1 = points[i][1];
        map<double, int> mp;
        for (int j = i + 1; j < sz; j++) {
            int x2 = points[j][0], y2 = points[j][1];
            double slope = DBL_MAX;
            if (x1 != x2)
                slope = double(y1 - y2) / double(x1 - x2);

            //cout << "1st point " << x1 << " " << y1 << " 2nd " << x2 << " " << y2 << "  slope = " << slope << endl;
            mp[slope]++;
            mx = max(mx, mp[slope]);
        }
    }
    return mx + 1;
}

// 1283
int smallestDivisor(vector<int>& nums, int threshold) {
    int right = 0, left = 1;
    for (auto num : nums)
        right = max(num, right);

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isSmallesDivisor(mid, nums, threshold))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

// 1833
int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int count = 0;

    for (auto cost : costs) {
        if (cost <= coins) {
            coins -= cost;
            count++;
        }
        else break;
    }
    return count;
}

// 2244
int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> mp;
    int count = 0;

    for (auto t : tasks)
        mp[t]++;

    for (auto kv : mp) {
        int val = kv.second;
        cout << val << endl;
        if (val == 1) return -1;
        int rem = val % 3;

        count += val / 3;
        if (rem > 0) count++;
    }
    return count;
}

// 944
int minDeletionSize(vector<string>& strs) {
    char maxStr[1001] = {};
    int cnt = 0;
    for (auto str : strs) {
        for (int i = 0; i < str.size(); i++) {
            if (maxStr[i] != 'X') {
                if (maxStr[i] != '\0' && maxStr[i] > str[i]) {
                    cnt++;
                    maxStr[i] = 'X';
                }
                else
                    maxStr[i] = str[i];
            }
        }
    }
    return cnt;
}

bool enoughThanK(vector<int>& nums, int dis, int k) {
    int count = 0, i = 0, j = 0;

    while (i <= j && (i < nums.size() || j < nums.size())) {
        while (j < nums.size() && nums[j] - nums[i] <= dis)
            j += 1;
        count += j - i - 1;
        i += 1;
    }

    return count >= k;
}

// 719
int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums[nums.size() - 1] - nums[0];

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (enoughThanK(nums, mid, k))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

// 520
bool detectCapitalUse(string w) {
    bool isAllCap = true, isFirstCap = true, isAllSmall = true;

    if (w[0] >= 'a' && w[0] <= 'z') {
        isFirstCap = false;
        isAllCap = false;
    }

    for (int i = 0; i < w.size(); i++) {
        if (isAllSmall && w[i] >= 'A' && w[i] <= 'Z')
            isAllSmall = false;
        if (isAllCap && w[i] >= 'a' && w[i] <= 'z')
            isAllCap = false;
        if (isFirstCap && i > 0 && w[i] >= 'a' && w[i] <= 'z')
            isFirstCap = false;

        if (!isAllCap && !isFirstCap && !isAllSmall)
            return false;
    }
    return true;
}

// 290
bool wordPattern(string pattern, string s) {
    stringstream ss(s);
    string word;
    unordered_map<char, string> mp;
    unordered_map<string, int> wordTrack;
    int indx = 0;

    while (getline(ss, word, ' ')) {
        if (indx >= pattern.size())
            return false;

        if (mp[pattern[indx]].empty() && wordTrack[word] == 0) {
            mp[pattern[indx]] = word;
            wordTrack[word] = 1;
        }
        else if (mp[pattern[indx]] != word)
            return false;

        indx++;
    }
    return indx == pattern.size() - 1;
}

bool isValidKthNum(int num, int m, int n, int k) {
    int count = 0;
    for (int i = 1; i <= m; i++) {
        count += min((num / i), n);
    }
    return count >= k;
}

// 668
int findKthNumber(int m, int n, int k) {
    int left = 1, right = m * n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isValidKthNum(mid, m, n, k))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

bool isValidDay(int days, vector<int>& bloomDay, int m, int k) {
    int flowers = 0, bouquets = 0;

    for (auto bloom : bloomDay) {
        if (days < bloom)
            flowers = 0;
        else {
            bouquets += (flowers + 1) / k;
            flowers = (flowers + 1) % k;
        }
    }

    return bouquets >= m;
}

// 1482
int minDays(vector<int>& bloomDay, int m, int k) {
    int left = 0, right = 0;

    if (m * k > bloomDay.size())
        return -1;

    for (auto day : bloomDay) {
        left = min(day, left);
        right = max(day, right);
    }

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isValidDay(mid, bloomDay, m, k))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

//1046
int lastStoneWeight(vector<int>& stones) {
    vector<int> v(1001);

    priority_queue<int> pq;
    for (auto stone : stones) {
        pq.push(stone);
    }

    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        pq.push(x - y);
    }

    return pq.top();
}

//1433
bool checkIfCanBreak(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    bool isGreater = false, isLesser = false;

    for (int i = 0; i < s1.size(); i++) {
        if (isGreater || isLesser) {
            if (isGreater && s1[i] < s2[i])
                return false;
            else if (isLesser && s1[i] > s2[i])
                return false;
        }

        else if (s1[i] > s2[i])
            isGreater = true;

        else if (s1[i] < s2[i])
            isLesser = true;
    }

    return true;
}

// 984
string strWithout3a3b(int a, int b) {
    string res = "";
    bool isA = false;
    bool isB = false;


    while (a + b > 0) {
        int mx = max(a, b);
        if ((!isB && mx == a) || isA) {
            if (!res.empty() && res[res.size() - 1] == 'a')
                isB = true;
            else {
                isA = false;
                isB = false;
            }
            res += "a";
            --a;
        }
        else if ((!isA && mx == b) || isB) {
            if (!res.empty() && res[res.size() - 1] == 'b')
                isA = true;
            else {
                isA = false;
                isB = false;
            }
            res += "b";
            --b;
        }
    }
    return res;
}

// 767
string reorganizeString(string s) {
    vector<int> count(26);
    priority_queue<pair<int, int>> pq;

    for (auto c : s) {
        count[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i])
            pq.push(make_pair(count[i], i));
    }

    pair<int, int> prev = make_pair(0, -1);
    string res = "";

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        if (prev.second != -1)
            pq.push(prev);

        int resLast = -100;
        if (res.size() > 0)
            resLast = res[res.size() - 1] - 'a';
        if (top.second == resLast) {
            res = "";
            break;
        }

        res += (char(top.second) + 'a');

        if (top.second >= -1 && --top.first > 0) {
            prev = top;
        }
        else
            prev = make_pair(0, -1);

        if (pq.empty() && prev.second != -1)
            pq.push(prev);
    }


    return res;
}

// 870
vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    vector<int> res(nums1.size());
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < nums2.size(); i++) {
        pq.push(make_pair(nums2[i], i));
    }
    int lo = 0, hi = nums2.size() - 1;

    while (!pq.empty()) {
        auto pr = pq.top();
        if (nums1[hi] > pq.top().first) {
            res[pq.top().second] = nums1[hi--];
        }
        else {
            res[pq.top().second] = nums1[lo++];
        }
        pq.pop();
    }
    return res;
}

// 6214
bool haveConflict(vector<string>& event1, vector<string>& event2) {
    int e1StH = stoi(event1[0].substr(0, 2));
    int e1StM = stoi(event1[0].substr(3, 2));
    int e1EndH = stoi(event1[1].substr(0, 2));
    int e1EndM = stoi(event1[1].substr(3, 2));

    int e2StH = stoi(event2[0].substr(0, 2));
    int e2StM = stoi(event2[0].substr(3, 2));
    int e2EndH = stoi(event2[1].substr(0, 2));
    int e2EndM = stoi(event2[1].substr(3, 2));

    int e1St = e1StH * 60 + e1StM;
    int e1End = e1EndH * 60 + e1EndM;
    int e2St = e2StH * 60 + e2StM;
    int e2End = e2EndH * 60 + e2EndM;

    if ((e2St <= e1End && e2St >= e1St) || (e1St <= e2End && e1St >= e2St) || (e2End <= e1End && e2End >= e1St) || (e1End <= e2End && e1End >= e2St))
        return true;
    return false;
}

bool isValidSpeed(int speed, vector<int>& piles, int h) {
    int cur = 0;
    for (auto pile : piles) {
        cur += ceil(double(pile) / double(speed));
    }
    return cur <= h;
}

// 875
int minEatingSpeed(vector<int>& piles, int h) {
    int left = piles[0], right = piles[0];
    long long sum = 0;

    for (auto pile : piles) {
        sum += pile;
        right = max(right, pile);
    }
    left = (sum / h) == 0 ? 1 : (sum / h);
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isValidSpeed(mid, piles, h))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

bool isValidSplit(int sum, vector<int>& nums, int k) {
    int curK = 0, curSum = 0;

    for (auto num : nums) {
        if (curSum + num > sum) {
            curSum = 0;
            curK++;
        }
        curSum += num;
    }

    return ++curK <= k;
}

// 410
int splitArray(vector<int>& nums, int k) {
    int left = nums[0], right = 0;

    for (auto num : nums) {
        left = max(left, num);
        right += num;
    }

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isValidSplit(mid, nums, k))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

bool isValidCapacity(int capacity, vector<int>& weights, int days) {
    int indx = 0;
    for (int i = 0; i < days; i++) {
        int cur = 0;
        while (indx < weights.size() && cur + weights[indx] <= capacity) {
            cur += weights[indx];
            indx++;
        }
    }

    return indx == weights.size();
}

// 1011
int shipWithinDays(vector<int>& weights, int days) {
    int sum = 0, maxWeight = weights[0];
    for (auto weight : weights) {
        sum += weight;
        maxWeight = max(weight, maxWeight);
    }

    int left = maxWeight, right = sum + 1;

    while (left < right) {
        int midCapacity = left + (right - left) / 2;
        if (isValidCapacity(midCapacity, weights, days))
            right = midCapacity;
        else
            left = midCapacity + 1;
    }

    return left;
}

//35
// ideal binary search
int searchInsert(vector<int>& nums, int target) {

    int lo = 0, hi = nums.size()-1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] >= target)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

// 69
int mySqrt(int x) {
    if (x == 0) return x;
    int lo = 1, hi = x / 2;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2 + 1;
        if (mid <= x / mid)
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

bool isBadVersion(int version) {
    if (version >= 14)
        return true;
    else
        return false;
}

// 278
int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int firstBadVersion2(int n) {

    if (isBadVersion(1)) {
        return 1;
    }

    int i = 1;
    int j = n;

    while (i < j) {
        int mid = i + (j - i) / 2 + 1;
        if (!isBadVersion(mid)) {
            i = mid;
        }
        else {
            j = mid - 1;
        }
    }

    return j + 1;

}

// 6207
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int minX = min(minK, maxK);
    int maxX = max(minK, maxK);

    long long count = 0;
    bool minF = false, maxF = false;
    int curLen = 0;

    if (minX != maxX) {
        for (auto n : nums) {
            if (n == minX) {
                minF = true;
                if (maxF) count++;
            }
            else if (n == maxX) {
                maxF = true;
                if (minF) count++;
            }
            else if (n < minX || n > maxX) {
                minF = false;
                maxF = false;
            }
            else if (minF && maxF)
                count++;
        }
    }
    else {
        for (auto n : nums) {
            if (n == minX)
                curLen++;
            else {
                curLen = 0;
                count += ((curLen * (curLen + 1)) / 2);
            }
        }
        if (curLen > 0)
            count += ((curLen * (curLen + 1)) / 2);
    }
    return count;
}

// 6205
int reverseIntDigits(int n) {
    int reversed_number = 0, remainder;

    while (n != 0) {
        remainder = n % 10;
        reversed_number = reversed_number * 10 + remainder;
        n /= 10;
    }
    return reversed_number;
}

// 6219
bool sumOfNumberAndReverse(int num) {
    for (int i = 1; i < num; i++) {
        if (i + reverseIntDigits(i) == num)
            return true;
    }
    return false;
}

int countDistinctIntegers(vector<int>& nums) {
    unordered_map<int, int> mp;

    for (auto n : nums) {
        if (mp[n] == 0)
            mp[n] = 1;

        int rev = reverseIntDigits(n);
        if (mp[rev] == 0)
            mp[rev] = 1;
    }

    return mp.size();
}

// 6204
int findMaxK(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int maxVal = 0;

    for (int i = 0, j = nums.size() - 1; i < j; ) {
        if (nums[i] < 0) {
            if ((-1 * nums[i]) == nums[j])
                return nums[j];
            else if ((-1 * nums[i]) < nums[j])
                j--;
            else
                i++;
        }
        else
            return -1;
    }
    return -1;
}

// 6209
vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers;
    int temp = 0, mod = 1e9 + 7;
    while (n > 0) {
        if (n % 2 == 1)
            powers.push_back(pow(2, temp));

        temp++;
        n /= 2;
    }
    for (auto a : powers)
        cout << a << endl;
    vector<long long> prefixProd;
    vector<int> res;

    prefixProd.push_back(powers[0]);
    for (int i = 1; i < powers.size(); i++) {
        prefixProd.push_back(((prefixProd[i - 1] % mod) * (powers[i] % mod)) % mod);
    }

    for (auto q : queries) {
        if (q[0] == q[1])
            res.push_back(powers[q[0]]);
        else {
            int ans = (prefixProd[q[1]] / (q[0] == 0 ? 1 : prefixProd[q[0] - 1])) % mod;
            res.push_back(ans);
        }
    }
    return res;
}

// 6208
int countTime(string time) {
    int hour = 1;
    if (time[0] == '?' && time[1] == '?')
        hour = 24;
    else if (time[0] == '?')
        if (time[1] <= '3')
            hour = 3;
        else
            hour = 2;
    else if (time[1] == '?')
        if (time[0] <= '1')
            hour = 10;
        else
            hour = 4;

    int minute = 1;
    if (time[3] == '?' && time[4] == '?')
        minute = 60;
    else if (time[3] == '?')
        minute = 6;
    else if (time[4] == '?')
        minute = 10;

    return hour * minute;
}

bool canConstruct(string s, int k) {
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
        mp[s[i]]++;

    int oddCount = 0;
    for (auto it : mp)
        if (it.second % 2 == 1)
            oddCount++;

    if (oddCount <= k && k <= s.size())
        return true;
    else
        return false;
}

// 1386
int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    sort(reservedSeats.begin(), reservedSeats.end(), [](vector<int> v1, vector<int> v2) {
        return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
        });

    int cur = 1;
    int count = 0;
    bool left = true, middle = true, right = true;
    for (auto seat : reservedSeats) {
        cout << seat[0] << endl;
        if (seat[0] != cur) {
            if (left && middle && right) count += 2;
            else if (left || middle || right) count += 1;

            count += (seat[0] - cur - 1) * 2;
            cur = seat[0];
            left = true, middle = true, right = true;
        }

        if (seat[1] == 2 || seat[1] == 3) left = false;
        else if (seat[1] == 8 || seat[1] == 9) right = false;
        else if (seat[1] == 4 || seat[1] == 5) left = false, middle = false;
        else if (seat[1] == 6 || seat[1] == 7) right = false, middle = false;

    }
    if (left && middle && right) count += 2;
    else if (left || middle || right) count += 1;
    count += (n - cur) * 2;

    return count;
}

// 1282
vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < groupSizes.size(); i++) {
        mp[groupSizes[i]].push_back(i);
    }

    vector<vector<int>> res;
    for (auto it : mp) {
        while (it.second.size()) {
            int sz = it.first;
            vector<int> temp;
            while (sz--) {
                temp.push_back(it.second.back());
                it.second.pop_back();
            }
            res.push_back(temp);
        }
    }
    return res;
}

map<int, map<int, multiset<int>>> stmap;
void storeDatabyDfs(TreeNode* root, int row, int col) {
    if (!root) return;

    if (col == 0) {
        int a = root->val;
    }

    map<int, multiset<int>> temp;
    multiset<int> set;
    if (stmap[col].find(row) != stmap[col].end())
        set = stmap[col][row];
    set.insert(root->val);
    if (stmap.find(col) != stmap.end())
        temp = stmap[col];
    temp[row] = set;
    stmap[col] = temp;

    storeDatabyDfs(root->left, row + 1, col - 1);
    storeDatabyDfs(root->right, row + 1, col + 1);
}

// 987
vector<vector<int>> verticalTraversal(TreeNode* root) {
    storeDatabyDfs(root, 0, 0);
    vector<vector<int>> ans;

    for (auto it1 : stmap) {
        vector<int> v;
        for (auto it : it1.second) {
            for (auto val : it.second)
                v.push_back(val);
        }
        ans.push_back(v);
    }

    return ans;
}

// 1379
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (!original || !target) return NULL;

    if (original == target)
        return cloned;

    TreeNode* l = getTargetCopy(original->left, cloned->left, target);
    if (l) return l;
    TreeNode* r = getTargetCopy(original->right, cloned->right, target);
    return r;
}

// 863
void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front(); q.pop();

        if (cur->left) {
            mp[cur->left] = cur;
            q.push(cur->left);
        }
        if (cur->right) {
            mp[cur->right] = cur;
            q.push(cur->right);
        }
    }
}


vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> mp;
    markParents(root, mp);
    queue<TreeNode*> q;
    vector<int> visited(501, 0);
    q.push(target);
    visited[target->val] = 1;

    while (!q.empty() && k--) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* cur = q.front(); q.pop();

            if (cur->left && !visited[cur->left->val]) {
                q.push(cur->left);
                visited[cur->left->val] = 1;
            }
            if (cur->right && !visited[cur->right->val]) {
                q.push(cur->right);
                visited[cur->right->val] = 1;
            }
            if (mp[cur] && !visited[mp[cur]->val]) {
                q.push(mp[cur]);
                visited[mp[cur]->val] = 1;
            }
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}

// 985
vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int sumEv = 0;
    vector<int> ans;

    for (int& i : nums)
        if (i % 2 == 0)
            sumEv += i;

    for (auto query : queries) {
        if (nums[query[1]] % 2 == 0) {
            if (query[0] % 2 == 0)
                sumEv += query[0];
            else
                sumEv -= nums[query[1]];
        }
        else if ((nums[query[1]] + query[0]) % 2 == 0)
            sumEv += nums[query[1]] + query[0];

        nums[query[1]] += query[0];
        ans.push_back(sumEv);
    }
    return ans;
}

// 621
auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    return lhs.second > rhs.second;
};
bool pairComapre(const pair<char, int>& firstElem, const pair<char, int>& secElem) {
    return firstElem.second > secElem.second;
}

// 846
bool isNStraightHand(vector<int>& nums, int k) {
    if (nums.size() % k != 0)
        return false;
    map<int, int> mp;
    map<int, int>::iterator it;
    int val;

    for (int& i : nums)
        mp[i]++;

    for (it = mp.begin(); it != mp.end(); it++) {
        val = it->second;
        if (val) {
            for (int i = 0; i < k; i++) {
                if (mp[it->first + i] < val)
                    return false;
                else
                    mp[it->first + i] -= val;
            }
        }
    }
    return true;
}

// 1296
bool isPossibleDivide(vector<int>& nums, int k) {
    if (nums.size() % k != 0)
        return false;
    map<long, int> mp;
    bool ans = true;
    for (int i = 0; i < nums.size(); i++) mp[nums[i]]++;

    while (!mp.empty() && ans)
    {
        auto it = mp.begin();
        long val = 0;
        int i = 0;
        for (i = 0; i < k && ans && !mp.empty(); i++, it++) {
            if (it == mp.end()) {
                ans = false;
                break;
            }
            if (val == 0)
                val = it->first;

            else if (++val != it->first)
                ans = false;

            --it->second;
            if (it->second == 0) mp.erase(it);
        }
        if (i != k) ans = false;
    }

    return ans;
}

// 1094
bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> from(1001, 0);
    vector<int> to(1001, 0);

    for (auto trip : trips) {
        from[trip[1]] += trip[0];
        to[trip[2]] += trip[0];
    }

    int cur = 0;
    for (int i = 0; i < 1001; i++) {
        cur -= to[i];
        cur += from[i];
        if (cur > capacity) return false;
    }

    return true;
}

// 621
int leastInterval(vector<char>& tasks, int n) {
    if (n == 0) return tasks.size();
    vector<pair<char, int>> vec;
    vector<int> mp(26, 0);

    for (int i = 0; i < tasks.size(); i++) {
        mp[tasks[i] - 'A']++;
    }

    for (int i = 0; i < mp.size(); i++) {
        if (mp[i] > 0)
            vec.push_back(make_pair(i + 'A', mp[i]));
    }

    sort(vec.begin(), vec.end(), [](pair<char, int> p1, pair<char, int> p2) {
        return p1.second > p2.second;
        });

    int cnt = 0, indx = 0;
    bool isFin = false;
    while (!isFin)
    {
        for (int i = 0, j = 0; j < n + 1; j++, i++) {
            if (vec.empty()) {
                isFin = true;
                cnt += i;
                break;
            }
            else if (i >= vec.size()) {
                cnt += n + 1 - j;
                break;
            }

            if (i < vec.size() && vec[i].second > 0) {
                vec[i].second = --vec[i].second;
                if (vec[i].second == 0) {
                    vec.erase(vec.begin() + i--);
                }
                cnt++;
            }
        }
        sort(vec.begin(), vec.end(), [](pair<char, int> p1, pair<char, int> p2) {
            return p1.second > p2.second;
            });
    }

    return cnt;
}

// 860
bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int i = 0; i < bills.size(); i++) {
        if (bills[i] == 20) {
            if (ten > 0 && five > 0)
                ten--, five--;
            else if (five >= 3)
                five -= 3;
            else
                return false;
        }
        else if (bills[i] == 10) {
            if (five > 0) five--, ten++;
            else
                return false;
        }
        else
            five++;
    }
    return true;
}

// 1217
int minCostToMoveChips(vector<int>& position) {
    int odd = 0, even = 0;
    for (int i = 0; i < position.size(); i++) {
        if (position[i] % 2 == 0) even++;
        else odd++;
    }
    return min(odd, even);
}

// 406
// sol2
vector<vector<int>> reconstructQueue_sol2(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int> v1, vector<int> v2) {
        return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]);
        });

    vector<vector<int>> vec(people.size(), vector<int>());
    for (auto person : people) {
        int cnt, j;
        for (cnt = 0, j = 0; j < vec.size(); j++) {
            if (vec[j].empty()) {
                if (person[1] == cnt) break;
                cnt++;
            }
        }
        vec[j] = person;
    }

    return vec;
}

// sol1
vector<vector<int>> reconstructQueue_sol1(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int> v1, vector<int>v2) {
        return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
        });

    vector<vector<int>> vec;
    for (auto person : people) {
        vec.insert(vec.begin() + person[1], person);
    }

    return vec;
}

// 1530
int ansCountPairs = 0;
vector<int> dfsCountPairs(TreeNode* root, int distance) {
    if (!root) return {};
    if (!root->left && !root->right) return { 1 };

    vector<int> left = dfsCountPairs(root->left, distance);
    auto right = dfsCountPairs(root->right, distance);

    for (int i = 0; i < left.size(); i++) {
        for (int j = 0; j < right.size(); j++) {
            if (left[i] + right[j] <= distance)
                ansCountPairs++;
        }
    }

    vector<int> newVec;
    for (int i = 0; i < left.size(); i++) {
        if (left[i] + 1 < distance)
            newVec.push_back(left[i] + 1);
    }
    for (int i = 0; i < right.size(); i++) {
        if (right[i] + 1 < distance)
            newVec.push_back(right[i] + 1);
    }
    return newVec;
}

int countPairs(TreeNode* root, int distance) {
    auto x = dfsCountPairs(root, distance);
    return ansCountPairs;
}

// Weekly Contest 309
int longestNiceSubarray(vector<int>& nums) {
    int st = -1, maxLen = 0;

    for (int i = 1; i < nums.size(); i++) {
        int bitNum = nums[i - 1] & nums[i];
        int revNum = nums[i] & nums[i - 1];

        cout << " bit " << bitNum << "  rev " << revNum << endl;

        if (bitNum == 0) {
            if (st == -1)
                st = i - 1;
            maxLen = max(maxLen, i - st);
        }
        else
            st = -1;
    }
    return maxLen;
}

// contest

// 2398
int maximumRobots(vector<int>& times, vector<int>& costs, long long budget) {
    multiset<int> setTimes;
    long long sum = 0;
    int i = 0, n = times.size();
    for (int j = 0; j < n; j++) {
        sum += costs[j];
        setTimes.insert(times[j]);

        if (*rbegin(setTimes) + (j - i + 1) * sum > budget) {
            sum -= costs[i];
            setTimes.erase(setTimes.find(times[i++]));
        }
    }
    return n - i;
}



// 6172

string conv(int decimal, int base) {
    if (decimal == 0) return "0";
    char NUMS[] = "0123456789ABCDEF";
    std::string result = "";
    do {
        result.push_back(NUMS[decimal % base]);

        decimal /= base;
    } while (decimal != 0);

    return std::string(result.rbegin(), result.rend());
}
int checkPalindrome(string str)
{
    int len = str.length();

    for (int i = 0; i < len / 2; i++) {

        if (str[i] != str[len - i - 1])
            return false;
    }

    return true;
}

bool isStrictlyPalindromic(int n) {
    for (int i = 2; i <= n - 2; i++) {
        string con_val = conv(n, i);
        cout << con_val << endl;
        if (!checkPalindrome(con_val))
            return false;
    }
    return true;
}

// 6171
bool findSubarrays(vector<int>& nums) {
    unordered_map<long, int> mp;

    for (int i = 1; i < nums.size(); i++) {
        long val = nums[i - 1] + nums[i];
        if (mp[val] == 1)
            return true;
        mp[val] = 1;
    }
    return false;
}


// 1026
int maxDiffAncestor = 0;
pair<int, int> dfsMaxAncestor(TreeNode* root) {
    if (!root) return { -1, -1 };

    auto left = dfsMaxAncestor(root->left);
    auto right = dfsMaxAncestor(root->right);

    cout << "left :" << left.first << " " << left.second << " " << "right :" << right.first << " " << right.second << endl;
    int minVal = root->val, maxVal = root->val;
    if (left.first > -1 && right.first > -1)
        minVal = min(minVal, min(left.first, right.first));
    else if (left.first > -1)
        minVal = min(minVal, left.first);
    else if (right.first > -1)
        minVal = min(minVal, right.first);

    if (left.second > -1 && right.second > -1)
        maxVal = max(maxVal, max(left.second, right.second));
    else if (left.second > -1)
        maxVal = max(maxVal, left.second);
    else if (right.second > -1)
        maxVal = max(maxVal, right.second);

    //int minVal = left.first == -1 ? right.first == -1 ? root->val : right.first : min(left.first,right.first);
    //int maxVal = left.second == -1 ? right.second == -1 ? root->val : right.second : min(left.second,right.second);

    int minDiff = abs(root->val - minVal);
    int maxDiff = abs(root->val - maxVal);

    maxDiffAncestor = max(maxDiffAncestor, minDiff);
    maxDiffAncestor = max(maxDiffAncestor, maxDiff);

    return { minVal, maxVal };
}

int maxAncestorDiff(TreeNode* root) {
    if (!root) return 0;
    auto x = dfsMaxAncestor(root);
    return maxDiffAncestor;
}

// 865
pair<TreeNode*, int> helperSubTreeDeepest(TreeNode* root) {
    if (!root) return { NULL, 0 };
    auto left = helperSubTreeDeepest(root->left);
    auto right = helperSubTreeDeepest(root->right);
    if (left.second > right.second)
        return { left.first, left.second + 1 };
    if (right.second > left.second)
        return { right.first, right.second + 1 };

    return { root, left.second + 1 };
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return helperSubTreeDeepest(root).first;
}

// 993
bool isCousins(TreeNode* root, int x, int y) {
    if (!root || root->val == x || root->val == y) return false;
    int xParent = 0, yParent = 0;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();

            if (node->left) {
                q.push(node->left);
                if (node->left->val == x) xParent = node->val;
                else if (node->left->val == y) yParent = node->val;
            }
            if (node->right) {
                q.push(node->right);
                if (node->right->val == x) xParent = node->val;
                else if (node->right->val == y) yParent = node->val;
            }
        }
        if (xParent != 0 && yParent != 0 && xParent != yParent)
            return true;
        else if (xParent != 0 || yParent != 0)
            return false;
    }
    return false;
}

// 958
bool isCompleteTree(TreeNode* root) {
    if (!root) return true;

    queue<pair<TreeNode*, long long>> q;
    q.push(make_pair(root, 1));
    int lvlNode = 1, size = 1;

    while (!q.empty())
    {
        size = q.size();

        for (long long i = 0; i < size; i++) {
            TreeNode* node = q.front().first;
            long long nodeNum = q.front().second;
            q.pop();

            if (nodeNum != (long long)i + 1) return false;
            if (node->left)
                q.push(make_pair(node->left, nodeNum * 2 - 1));
            if (node->right)
                q.push(make_pair(node->right, nodeNum * 2));
        }
        if (!q.empty() && lvlNode != size)
            return false;

        lvlNode *= 2;
    }
    return true;
}

// 662
int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    queue<pair<TreeNode*, long long>> q;
    q.push(make_pair(root, 1));
    long long maxWidth = 1, curWidth = 0, qSize = 0, stIndx = -1, lastIndx = 0, startNodeNum = 0;
    bool isStartNodeNum = false;

    while (!q.empty())
    {
        qSize = q.size();
        stIndx = -1, lastIndx = 0;
        isStartNodeNum = false;
        startNodeNum = 0;

        for (int i = 0; i < qSize; i++) {
            TreeNode* node = q.front().first;
            long long nodeNum = q.front().second;
            cout << nodeNum << endl;
            q.pop();
            lastIndx = nodeNum;

            if (stIndx == -1)
                stIndx = nodeNum;

            if (node->left) {
                q.push(make_pair(node->left, nodeNum - startNodeNum + nodeNum - 1));
                isStartNodeNum = true;
            }
            else if (!isStartNodeNum)
                startNodeNum++;

            if (node->right) {
                q.push(make_pair(node->right, nodeNum - startNodeNum + nodeNum));
                isStartNodeNum = true;
            }
            else if (!isStartNodeNum)
                startNodeNum++;

        }

        curWidth = lastIndx - stIndx + 1;
        maxWidth = max(curWidth, maxWidth);
    }

    return maxWidth;
}

// 222
int countNodes(TreeNode* root) {
    if (!root) return 0;

    int hl = 0, hr = 0;
    TreeNode* l = root, * r = root;
    while (l) { hl++, l = l->left; }
    while (r) { hr++, r = r->right; }

    if (hl == hr) return pow(2, hl) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 114
TreeNode* dfsFlatten(TreeNode* root) {
    if (root == NULL)
        return NULL;

    TreeNode* left = dfsFlatten(root->left);
    if (left) {
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right)
            root = root->right;
        root->right = temp;
    }
    TreeNode* right = dfsFlatten(root->right);
    return root;
}

void flatten(TreeNode* root) {
    dfsFlatten(root);
}

bool isValidBstBool = true;
int prevValBST;
bool unassignedPrevVal = true;
void dfsValidBst(TreeNode* root) {
    if (!root || !isValidBstBool)
        return;

    dfsValidBst(root->left);

    if (unassignedPrevVal) {
        prevValBST = root->val;
        unassignedPrevVal = !unassignedPrevVal;
    }
    else if (root->val > prevValBST) prevValBST = root->val;
    else isValidBstBool = false;

    dfsValidBst(root->right);
}

bool isValidBST(TreeNode* root) {
    dfsValidBst(root);
    return isValidBstBool;
}

int dfsCountValidateBT(vector<int>& l, vector<int>& r, int root) {
    if (root == -1)
        return 0;

    return 1 + dfsCountValidateBT(l, r, l[root]) + dfsCountValidateBT(l, r, r[root]);
}
// 1361
bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    if (n == 1)
        return true;

    vector<int> checkDuplicates(1001, 0), commonEle(1001, 0);

    for (int i = 0; i < n; i++) {
        if (leftChild[i] != -1 && checkDuplicates[leftChild[i]]++ == 1)
            return false;
        if (rightChild[i] != -1 && checkDuplicates[rightChild[i]]++ == 1)
            return false;
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (checkDuplicates[i] == 0)
        {
            if (root == -1)
                return false;
            else
                root = i;
        }
    }
    return dfsCountValidateBT(leftChild, rightChild, root) == n;
}

// 1276
vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    if (tomatoSlices % 2 == 1)
        return {};

    tomatoSlices /= 2;
    int bigBurger = tomatoSlices - cheeseSlices;
    int smallBurger = cheeseSlices - bigBurger;
    if ((bigBurger * 4) + (smallBurger * 2) == tomatoSlices)
        return { bigBurger, smallBurger };
    else
        return {};
}

// 948
int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int score = 0, maxScore = 0;

    for (int i = 0, j = tokens.size() - 1; i <= j;) {
        if (power >= tokens[i]) {
            score++;
            power -= tokens[i++];
        }
        else if (score > 0) {
            power += tokens[j--];
            score--;
        }
        else
            break;

        maxScore = max(score, maxScore);
    }

    return maxScore;
}

// 376
int wiggleMaxLengthDP(vector<int>& nums) {
    int inc = 1, dec = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1])
            inc = dec + 1;
        else if (nums[i] < nums[i - 1])
            dec = inc + 1;
    }

    return max(inc, dec);
}

int wiggleMaxLength(vector<int>& nums) {
    int curDiff = 0, prevDiff = 1001, count = 1;

    for (int i = 1; i < nums.size(); i++) {
        curDiff = nums[i] - nums[i - 1];

        if ((prevDiff < 0 && curDiff > 0) || (prevDiff > 0 && curDiff < 0) || (prevDiff == 1001 && curDiff != 0)) {
            count++;
            prevDiff = curDiff;
        }
    }

    return count;
}

// 881
int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int count = 0;

    for (int i = 0, j = people.size() - 1; i < people.size();) {
        if (people[i] + people[j] <= limit) {
            i++, j++, count++;
        }
        if (people[j] <= limit) {
            j++, count++;
        }
    }

    return count;
}

// 455
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0;

    for (; i < g.size() && j < s.size(); j++) {
        if (s[j] >= g[i])
            i++;
    }

    return i + 1;
}

// 402
string removeKdigits(string num, int k) {
    string ans = "";

    for (auto c : num) {

        while (k > 0 && !ans.empty() && ans[ans.size() - 1] > c)
        {
            ans.pop_back();
            k--;
        }

        ans += c;
    }

    ans = ans.substr(0, ans.size() - k);

    // handling leading zeros
    int cnt = 0;
    while (!ans.empty() && ans[cnt] == '0')
        cnt++;

    ans = ans.substr(cnt, ans.size());
    if (ans.empty())
        return "0";
    return ans;
}

int jump(vector<int>& nums) {
    if (nums.size() == 1)
        return 0;

    int left = 0, right = 0, furthermost = 0, level = 0;
    while (right < nums.size() - 1)
    {
        for (int i = left; i <= right; i++)
            furthermost = max(furthermost, i + nums[i]);

        left = right + 1;
        right = furthermost;
        furthermost = 0;
        level++;
    }

    return level;
}

// 55
bool canJump(vector<int>& nums) {
    int maxV = -1;
    for (int i = 0; i < nums.size() - 1; i++) {
        maxV = max(maxV, nums[i]);
        maxV--;
        if (maxV < 0)
            return false;
    }
    return true;
}

int res;
int leftn = 0, rightn = 0;

int sumNum() {
    return 3 + 5;
}

// 2295
vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) mp[nums[i]] = i;

    for (auto op : operations) {
        nums[mp[op[0]]] = op[1];
        mp[op[1]] = mp[op[0]];
    }
    return nums;
}

// 2232
string minimizeResult(string expression) {
    int idx;
    int n = expression.size();

    for (int i = 0; i < n; i++) {
        if (expression[i] == '+') {
            idx = i;
            break;
        }
    }

    string num1 = expression.substr(0, idx);
    string num2 = expression.substr(idx + 1, n - idx - 1);

    int b1 = 0, b2 = 0, min = INT_MAX, p1, p2;
    string ans;

    for (int b1 = 0; b1 < num1.size(); b1++) {
        for (int b2 = 0; b2 < num2.size(); b2++) {
            string s1 = num1.substr(0, b1);
            string s1Num = num1.substr(b1, num1.size());

            string s2 = num2.substr(b2 + 1, b2 - num2.size() - 1);
            string s2Num = num2.substr(0, b2 + 1);

            if (s1.empty()) p1 = 1;
            else p1 = stoi(s1);

            if (s2.empty()) p2 = 1;
            else p2 = stoi(s2);

            int sum = stoi(s1Num) + stoi(s2Num);
            int eval = p1 * sum * p2;

            if (eval < min) {
                min = eval;
                ans = s1 + "(" + s1Num + "+" + s2Num + ")" + s2;
            }
        }
    }
    return ans;
}

int findbyRec(TreeNode* root) {
    if (!root)
        return 0;

    int left = findbyRec(root->left);
    int right = findbyRec(root->right);
    res += abs(left - right);
    return left + right + root->val;
}

int findTilt(TreeNode* root) {
    if (!root)
        return 0;

    int x = findbyRec(root);
    return res;
}

map<int, int> mp;
int countPalPath = 0;

void dfsPalindromicPath(TreeNode* root) {
    if (!root)
        return;

    mp[root->val]++;
    if (!root->left && !root->right) {
        int countOdd = 0;
        for (auto it : mp)
            countOdd += (it.second % 2);
        countPalPath += countOdd <= 1 ? 1 : 0;
    }

    dfsPalindromicPath(root->left);
    dfsPalindromicPath(root->right);

    if (root)
        mp[root->val]--;
}

int pseudoPalindromicPaths(TreeNode* root) {
    dfsPalindromicPath(root);
    return countPalPath;
}

TreeNode* dfsBuildTreePostIn(int postStart, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder) {
    if (inStart > inEnd || postStart < 0 || inStart >= inorder.size())
        return NULL;

    TreeNode* root = new TreeNode(postorder[postStart]);
    int index = 0;
    for (index = inStart; index < inEnd; index++) {
        if (postorder[postStart] == inorder[index])
            break;
    }

    root->left = dfsBuildTreePostIn(postStart - (inEnd - index) - 1, inStart, index - 1, inorder, postorder);
    root->right = dfsBuildTreePostIn(postStart - 1, index + 1, inEnd, inorder, postorder);

    return root;
}

// 106
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return dfsBuildTreePostIn(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
}

// 543
int calDiameter(TreeNode* root) {
    if (!root)
        return 0;

    int leftLen = 1 + calDiameter(root->left);
    int rightLen = 1 + calDiameter(root->right);
    res = max(res, leftLen + rightLen);
    return leftLen > rightLen ? leftLen : rightLen;
}

int diameterOfBinaryTree(TreeNode* root) {
    res = -1;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);


    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    calDiameter(root);
    return res;
}

// 617
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)
        return root1;
    else if (!root1 || !root2)
        return root1 ? root1 : root2;

    TreeNode* curRoot1 = root1;
    TreeNode* curRoot2 = root2;
    queue<TreeNode*> q1, q2;
    q1.push(curRoot1);
    q2.push(curRoot2);

    while (!q1.empty() || !q2.empty()) {
        int curNodes = q1.size();

        for (int i = 0; i < curNodes; i++)
        {
            TreeNode* cur1 = q1.front();
            TreeNode* cur2 = q2.front();
            cur1->val += cur2->val;
            q1.pop(); q2.pop();

            if (cur1->left) {
                q1.push(cur1->left);
                q2.push(cur2->left ? cur2->left : new TreeNode(0));
            }
            else if (cur2->left) {
                cur1->left = new TreeNode(0);
                q1.push(cur1->left);
                q2.push(cur2->left);
            }

            if (cur1->right) {
                q1.push(cur1->right);
                q2.push(cur2->right ? cur2->right : new TreeNode(0));
            }
            else if (cur2->right) {
                cur1->right = new TreeNode(0);
                q1.push(cur1->right);
                q2.push(cur2->right);
            }
        }
    }
    return curRoot1;
}

// 111 - BFS will be better solution
int minDepth(TreeNode* root) {
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 1;

    return 1 + min(
        root->left ? minDepth(root->left) : INT_MAX,
        root->right ? minDepth(root->right) : INT_MAX
    );
}

// 110
bool isBalancedTree = true;

int depthCounter(TreeNode* root) {
    if (!root || !isBalancedTree)
        return 0;
    int depthLeft = depthCounter(root->left);
    int depthRight = depthCounter(root->right);
    if (abs(depthLeft - depthRight) > 1)
        isBalancedTree = false;

    return 1 + max(depthLeft, depthRight);
}

bool isBalanced(TreeNode* root) {
    if (!root)
        return true;
    int a = depthCounter(root);
    return isBalancedTree;
}

// 104
int maxDepth(TreeNode* root) {
    if (!root)
        return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// 2260
static int minimumCardPickup(vector<int>& cards) {
    int tracker[1000001] = {}, res = INT_MAX;

    for (int i = 0; i < cards.size(); i++)
    {
        if (tracker[cards[i]])
            res = min(res, i - tracker[cards[i]] + 2);
        tracker[cards[i]] = i + 1;
    }
    return res == INT_MAX ? -1 : res;
}

void RecursiveReverse(vector<char>& s, int i, int j) {
    if (i >= j)
        return;

    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    RecursiveReverse(s, ++i, --j);
}

// 344
void reverseString(vector<char>& s) {
    int i = 0, j = s.size();
    RecursiveReverse(s, i, j);
}

// 2202
int static maximumTop(vector<int>& nums, int k) {

    if (nums.size() == 1 && k % 2 == 1)
        return -1;

    int maxVal = 0;
    for (int num : nums) {
        if (k == 3) {
            int a = k;
        }
        if (k-- == 1) {
            continue;
        }

        maxVal = max(maxVal, num);
        if (k < -0)
            break;


    }

    return maxVal;
}

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq(begin(piles), end(piles));
    int sum = accumulate(begin(piles), end(piles), 0);

    while (k--)
    {
        int x = pq.top(); pq.pop();
        sum -= (x - ceil(x / 2));
    }
    return sum;
}

/*
* 2d vector initialize with size and 0
* vector<vector<int>> vis(r, vector<int>(c, 0));
*
* unordered_set<char> vw({'a', 'e', 'i', 'o', 'u'});
*
*
* // Sorting
* vector<vector<int>>& tasks
* sort(begin(tasks), end(tasks), [](const auto &t1, const auto &t2){
        return t1[1] < t2[1];
    });

    return *max_element(dp.begin(), dp.end());



    using compare function
    static int countBits(int num) {
        int count = 0;

        while (num > 0) {
            count++;
            num &= (num - 1);  // Clear the least significant set bit.
        }

        return count;
    }

    static bool compare(int a, int b) {
        int bitCountA = countBits(a);
        int bitCountB = countBits(b);

        if (bitCountA == bitCountB) {
            return a < b;  // If set bit counts are equal, compare numerically.
        }

        return bitCountA < bitCountB;  // Sort by the set bit count in ascending order.
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }

    // another example

    static int count_setBits_ByFlipping(int n) {
    int count = 0;
    while (n) {
        n = n & n - 1;
        count++;
    }

    return count;
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
*/

#endif 
