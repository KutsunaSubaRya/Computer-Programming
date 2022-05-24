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
int T,sum[1005],d[1005],dp[1005][1005],n;
void init(void){
    MS0(d); MS0(sum);
    //memset(dp,INF,sizeof(dp));
    REP(i,1005) dp[i][i]=0;
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    REP(fl,T){
        cin >> n;
        init();
        REP(i,n) {
            cin >> d[i];
            sum[i]=(sum[i-1]+d[i]);
        }
        for(int i=n-1;i>=0;i--){
            REP1(j,i+1,n){
                dp[i][j]=INF;
                REP1(k,i,j+1){
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+(j-i)*d[k]+dp[k+1][j]+(sum[j]-sum[k-i])*(k-i));
                }
            }
        }
        cout << "Case #" << fl+1 << ": " << dp[0][n-1] << "\n";
    }
    return 0;
}