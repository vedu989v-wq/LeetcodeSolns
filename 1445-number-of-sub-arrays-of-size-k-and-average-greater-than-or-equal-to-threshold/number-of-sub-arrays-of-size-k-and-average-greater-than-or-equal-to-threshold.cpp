class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(k>arr.size())
        return 0;

        //step 1: first window
        int sum=0;
        for(int i=0; i<k; i++){
          sum=sum+arr[i];
        }
        int avg=sum/k;
        int n=0;

        if(avg>=threshold)
            n++;
            
        for(int i=k; i<arr.size(); i++){
            
            sum=sum-arr[i-k];
            sum=sum+arr[i];
            avg=sum/k;

            if(avg>=threshold)
            n++;
        }

        return n;
    }
};