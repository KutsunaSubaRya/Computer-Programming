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
int Typing(vector<char> v, int sz){
    int L=0,R=0,ans=0;
    if(v[0]=='X') L=1;
    else R=1;
    REP1(i,1,sz){
        if(v[i]=='O' && L==1){
            ans++;
            L=0; R=1;
        }
        else if(v[i]=='X' && R==1){
            ans++;
            L=1; R=0;
        }
    }
    return ans;
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int T,fl=0;
    cin >> T;
    while(T--){
        int n,L=0,R=0,ans;
        char c;
        vector<char> str;
        cin >> n;
        REP(i,n){
            cin >> c;
            if(c!='F') str.emplace_back(c);
        }
        if(str.empty()){
            cout << "Case #" << ++fl << ": 0\n";
            continue;
        }
        cout << "Case #" << ++fl << ": ";
        cout << Typing(str, str.size()) << "\n";
    }
    return 0;
}