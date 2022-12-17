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
#define pb emplace_back
#define deb(x) cout<<"For debug : "<<x<<endl;
#define lowb(a, x) (lower_bound((a).begin(),(a).end(),(x))-(a).begin())
#define uppb(a, x) (upper_bound((a).begin(),(a).end(),(x))-(a).begin())
typedef long long ll;
#define ld long double
#define endl '\n'
#define mod 1000000007
const int MXN=1e5+10;
const int INF=INT_MAX;

struct disjoint{
        ll p[MXN];
        ll sz[MXN];
        void Build(ll n)
        {
            for(ll i = 0; i<=n; i++) p[i]=i, sz[i] = 1;
        }
        ll Find(ll x)
        {
            return x==p[x]?x:p[x]=Find(p[x]);
        }
        void Union(ll a, ll b)
        {
            a = Find(a);
            b = Find(b);
            if(sz[a] < sz[b]) swap(a,b);
            p[b] = a;
            sz[a] += sz[b];
        }
        ll Size(ll n)
        {
            return sz[n];
        }
};

void solve(){
    int n; cin>>n;
    
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
        // cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}