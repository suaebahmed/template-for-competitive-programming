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
#define endl '\n'
#define ld long double
#define mod 1000000007
const int MXN=1e6+5;
const int BLOCK_SIZE=700;

struct Query{
    int l,r,idx;
    // bool operator<(Query other) const{
    //
    // }
};
bool cmp(Query x,Query other)
{
    // int x_block = x.l/BLOCK_SIZE;
    // int other_block = other.l/BLOCK_SIZE;

    if(x.l/BLOCK_SIZE == other.l/BLOCK_SIZE) 
    return x.r < other.r;

    return (x.l/BLOCK_SIZE) < (other.l/BLOCK_SIZE);
}

ll curr_ans=0;
ll a[MXN],ans_arr[MXN],freq[MXN];

void add(int idx){

}
void remove(int idx){
    
}

void solve(){
    int n,q; cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<Query> queries(q);
    for(int i=0; i<q; i++){
        cin>>queries[i].l>>queries[i].r;
        queries[i].idx = i;
    }
    sort(all(queries),cmp);

    int l=1, r=0;
    for(auto x : queries){
        while(r<x.r){
            ++r;
            add(r);
        }
        while(l>x.l){
            --l;
            add(l);
        }
        while(r>x.r){
            remove(r);
        }
        while(l<x.l){
            remove(l);
            l++;
        }
        ans_arr[x.idx]=curr_ans;
    }
    for(int i=0; i<q; i++) cout<<ans_arr[i]<<"\n";
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