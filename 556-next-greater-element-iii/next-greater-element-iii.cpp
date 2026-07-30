class Solution {
public:
    int nextGreaterElement(int n) {
     string a=to_string(n);
    
    //Step1: finding pivot
      int pivot=a.length()-1;
     for(int i=a.length()-1; i>=1; i--){
       if(a[i-1]<a[i]){
          pivot=i-1;
          break;
       }
     }
    
    //Step2: Swap the rightmost number, which is just larger than the element present on pivot

    if(pivot==a.length()-1){
        return -1;
    }

    int j=a.length()-1;

    while(a[j]<=a[pivot]){
        j--;
    }
    swap(a[pivot], a[j]);

    //Step3: Reversing digit after pivot
    int start=pivot+1;
    int end=a.length()-1;

    while(start<=end){
        swap(a[start], a[end]);
        start++;
        end--;
    }
    

    long long ans=stoll(a);

    return ans>INT_MAX?-1:int(ans);

    }
};