class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        int targetIndex = nums.size() - k; // Convert kth largest to index of kth smallest
        
        srand(time(NULL)); // Seed the random number generator
        
        while (left <= right) {
            int randomIndex = left + rand() % (right - left + 1);
            int pivotIndex = randomizedPartition(nums, left, right, randomIndex);
            
            if (pivotIndex == targetIndex) {
                return nums[pivotIndex];
            } else if (pivotIndex < targetIndex) {
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }
        
        return -1; // Return an appropriate value when k is out of range.
    }
    
private:
    int randomizedPartition(vector<int>& nums, int left, int right, int pivotIndex) {
        swap(nums[pivotIndex], nums[right]);
        int pivotValue = nums[right];
        int partitionIndex = left;
        
        for (int i = left; i < right; ++i) {
            if (nums[i] < pivotValue) {
                swap(nums[i], nums[partitionIndex]);
                partitionIndex++;
            }
        }
        
        swap(nums[partitionIndex], nums[right]);
        return partitionIndex;
    }
};
