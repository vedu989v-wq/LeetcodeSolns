class Solution {
public:
    int arithmeticTriplets(vector<int>& arr, int target) {
        int start=0, end=1;
        int trips=0;
        unordered_map<int, int>m;
        int n=arr.size();
        while(end<n){
            if(arr[end]-arr[start]==target){
                m[start]=end;
                start++;
                end++;
            }
            else if(arr[end]-arr[start]<target)
            end++;
            else
            start++;
        }

        for (const auto& [key, value] : m) {

        if(m.count(value))
        trips++;
        
        }

        return trips;
    }
};