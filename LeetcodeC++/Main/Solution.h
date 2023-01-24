#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

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
    for (int i = 0; i < sz-1; i++) {
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
    return mx+1;
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
        count += min((num/i), n);
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

    while(!pq.empty()) {
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
        cur += ceil(double(pile)/ double(speed));
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
    left = (sum / h) == 0 ? 1 : (sum/h);
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

    int left = maxWeight, right = sum+1;

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
int searchInsert(vector<int>& nums, int target) {

    int lo = 0, hi = nums.size() - 1;

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
            else if(minF && maxF)
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
        prefixProd.push_back(((prefixProd[i-1]%mod) * (powers[i]%mod))%mod);
    }

    for (auto q : queries) {
        if (q[0] == q[1])
            res.push_back(powers[q[0]]);
        else {
            int ans = (prefixProd[q[1]] / (q[0] == 0 ? 1 : prefixProd[q[0]-1]) ) % mod;
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

    storeDatabyDfs(root->left, row+1, col-1);
    storeDatabyDfs(root->right, row+1, col+1);
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

    for (auto query : queries){
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
    for (int j = 0; j < n; j++){
        sum += costs[j];
        setTimes.insert(times[j]);

        if (*rbegin(setTimes) + (j-i+1) * sum > budget) {
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

    cout << "left :" << left.first << " " << left.second << " " <<"right :" << right.first << " " << right.second << endl;
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

    maxDiffAncestor = max(maxDiffAncestor,minDiff);
    maxDiffAncestor = max(maxDiffAncestor,maxDiff);
    
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
                q.push(make_pair(node->left, nodeNum*2 - 1));
            if (node->right)
                q.push(make_pair(node->right, nodeNum*2));
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
    TreeNode *l = root, *r = root;
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

    for (int i = 0, j = people.size()-1; i < people.size();) {
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
    string num2 = expression.substr(idx+1, n - idx - 1);

    int b1 = 0, b2 = 0, min = INT_MAX, p1, p2;
    string ans;

    for (int b1 = 0; b1 < num1.size(); b1++) {
        for (int b2 = 0; b2 < num2.size(); b2++) {
            string s1 = num1.substr(0, b1);
            string s1Num = num1.substr(b1, num1.size());

            string s2 = num2.substr(b2+1, b2 - num2.size() - 1);
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


#endif 
