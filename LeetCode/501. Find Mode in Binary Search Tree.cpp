//Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
//
//If the tree has more than one mode, return them in any order.
//
//Assume a BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than or equal to the node's key.
//The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//Both the left and right subtrees must also be binary search trees.
//
//
//Example 1:
//
//
//Input: root = [1,null,2,2]
//Output: [2]
//Example 2:
//
//Input: root = [0]
//Output: [0]
//
//
//Constraints:
//
//The number of nodes in the tree is in the range [1, 104].
//-105 <= Node.val <= 105
//
//
//Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <set>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   
};

vector<int> findMode(TreeNode* root) {
    vector<int> all;
    map<int, int> check;
    int max = INT_MIN;
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(root)
    {
        if(!root->left)
        {
            
            if(check.count(root->val) == 0)
                check[root->val] = 1;
            else
                check[root->val] += 1;
            if(check[root->val] > max)
                max = check[root->val];
            
            root = root->right;
        }
        else
        {
            TreeNode* n = root->left;
            
            while(n->right != NULL && n->right != root)
                n = n->right;
            
            if(n->right == NULL)
            {
                n->right = root;
                root = root->left;
            }
            else
            {
                n->right = NULL;
                
                if(check.count(root->val) == 0)
                    check[root->val] = 1;
                else
                    check[root->val] += 1;
                if(check[root->val] > max)
                max = check[root->val];
                
                root = root->right;
            }
        }
    }
    map<int, int>::iterator it;
    
    for(it = check.begin(); it != check.end(); it++)
    {
        if(it->second == max)
            all.push_back(it->first);
    }
    
    return all;
}

int main()
{
    return 0;
}
