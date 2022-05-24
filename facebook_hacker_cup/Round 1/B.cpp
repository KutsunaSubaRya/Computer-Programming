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
const int iinf=16;
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int T,fl=0;
    cin >> T;
    while(T--){
        int n,m,a,b;
        cin >> n >> m >> a >> b;
        if(n+m-1 > a || n+m-1 > b){
            cout << "Case #" << ++fl << ": Impossible\n";
            continue;
        }
        int arr[n+5][m+5];
        REP(i,n) REP(j,m) arr[i][j]=iinf;
        REP(i,n) arr[i][0]=arr[i][m-1]=1;
        REP(i,m) arr[n-1][i]=1;
        // REP(i,n) {
        //     REP(j,m) cout << arr[i][j] << " ";
        //     cout << "\n";
        // }
        // cout << "\n";
        arr[0][0]=arr[0][0]+(a-(n-1)-m);
        arr[0][m-1]=arr[0][m-1]+(b-(n-1)-m);
        cout << "Case #" << ++fl << ": Possible\n";
        REP(i,n) {
            REP(j,m) cout << arr[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}