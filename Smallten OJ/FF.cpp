#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
using namespace std;
struct infor{
    int x,y,dis;
};
int ans,deter=0,xx[4]={0,0,1,-1},yy[4]={1,-1,0,0},n,len;
char mp[105][1005];
queue<infor> smallten;
void BFS(){
    while(!smallten.empty() && deter==0){
        int x=smallten.front().x, y=smallten.front().y, dis=smallten.front().dis;
        for(int i=0;i<4;i++){
            if(mp[x+xx[i]][y+yy[i]]!='#'){
                if(mp[x+xx[i]][y+yy[i]]=='@'){
                    ans=dis;
                    deter=1;
                }
                else{
                    mp[x+xx[i]][y+yy[i]]='#';
                    infor tmp;
                    tmp.x=x+xx[i]; tmp.y=y+yy[i]; tmp.dis=dis+1;
                    smallten.emplace(tmp);
                }
            }
        }
        smallten.pop();
    }
}
void init(){
    for(int i=0;i<105;i++) for(int j=0;j<1005;j++) mp[i][j]='.';
    while(!smallten.empty()) smallten.pop();
    deter=0;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x,y;
    while(cin >> n){
        if(!n) break;
        init();
        string str;
        for(int i=0;i<n;i++) {
            cin >> str;
            len=str.size();
            for(int j=0;j<len;j++) mp[i][j]=str[j];
        }
        for(int i=0;i<n;i++){ 
            for(int j=0;j<len;j++) 
                if(mp[i][j]=='T'){ x=i; y=j; break;}
        }
        infor tmp;
        tmp.x=x; tmp.y=y; tmp.dis=0;
        smallten.emplace(tmp);
        mp[x][y]='#';
        BFS();
        if(deter) cout << ans+1 << "\n";
        else cout << "= =\"\n";
    }
    return 0;
}