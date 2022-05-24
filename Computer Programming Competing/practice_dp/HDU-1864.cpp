#pragma GCC optimize ("O3")
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
#define maxE(x) (*max_element((x).begin(), (x).end()))
#define minE(x) (*min_element((x).begin(), (x).end()))
//#define int long long
/*-----typedef-----*/
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
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
    int TC, N;
    char tmp[3];
    double Q;
    while(cin >> Q >> TC && TC) {
        double cost[1005], dp[1005] = {0}, c;
        REP(i, TC) {
            double id[4] = {0};
            bool det = 0;
            cin >> N;
            REP(j, N) {
                cin >> setw(3) >> tmp >> c; //set(n) 讀 n 個字元進 tmp
                if(tmp[0] == 'A') id[0] += c;
                else if(tmp[0] == 'B') id[1] += c;
                else if(tmp[0] == 'C') id[2] += c;
                else det = true;
            }
            if(id[0] > 600 || id[1] > 600 || id[2] > 600 || det || id[0] + id[1] + id[2] > 1000) cost[i] = 0;
            else cost[i] = id[0] + id[1] + id[2];
        }
        REP(i, TC)
            for(int j = i + 1; j >= 0; j--)
                dp[j] = max(dp[j], dp[j - 1] + cost[i]);
        for(int i = TC; i >= 0; i--)
            if(dp[i] <= Q) {
                cout << fixed << setprecision(2) << dp[i] << "\n";
                break;
            }
    }

    return 0;
}