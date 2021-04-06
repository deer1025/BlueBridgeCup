/*LIS(Longest Increased Subsequence)最长公共递增子序列*/
#include <iostream>
#include<vector>
using namespace std;
    int lengthOfLIS(vector<int>& nums) {
        int dp[2501];
        int index;//记录当前多少个数字，即那个最长递增子序列的长度
        int lengthOfLIS(vector<int>& nums) {
            int len=nums.size();//size()返回的是长度
            index = 0;
            //此时的dp[i]记录的是长度为i的结尾的最小的数字
            dp[++index] = nums[0];//初始化第一个元素
            for(int i = 1;i < len;++i){//遍历nums数组
                if(nums[i]>dp[index]){//如果比最后那个大，那么就插入在最后
                    dp[++index]=nums[i];
                }
                else{
                    //否则就要替换dp数组中第一个比nums[i]大或相等的数字
                    int axe=findFirstBigger(nums[i]);
                    if(axe!=-1){
                            dp[axe]=nums[i];
                    }
                }
            }
            return index;
        }
         /*
            返回dp数组中第一个大于等于key的索引下标
        */
        int findFirstBigger(int key){
            int left=1,right=index;
            while(left<=right){
                int mid=(left+right)/2;//二分
                if(left==right&&dp[mid]==key){//找到了第一个比key大或相等的数，返回其索引
                    return mid;
                }
                if(key>dp[mid]){
                    left=mid+1;//注意此处是mid+1
                }
                else{
                    right=mid;//注意<=处是mid，防止mid就是第一个比key大的数字
                }
            }
            return -1;
        }

int main()
{
    return 0;
}
int lengthOfLIS(vector<int>& nums) {
    int len= nums.size(),dp[2501];
    int res=0;//最长上升子序列总    长度
    for(int i=0;i<len;++i){
        dp[i]=1;//dp[i]表示以nums[i]为末尾的最长上升子序列的长度
        for(int j=0;j<i;++j){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
                //dp[j]+1表示在满足j<i并且nums[j]<nums[i]的以nums[j]结尾上升子序列末尾追加上nums[i]后得到的子序列
            }
        }
        res=max(res,dp[i]);
    }
    return res;
}

int lengthOfLIS(vector<int>& nums) {
        int len=nums.size(),dp[2501];//dp[i]表示长度为i+1的上升序列中末尾元素的最小值(不存在就是INF)
        fill(dp,dp+len,INF);//最开始全部dp的值都初始化为INF
        for(int i=0;i<len;++i){
            *lower_bound(dp,dp+len,nums[i])=nums[i];//对于每个nums[i],如果i==0或者dp[i-1]<nums[j]的话，就更新dp[i]=min(dp[i],nums[j])
        }
        return (lower_bound(dp,dp+len,INF)-dp);//返回使得dp[i]<INF的最大的i+1即为结果
    }
