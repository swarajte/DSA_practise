#include <bits/stdc++.h> 
using namespace std;

void inorder_vec(Node*root,vector<int> &vec){
    if(root==NULL){
        return ;
    }

    inorder_vec(root->left,vec);
    vec.push_back(root-<data);
    inorder_vec(root->right,vec);
}

void populate_inorder_vec_in_preorder_fashion(Node*root,vector<int> inorder_vec,int index){
    if(root==NULL){
        return;
    }

    root->data=inorder_vec[index++];
    populate_inorder_vec_in_preorder_fashion(root->left,inorder_vec,index);
    populate_inorder_vec_in_preorder_fashion(root->right,inorder_vec,index);

}
int main()
{

    return 0;
}