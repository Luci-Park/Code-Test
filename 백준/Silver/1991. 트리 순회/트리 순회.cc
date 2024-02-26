#include <bits/stdc++.h>

using namespace std;

struct node{
    char value;
    int left = -1;
    int right = -1;
};

void Preorder(node root, vector<node> tree){
    cout<<root.value;
    if(root.left != -1) Preorder(tree[root.left], tree);
    if(root.right != -1) Preorder(tree[root.right], tree);
}


void Inorder(node root, vector<node> tree){
    if(root.left != -1) Inorder(tree[root.left], tree);
    cout<<root.value;
    if(root.right != -1) Inorder(tree[root.right], tree);
}


void Postorder(node root, vector<node> tree){
    if(root.left != -1) Postorder(tree[root.left], tree);
    if(root.right != -1) Postorder(tree[root.right], tree);
    cout<<root.value;
}
int main()
{
    int N; cin >> N;
    vector<node> tree(N);
    for(int i =0; i<N; i++){
        char parent, left, right;
        node newNode;
        cin >> parent >> left >> right;
        newNode.value = parent;
        if(left != '.') newNode.left = left - 'A';
        if(right != '.') newNode.right = right - 'A';
        tree[newNode.value - 'A'] = newNode;
    }
    Preorder(tree[0], tree);
    cout<<endl;
    Inorder(tree[0], tree);
    cout << endl;
    Postorder(tree[0], tree);
    
    return 0;
}