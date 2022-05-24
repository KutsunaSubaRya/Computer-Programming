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
    int n;
    while(cin >> n && n){
        int arr[2005],dp[2005][2005],m_pa=0;
        REP(i,n) cin >> arr[i] , arr[i+n]=arr[i];
        MS0(dp); REP(i,2005) dp[i][i]=1;
        REP1(len,2,n+1){
            for(int i=0;i+len-1<2*n;i++){
                int j=i+len-1;
                if(arr[i]==arr[j]) dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        REP(i,n){
            //cout << dp[i][i+n-1] <<" ";
            m_pa=max(m_pa,dp[i][i+n-1]); 
            m_pa=max(m_pa,dp[i][i+n-2]+1); // 原先踏在同一個地方
        }
        cout << m_pa << "\n";
    }
    return 0;
}