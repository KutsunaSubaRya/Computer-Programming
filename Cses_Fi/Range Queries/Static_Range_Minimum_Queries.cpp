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
const int max_lg=20,max_arrlen=200000;
int Log[max_arrlen+5],F[max_arrlen+5][max_lg+5];
inline void build_logn(void){
    Log[1]=0; Log[2]=1; 
    for(int i=3;i<max_arrlen;i++) Log[i]=Log[i/2]+1;
    // REP1(i,3,max_arrlen) Log[i]=Log[i/2]+1;
}
inline void build_ST(int n){
    REP1(j,1,max_lg+1) 
        for(int i=1;i+(1<<j)-1<=n;i++)
            F[i][j]=min(F[i][j-1],F[i+(1<<(j-1))][j-1]);
}
inline void init(int n){
    build_logn();
    REP1(i,1,n+1) cin >> F[i][0];
    build_ST(n);
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n,q,a,b,log_j;
    cin >> n >> q;
    init(n);
    REP(i,q){
        cin >> a >> b;
        int log_j=Log[b-a+1];
        cout << min(F[a][log_j], F[b-(1<<log_j)+1][log_j]) << "\n";
    }
    return 0;
}