class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int ans=-1, start=0, n=arr.size();
        int end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            //final condition
            if(arr[mid]==target)
            return true;
            
            //duplicates
            if(arr[start]==arr[mid] && arr[mid]==arr[end]){
                start++;
                end--;
            }

            else if(arr[mid]>=arr[start]){
                if(arr[start]<=target && arr[mid]>target)
                end=mid-1;
                else
                start=mid+1; 
            }

            else {
                if(arr[mid]<target && arr[end]>=target)
                start=mid+1;
                else
                end=mid-1;
            }
            

        }
        return false;
    }
};