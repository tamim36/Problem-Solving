// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Main.h"
#include "Solution.h"

//#include "SortingAlgorithms.h"

TreeNode* buildManualTree() {
    TreeNode* tree = new TreeNode(-1);
    tree->right = new TreeNode(-1);


    //tree->right->left = new TreeNode(6);
    //tree->right->right = new TreeNode(7);

    //tree->right->left->left = new TreeNode(119);
    //tree->right->left->right = new TreeNode(135);

    return tree;
}


vector<string> parseInputString(const string& input) {
    // Remove leading '[' and trailing ']' characters
    string data = input.substr(1, input.size() - 2);

    // Tokenize the string based on ','
    stringstream ss(data);
    vector<string> tokens;
    string token;
    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    return tokens;
}

TreeNode* buildAutomatedTree(string input) {
    auto nodes = parseInputString(input);

    if (nodes.empty())
        return NULL;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    q.push(root);

    for (int i = 1; i < nodes.size() - 1; i+=2) {
        TreeNode* node = q.front(); q.pop();

        if (nodes[i] != "null") {
            node->left = new TreeNode(stoi(nodes[i]));
            q.push(node->left);
        }
        if (i+1 < nodes.size() && nodes[i + 1] != "null") {
            node->right = new TreeNode(stoi(nodes[i + 1]));
            q.push(node->right);
        }
    }

    return root;
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
    vector<int> vect1{ 2, 2, 3, 7 };
    vector<char> chvect{ 'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E' };
    //int a = Solution::maximumTop(vect, 5);

    // Binary Tree Generate
    //struct TreeNode* root = new TreeNode(5);

    vector<int> vect2 = { 4,1,6,0,2,5 };

    auto trea = buildAutomatedTree("[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]");
    vector<string> vs = { "a==b","b!=a", "c==d", "d==e"};
    vector<string> vs1 = { "04:01","06:44" };

    vector<vector<string>> vectStr2d{
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };

    string vect2dStr = "[[1,2,2],[1,1,0],[0,1,1]]";
    string vect2dStr1 = "[[0,1],[1,2],[2,3],[2,4]]";
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

    ListNode* al = buildListNode({ 5,2,13,3,8 });
    ListNode* bl = buildListNode({2,4,6});
    ListNode* cl = buildListNode({2,6});

    vector<ListNode*> vln = { al, bl, cl };

    int arr[] = { 5,2,3,1,6,7,2 };

    //auto res = combinationSum(vect1, 7);

    // findelements* obj = new findelements(c);
    // auto ans1 = obj->find(1);

    //cout << b << endl;
}

