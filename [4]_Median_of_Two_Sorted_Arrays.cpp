class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        if(nums1.size()&1){
            return (double)nums1.at((int)nums1.size()/2);
        }else{
            return (double)(nums1.at(nums1.size()/2)+nums1.at(nums1.size()/2-1))/2;
        }
    }
};