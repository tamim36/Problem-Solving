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
