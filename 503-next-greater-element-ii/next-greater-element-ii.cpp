class Solution
{
public:
    vector<int> NGT(vector<int> &arr)
    {
        stack<int> st;
        vector<int> ans(arr.size(), -1);

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                ans[i] = arr[st.top()];
            }
            st.push(i);
        }

        return ans;
    }

    vector<int> nextGreaterElements(vector<int> &nums)
    {
        // concatenating same arrays two times
        //  1. Reserve the combined size upfront to prevent multiple memory reallocations
        vector<int> ans = nums;
        ans.reserve(nums.size() + nums.size());

        // 2. Append the second array as a single block copy
        ans.insert(ans.end(), nums.begin(), nums.end());

        ans = NGT(ans);
        ans.resize(nums.size());
        return ans;
        //3. if not using reserve, stl implementation doubling method, will take a lil more time...
    }
};