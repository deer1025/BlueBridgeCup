#include<iostream>
const int max_n = 1000010;
using namespace std;
int num[max_n];
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=1;i<max_n;++i){
		num[i]=i;
	}
	int i=2;
	while(i<=n){
		int count=0;
		for(int j=1;j<=n;++j){
			if(num[j]!=0){
				count++;//count是第count个不为0的数，即幸运数
			}
			if(count%i==0){
				num[j]=0;
			}
		}
		i++;
		while(num[i]==0) i++;
	}
	int total=0;
	for(int i=m+1;i<n;++i){
		if(num[i]) 	total++;
	}
	cout<<total<<endl;
	return 0;
}
