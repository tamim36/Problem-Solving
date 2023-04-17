class Solution {
public:
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
        pq.push({count, i});
    }

    for (int i = 0; i < k; i++) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}
};