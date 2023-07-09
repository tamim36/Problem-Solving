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
// check 378 follow up question
// study on this https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/313347/A*-search-in-Python

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
            if (grid[i+1][j]) cnt++;
            if (grid[i][j+1]) cnt++;
            if (grid[i+1][j+1]) cnt++;
            vec[cnt]++;
        }

    }
    return vec;
}

vector<long long> countBlackBlocks_2(int m, int n, vector<vector<int>>& coordinates) {
    vector<long long> vec(5, 0);
    unordered_set<pair<int, int>, pair_hash> st;

    for (auto v : coordinates)
        st.insert({v[0], v[1]});

    for (int i = 0; i < m-1; i++) {
        
        for (int j = 0; j < n-1; j++) {
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

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                q.push({i, j});
                cal[i][j] = 0;
                break;
            }
        }
    }

    while (!q.empty()) {
        auto top = q.front(); q.pop();
        int curVal = cal[top.first][top.second];

        for (int i = 0; i < 4; i++) {
            int x = top.first + dx[i], y = top.second + dy[i];
            if (!curVal && cal[x][y] == -1 && grid[x][y]) {
                q.push({x, y});
                cal[x][y] = 0;
            }
            else if (!grid[x][y]) {
                // value barabo 0 er jonno
            }
            // arekta else onno 1 pawa gese kina check korbo r min dis calculate korbo
        }
    }
    return 0;
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

#endif 
