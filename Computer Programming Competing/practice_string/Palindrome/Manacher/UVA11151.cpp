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
#define maxEP(x) (max_element((x).begin(), (x).end()))-(x).begin()
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
vector<int> p(10005);
PII manacher(string s) {
    int len = s.size(), Center = 0, R = 0;
    for(int i = 0; i < len; i++) {
        int mirror = 2 * Center - i;
        if(i + p[mirror] < R) p[i] = min(p[mirror], R - i);
        while(s[i + (1 + p[i])] == s[i - (1 + p[i])]) p[i]++;
        if(i + p[i] > R) {
            Center = i;
            R = i + p[i];
        }
    }
    return make_pair(maxE(p),maxEP(p));
}
inline void init(void) {
    REP(i, 10005) p[i] = 0;
}
signed main() {
    //jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    init();
    string s, new_s;
    cin >> s;
    int flag = 1, len = s.size();
    new_s.insert(0, "@");
    for(int i = 0; i < len; i++) {
        new_s += "#";
        new_s += s[i];
    }
    new_s += "#$";
    PII max_pa=manacher(new_s);
    int pa_len=max_pa.first, pos=max_pa.second;
    REP1(i,pos-pa_len,pos+pa_len) if(new_s[i]!='#') cout << new_s[i];
    cout << "\n";
    return 0;
}