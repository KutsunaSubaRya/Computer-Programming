#include<bits/stdc++.h>
/*-----define-----*/
#define jizz ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ALL(X) (X).begin(), (X).end()
#define REP(I,N) for(int I=0;I<(N);I++)
#define REP1(I,N,M) for(int I=(N);I<(M);I++)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(), c.end(),x)-c.begin())
#define pb emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define LEN(X) strlen((X))
#define F first
#define S second
#define LB lower_bound
#define UP upper_bound
#define CN cout<<"\n"
#define lowbit(x) ((x)&(-x))
#define maxE(x) (*max_element((x).begin(), (x).end()))
#define minE(x) (*min_element((x).begin(), (x).end()))
//#define int long long
#define INF 0x3f3f3f3f
#define NINF 0xc0c0c0c0
/*-----typedef-----*/
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<int, pair<int, int>> PIII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
signed main() {
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int c, s, q,a,b,w,tc=0;
    while(cin >> c >> s >> q) {
        if(c == s && s == q && c == 0) break;
        if(tc) CN;
        int v[c+5][c+5];
        memset(v,INF,sizeof(v));
        REP(i,s){
            cin >> a >> b >> w;
            v[a][b]=w;
            v[b][a]=w;
        }
        REP1(k,1,c+1) REP1(i,1,c+1) REP1(j,1,c+1) v[i][j]=min(v[i][j],max(v[i][k],v[k][j]));
        cout << "Case #" << ++tc << "\n";
        REP(i,q){
            cin >> a >> b;
            if(v[a][b]==INF) cout << "no path\n";
            else cout << v[a][b] << "\n";
        }
    }
    return 0;
}