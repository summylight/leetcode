#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int nums=0;

vector<int> repeat(TreeNode *root){
    vector<int> res;
    if(root==NULL) return res;
    vector<int> lv=repeat(root->left);
    vector<int> rv=repeat(root->right);
    res.resize(lv.size()+rv.size());
    merge(lv.begin(),lv.end(),rv.begin(),rv.end(),res.begin());
    if(res.size()==0){
        res.push_back(1);
        nums+=root->val;
    }
    else{
        for(int k=0;k!=res.size();++k){
            int ten=1;
            for(int j=0;j!=res[k];++j){
                ten*=10;
            }
            nums+=root->val*ten;
            res[k]++;
        }
    }
    return res;
}
int sumNumbers(TreeNode* root) {
    repeat(root);
}