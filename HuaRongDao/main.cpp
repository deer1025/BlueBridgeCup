#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
string st="";
map<string,int>mp;
int dir[4]={-1,1,-4,4};
int orgposA,orgposB;
int bfs(){
	queue<string>que;
	que.push(st);
	mp[st]=0;

	while(que.size()){
		string temp=que.front();
		que.pop();

		int pos=temp.find(' ');
		int dis=mp[temp];
		for(int i=0;i<4;++i){
            int nx=pos+dir[i];
            if((nx>=0&&nx<=2)||(nx>=4&&nx<=6)){
                swap(temp[pos],temp[nx]);
                if(mp.count(temp)==0){
                    mp[temp]=dis+1;
                    if(temp.find('A')==orgposB&&temp.find('B')==orgposA){
                        return mp[temp];
                    }
                    que.push(temp);
                }
                swap(temp[pos],temp[nx]);
            }
		}
	}
	return -1;
}
int main(){
	string map;
    getline(cin,map);
    st+=map;
    st+='#';
    getline(cin,map);
    st+=map;

	orgposA=st.find('A');
	orgposB=st.find('B');
	cout<<bfs()<<endl;
	return 0;
}

