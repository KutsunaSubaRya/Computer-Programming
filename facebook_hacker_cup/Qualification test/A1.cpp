#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
/*-----define-----*/
#define jizz ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ALL(X) (X).begin(), (X).end()
#define REP(I,N) for(int I=0;I<(N);I++)
#define REP1(I,N,M) for(int I=(N);I<(M);I++)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(), c.end(),x)-c.begin())
#define MS0(X) memset((X), 0, sizeof((X)))
#define maxE(x) (*max_element((x).begin(), (x).end()))
#define minE(x) (*min_element((x).begin(), (x).end()))
#define INF 0x3f3f3f3f
#define NINF 0xc0c0c0c0
/*-----typedef-----*/
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<char,int> PCI;
typedef vector<int> VI;
typedef vector<PII> VPII;
map<char,int> mp;
int C1(char id){
    int n_v=0,v=0;
    for(char i='A';i<='Z';i++){
        if(i=='A' || i=='E' || i=='I' || i=='O' || i=='U'){ if(i!=id) v+=(mp[i]*2); }
        else n_v+=mp[i];
    }
    return n_v+v;
}
int C2(char id){
    int n_v=0,v=0;
    for(char i='A';i<='Z';i++){
        if(i!='A' && i!='E' && i!='I' && i!='O' && i!='U'){ if(i!=id) n_v+=(mp[i]*2); }
        else v+=mp[i];
    }
    return n_v+v;
}
int Solve(void){
    int tmp_vm=0,tmp_nvm=0;
    char num='*',n_v='*';
    for(char i='A';i<='Z';i++){
        if(i=='A' || i=='E' || i=='I' || i=='O' || i=='U'){
            if(mp[i]>tmp_vm){
                num=i;
                tmp_vm=mp[i];
            }
        }
        else{
            if(mp[i]>tmp_nvm){
                n_v=i;
                tmp_nvm=mp[i];
            }
        }
    }
    return min(C1(num),C2(n_v));
}
void init(void){
    for(char i='A';i<='Z';i++) mp[i]=0;
}
signed main(){
    int T,fl=0;
    cin >> T;
    while(T--){
        init();
        string str;
        cin >> str;
        int len=str.size();
        REP(i,len) mp[str[i]]++;
        printf("Case #%d: %d\n",++fl,Solve());
    }
    return 0;
}