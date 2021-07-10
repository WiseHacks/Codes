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

//-------------------------DEBUGGING----------------------------------
template <typename A, typename B>
string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}
string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
string to_string(bool b) {return (b ? "true" : "false");}
template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++)res += static_cast<char>('0' + v[i]);
	reverse(all(res));
	return res;
}
template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 09
#endif
//--------------------------------------------------------------------
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
void printKdistantNodes(auto root, int k) {
	if (root == NULL)return;
	if (k == 0) {
		cout << root->key << " ";
		return;
	}
	printKdistantNodes(root->left, k - 1);
	printKdistantNodes(root->right, k - 1);
}
int maxLevel = 0;
void printLeftView(auto root, int level) {
	// preorder traversal
	if (root == NULL)return;
	if (maxLevel < level) {
		cout << root->key << " ";
		maxLevel = level;
		//change level, mark this level as visited..
	}
	printLeftView(root->left, level + 1); // calling left subtree, maxlevel changed;
	printLeftView(root->right, level + 1);
}
bool childrenSum(auto root) {
	if (root == NULL)return true;
	// The following condition is crucial!!
	if (root->left == NULL && root->right == NULL)return true;
	int s = 0;
	if (root->left)s += root->left->key;
	if (root->right)s += root->right->key;
	return ((s == root->key) & (childrenSum(root->left)) & (childrenSum(root->right)));
}
int height(auto root) {
	if (root == NULL)return 0;
	else return 1 + max(height(root->left), height(root->right));
}
bool checkBalanced = true;
int checkBalancedTree(auto root) {
	// The difference b/t left and right subtree height should not be >1
	if (root == NULL)return 0;
	int hL = checkBalancedTree(root->left);
	int hR = checkBalancedTree(root->right);
	if (abs(hL - hR) > 1)checkBalanced = false;
	return max(hL, hR) + 1;
}
int checkBalancedTreeAlt(auto root) {
	// The difference b/t left and right subtree height should not be >1
	if (root == NULL)return 0;
	int hL = checkBalancedTreeAlt(root->left);
	if (!hL)return -1;
	int hR = checkBalancedTreeAlt(root->right);
	if (!hR)return -1;
	if (abs(hL - hR) > 1)return -1;
	return max(hL, hR) + 1;
}
int maxWidthofBT(auto root) {
	queue<Node*> q;
	q.push(root);
	int width = 0 ;
	while (!q.empty()) {
		int cnt = q.size();
		width = max(width, cnt);
		// for all nodes at this level, pop all of them and
		// keep pushing(enqueue) their l,r(new level)
		while (cnt--) {
			auto cur = q.front();
			q.pop();
			if (cur->left)q.push(cur->left);
			if (cur->right)q.push(cur->right);
		}
	}
	return width;
}
int pre = 0;
Node* constructTree(vi &Inorder, vi &Preorder, int L, int R) {
	if (L > R)return NULL;
	Node* root = new Node(Preorder[pre++]);
	// find root from preorder, then find left subtree and right subtree from inorder
	int id;
	// We can use hashing here..
	for (int i = L; i <= R; i++) {
		if (Inorder[i] == root->key) {
			id = i;
			break;
		}
	}
	root->left = constructTree(Inorder, Preorder, L, id - 1);
	root->right = constructTree(Inorder, Preorder, id + 1, R);
	return root;
}
int D = 0;
int diameter(auto root) {
	if (root == NULL)return 0;
	int hL = diameter(root->left);
	int hR = diameter(root->right);
	// debug(hL, hR, root->key);
	D = max(D, 1 + hL + hR);
	return max(hL, hR) + 1;
}
// hash can also be used to precompute height for each node
int diameterAlt(auto root) {
	if (root == NULL)return 0;
	int hL = 1 + diameterAlt(root->left);
	int hR = 1 + diameterAlt(root->right);
	// debug(hL, hR, root->key);
	D = max(D, hL + hR - 1);
	return max(hL, hR);
}
vec<Node*> path;
void findPath(auto &root, int k, vec<Node*> &v) {
	if (root == NULL)rt;
	v.pb(root);
	if (root->key == k) {path = v; rt;}
	findPath(root->left, k, v);
	findPath(root->right, k, v);
	v.pp();
}
Node* lca(auto root, int n1, int n2) {
	vec<Node*> v;
	findPath(root, n1, v);
	vec<Node*> path1 = path;
	path.clear(), v.clear();
	findPath(root, n2, v);
	vec<Node*> path2 = path;
	for (int i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++) {
		if (path1[i + 1] != path2[i + 1])return path1[i];
	} return NULL;
}
// GOOD SOLUTION LOL,XD
Node* LCA(auto root, int n1 , int n2) {
	if (root == NULL)return NULL;
	if (root->key == n1 || root->key == n2)return root;
	auto lca1 = LCA(root->left, n1, n2);
	auto lca2 = LCA(root->right, n1, n2);
	if (lca1 != NULL && lca2 != NULL)return root;
	if (lca1 != NULL)return lca1;
	else return lca2;
}
int farthest = 0;
int burnTheTree(auto root, int leaf, int &dis) {
	if (root == NULL)return 0;
	if (root->key == leaf) {
		dis = 0;
		return 1;
	}
	int ldist = -1, rdist = -1;
	int hL = burnTheTree(root->left, leaf, ldist);
	int hR = burnTheTree(root->right, leaf, rdist);
	if (ldist != -1) {
		dis = ldist + 1;
		farthest = max(farthest, hR + dis);
	}
	else if (rdist != -1) {
		dis = rdist + 1;
		farthest = max(farthest, dis + hL);
	}
	return max(hL, hR) + 1;
}
{
int res=0;
int fun(auto root, int B, int &dis){
// burn d tree alt
    if(root==NULL)return 0;
    if(root->val == B){
        dis=0; // dis left leaf tk.. lekin root hi ye hai to abhi b ka b se dis = 0;
        return 1;
    }
    int l=-1,r=-1;
    int hL = fun(root->left,B,l);
    int hR = fun(root->right,B,r);
    if(l!=-1){
        // leaf found in left subtree;
        // cur node se b ka dis = l+1
        // if cur node b hai, to dis(b-b) = 0; height 1;// usko jalne ka time
        // else cur, is not B, B can be left subtree or right,
        // to find dis in left subtree.. we do same thing,in left subtree cur dis.. +l.. aur height right
        dis = l + 1;
        res = max(res,dis+hR);
    }
    else if(r!=-1){
        dis=r+1;
        res=max(res,hL+dis);
    }
    return max(hL,hR)+1;

}
}
int isPerfect(auto root) {
	int cnt = 0, res = 0;
	auto cur = root;
	while (cur)cnt++, cur = cur->left;
	cur = root;
	res = cnt;
	while (cur)cnt--, cur = cur->right;
	if (cnt == 0)return res;
	return 0;
}
int countofNodesInCompleteBT(auto root) {
	if (root == NULL)return 0;
	int h = isPerfect(root);
	if (h)return pow(2, h) - 1;
	else return 1 + countofNodesInCompleteBT(root->left) + countofNodesInCompleteBT(root->right);
}

