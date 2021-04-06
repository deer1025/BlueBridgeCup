#include <iostream>
#include<algorithm>
using namespace std;
int n,cnt=0;
pair<int,int>job[101];
int dfs(){
    int ans = -1;//ans是所选工作的结束时间，不能初始化为0由于可能第一项工作的开始时间为0
    for(int i=0;i<n;++i){
        if(ans<job[i].second){
            ans=job[i].first;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>job[i].second;//s
    }
    for(int i=0;i<n;++i){
        cin>>job[i].first;//t
    }
    sort(job,job+n);
    cout<<dfs()<< endl;
    return 0;
}

