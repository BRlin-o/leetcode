class Solution {
public:
    vector<int> nums;
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int left = 0;
        int right = nums.size()-1;
        int mid = left + (right-left)/2;
        while(left < right) {
            if(nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid+1;
            else right = mid-1;
            mid = left + (right-left)/2;
        }
        return nums[mid] == target ? mid : -1;
    }
};
