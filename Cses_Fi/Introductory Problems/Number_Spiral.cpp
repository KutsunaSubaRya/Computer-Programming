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
#define int long long
#pragma endregion
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n,a,b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(a>=b){
            int flag=3,deter=0;
            if(a==b && a==1) {
                cout << "1\n";
                continue;
            }
            if(a%2==0) deter=0; //negative
            else deter=1; // positive
            int three=a/2,eight=(a/2-1)*(a/2)/2,one=(a+1)/2,num=three*3+eight*8+one;
            if(!deter) cout << num-b+1 << "\n";
            else cout << num+b-1 << "\n";
        }
        else {
            int flag=7,deter=0;
            if(b%2==0) deter=1; // positive
            else deter=0; // negative
            int eight=((b-1)/2-1)*((b-1)/2)/2,seven=(b-1)/2,one=b/2+1,num=eight*8+seven*7+one;
            if(!deter) cout << num-a+1 << "\n";
            else cout << num+a-1 << "\n";
        }
    }
    return 0;
}