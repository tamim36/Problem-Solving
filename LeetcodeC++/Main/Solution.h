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








#endif 
