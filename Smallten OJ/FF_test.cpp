#include<bits/stdc++.h>
using namespace std;
struct pos{
	int x,y,dis;//dis:離喵喵的距離 
	pos(){;}
	pos(int _x,int _y,int _dis){x=_x;y=_y;dis=_dis;}
};
bool check[105][1005];//這個格子��否走過 
char maze[105][1005];
int n,m,flag,goal_dis;//n:row m:col
queue<pos>bfs_queue;
pos cat;
void reset(){
	for(int i=0;i<105;i++){
		for(int j=0;j<1005;j++){
			maze[i][j]='#';check[i][j]=false;				
		}
	} 
	flag=0;goal_dis=0;
	while(!bfs_queue.empty())bfs_queue.pop(); 
}
void bfs(){
	int x,y;
	while(!bfs_queue.empty()&&flag==0){//對上下左右進行bfs，if走過則不會再走 
		x=bfs_queue.front().x;y=bfs_queue.front().y;
		if(maze[x][y-1]!='#'&&check[x][y-1]==false){
			if(maze[x][y-1]=='@'){
				goal_dis=bfs_queue.front().dis+1;
				flag=1;	
			}
			else{
				pos tmp(x,y-1,bfs_queue.front().dis+1);
				check[x][y-1]=true;
				bfs_queue.push(tmp);
			}
		}
		if(maze[x][y+1]!='#'&&check[x][y+1]==false){
			if(maze[x][y+1]=='@'){
				goal_dis=bfs_queue.front().dis+1;
				flag=1;	
			}
			else{
				pos tmp(x,y+1,bfs_queue.front().dis+1);
				check[x][y+1]=true;
				bfs_queue.push(tmp);
			}
		}
		if(maze[x-1][y]!='#'&&check[x-1][y]==false){
			if(maze[x-1][y]=='@'){
				goal_dis=bfs_queue.front().dis+1;
				flag=1;	
			}
			else{
				pos tmp(x-1,y,bfs_queue.front().dis+1);
				check[x-1][y]=true;				
				bfs_queue.push(tmp);
			}
		}
		if(maze[x+1][y]!='#'&&check[x+1][y]==false){
			if(maze[x+1][y]=='@'){
				goal_dis=bfs_queue.front().dis+1;
				flag=1;	
			}
			else{
				pos tmp(x+1,y,bfs_queue.front().dis+1);
				check[x+1][y]=true;
				bfs_queue.push(tmp);
			}
		}
		bfs_queue.pop();				
	}
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
	int length;
	string input;
	char data;
	while(cin>>n){
		if(n==0)return 0;
	    reset();
		for(int i=0;i<n;i++){//read data
			cin>>input;
			length=input.length();
			for(int j=0;j<length;j++){
				maze[i][j]=input[j];
				if(maze[i][j]=='T'){
					pos tmp(i,j,0);
					bfs_queue.push(tmp);
				}
			}
		}
		bfs(); 
		if(flag==1)std::cout<<goal_dis<<std::endl;
		else std::cout<<"= =\"\n";
	}	
}