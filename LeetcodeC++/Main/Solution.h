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

  sort(people.begin(), people.end(), [](vector<int> v1, vector<int>v2) {
        return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
        });

  vector<pair<char, int>> vec;
  sort(vec.begin(), vec.end(), [](pair<char, int> p1, pair<char, int> p2) {
            return p1.second > p2.second;
            });
*/

#endif 
