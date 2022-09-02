class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> pq; //[(index)]
        vector<int> ans;
        for(int i=0;i<n;++i){
            while((pq.empty()==false) && (nums[i] >= nums[pq.back()])){
                pq.pop_back();
            }
            pq.push_back(i);
            if(i>=k-1){
                while(pq.front() <= i-k){
                    pq.pop_front();
                }
                ans.push_back(nums.at(pq.front()));
            }
        }
        return ans;
    }
};

/*
Runtime: 328 ms, faster than 88.75% of C++ online submissions for Sliding Window Maximum.
Memory Usage: 134.6 MB, less than 92.32% of C++ online submissions for Sliding Window Maximum.
*/