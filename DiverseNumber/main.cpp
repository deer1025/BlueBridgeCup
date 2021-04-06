#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
/*随机产生4个数字，对每一位进行判重，
如果有重复则重新产生*/
bool pick[10];//判重标志
int main(){
	srand((unsigned)time(NULL));
	int a=rand()%9+1;
	pick[a]=true;
	cout<<a;
	int cnt=4;
	while(cnt--){
		a=rand()%9;
		if(!pick[a]){
			pick[a]=true;
			cout<<a;
		}
	}
	return 0;
}
/*package example;
//选择区域缩小法：
定义一个数组array{0,1,2,3,4,5,6,7,8,9}，用Random(array.length)函数选择下标i，
读取array[i]做第一位，移除array[i];
再用Random(array.length-1)选择下标i，读取array[i]做第二位，移除array[i]依次类推。
时间复杂度为 T(n) = O(4)
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
public class disperserNumber {
    public static void main(String[] args) {

        Random rand=new Random();
        List<Integer> set=new ArrayList<Integer>();
        for(int i=0;i<10;i++){set.add(new Integer(i));}

        int multiple=1;
        int result=0;

        for(int i=0;i<4;i++){

            Integer in= set.get(rand.nextInt(9-i));
            set.remove(in);
            result+=in*multiple;
            multiple*=10;
            if(i==2){set.remove(new Integer(0));}
        }
        System.out.println(result);
    }
}
*/
