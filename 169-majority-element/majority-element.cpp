class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq;
        int n = nums.size();

        for (auto a : nums){
            freq[a]++;

            if(freq[a] > n/2) return a;
        }
        return -1;
    }
};