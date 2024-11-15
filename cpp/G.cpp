
#include "bits/stdc++.h"

#ifndef DeBuG
#define dbg(...)
#endif

using namespace std;
typedef long long int ll;
#define print(x) cout<< #x <<" = "<< x<<"\n";
#define nl "\n"
#define sp " "
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define pii pair<int,int>

const int nmax = 2e5+10;
vector<int> adj[nmax];
vector<int> clr(nmax);
vector<ll> ans(nmax, 0);

struct DS{
    set<int> st;
    int len;

    DS(){

    }

    DS(int u){
        st.insert(clr[u]);
        len=1;
    }

    void merge(DS &D2){
        if(len < D2.len){
            swap(st, D2.st);
            swap(len, D2.len);
        }
        for(auto a : D2.st){
            st.insert(a);
        }
        len += D2.len;
        D2.st.clear();
    }
};

vector<DS> sack(nmax);

void dfs(int u, int p){
    sack[u] = DS(u);
    for(int v : adj[u]) if(v!=p) {
        dfs(v, u);
        sack[u].merge(sack[v]);
    }
    ans[u] = sz(sack[u].st);
}

// Distinct Colors
// https://cses.fi/problemset/task/1139

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>clr[i];
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    for(int i=1; i<=n; i++) cout<<ans[i]<<sp;
    cout<<nl;
    return 0;
}