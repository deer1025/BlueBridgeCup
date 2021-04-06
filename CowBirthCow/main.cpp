#include<iostream>
using namespace std;
int dp[55]={1,2,3};
int solve(int n){
	if(n==1||n==2||n==3) return dp[n-1];
	if(n>=4){
		for(int i=4;i<=n;++i){
		    if(dp[i-1]==0){
                dp[i-1]=dp[i-2]+dp[i-4];
		    }
		}
		return dp[n-1];
	}
}
int main(){
	int n;
	cin>>n;
	while(n!=0){
		cout<<solve(n)<<endl;
		cin>>n;
	}
	return 0;
}
