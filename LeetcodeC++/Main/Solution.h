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

    if (dp[start][end-1] != -1)
        return dp[start][end] == 1 ? true : false;

    if (sum < m) {
        dp[start][end-1] = 0;
        return false;
    }

    if (end - start <= 2) {
        isSpliArray = true;
        dp[start][end-1] = 1;
        return true;
    }
    bool left = recurCanSplitArray(nums, dp, start + 1, end, sum - nums[start], m);
    bool right = recurCanSplitArray(nums, dp, start, end - 1, sum - nums[end - 1], m);

    if (left || right)
        dp[start][end-1] = 1;
    else
        dp[start][end-1] = 0;

    return dp[start][end-1];
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

void dfsCountCompleteComponents(vector<vector<int>>& graph, int cur, vector<int>& vis, int &node, int &edge) {
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






#endif 
