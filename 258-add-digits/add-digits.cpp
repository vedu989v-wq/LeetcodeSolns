#include<cmath>
class Solution {
public:
    int addDigits(int num) {
        int len=0;
        int a=num;
        while(a){
            len++;
            a=a/10;
        }
        while(num/10!=0){
        int sum=0;
        int a=num;
        for(int i=1; i<=len; i++){
            int p=int(pow(10, len-i));
            int bit=a/p;
            a=a%p;

            sum=sum+bit;
        }
        num=sum;
        }

        return num;
    }
};