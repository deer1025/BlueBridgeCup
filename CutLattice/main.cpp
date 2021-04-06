#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> POS;
int m,n;
int map[10][10],Sum[10][10],vis[10][10],Num[10][10];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int BFS(int total){
	queue<POS>qs;//队列里的只能为一种数据类型，可以是自定义的
	POS F;
	F.first=0;
	F.second=0;
	qs.push(F);
	Sum[0][0]=map[0][0];
	Num[0][0]=1;
    vis[0][0]=1;
	while(qs.size()){
		POS p=qs.front();
		qs.pop();
		vis[p.first][p.second]=1;

		if(Sum[p.first][p.second]==total){
			return Num[p.first][p.second];
		}

		for(int i=0;i<4;++i){
			int nx=p.first+dx[i],ny=p.second+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]){
				POS n;
				n.first=nx;
				n.second=ny;
				qs.push(n);
				Sum[nx][ny]=map[nx][ny]+Sum[p.first][p.second];
				Num[nx][ny]=Num[p.first][p.second]+1;
			}
		}
	}
    return 0;
}
int main(){
	cin>>m>>n;
	int sum=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>map[i][j];
			sum+=map[i][j];
		}
	}
	cout<<BFS(sum/2)<<endl;
	return 0;
}
