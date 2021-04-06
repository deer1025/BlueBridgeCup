#include <iostream>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int sticks(int n){
    if(n==0) return num[0];
    else{
        int ans=0;
        while(n){
            int k=n%10;
            ans+=num[k];
            n/=10;
        }
        return ans;
    }
}
int main()
{
    int n,count_;
    cin>>n;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if((sticks(i)+sticks(j)+sticks(i+j)+4)==n){
                count_++;
            }
        }
    }
    cout<<count_;
    return 0;
}
