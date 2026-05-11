#include<iostream>
class Solution {
public:
    int alternateDigitSum(int n) {
        int a=n;
        int len=0;
        while(a){
            len++;
            a=a/10;
        }
        a=n;
        int j=1;
        int sum=0;
        while(j<=len){
        int p=int(pow(10, len-j));
        int bit=a/p;
        a=a%p;
        if(j%2==1){
         sum=sum+bit;
        }
        else{
            sum=sum-bit;
        }
        j++;
        }

        return sum;
    }
};