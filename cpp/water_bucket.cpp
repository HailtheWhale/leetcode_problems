#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/container-with-most-water/description/
class Solution{
public:
    int maxArea(vector<int>& height){
        int left {0};
        int right {static_cast<int>(height.size()) - 1};
        int max_area {0};
        int h {0};
        int w {0};
        
        while (left < right){
            h = min(height[left],height[right]);
            w = right - left;
            max_area = max(max_area, h*w);

            // Move shorter wall inward hoping to find a taller one.
            if (height[left] < height[right]){
                left ++;
            } else {
                right --;
            }
        }

        return max_area;
    }
};


int main() {
    Solution sol;

    vector<int> h = {1,8,6,2,5,4,8,3,7};
    cout << "Max area 1: " << sol.maxArea(h) << endl;
    h = {1,1};
    cout << "Max area 2: " << sol.maxArea(h) << endl;

    return 0;
}