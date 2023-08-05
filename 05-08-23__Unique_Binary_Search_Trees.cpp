/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTree(int size,int s,int e) {
        if(size==0){
            return {NULL};
        }
        if(size==1){
            TreeNode* temp = new TreeNode(s);
            return {temp};
        }
       vector<TreeNode*>ans;
        for(int i=s;i<=e;i++){
            vector<TreeNode*>v1 = generateTree(i-s,s,i-1);
             vector<TreeNode*>v2 = generateTree(e-i,i+1,e);
             for(int j=0;j<v1.size();j++){
                 for(int k=0;k<v2.size();k++){
                     TreeNode* temp = new TreeNode(i);
                     temp->left = v1[j];
                     temp->right = v2[k];
                     ans.push_back(temp);
                 }
             }   
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTree(n,1,n);
    }
};