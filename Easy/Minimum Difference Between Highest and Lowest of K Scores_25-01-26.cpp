class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> arr;
        sort(nums.begin(),nums.end());
        int ans=nums[k-1]-nums[0];
        for(int i=0;i<=n-k;i++){
            int len=nums[i+k-1]-nums[i];
            ans=min(ans,len);
        }
        return ans;
    }
};