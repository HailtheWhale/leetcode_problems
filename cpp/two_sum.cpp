#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    // The parser
    vector<int> twoSum(vector<int>& nums, int target) {
        // Make a hashmap
        unordered_map<int, int> seen;
        
        for (int i = 0; i < static_cast<int>(nums.size()); i++){
            
            // diff is the other number
            int diff = target - nums[i];
            if (seen.count(diff)) {
                return {seen[diff], i};
            }
            seen[nums[i]] = i;
        }
        
        return {};
    }
    
    // Testing
    void test(vector<int>& nums, int target) {
        vector<int> result = this->twoSum(nums, target);
    
        cout << "Test result: ";
        for (int i: result) 
            cout << i << " ";
        cout << endl;
    }
};

int main() {
    Solution sol;
    
    // Test 1
    vector<int> nums = {2, 7, 11, 15};
    sol.test(nums, 9);
    // Test 2
    nums = {3, 2, 4};
    sol.test(nums, 6);
    // Test 3
    nums = {3, 3};
    sol.test(nums, 6);
}