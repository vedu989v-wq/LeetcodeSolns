// ---X----Contest Written Syntax--X---

// class Solution {
// public:
//     vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
//         vector<vector<int>>ans;

//         for(int i=0; i<series1.size(); i++){
//             int key=series1[i][0];

//             int start=0;
//             int end=series2.size()-1;
//             int s2key=0;
//             //binary search
//             while(start<=end){
//                 int mid=start+(end-start)/2;
                 
//                 if(series2[mid][0]==key){
//                     s2key=mid;
//                     break;
//                 }
//                 else if(series2[mid][0]<key){
//                     start=mid+1;
//                 }
//                 else{
//                     s2key=mid;
//                     end=mid-1;
//                 }
//             }
//             if(s2key!=0){
//             ans.push_back({key, series1[key][1]+series2[s2key][1]});
//             }
//             else{
//                 ans.push_back({key, series1[key][1]});
//             }
//         }
//         for(int i=0; i<series2.size(); i++){
//             int key=series2[i][0];

//             int start=0;
//             int end=series1.size()-1;
//             int s1key=0;
//             //binary search
//             while(start<=end){
//                 int mid=start+(end-start)/2;
                 
//                 if(series1[mid][0]==key){
//                     s1key=mid;
//                     break;
//                 }
//                 else if(series1[mid][0]<key){
//                     start=mid+1;
//                 }
//                 else{
//                     s1key=mid;
//                     end=mid-1;
//                 }
//             }
//             ans.push_back({key, series1[s1key][1]+series2[key][1]});
//         }

//         return ans;
//     }
// };

// --X--- Upsolving---X--

class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<int>timestamps;

        //1) collecting all the timestamps

        for(int i=0; i<series1.size(); i++){
            timestamps.push_back(series1[i][0]);
        }

        for(int i=0; i<series2.size(); i++){
            timestamps.push_back(series2[i][0]);
        }

        //2) Sort and remove duplicates
        sort(timestamps.begin(), timestamps.end());
        timestamps.erase(unique(timestamps.begin(), timestamps.end()), timestamps.end());

        vector<vector<int>>ans;

        for(int i=0; i<timestamps.size(); i++){
            int sum=0;

            //binary search in series1 (lower_bound)

            int l=0, r=series1.size()-1;
            int idx=-1;

            while(l<=r){
                int mid=l+(r-l)/2;

                if(series1[mid][0]>=timestamps[i]){
                    idx=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }

            if(idx!=-1)
            sum+=series1[idx][1];

            //binary search in series2 (lower_bound)
            l=0, r=series2.size()-1;
            idx=-1;

            while(l<=r){
                int mid=l+(r-l)/2;

                if(series2[mid][0]>=timestamps[i]){
                    idx=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }

            if(idx!=-1)
            sum+=series2[idx][1];

             ans.push_back({timestamps[i], sum});
        }

      return ans;
       
    }
};

