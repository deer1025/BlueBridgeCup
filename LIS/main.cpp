/*LIS(Longest Increased Subsequence)���������������*/
#include <iostream>
#include<vector>
using namespace std;
    int lengthOfLIS(vector<int>& nums) {
        int dp[2501];
        int index;//��¼��ǰ���ٸ����֣����Ǹ�����������еĳ���
        int lengthOfLIS(vector<int>& nums) {
            int len=nums.size();//size()���ص��ǳ���
            index = 0;
            //��ʱ��dp[i]��¼���ǳ���Ϊi�Ľ�β����С������
            dp[++index] = nums[0];//��ʼ����һ��Ԫ��
            for(int i = 1;i < len;++i){//����nums����
                if(nums[i]>dp[index]){//���������Ǹ�����ô�Ͳ��������
                    dp[++index]=nums[i];
                }
                else{
                    //�����Ҫ�滻dp�����е�һ����nums[i]�����ȵ�����
                    int axe=findFirstBigger(nums[i]);
                    if(axe!=-1){
                            dp[axe]=nums[i];
                    }
                }
            }
            return index;
        }
         /*
            ����dp�����е�һ�����ڵ���key�������±�
        */
        int findFirstBigger(int key){
            int left=1,right=index;
            while(left<=right){
                int mid=(left+right)/2;//����
                if(left==right&&dp[mid]==key){//�ҵ��˵�һ����key�����ȵ���������������
                    return mid;
                }
                if(key>dp[mid]){
                    left=mid+1;//ע��˴���mid+1
                }
                else{
                    right=mid;//ע��<=����mid����ֹmid���ǵ�һ����key�������
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
    int res=0;//�������������    ����
    for(int i=0;i<len;++i){
        dp[i]=1;//dp[i]��ʾ��nums[i]Ϊĩβ������������еĳ���
        for(int j=0;j<i;++j){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
                //dp[j]+1��ʾ������j<i����nums[j]<nums[i]����nums[j]��β����������ĩβ׷����nums[i]��õ���������
            }
        }
        res=max(res,dp[i]);
    }
    return res;
}

int lengthOfLIS(vector<int>& nums) {
        int len=nums.size(),dp[2501];//dp[i]��ʾ����Ϊi+1������������ĩβԪ�ص���Сֵ(�����ھ���INF)
        fill(dp,dp+len,INF);//�ʼȫ��dp��ֵ����ʼ��ΪINF
        for(int i=0;i<len;++i){
            *lower_bound(dp,dp+len,nums[i])=nums[i];//����ÿ��nums[i],���i==0����dp[i-1]<nums[j]�Ļ����͸���dp[i]=min(dp[i],nums[j])
        }
        return (lower_bound(dp,dp+len,INF)-dp);//����ʹ��dp[i]<INF������i+1��Ϊ���
    }
