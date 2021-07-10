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
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
void preorder(auto root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(auto root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}
int sizeTree(auto root) {
    if (root != NULL) {
        return 1 + sizeTree(root->left) + sizeTree(root->right);
    }
    return 0;
}
int maxofBT(auto root) {
    if (root != NULL) {
        return max(root->key, max(maxofBT(root->left), maxofBT(root->right)));
    }
    return -1e9;
}
void solve() {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right->right = new Node(60);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    cout << sizeTree(root) << endl;
    queue<Node*> q;
    // iterative code using queue for size of binary tree
    {
        int cnt = 0;
        if (root)q.push(root);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
            cnt++;
        }
        cout << cnt << endl;
    }
    //-----
    int maxe;
    maxe = maxofBT(root);
    cout << "maximum = " << maxe << endl;
    // Iterative inorder traversal
    {
        auto cur = root;
        stack<Node*> s;
        while (cur || !s.empty()) {
            while (cur)s.push(cur), cur = cur->left;
            cur = s.top();
            s.pop();
            cout << cur->key << " ";
            cur = cur->right;
        }
        cout << endl;
    }
    //-----

    // Iterative preorder traversal
    {
        auto cur = root;
        stack<Node*> s;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cout << cur->key << " ";
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            cur = cur->right;
        }
        cout << "Another method(both same lol - O(n), O(h)) with good space complexity ----" << endl;
        cur = root;
        s.push(cur);
        while (!s.empty()) {
            while (cur) {
                cout << cur->key << " ";
                if (cur->right)
                    s.push(cur->right);
                cur = cur->left;
            }
            if (!s.empty()) {
                cur = s.top();
                s.pop();
            }
        }
    }
    //-----


}

signed main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);

    testcases
    solve();
}


