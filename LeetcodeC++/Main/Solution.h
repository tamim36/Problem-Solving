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
                    q.push({x, y});
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

    return {path[size(path)/2], path[size(path)/2 - 1]};
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
        st.insert({v[0], v[1]});
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
    vector<int> color(n+1, 0);
    vector<vector<int>> edges(n+1);
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
        string left = str.substr(0, i+1);
        string right = str.substr(i+1);
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

        while (!stk.empty()  && (a == 'A' && b == 'B') || (a == 'C' && b == 'D')) {
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

    int dx[] = {-1, 0, 1};
    int dy[] = {1, 1, 1};
    ++mov;
    mvMov = max(mov, mvMov);
    for (int i = 0; i < 3; i++)
        dfsMaxMoves(grid, m, n, r+dx[i], c+dy[i], prev, mov);
}

int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++) {
        dfsMaxMoves(grid, m, n, i, 0, 0, 0);
    }
    return mvMov-1;
}

int maxMovesBFS(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int mx = 0, lvl = 0;;

    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        q.push({i, 0});

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

        mx = max(lvl-1, mx);
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
        if (!fnd[i]) ans.push_back(i+1);
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
        dfsNumEnclaves(grid, m, n, r+dx[i], c+dy[i]);
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
        if (!vis.count({x, y})) {
            q.push({ x, y });
            vis.insert({x, y});
            val = 0;

            while (!q.empty()) {
                int a = q.front().first, b = q.front().second; q.pop();
                val++;

                for (int j = 0; j < row[a].size(); j++) {
                    if (!vis.count({a, row[a][j]})) {
                        q.push({ a, row[a][j] });
                        vis.insert({ a, row[a][j] });
                    }
                }
                for (int j = 0; j < col[b].size(); j++) {
                    if (!vis.count({ col[b][j], b })) {
                        q.push({col[b][j], b});
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
    for (int i = s.size()-1; i >= 0; i--) {
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
                minv = min(minv, (j - i + n-1));
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
    return dfsconstructMaximumBinaryTree(nums, 0, nums.size()-1);
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
    cout << "root: " << root->val << " ; right: {" << preStart + 1 + idx - inStart << "," << idx+1 << "," << inEnd << "}" << endl;
    root->left = dfsToBuildTree(preStart+1, inStart, idx, pre, in);
    root->right = dfsToBuildTree(preStart+1+idx-inStart, idx+1, inEnd, pre, in);

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
        for (int c = 0; c < n; c++){
            if (isCon[r][c] && r != c) {
                int x = fpFindCircleNum(parent, r);
                int y = fpFindCircleNum(parent, c);
                if (x != y) parent[y] = x;
            }
        }
    }
    
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(fpFindCircleNum(parent ,i));

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
        dfsToMarkLand(grid, vis, r+dx[i], c+dy[i]);
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
    q.push({nodeA, 0});
    vis.insert(nodeA);

    while (!q.empty()) {
        auto top = q.front(); q.pop();
        string curNode = top.first; int dis = top.second;

        for (auto neighbor : adj[curNode]) {
            if (vis.count(neighbor))
                continue;

            if (neighbor == nodeB)
                return dis + 1;

            q.push({neighbor, dis+1});
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

    storeDatabyDfs(root->left, row+1, col-1);
    storeDatabyDfs(root->right, row+1, col+1);
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
