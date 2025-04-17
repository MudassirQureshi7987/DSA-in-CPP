#include <vector>
#include <queue>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// BFS solution of problem
vector<vector<int>> listOfDepthsBFS(TreeNode* root) {
        vector<vector<int> > result;
        if(root == NULL)    return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();   // Number of nodes at each level
            vector<int> temp;

            for(int i = 0;i < levelSize;i++)
            {
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);

                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }

            result.push_back(temp);
        }

        return result;
}


// DFS solution

#include <vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* node, int level, vector<vector<int>>& result) {

    // base case
    if(node == NULL)    return ;

    // If this is the first time we are visiting this level,
    // we need to add a new list to hold values at this depth
    if(level == result.size())  result.push_back(vector<int> ());   // create a new level

    result[level].push_back(node->val);

    dfs(node->left,level+1,result);
    dfs(node->right,level+1,result);
}

vector<vector<int>> listOfDepths(TreeNode* root) {
        vector<vector<int> > result;
        dfs(root,0,result);
        return result;
}
