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
auto FloorOfk(auto root, int k) {
    auto cur = root;
    Node* res = NULL;
    while (cur) {
        if (k == cur->key)return cur;
        if (cur->key < k) {
            res = cur;
            cur = cur->right;
        }
        else {
            cur = cur->left;
        }
    }
    return res;
}
void selfBalancingTree(auto &root, vi v, int L, int R) {
    if (L > R) {root = NULL; rt;}
    int mid = (L + R) / 2;
    root = new Node(v[mid]);
    selfBalancingTree(root->left, v, L, mid - 1);
    selfBalancingTree(root->right, v, mid + 1, R);
}
bool checkBST(auto root, int L, int R) {
    // For every node value we define range for the value and check
    if (root == NULL)rt 1;
    if (root->key >= L && root->key <= R) {
        rt checkBST(root->right, root->key, R)&checkBST(root->left, L, root->key);
    }
    rt 0;
}
int preVal = INT_MIN;
bool checkBSTAlt(auto root) {
    if (root == NULL)rt 1;
    if (!checkBSTAlt(root->left))rt 0;
    if (root->key < preVal) {
        rt 0;
    }
    preVal = root->key;
    rt checkBSTAlt(root->right);
}
bool pairWithGivenSum(auto root, int sum, set<int> &s) {
    if (root == NULL)rt 0;
    if (pairWithGivenSum(root->left, sum, s))rt true;
    if (s.find(sum - root->key) != s.end())rt 1;
    else s.insert(root->key);
    rt pairWithGivenSum(root->right, sum, s);
}
map<int, int> vsum;
void verticalSum(auto root, int curDist) {
    if (root == NULL)rt;
    vsum[curDist] += root->key;
    verticalSum(root->left, curDist - 1);
    verticalSum(root->right, curDist + 1);
}
map<int, vec<Node*>> verticalMp;
void verticalTravs(auto root) {
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        verticalMp[cur.SS].pb(cur.FF);
        if (cur.FF->left)q.push({cur.FF->left, cur.SS - 1});
        if (cur.FF->right)q.push({cur.FF->right, cur.SS + 1});
    }
}
void TopViewBST(auto root) {
    map<int, Node*> mp;
    queue<pair<Node*, int> > q;
    q.push({root, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int dist = cur.SS;
        auto temp = cur.FF;
        if (mp.find(dist) == mp.end())mp[dist] = temp;
        if (temp->left)q.push({temp->left, dist - 1});
        if (temp->right)q.push({temp->right, dist + 1});
    }
    for (auto k : mp) {
        cout << k.SS->key << " ";
    }
    cout << endl;
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

    cout << "\nFloor of the given value in bst\n";
    {
        int k = 19;
        if (!FloorOfk(root, k)) {
            cout << "NULL\n";
        }
        else cout << FloorOfk(root, k)->key << endl;
    }
    cout << "This is self selfBalancingTree \n";
    sort(all(v));
    {
        Node *root = NULL;
        selfBalancingTree(root, v, 0, v.size() - 1);
        inorder(root);
    }
    cout << "\nChecking BST " << checkBST(root, INT_MIN, INT_MAX) << " " << checkBSTAlt(root) << endl;
    set<int> s;
    cout << "Pair with given sum : " << pairWithGivenSum(root, 31, s) << endl;
    cout << "\nVertical sum\n";
    verticalSum(root, 0);
    for (auto k : vsum)cout << k.SS << " ";
    cout << endl;
    cout << "Vertical Traversal\n";
    verticalTravs(root);
    for (auto k : verticalMp) {
        for (auto x : k.SS) {
            cout << x->key << " ";
        }
        cout << endl;
    }
    cout << "TopViewBST\n";
    // TopViewBST(root);
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

