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
#define getchar getchar_unlocked
#define fread fread_unlocked
/*-----typedef-----*/
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
#pragma endregion
inline char readchar() {
	const int S = 1<<20; // buffer size
	static char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}
inline void input(int &_x){
    _x = 0;
    int _tmp = 1; char _tc = readchar();
    while((_tc < '0' || _tc > '9') && _tc != '-') _tc = readchar();
    if(_tc == '-') _tc = readchar(), _tmp = -1;
    while(_tc >= '0' && _tc <= '9') _x = _x*10+(_tc-48), _tc = readchar();
    _x *= _tmp;
}
inline int positiveModulo(int i, int n){
    return (i%n+n)%n;
}
inline int minDistance(char a, char b){
    int num1=(int)a,num2=(int)b; 
    return min(positiveModulo(num1-num2,26),positiveModulo(num2-num1,26));
}
LL a,b,c;
LL dp[5005][5005];
LL min(LL x, LL y, LL z) { return min(min(x, y), z); }
LL DP(string str1, string str2, int m, int n)
{
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            dp[i][j]=0;
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            //if(j>i) continue;
            if (i == 0){
                if(j==0) continue;
                dp[i][j] = dp[i][j-1]+a;
            }
            else if (j == 0){
                if(i==0) continue;
                dp[i][j] = dp[i-1][j]+b; 
            }
            else if(i==0 || j==0) continue;
            else{
                dp[i][j]
                    = min((dp[i][j - 1]+a), // Insert
                            (dp[i - 1][j]+b), // Remove
                            (dp[i - 1][j - 1]+minDistance(str1[i-1],str2[j-1])*c)); // 轉
            }
        }
    }
    return dp[m][n];
}
signed main(){
    //jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    string str1,str2;
    cin >> a >> b >> c;
    cin >> str1 >> str2;
    cout << DP(str1, str2, str1.length(),str2.length());
    return 0;
}