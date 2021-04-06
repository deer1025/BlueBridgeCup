/*≥È«©*/
#include <iostream>
#include<algorithm>
using namespace std;
int n,m,k[51],kk[2501];
bool binary_Search(int m){
    int left=0,right=n*n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(kk[mid]==m){
            return true;
        }
        else if(kk[mid]>m){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return false;
}
bool ballot(){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            kk[i*n+j]=k[i]+k[j];
        }
    }
    sort(kk,kk+n*n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
                if(binary_Search(m-k[i]-k[j])){
                    return true;
                }
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>k[i];
    }
    if(ballot()){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}
