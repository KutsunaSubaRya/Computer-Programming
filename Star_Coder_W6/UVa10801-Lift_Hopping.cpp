#include<bits/stdc++.h>
/*-----define-----*/
#define jizz ios_base::sync_with_stdio(false),cin.tie(NULL)
#define REP(I,N) for(int I=0;I<(N);I++)
#define REP1(I,N,M) for(int I=(N);I<(M);I++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define CN cout<<"\n"
#define INF 0x3f3f3f3f
#define NINF 0xc0c0c0c0
/*-----typedef-----*/
using namespace std;
int v[1005],n,flo,cost[15],dp[1005][1005];
char tmp;
void gen_G(int idx, int sz){
    REP(i,sz) REP1(j,i+1,sz){
        int p=dp[v[i]][v[j]];
        p=min(p,(v[j]-v[i])*cost[idx]);//邊建立邊維護從 i 到 j 最小值
        dp[v[i]][v[j]]=p;
        dp[v[j]][v[i]]=p;
    }
}
signed main(){
    //jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    while(cin >> n >> flo){
        memset(dp,INF,sizeof(dp));
        MS0(v); MS0(cost);
        REP(i,1005) dp[i][i]=0;
        REP(i,n) cin >> cost[i];
        REP(i,n){
            tmp=0;
            int j;
            for(j=0;tmp!='\n';j++) scanf("%d%c",&v[j],&tmp);
            gen_G(i,j);//把題意轉成鄰接矩陣
        }
        //套用 Floyd Warshall，因為dp[i][k]+dp[k][j] 表示從第 i 層到第 k 層，再從第 k 層到第 j 層時，必定在 k 層換了電梯，所以要加 60
        REP(k,101) REP(i,101) REP(j,101) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+60);
        if(dp[0][flo]==INF) cout << "IMPOSSIBLE\n";
        else cout << dp[0][flo] << '\n';
    }
    return 0;
}