#include<iostream>
using namespace std;
/*enum{
    D,L,U,R
};*/
int x,y;
int map[97][97],m,n;
int direction[2][4]={{3,0,1,2},{1,2,3,0}};
//dx[0][0-3]�ֱ��ʾ�ڰ׸�ͷ�ĳ���ΪDLURʱλ��Ӧ�õı仯
int dx[2][4]={{0,1,0,-1},{0,-1,0,1}},dy[2][4]={{1,0,-1,0},{-1,0,1,0}};
//dy[1][0-3]�ֱ��ʾ�ںڸ�ͷ�ĳ���ΪDLURʱλ��Ӧ�õı仯
void solve(int s,int k){
	while(k){
            int x1=x,y1=y;
		x=x+dx[map[x][y]][s];
		y=y+dy[map[x][y]][s];
		s=direction[map[x1][y1]][s];
		map[x1][y1]=map[x1][y1]^1;
		k--;
	}
}
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin>>map[i][j];
		}
	}
	int k;
	char s;
	cin>>x>>y>>s>>k;
	int dir;
	switch(s){
	    case 'D':
	        dir=0;
            break;
        case 'L':
            dir=1;
            break;
        case 'U':
            dir=2;
            break;
        case 'R':
            dir=3;
            break;
	}
    solve(dir,k);
    cout<<x<<" "<<y<<endl;//Ҫ�޸�x��y�Ͳ��ܰ�������Ϊ�����е��βΣ�����ĵ�ֻ���βε�ֵ
	return 0;
}
