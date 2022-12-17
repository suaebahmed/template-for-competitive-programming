#include<bits/stdc++.h>
using namespace std;
// #define T int
template<class T> //as like as micross
class data
{
public:
    T a,b,c;
    data(){}
    data(T a,T b,T c){
        this-> a = a;
        this-> b = b;
        this-> c = c;
    }
    bool operator<(data other)const{ 
        return a < other.a;
    }
    friend void operator<<(ostream &cout,data &d){
        cout<<d.a<<" "<<d.b<<" "<<d.c<<"\n";
    }
};

template <class T> 
void operator<<(ostream &cout,vector<T> d){
    cout<<"[";
    for(auto x: d) cout<<x<<", ";
    cout<<"]\n";
}
template <class T> 
void operator<<(ostream &out,pair<T,T> &d){
    out<<"{ "<<d.first<<" , "<<d.second<<" }\n";
}
// ----------   parameter pack && flod expression ---------
int multi(){
    return 0;
}
template<typename T,typename...V>
int multi(T t,V... v){
    // static const std::size_t index = sizeof...(V);
    // cout<<index<<'\n';
    return t*multi(v...);
}
template<typename...Args> // c++17 or earliar version
auto foldMulti(Args... args){
    return (args*...*1);
}

void solve(){
    data<float> d1(0.4,0.9,0.99);
    data<int> d2(10,20,30);
    cout<<d1;
    cout<<d2;

    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    cout<<arr;
    pair<int,int> p = {9,2};
    cout<<p;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif
    int tt=1;
    // cin>>tt;
    for(int i=1; i<=tt; i++){
        // cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}