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
    int n,tmp1,z1,tmp2,z2,a1,a2;
    cin >> n;
    while(n--){
        int zz1=0,zz2=0;
        cin >> tmp1 >> z1;
        a1=tmp1;
        cin >> tmp2 >> z2;
        a2=tmp2;
        while(a1>=10){
            a1/=10;
            zz1++;
        }
        while(a2>=10){
            a2/=10;
            zz2++;
        }
        z1+=zz1;
        z2+=zz2;
        if(z1>z2){
            cout << ">\n";
        }
        else if(z2>z1){
            cout << "<\n";
        }
        else{
            if(zz1>zz2){
                int tmp=zz1-zz2;
                while(tmp--){
                    tmp2*=10;
                }
            }
            else if(zz2>zz1){
                int tmp=zz2-zz1;
                while(tmp--){
                    tmp1*=10;
                }
            }
            if(tmp1>tmp2) cout << ">\n";
            else if(tmp2>tmp1) cout << "<\n";
            else cout << "=\n";
        }
    }
    return 0;
}