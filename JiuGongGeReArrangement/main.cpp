#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;
queue<string>que;
//dirFlag表示string为九宫格某个状态时的方向int，向着终态和末态分别用1和2表示。不用0由于map会把无string关键字的int值自动初始化为0
map<string,int>dirFlag,stepSum;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};//分别表示上下左右四个方向
void swap(char &a,char &b){//交换九宫格中两个位置的字符
	char t=a;
	a=b;
	b=t;
}
string next(string s,int i){
	int loc;
	for(int j=0;j<9;++j){
		if(s[j]=='.'){//九宫格排列就是移动空格'.'的位置
			loc=j;
			break;
		}
	}
	int x=loc/3+dx[i],y=loc%3+dy[i];//将字符串下标转化为九宫格的二维数组的下标
	if(x<0||x>2||y<0||y>2){//如果越界了
		return "";
	}
	swap(s[loc],s[x*3+y]);//没有越界则按照i规定的方向移动空格'.'
	return s;
}
int BFS(string begin,string end){
    if(begin==end){
        return 0;
    }
	//起点入队列
	que.push(begin);
	que.push(end);
	dirFlag[begin]=1;
	dirFlag[end]=2;
	stepSum[begin]=0;
	stepSum[end]=0;
	//队列非空循环
	while(que.size()){
		//出队
		string s=que.front();
		que.pop();

		//各个方向宽搜
		for(int i=0;i<4;++i){
			string ns=next(s,i);//下一个状态的九宫格
			if(ns!=""//有效性检测
            &&dirFlag[ns]!=dirFlag[s]){////如果这个方向曾经出现过，就不用入队了，防止往回走。
                //边界检测
				if(dirFlag[ns]+dirFlag[s]==3){//如果两个状态相遇了，即构成了从始态到终态的通路
					return stepSum[ns]+stepSum[s]+1;//返回两头各经过的步数再加上两者之间的一步
				}
				//如果没到达终点，则继续入队并且记录
				que.push(ns);
				dirFlag[ns]=dirFlag[s];
				stepSum[ns]=stepSum[s]+1;
			}
		}
	}
	return -1;
}
int main(){
	string begin,end;
	cin>>begin>>end;
	cout<<BFS(begin,end)<<endl;
	return 0;
}
