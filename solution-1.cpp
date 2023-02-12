#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int N = 2e5+5, inf = 1e10;

void solve(){
    int n; cin>>n;
    vector<array<string,4>> v(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            cin>>v[i][j];
        }
    }
    sort(rall(v)); // descending order..
    map<string,int> bloodG, years, visited;
    for(int i=0; i<n; i++){

        if(visited[v[i][1]]==1) continue;
        visited[v[i][1]] = 1;

        string y;
        for(int j=(int)v[i][2].size()-4; j<(int)v[i][2].size(); j++){
            y.push_back(v[i][2][j]);
        }
        years[y]++;

        bloodG[v[i][3]]++;
    }
    cout<<"A+ "<<bloodG["A+"]<<endl;
    cout<<"A- "<<bloodG["A-"]<<endl;
    cout<<"AB+ "<<bloodG["AB+"]<<endl;
    cout<<"AB- "<<bloodG["AB-"]<<endl;
    
    cout<<"B+ "<<bloodG["B+"]<<endl;
    cout<<"B- "<<bloodG["B-"]<<endl;
    cout<<"O+ "<<bloodG["O+"]<<endl;
    cout<<"O- "<<bloodG["O-"]<<endl;

    for(auto x: years) cout<<x.first<<" "<<x.second<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tt = 1;
    // cin>>tt;
    for(int i=1; i<=tt; i++){
        // cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
