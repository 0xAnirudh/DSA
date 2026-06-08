class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> freq;
        vector<int> result;

        for (int x : nums) freq[x]++;

        for(auto x : freq)
            if(x.second > nums.size()/3) result.push_back(x.first);
        
        return result;
    }
};