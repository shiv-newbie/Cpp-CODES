// Morris Algorithm for preorder binary traversal

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

int main()
{
    
    TreeNode* root = new TreeNode;
    root->val = 1;
    root->left = new TreeNode;
    root->right = new TreeNode;
    root->left->val = 2;
    root->right->val = 3;
    root->left->left = new TreeNode;
    root->left->right = new TreeNode;
    root->left->left->val = 4;
    root->left->right->val = 5;

    TreeNode* current = root;
    
    while(current)
    {
        if(!current->left)
        {
            printf("%d ", current->val);
            current = current->right;
        }
        else
        {
            TreeNode*n = current->left;
            
            while(n->right != NULL && n->right != current)
                n = n->right;
            
            if(!n->right)
            {
                printf("%d ", current->val);
                n->right = current;
                current = current->left;
            }
            else
            {
                n->right = NULL;
                current = current->right;
            }
        }
    }
    printf("\n");
  
    return 0;
}
