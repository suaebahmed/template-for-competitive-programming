#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include<debug.h>
#else
#define dbg(x...)
#endif

/*
Regular Expression:
	a
	a*b+
	abb
*/

// const int N = 1001;
// char s[N];

// void MatchRegulerExp(){
//     scanf("%s",s);
//     int n = strlen(s);
//     int ca = 0, cb = 0, flag = 1;
//     for(int i=0; i<n; i++){
//         if(s[i] == 'a'){
//             ca++;
//             cb = 0;
//             if(ca == 1)
//             printf("Accepted Reguler Expression: a\n");
//             flag = 0;
//         }
//         else if(ca >= 0 && s[i] == 'b'){
//             cb++;
//             if(ca==1 && cb==2){
//                 printf("Accepted Reguler Expression: abb\n");
//             }
//             else{
//                 printf("Accepted Reguler Expression: a*b+\n");
//             }
//             flag = 0;
//         }
//         else{
//             ca = 0;
//             cb = 0;
//         }
//     }
//     if(flag) printf("No match under 3 given rules\n");
// }


// void SimulateLxicalAnalyzer(){
//     while(fgets(s,sizeof(s),stdin) != NULL){
//         int lastIdx = strcspn(s, "\n");
//         s[lastIdx] = '\0';
//         int n = strlen(s), i = 0;
//         while(i < n){
//             if(s[i]=='+' && s[i+1]=='+'){
//                 printf("<Increment,++>\n");
//                 i += 1;
//             }
//             else if(s[i]=='-' && s[i+1]=='-'){
//                 printf("<Decrement,-->\n");
//                 i += 1;
//             }
//             else if(s[i]=='=' && s[i+1]=='='){
//                 printf("<Equal,==>\n");
//                 i += 1;
//             }
//             else if(s[i]=='>' && s[i+1]=='='){
//                 printf("<GreaterThenOrEqual,>=>\n");
//                 i += 1;
//             }
//             else if(s[i]=='<' && s[i+1]=='='){
//                 printf("<LessThenOrEqual,<=>\n");
//                 i += 1;
//             }
//             else if(s[i]=='>'){
//                 printf("<GreaterThen,>>\n");
//             }
//             else if(s[i]=='<'){
//                 printf("<LessThen,<>\n");
//             }
//             else if(s[i]=='+'){
//                 printf("<Plus,+>\n");
//             }
//             else if(s[i]=='-'){
//                 printf("<Minus,->\n");
//             }
//             else if(s[i]=='*'){
//                 printf("<Multiply,*>\n");
//             }
//             else if(s[i]=='/'){
//                 printf("<Division,/>\n");
//             }
//             i++;
//         }
//     }
// }

// char findFirst(char F[], int i){
//     // Tarminal
//     bool isTarminal = 0;
//     int j = 0;
//     while(true){
//         if(F[j]>='a' && 'z'<=F[j]){
//             isTarminal = 1;
//             break;
//         }
//         else if(F[j] == '|') break;
//         j++;
//     }
//     if(isTarminal){
//         printf("%c,",  F[j]);
//     }
//     // Non-tarminal
//     // else{

//     // }
//     return 'z';
// }


vector<int> st[10];
set<int> ans;

void eClouser(int state){
    ans.insert(state);
    int sz = st[state].size();
    if(sz == 0) return;
    else{
        for(int i=0; i<sz; i++){
            eClouser(st[state][i]);
        }
    }
}


int main(){
    int t = 1;
    // printf("Please enter the number of testcase: ");
    // scanf("%d",&t);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    while(t--){
        // char P[] = "i|c|nTS";
        // char Q[] = "P|aS|bScST";
        // char R[] = "b|e";
        // char S[] = "c|Rn|e";
        // char T[] = "RSq";

        string s,a,b,e;
        cin>>s>>a>>b>>e;
        vector<int> A;
        for(int i=0; i<=10; i++){
            string state,aa,bb,ee;
            cin>>state>>aa>>bb>>ee;
            if(ee != "-"){

                char *token = strtok(ee, ",");
                while (token != NULL)
                {
                    st[stoi(state)].push_back(stoi(token));
                    token = strtok(NULL, ",");
                }

            }
            if(aa != "-") A.push_back(stoi(aa));
            
        }
        for(auto& x: ans) cout<<x<<" ";
    }
    return 0;
}



/*
NFA -> DFA

state a b e
0 - - 1,7
1 - - 2,4
2 3 - -
3 - - 6
4 - 5 -
5 - - 6
6 - - 1,7
7 8 - -
8 - 9 -
9 - 10 -
10 - - -


{3,8} => {1,2,3,4,6,7,8}

*/