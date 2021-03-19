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
#define lxb(a, x) (lxer_bound((a).begin(),(a).end(),(x))-(a).begin())
#define uppb(a, x) (upper_bound((a).begin(),(a).end(),(x))-(a).begin())
typedef long long ll;
#define ld long double
#define mod 1000000007
#define endl '\n'
const ll INF=1e18;
const int MAXN=2*1e5+2;
const int K=10;

struct FenwickTree1Base
{
    vector<ll> tree;
    int n;
    FenwickTree1Base(int n){
        this->n = n+1;
        tree.assign(n+1,0);
    }
    FenwickTree1Base(vector<ll> a)
        : FenwickTree1Base(a.size()){
        for(int i=1; i<=a.size(); i++){
            add(i,a[i-1]);
        }
    }
    ll sum(int i){
        ll res=0;
        while(i>0){
            res += tree[i];
            i -= i&(-i);
        }
        return res;
    }
    ll sum(int l,int r){
        return sum(r)-sum(l-1);
    }
    // Add 'v' to index 'i', O(log(n))
    void add(int i,ll dlt){
        for(; i<n; i += i&(-i)){
            tree[i] += dlt;
        }
    }
    // Set index i to be equal to v,O(long(n))
    void set(int i,ll value){
        add(i,value-sum(i,i));
    }
    // Get the value at index i
    ll get(int i){
        return sum(i,i);
    }
    void printA(){
        for(auto x: tree) cout<<x<<" ";
        cout<<endl;
    }
};

void solve(){
    int n,q; cin>>n>>q;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    FenwickTree1Base t1(a);

    while(q--){
        int type; cin>>type;
        if(type==1){
            int pos;ll v;
            cin>>pos>>v;
            t1.set(pos,v);
        }
        else{
            int l,r; cin>>l>>r;
            cout<<t1.sum(l,r)<<"\n";
        }
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
        // cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}