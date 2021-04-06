#include <iostream>
using namespace std;
int coins[101],count_[101];
int dp[100001];
int solve(int n,int m){
    //初始化第一行
    for(int j=0;j<=m;++j){
        if(j%coins[0]==0&&j<=coins[0]*count_[0]){
            dp[j]=count_[0]-j/coins[0];
        }
        else{
            dp[j]=-1;
        }
    }

    //开始迭代
    for(int i=1;i<n;++i){
        for(int j=0;j<=m;++j){
            if(dp[j]>=0){
                dp[j]=count_[i];
            }
            else if(j<coins[i]||dp[j-coins[i]]<=0){
                dp[j]=-1;
            }
            else{
                dp[j]=dp[j-coins[i]]-1;
            }
        }
    }

    int ans=0;
    for(int j=m;j>=1;--j){
            if(dp[j]>=0) ans++;
    }
     return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(n!=0||m!=0){
        for(int i=0;i<n;i++){
            cin>>coins[i];
        }
        for(int i=0;i<n;++i){
            cin>>count_[i];
        }
        cout<<solve(n,m)<<endl;
        cin>>n>>m;
    }
    return 0;
}
