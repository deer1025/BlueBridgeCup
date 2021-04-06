#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;
queue<string>que;
//dirFlag��ʾstringΪ�Ź���ĳ��״̬ʱ�ķ���int��������̬��ĩ̬�ֱ���1��2��ʾ������0����map�����string�ؼ��ֵ�intֵ�Զ���ʼ��Ϊ0
map<string,int>dirFlag,stepSum;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};//�ֱ��ʾ���������ĸ�����
void swap(char &a,char &b){//�����Ź���������λ�õ��ַ�
	char t=a;
	a=b;
	b=t;
}
string next(string s,int i){
	int loc;
	for(int j=0;j<9;++j){
		if(s[j]=='.'){//�Ź������о����ƶ��ո�'.'��λ��
			loc=j;
			break;
		}
	}
	int x=loc/3+dx[i],y=loc%3+dy[i];//���ַ����±�ת��Ϊ�Ź���Ķ�ά������±�
	if(x<0||x>2||y<0||y>2){//���Խ����
		return "";
	}
	swap(s[loc],s[x*3+y]);//û��Խ������i�涨�ķ����ƶ��ո�'.'
	return s;
}
int BFS(string begin,string end){
    if(begin==end){
        return 0;
    }
	//��������
	que.push(begin);
	que.push(end);
	dirFlag[begin]=1;
	dirFlag[end]=2;
	stepSum[begin]=0;
	stepSum[end]=0;
	//���зǿ�ѭ��
	while(que.size()){
		//����
		string s=que.front();
		que.pop();

		//�����������
		for(int i=0;i<4;++i){
			string ns=next(s,i);//��һ��״̬�ľŹ���
			if(ns!=""//��Ч�Լ��
            &&dirFlag[ns]!=dirFlag[s]){////�����������������ֹ����Ͳ�������ˣ���ֹ�����ߡ�
                //�߽���
				if(dirFlag[ns]+dirFlag[s]==3){//�������״̬�����ˣ��������˴�ʼ̬����̬��ͨ·
					return stepSum[ns]+stepSum[s]+1;//������ͷ�������Ĳ����ټ�������֮���һ��
				}
				//���û�����յ㣬�������Ӳ��Ҽ�¼
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
