#pragma once
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
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
using namespace std;

class Solution
{

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

public:
    

    vector<int> static inorderTraversal(TreeNode* root) {
        TreeNode current = root;

        while (current != NULL)
        {

        }
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
};

