给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1

示例 2:
输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？

--------------------------------------------
思路：这就是一颗二叉排序树，先序遍历可以直接排序了！！！直接遍历呗

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//12ms
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inOrder(root,ans);
        
        return ans[k - 1];
    }
    
    void inOrder(TreeNode* p,vector<int> &ans){
        if(p == NULL)return ;
        
        inOrder(p->left,ans);
        ans.push_back(p->val);
        inOrder(p->right,ans);
    }
};


---------------
//动态 4ms
class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        return inOrder(root, k);
    }
    
    int inOrder(TreeNode* root, int& k)
    {
        if(!root) return -1;
        int val = inOrder(root->left, k);
        if(k == 0) return val;
        if(--k == 0) return root->val;
        return inOrder(root->right, k);
    }
};

