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
    string s1,s2;
    while(cin >> s1 >> s2){
        int det=0;
        int len=s2.size(),st=0,flag=0;
        while(flag!=s1.size()){
            if(find(s2.begin()+st,s2.end(),s1[flag])!=s2.end()){
                int pos=find(s2.begin()+st,s2.end(),s1[flag])-s2.begin();
                st=pos+1;
                flag++;
                //cout << pos << "\n";
            }
            else{
                det=1;
                break;
            }
        }
        if(det) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}