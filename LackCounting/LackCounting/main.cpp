#include <iostream>

using namespace std;
int n,m;
char map[100][100];
void dfs(int x,int y){
    map[x][y] = '.';

    //往各个方向走
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            //计算下一个位置的坐标
            int nx = x+i;
            int ny = y+j;
            //判断
            if(nx>=0 && nx<n && ny>=0 && ny<m && //越界检查
               map[nx][ny]=='W'){//有水洼
                dfs(nx,ny);
            }

        }
    }
}
int main()
{
    cin>>n>>m;  //n行m列
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]=='W'){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
