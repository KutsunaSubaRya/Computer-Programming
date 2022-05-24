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
int flag=0;
bool cmpSequence(const int i){
    return (++flag)==i;
}
int ABS(int a,int b){
    return abs(b-a);
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int T;
    while(cin >> T){
        flag=0;
        int v[T];
        vector<int> tmp(T);
        for(int i=0;i<T;++i){
            cin >> tmp[i];
        }
        adjacent_difference(tmp.begin(),tmp.end(),v,ABS);
        // REP1(i,1,T){
        //     cout << tmp[i] << " ";
        // }cout << "\n";
        sort(v+1,v+T);
        bool ans=all_of(v+1,v+T,cmpSequence);
        if(ans) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}