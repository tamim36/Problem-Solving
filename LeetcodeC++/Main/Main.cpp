// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Main.h"
#include "Solution.h"

//#include "SortingAlgorithms.h"



int main()
{
    std::cout << "Hello World!\n";
    //vector<int> vect{ 35,43,23,86,23,45,84,2,18,83,79,28,54,81,12,94,14,0,0,29,94,12,13,1,48,85,22,95,24,5,73,10,96,97,72,41,52,1,91,3,20,22,41,98,70,20,52,48,91,84,16,30,27,35,69,33,67,18,4,53,86,78,26,83,13,96,29,15,34,80,16,49 };
    vector<int> vect1{ 4,5,2,1 };
    vector<char> chvect{ 'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E' };
    //int a = Solution::maximumTop(vect, 5);

    // Binary Tree Generate
    //struct TreeNode* root = new TreeNode(5);

    vector<int> vect2 = { 21 };
    vector<string> vs = { "06:20","06:28" };
    vector<string> vs1 = { "04:01","06:44" };
    //Solution *sln = new Solution;
    //int ab = *sln.findTilt(root);
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);

    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(7);

    //tree->right->left->left = new TreeNode(119);
    //tree->right->left->right = new TreeNode(135);

    //TreeNode* c = buildTree(vect, vec);   
    auto res = answerQueries(vect1, vect2);

    //cout << b << endl;
}

