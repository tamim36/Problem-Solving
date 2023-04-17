// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Main.h"
#include "Solution.h"

//#include "SortingAlgorithms.h"

TreeNode* buildManualTree() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    //tree->left->left = new TreeNode(4);
    //tree->left->right = new TreeNode(5);

    //tree->right->left = new TreeNode(6);
    //tree->right->right = new TreeNode(7);

    //tree->right->left->left = new TreeNode(119);
    //tree->right->left->right = new TreeNode(135);

    return tree;
}

ListNode* buildListNode(vector<int> vec) {
    ListNode* head = new ListNode(vec[0]);
    ListNode* node = head;

    for (int i = 1; i < vec.size(); i++) {
        node->next = new ListNode(vec[i]);
        node = node->next;
    }

    return head;
}

int main()
{
    std::cout << "Hello World!\n";
    vector<int> vect1{ 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
    vector<char> chvect{ 'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E' };
    //int a = Solution::maximumTop(vect, 5);

    // Binary Tree Generate
    //struct TreeNode* root = new TreeNode(5);

    vector<int> vect2 = { 1,2,3,4,5,6 };
    vector<string> vs = { "aba","leetcode" , "ee", "a", "abba"};
    vector<string> vs1 = { "04:01","06:44" };

    vector<vector<int>> vect2d{
        {1, 2},
        {3},
        {3},
        {}
    };

    vector<vector<int>> vect2dT{
        {2}
    };

    unordered_map<int, vector<int>> graph{
      { 0, {8, 1, 5} },
      { 1, {0} },
      { 5, {0, 8} },
      { 8, {0, 5} },
      { 2, {3, 4} },
      { 3, {2, 4} },
      { 4, {3, 2} }
    };

    //Solution *sln = new Solution;
    //int ab = *sln.findTilt(root);
    
    TreeNode* c = buildManualTree();

    ListNode* al = buildListNode({1,2,3,4});
    ListNode* bl = buildListNode({2,4,6});
    ListNode* cl = buildListNode({2,6});

    vector<ListNode*> vln = { al, bl, cl };

    auto res = distance(vect1);

    //cout << b << endl;
}