void serialization(auto root, vec<int> &arr) {
	if (root == NULL) {arr.pb(-1); rt;}
	arr.pb(root->key);
	serialization(root->left, arr);
	serialization(root->right, arr);
}
void deserialization(auto &root, vi v, int &id) {
	if (id == v.size())rt;
	int val = v[id];
	id++;
	if (val == -1) {root = NULL; rt;}
	root = new Node(val);
	deserialization(root->left, v, id);
	deserialization(root->right, v, id);
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
void TopViewBT(auto root) {
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
void BottomViewBT(auto root) {
	map<int, Node*> mp;
	queue<pair<Node*, int> > q;
	q.push({root, 0});
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int dist = cur.SS;
		auto temp = cur.FF;
		mp[dist] = temp;
		if (temp->left)q.push({temp->left, dist - 1});
		if (temp->right)q.push({temp->right, dist + 1});
	}
	for (auto k : mp) {
		cout << k.SS->key << " ";
	}
	cout << endl;
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
	/*
	            10
	           /  \
	          20   30
	        /  \    \
	       40  50   60
	           / \
	          70 80
	*/
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
		cout << "\nAnother method(both same lol - O(n), O(h)) with good space complexity ----" << endl;
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
	cout << "\nLevel order traversal\n";
	// Level order
	{
		queue<Node*> q;
		q.push(root);
		q.push(NULL);
		// push null to mark the level
		while (q.size() > 1) {
			auto cur = q.front();
			q.pop();
			if (cur == NULL) {
				cout << "\n";
				q.push(NULL);
				continue;
			}
			cout << cur->key << " ";
			if (cur->left)q.push(cur->left);
			if (cur->right)q.push(cur->right);
		}
	}
	cout << "Another method for level order\n";
	{
		queue<Node*>q;
		q.push(root);
		while (!q.empty()) {
			int cnt = q.size();
			for (int i = 0; i < cnt; i++) {
				auto cur = q.front();
				q.pop();
				cout << cur->key << " ";
				if (cur->left)q.push(cur->left);
				if (cur->right)q.push(cur->right);
			}
			cout << endl;
		}
	}

	cout << "Print node that are distant k from root\n";
	printKdistantNodes(root, 2);

	cout << "\nPrint left view of bt\n";

	printLeftView(root, 1);
	// Itreative
	cout << "\nIterative printLeftView\n";
	{
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			int cnt = q.size();
			auto cur = q.front();
			// print left most
			cout << cur->key << " ";
			// for all nodes at this level, pop all of them and keep pushing their l,r(new level)
			while (cnt--) {
				cur = q.front();
				q.pop();
				if (cur->left)q.push(cur->left);
				if (cur->right)q.push(cur->right);
			}
		}
	}
	cout << "\nAnother method fro printLeftView\n";
	{
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			int cnt = q.size();
			for (int i = 0; i < cnt; i++) {
				auto cur = q.front();
				q.pop();
				if (i == 0)cout << cur->key << " ";
				if (cur->left)q.push(cur->left);
				if (cur->right)q.push(cur->right);
			}
		}
	}
	cout << "\nNow checking for childrenSum property (Lchild+Rchild = P)\n";
	cout << childrenSum(root) << endl;
	{
		cout << "Making a BT which follows childrenSum\n";
		Node* csumRoot = new Node(20);
		csumRoot->left = new Node(8);
		csumRoot->right = new Node(12);
		csumRoot->left->left = new Node(3);
		csumRoot->left->right = new Node(5);
		cout << "Is childrenSum ? => " << childrenSum(csumRoot) << endl;
	}
	cout << "\nNow checking for balanced tree -->\n";
	checkBalancedTree(root);
	if (checkBalanced)cout << "YES\n";
	else cout << "NO\n";
	{
		cout << "Making imbalanced--\n";
		Node* balancedRoot = new Node(20);
		balancedRoot->left = new Node(8);
		balancedRoot->right = new Node(12);
		balancedRoot->left->left = new Node(3);
		balancedRoot->left->right = new Node(5);
		balancedRoot->left->left->left = new Node(1);
		checkBalanced = 1;
		checkBalancedTree(balancedRoot);
		if (checkBalanced)cout << "YES\n";
		else cout << "NO\n";
		if (checkBalancedTreeAlt(balancedRoot) == -1)cout << "NO\n";
		else cout << "YES\n";
	}
	cout << "\nMaximum width of BT---\n" << maxWidthofBT(root) << endl;

	//Inorder and preorder is given, construct a binary tree;
	cout << "\nConstruct a BT from inorder and preorder\n";
	{
		vi Inorder = {40, 20, 50, 10, 30, 80, 70, 90};
		vi Preorder = {10, 20, 40, 50, 30, 70, 80, 90};
		/*
		        10
		     /     \
		    20     30
		  /  \      \
		40   50     70
		           / \
		          80 90
		*/
		// L root R, root L R
		//
		Node* node = constructTree(Inorder, Preorder, 0, Inorder.size() - 1);
		inorder(node);
		cout << endl;
		preorder(node);
		cout << "Hey, It works!\n";
	}

	cout << "\nSpiral level order traversal\n";
	{
		queue<Node*> q;
		q.push(root);
		int flag = 0;
		while (!q.empty()) {
			int cnt = q.size();
			vi k;
			for (int i = 0; i < cnt; i++) {
				auto cur = q.front();
				k.push_back(cur->key);
				q.pop();
				if (cur->left)q.push(cur->left);
				if (cur->right)q.push(cur->right);
			}
			if (flag == 1)reverse(all(k));
			for (auto x : k)cout << x << " ";
			flag ^= 1;
			// cout << endl;
		}
		cout << "\nAnother method of doing so..(don't need to reverse)\n";
		stack<Node*>s1, s2;
		s1.push(root);
		// idea is, maintain two stacks, if s1 is non empty, print and push its children in s2,
		// while s2 is non empty, print, pop cur and push its children in s1 (R then L)
		while (!s1.empty() || !s2.empty()) {
			while (!s1.empty()) {
				auto cur = s1.top();
				s1.pop();
				cout << cur->key << " ";
				if (cur->left)s2.push(cur->left);
				if (cur->right)s2.push(cur->right);
			}
			while (!s2.empty()) {
				auto cur = s2.top();
				s2.pop();
				cout << cur->key << " ";
				if (cur->right)s1.push(cur->right);
				if (cur->left)s1.push(cur->left);
			}
		}
	}


	cout << "\ndiameter => ";
	diameter(root);
	cout << D << ",";
	D = 0; diameterAlt(root);
	cout << D << endl;

	cout << "\nLowest common ancestor ===> \n";

	// check for node... if we can find nodes under that..
	{
		cout << lca(root, 70, 40)->key << endl;
		cout << LCA(root, 70, 30)->key << endl;
	}

	cout << "Burn a Binary tree from a leaf node..(time taken to burn the tree)\n";
	// burnTheTree(root, 50, 0);
	int dis = 0;
	burnTheTree(root, 50, dis);
	cout << farthest << endl;

	cout << "Count no of nodes in complete bt\nMaking a complete bt...\n";
	{
		Node* root = NULL;
		root = new Node(10);
		root->left = new Node(20);
		root->right = new Node(30);
		root->left->left = new Node(40);
		root->left->right = new Node(50);
		root->right->left = new Node(60);
		root->right->right = new Node(70);
		root->left->left->left = new Node(80);
		root->left->left->right = new Node(90);
		cout << countofNodesInCompleteBT(root) << endl;

	}

	cout << "\nSerialization of Binary tree\n";
	{
		vi v;
		serialization(root, v);
		vecout(v, v.size(), 0);
		Node* root = NULL;
		int id = 0;
		deserialization(root, v, id);
		preorder(root);
	}
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
	cout << "TopViewBT\n";
	TopViewBT(root);
	BottomViewBT(root);
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



