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
int cost[100005],number[100005],c[100005];
void knapsack(int n, int m) {
    MS0(c);
    int ans=0;
    for (int i = 0; i < n; ++i) {
        int num = min(number[i], m / cost[i]);
        for (int k = 1; num > 0; k *= 2) {
            if (k > num) k = num;
            num -= k;
            for (int j = m; j >= cost[i] * k; --j)
                c[j] = max(c[j], c[j - cost[i] * k] + cost[i] * k);
        }
    }
    REP1(i,1,m+1) if(c[i]==i) ans++;
    cout << ans << "\n";
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n,m;
    while(cin >> n >> m){
        if(n==m && n==0) break;
        REP(i,n) cin >> cost[i];
        REP(i,n) cin >> number[i];
        knapsack(n,m);
    }
    return 0;
}