#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 102
int const inf = 0x3f3f3f3f;
using namespace std;
int dp[maxn][maxn];
int a[maxn], sum[maxn];
int main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
	int t, n, i, j, k;
	scanf("%d", &t);
	int  cont = 1;
	while(t--){
		scanf("%d", &n);
		sum[0] = 0;
		for(i = 0; i < n; i++){
			scanf("%d", &a[i]);
			sum[i] = (sum[i-1]+a[i]);
		}
		memset(dp, 0, sizeof(dp)); 
		for(i = n-1; i >=0 ; i--){
			for(j = i; j < n; j++){
				if(i == j){
					dp[i][j] = 0;
					continue;
				}
				dp[i][j] = inf;
				for(k = i; k <= j; k++){
					dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k+1][j] + (j-i)*a[k]+((sum[j] - sum[k])*(k-i)));
				}
			}
		}
		printf("Case #%d: %d\n", cont++,dp[0][n-1]);
	}	
	return 0;
} 