//运用哈弗曼树
#include <iostream>
using namespace std;
int N,len[20001];
long long solve(){
    long long ans=0;
    while(N>1){
            int min1=0,min2=1;
        if(len[min1]>len[min2]){
            min1=min1+min2;
            min2=min1-min2;
            min1=min1-min2;
        }
        for(int i=2;i<N;++i){//i必须从2开始
            if(len[min1]>len[i]){
                min2=min1;
                min1=i;
            }
            else if(len[min2]>len[i]){//必须用else if，如果用if会把min1和min2都变成i
                min2=i;
            }
        }
        long long t=len[min1]+len[min2];
        ans+=t;
        if(min1==N-1){
            //交换min1、min2
            min1=min1+min2;
            min2=min1-min2;
            min1=min1-min2;
        }
        len[min1]=t;
        len[min2]=len[N-1];
        N--;
    }
    return ans;
}
int main()
{
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>len[i];
    }
    cout <<solve()<< endl;
    return 0;
}
