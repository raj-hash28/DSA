class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftPointer = 0, rightPointer = height.size()-1;
        int maxWater = 0;

        while(leftPointer < rightPointer){
            int w = rightPointer - leftPointer;
            int ht = min(height[leftPointer], height[rightPointer]);
            int currWater = w * ht;
            maxWater = max(maxWater, currWater);

            if(height[leftPointer] < height[rightPointer]){
                leftPointer++;
            } else {
                rightPointer--;
            }
        }
        return maxWater;
    }
};