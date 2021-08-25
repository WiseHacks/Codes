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

const int N = 1e5 + 1;
struct node {
    map<char, int> mp; // char, vertex(index);
    bool terminal = 0;
};
struct Trie {
    node A[N]; // trie structure;
    int ptr = 2;
    void insert(string s) {
        int cur = 1;
        for (auto &c : s) {
            if (A[cur].mp.count(c)) {
                cur = A[cur].mp[c];
            }
            else {
                A[cur].mp[c] = ptr++;
                cur = A[cur].mp[c];
            }
        }
        A[cur].terminal  = 1;
    }
    bool search(string s) {
        int cur = 1;
        for (auto &c : s) {
            if (!A[cur].mp.count(c)) {
                rt 0;
            }
            else {
                cur = A[cur].mp[c];
            }
        }
        return A[cur].terminal;
    }
    bool startsWith(string s) {
        int cur = 1;
        for (auto &c : s) {
            if (!A[cur].mp.count(c)) {
                rt 0;
            }
            else {
                cur = A[cur].mp[c];
            }
        }
        rt 1;
    }

};

void solve() {
    Trie T;
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


