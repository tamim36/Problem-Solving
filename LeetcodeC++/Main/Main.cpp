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

vector<vector<int>> parseStringToMatrix(const string& str) {
    vector<vector<int>> matrix;

    string trimmedStr = str.substr(1, str.length() - 2);

    stringstream ss(trimmedStr);
    string token;

    while (getline(ss, token, ']'))
    {
        vector<int> row;
        token = token.substr(token.find('[') + 1);
        stringstream rowStream(token);
        string element;

        while (getline(rowStream, element, ',')) {
            row.push_back(stoi(element));
        }

        matrix.push_back(row);
    }

    return matrix;
}

void visualizeMatrix(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";

        cout << endl;
    }
    
}

int main()
{
    std::cout << "Hello World!\n";
    vector<int> vect1{ 4, 4, 4 };
    vector<char> chvect{ 'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E' };
    //int a = Solution::maximumTop(vect, 5);

    // Binary Tree Generate
    //struct TreeNode* root = new TreeNode(5);

    vector<int> vect2 = { 8,4,10,9,11,2,5,1,6,3,7 };
    vector<string> vs = { "a==b","b!=a", "c==d", "d==e"};
    vector<string> vs1 = { "04:01","06:44" };

    vector<vector<string>> vectStr2d{
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };

    string vect2dStr = "[[0,0]]";
    string vect2dStr1 = "[[5,5],[5,0],[4,4],[0,3],[1,0]]";
    vector<vector<int>> vect2d = parseStringToMatrix(vect2dStr);
    vector<vector<int>> vect2d1 = parseStringToMatrix(vect2dStr1);
    // visualizeMatrix(vect2d);


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

    auto res = countBlackBlocks(3,3, vect2d);

    //cout << b << endl;
}

