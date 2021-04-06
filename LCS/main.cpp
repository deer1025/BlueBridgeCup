//LCS(longest Common Subsequence)最长公共子序列
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
char s1[1001];
char s2[1001];
int dp[1001][1001];
int max(int a,int b,int c=0){
    if(a>=b){
        return a>c?a:c;
    }
    else{
        return b>c?b:c;
    }
}
void DP(){
    //DP求解
    //先获取两个字符串的长度
    int row = strlen(s1);
    int col = strlen(s2);

    //初始化第一行
    bool first = false;
    for(int j=0;j<col;j++){
        if(s1[0]==s2[j]){//遇到了第一个相等的字符
            first = true;
        }
        if(first)dp[0][j]=1;
        else dp[0][j] = 0;
    }

    //初始化第一列
    first = false;
    for(int i=0;i<row;i++){
        if(s1[i]==s2[0]){
            first = true;
        }
        if(first)dp[i][0]=1;
        else dp[i][0] = 0;
    }

    //开始迭代，就是dp
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(s1[i]==s2[j]){
                //如果这两个字符相等就看左上角的数字和上、左数字取最大值
                dp[i][j] = max(dp[i-1][j-1]+1,dp[i-1][j],dp[i][j-1]);
            }
            else{
                //否则只看左、上
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
}
string parseString(){
    int x = strlen(s1)-1;
    int y = strlen(s2)-1;
    string ans;
    while(true){
        //走到了左上角
        if(x==-1 || y==-1)break;
        //相等的走法
        if(s1[x]==s2[y]){
            ans+=s1[x];
            x--;y--;
            continue;
        }
        //只有一条路可走
        if(x-1<0){
            y--;
            continue;
        }
        if(y-1<0){
            x--;
            continue;
        }
        //不相等的走法
        if(dp[x-1][y]>dp[x][y-1]){
            x--;
        }else{
            y--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    cin>>s1>>s2;
    DP();
    cout<<parseString()<<endl;
    return 0;
}
