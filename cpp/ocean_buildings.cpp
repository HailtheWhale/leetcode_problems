#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/buildings-with-an-ocean-view
class Solution{
    public:
        vector<int> findBuildings(vector<int>& heights){
            vector<int> ocean_view {};
            int max_height {0};
            for (int i = heights.size()-1; i>=0; i--){
                cout << "Height: " << heights[i] << endl;
                // Sweep right to left as that's what's likely to have the view.
                // If blocked, it doesn't have a view.
                if (heights[i] <= max_height) {
                    cout << "View blocked!" << endl;
                    continue;
                }
                // Otherwise, height increases.
                max_height = heights[i];
                ocean_view.push_back(i);
            }

            // Wanted the indices sorted in increasing order.
            sort(ocean_view.begin(),ocean_view.end());
            return ocean_view;
        }
};

int main(){
    Solution sol;
    
    // Test 1
    vector<int> heights {4,2,3,1};
    vector<int> ocean_view = sol.findBuildings(heights);
    cout << "Ocean view: ";
    for (auto& i: ocean_view) cout << i << " ";
    cout << endl;

    // Test 2
    heights = {4,3,2,1};
    ocean_view = sol.findBuildings(heights);
    cout << "Ocean view: ";
    for (auto& i: ocean_view) cout << i << " ";
    cout << endl;

    // Test 3
    heights = {1,3,2,4};
    ocean_view = sol.findBuildings(heights);
    cout << "Ocean view: ";
    for (auto& i: ocean_view) cout << i << " ";
    cout << endl;


    return 0;
}