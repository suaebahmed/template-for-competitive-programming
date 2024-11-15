#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define PI acos(-1)
const int MX = 1e5+5;

int fastExpo(int a,int N,int md){
    int res=1;
    while(N>0){
        if(N&1) res=(res*a)%md;
        a=(a*a)%md;
        N>>=1;
    }
    return res;
}

int modInverse(int n,int md){
    return fastExpo(n,md-2,md);
}

int nCrModPfermat(int n,int r,int md){
    if(n<r) return 0;
    if(r==0) return 1;
    int *fact=new int[n+1];
    fact[0]=1;
    for(int i=1; i<=n; i++){
        fact[i]=(fact[i-1]*i)%md;
    }
    int a=fact[n];
    int b=(fact[r]%md*fact[n-r]%md)%md;
    return (a%md*modInverse(b,md)%md)%md;
}

/*
    Remember, Hope is a good thing... 
    May be the best of things... 
    and No Good thing ever Dies !!!
*/

void solve(){
	int n,k; cin>>n>>k;
    vector<int> a(n);
    read(a);
    sort(all(a));
    map<int,int> c1,c2;
    for(int i=0; i<k; i++) ++c1[a[i]];
    for(int i=0; i<n; i++) ++c2[a[i]];

    cout<<c2[a[k-1]]<<" "<<c1[a[k-1]]<<"\n";
    // cout<<nCrModPfermat(c2[a[k-1]],c1[a[k-1]],mod)<<endl;
}

int main(){
    optimize();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tt=1; //cin>>tt;
    for(int i=1; i<=tt; i++){
        // cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
