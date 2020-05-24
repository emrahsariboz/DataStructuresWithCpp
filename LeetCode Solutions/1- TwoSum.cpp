class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
         unordered_map<int , int> umap;
        
         vector<int> indices;
          for (int i=0; i<nums.size(); i++){
                umap.emplace(nums[i], i);
          }

          for(int i=0; i<nums.size(); i++){
                auto it = umap.find(target - nums[i]);

                if( it != umap.end() && umap[target -nums[i]] != i){
                        indices.push_back(umap[target -nums[i]]);
                        indices.push_back(i);
                        return indices;
                }

          }
        
        return indices;
    }
};