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
    int N,Q,flag=1;
    while(cin >> N >> Q){
        if(N==0 && Q==0) break;
        vector<int> v(N);
        REP(i,N) cin >> v[i];
        sort(ALL(v));
        cout << "CASE# " << flag++ << ":\n";
        REP(i,Q){
            int val;
            cin >> val;
            int foundPos=lower_bound(ALL(v),val)-v.begin();
            if(v[foundPos]!=val){
                cout << val << " not found\n";
            }
            else{
                cout << val << " found at " << foundPos+1 << "\n";
            }
        }
    }
    return 0;
}