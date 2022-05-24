#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
#pragma region define/typedef
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
typedef vector<int> VI;
typedef vector<PII> VPII;
#pragma endregion
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    string str[2];
    cin >> str[0];
    cin >> str[1];
    int strLen=str[0].size(),total=0;
    REP(i,strLen-1){
        if(str[0][i]=='0' && str[0][i+1]=='0' && str[1][i]=='0'){
            str[0][i]='1';  str[0][i+1]='1'; str[1][i]='1';
            total++;
        }
        else if(str[0][i]=='0' && str[1][i+1]=='0' && str[1][i]=='0'){
            str[0][i]='1';  str[1][i+1]='1';  str[1][i]='1';
            total++;
        }
        else if(str[1][i]=='0' && str[1][i+1]=='0' && str[0][i+1]=='0'){
            str[1][i]='1';  str[1][i+1]='1';  str[0][i+1]='1';
            total++;
        }
        else if(str[0][i]=='0' && str[0][i+1]=='0' && str[1][i+1]=='0'){
            str[0][i]='1';  str[0][i+1]='1';  str[1][i+1]='1';
            total++;
        }
    }
    cout << total << "\n";
    return 0;
}