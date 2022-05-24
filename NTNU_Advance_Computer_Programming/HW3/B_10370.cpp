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
double aver;
bool lowerThanAver(const double i){
    return i>aver;
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int T,N;
    double total;
    cin >> T;
    while(T--){
        total=0;
        cin >> N;
        vector<double> v(N);
        REP(i,N){
            cin >> v[i];
        }
        aver=accumulate(ALL(v),total)/N;
        int upperThanAver=count_if(ALL(v),lowerThanAver);
        cout << setprecision(5) << fixed << setprecision(3)<< ((double)upperThanAver*100)/N<< "%\n";
    }
    return 0;
}