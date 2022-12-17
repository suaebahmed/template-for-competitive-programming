#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Rep(i,n) for(ll i=0; i<int(n); ++i)
#define read(v) for (auto &it : v) cin >> it;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(s) s.size()
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define deb(x) cout<<"For debug : "<<x<<endl;
#define lowb(a, x) (lower_bound((a).begin(),(a).end(),(x))-(a).begin())
#define uppb(a, x) (upper_bound((a).begin(),(a).end(),(x))-(a).begin())
typedef long long ll;
#define ld long double
#define endl '\n'
#define mod 1000000007
#define m_p make_pair
const int MXN = 2*1e5+10;
const ll INF = LLONG_MAX;
vector<int> G[MXN];
int level[MXN],vis[MXN];
const int K = 20;
int lca[K][MXN];
int n;
 
void dfs(int u=1,int d=0,int p=-1){
    vis[u] = 1;
    level[u] = d;
    lca[0][u] = p;
    for(auto v: G[u]){
        if(!vis[v]){
            dfs(v,d+1,u);
        }
    }
}
 
void build_lca(){
    for(int i=1; i<=K; i++){
        for(int j=1; j<=n; j++){
            if(lca[i-1][j] != -1){
                int par = lca[i-1][j];
                lca[i][j] = lca[i-1][par];
            }
        }
    }
}
 
int LCA(int a,int b){
    if(level[a]>level[b]) swap(a,b);
    int d = level[b]-level[a];
    while(d>0){
        int i = log2(d);
        b = lca[i][b];
        d -= (1<<i);
    }
    if(a==b) return a;
    for(int i=K; i>=0; i--){
        if(lca[i][a]!=-1 && lca[i][a]!=lca[i][b]){
            a = lca[i][a];
            b = lca[i][b];
        }
    }
    return lca[0][a];
}
 
int query(int d,int a){
    while(d>0 && a!=-1){
        int i = log2(d);
        deb(i);
        a = lca[i][a];
        d -= (1<<i);
    }
    return a;
}
 
void solve(){
    int q; cin>>n>>q;
    for(int i=2; i<=n; i++){
        int x; cin>>x;
        G[x].pb(i);
        G[i].pb(x);
    }
    memset(lca,-1,sizeof(lca));
    dfs();
    build_lca();
    for(int i=0; i<q; i++){
        int a,b; cin>>a>>b;
        cout<<LCA(a,b)<<"\n";
    }
}
 
int main(){
    optimize();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tt=1;
    // scanf("%d",&tt);cin>>tt;
    for(int i=1; i<=tt; i++){
        // cout<<"Case #"<<i<<":\n";
        solve();
    }
    return 0;
}