class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z = 0, nz = 0;
        while(z < nums.size() && nz < nums.size())
        {
            while(nz < nums.size() && !nums[nz]) nz += 1;
            while(z < nz && nums[z]) z += 1;
            if(nz < nums.size() && z < nz)
            {
                nums[z] = nums[nz];
                nums[nz] = 0;                
            }
            z+= 1;
            nz += 1;
        }
    }
};