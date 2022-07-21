/*
Solution For Maximum Product Subarray Problem

Approach 1:-

Variation of Largest Contiguous Sum Subarray Problem
Here, we have to deal with negative elements also in the array.
Whenever a negative element is multiplied with the current maximum product, it becomes minimum product and vice versa right?
So, we will be finding both current maximum as well as minimum product upto every index i.
Also, note that whenever we'll encounter the negative element, we will swap the max product and minimum product.
Take maximum for every index i
*/
 int maxProduct(vector<int>& nums) {
    int ans = nums[0],max_prod = nums[0],min_prod = nums[0]; // initialize max product,min product and answer
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) // if number is negative, we will swap max prod and min prod
                swap(max_prod,min_prod);
            max_prod = max(nums[i],max_prod*nums[i]); // find current max prod each time
            min_prod = min(nums[i],min_prod*nums[i]); // find current min prod each time
            ans = max(ans,max_prod); // store the maximum product each time
        }
        return ans;

    }