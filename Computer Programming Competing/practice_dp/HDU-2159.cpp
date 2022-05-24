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
    int n,m,k,s,a[1005],b[1005],dp[1005][1005];
    while(cin >> n >> m >> k >> s){
        REP(i,k) cin >> a[i] >> b[i];
        MS0(dp);
        REP(i,k) REP1(j,1,s+1) REP1(k,b[i],m+1)
            dp[k][j]=max(dp[k][j],dp[k-b[i]][j-1]+a[i]);
        if(dp[m][s]<n) cout << "-1\n";
        else{
            REP(i,m+1) if(dp[i][s]>=n){
                cout << m-i << "\n";
                break;
            }
        }
    }
    
    return 0;
}