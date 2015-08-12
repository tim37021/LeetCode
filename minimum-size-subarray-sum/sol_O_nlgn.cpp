/*
13 / 13 test cases passed.
Status: Accepted
Runtime: 12 ms
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> table(nums.size()+1, 0);

        for(int i=0; i<nums.size(); i++)
            table[i+1]=table[i]+nums[i];
            
        int ans=INT_MAX;
        for(int i=1; i<=nums.size(); i++)
        {
            // sum[p, q]=table[q]-table[p-1] >= s
            // => table[q]>= s+table[p-1]
            auto it=lower_bound(table.begin()+i, table.end(), s+table[i-1]);
            if(it!=table.end())
            {
                int j=it-table.begin();
                ans=min(ans, j-i+1);
            }
        }
        return ans==INT_MAX? 0: ans;
    }
};