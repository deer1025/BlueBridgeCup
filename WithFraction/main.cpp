#include<iostream>
#include<algorithm>
using namespace std;
int number[9]={1,2,3,4,5,6,7,8,9};
int N,total=0;;
void solve(int num[]){
	for(int i=1;i<8;++i){
		for(int j=i+1;j<=8;++j){
			int count1=num[0];
			for(int k=1;k<i;++k){
				count1=count1*10+num[k];
			}
			int count2=num[i];
			for(int p=i+1;p<j;++p){
				count2=count2*10+num[p];
			}
			int count3=num[j];
			for(int q=j+1;q<9;++q){
				count3=count3*10+num[q];
			}
			if(N==(count1+count2/count3)&&count2%count3==0){
				total++;
			}
		}
	}
}
int main(){
	cin>>N;
	do{
		solve(number);
	}while(next_permutation(number,number+8));
	cout<<total<<endl;
	return 0;
}
