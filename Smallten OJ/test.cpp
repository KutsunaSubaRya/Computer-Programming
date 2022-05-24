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
void generate(int n){
    char sec[4]={'#','.','.','.'};
    int m=-1,a=0;
    REP(i,n+1) cout << '#';
    cout << "\n#T";
    REP(i,n-3) cout << sec[(++m)%4];
    cout << "@#\n";
    REP(j,20) {
        a=0;
        REP(i,n) cout << "#."[(++a)%2==0];
        cout << "#\n";
    }
    m=-1;
    REP(i,n) cout << sec[(++m)%4];
    cout << "#\n";
    REP(i,n+1) cout << '#';
}
signed main(){
    //jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n;
    for(int i=3;i<1001;i++){
        cout << 24 <<"\n";
        generate(i);
        cout << "\n";
    }
    return 0;
}