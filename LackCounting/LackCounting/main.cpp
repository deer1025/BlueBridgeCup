#include <iostream>

using namespace std;
int n,m;
char map[100][100];
void dfs(int x,int y){
    map[x][y] = '.';

    //������������
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            //������һ��λ�õ�����
            int nx = x+i;
            int ny = y+j;
            //�ж�
            if(nx>=0 && nx<n && ny>=0 && ny<m && //Խ����
               map[nx][ny]=='W'){//��ˮ��
                dfs(nx,ny);
            }

        }
    }
}
int main()
{
    cin>>n>>m;  //n��m��
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
