#include<bits/stdc++.h>
#define maxE(x) (*max_element((x).begin(), (x).end()))
#define INF 0x3f3f3f3f
using namespace std;
vector<int> tot_leaf(105);
int dfs(int id){
    int num;
    cin >> num;
    if(num==-1) return 0;
    tot_leaf[id]+=num;
    dfs(id-1);
    dfs(id+1);
    return 1;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int maxu=100,flag=0;
    fill(tot_leaf.begin(), tot_leaf.end(),0);
    while(dfs(maxu/2)){
        int minu=INF;
        for(auto i:tot_leaf) if(i!=0 && minu>i) minu=i; 
        cout << "Case " << ++flag << ":\n" << maxE(tot_leaf)-minu << "\n\n";
        fill(tot_leaf.begin(), tot_leaf.end(),0);
    }
    return 0;
}