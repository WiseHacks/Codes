#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(I,v,b) for(int I=v;I<b;I++)
#define FORit(it,v) for(auto it=v.begin();it!=v.end();it++)
#define ROF(I,v,b) for(int I=v;I>=b;I--)
#define vec vector
#define vi vec<int>
#define pb push_back
#define pp pop_back
#define all(x) x.begin(),x.end()
#define testcases int tc;cin>>tc;while(tc--)
#define mem(v,k) memset(v,k,sizeof(v))
#define FF first
#define SS second
#define rt return
#define br break
#define ct continue
#define endl "\n"
#define ii pair<int,int>
#define vecin(v,n,index) for(int I=index;I<n;I++)cin>>v[I];
#define vecout(v,n,index) for(int I=index;I<n;I++)cout<<v[I]<<" ";cout<<endl;

// auto = Node*
struct Node
{
    int key;
    struct Node *left, *right;
    Node(int k) {
        key = k;
        left = right = NULL;
    }
};
void inorder(auto root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
void preorder(auto root) {
    if (root) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void insert(auto &root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return ;
    }
    if (val == root->key)return;
    else if (val > root->key)insert(root->right, val);
    else insert(root->left, val);
}
void insertIterative(auto &root, int val) {
    auto cur = root;
    Node* parent = NULL;
    while (cur) {
        parent = cur;
        if (cur->key == val)return;
        if (val > cur->key)cur = cur->right;
        else cur = cur->left;
    }
    // pass by ref can't be used since we change cur;
    // parent for linking
    cur = new Node(val);
    if (parent == NULL)root = cur;
    else if (val > parent->key) {
        parent->right = cur;
    }
    else parent->left = cur;
}
Node* getSuccesor(Node* cur) {
    // the closest greater value, left most leaf of the right child.;
    cur = cur->right;
    while (cur && cur->left) {
        cur = cur->left;
    }
    return cur;
}
Node* deleteNode(Node* root, int val) {
    if (root == NULL)return root;
    if (val < root->key) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->key) {
        root->right = deleteNode(root->right, val);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* succ = getSuccesor(root);
            root->key = succ->key;
            root->right = deleteNode(root->right, succ->key);
        }
    }
    return root;
}
bool search(auto root, int val) {
    if (root == NULL)return false;
    else if (val == root->key)return true;
    else if (val > root->key)return search(root->right, val);
    else return search(root->left, val);
}
void solve() {
    cout << "Time for binary search tree\n";
    vi v = {15, 5, 20, 3, 18, 80, 16, 16};
    Node* root = NULL;
    for (int i = 0; i < v.size(); i++) {
        insert(root, v[i]);
    }
    inorder(root);
    cout << endl;
    // preorder(root);
    if (search(root, 16))cout << "YES!\n";
    else cout << "OH NO\n";

    insertIterative(root, 13);
    inorder(root);
    cout << endl;
    cout << "Introducing deletion\n";
    root = deleteNode(root, 16);
    inorder(root);

}

signed main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);

    // testcases
    solve();
}


