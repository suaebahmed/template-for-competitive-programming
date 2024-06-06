#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#ifndef ONLINE_JUDGE
#include<debug.h>
#else
#define dbg(x...)
#endif
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define ff first
#define ss second
#define pii pair<int,int>
#define mod 1000000007
int dx[]={0,+1,0,-1};
int dy[]={+1,0,-1,0};
#define vi vector<int>
typedef tree<int, null_type, less_equal<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;
#define scanv(a) for(auto &x: a) cin>>x;
#define ll long long
#define int long long 
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
const int N = 3e5+5, inf = 1e9;
const int MOD = 998244353;

void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans = 0, l = 0, r = n-1;
    while(l <= r){
        if(l == r){
            if(k >= a[l]) ans++;
            break;
        }
        bool ok = 1;
        if(a[l] <= 0){
            l++;
            a[l] += a[l-1];
            ans++;
            ok = 0;
        }
        else if(k >= 2*a[l]-1){
            k -= 2*a[l]-1;
            a[r] -= a[l]-1;
            // a[l] = 0;
            ans++;
            l++;
            ok = 0;
        }
        else if(k > 0){
            a[l]--;
            k--;
        }


        if(a[r] <= 0){
            r--;
            a[r] += a[r+1];
            ans++;
            ok = 0;
        }
        else if(k >= 2*a[r]-1){
            k -= 2*a[r]-1;
            a[l] -= a[r]-1;
            a[r] = 0;
            ans++;
            r--;
            ok = 0;
        }
        else if(k > 0){
            a[r]--;
            k--;
        }

        dbg(a, ans, k);
        if(ok) break;
    }
    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tt=1;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        // cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}