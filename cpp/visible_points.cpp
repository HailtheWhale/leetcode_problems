#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/maximum-number-of-visible-points
class Solution{
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location){
        // Objective: Count the pts for each PoV. Return the max.
        int same_spot {0};

        // Get each points angle in degrees.
        int dx, dy {0};
        double angle_ {0.0};
        vector<double> pt_angles {};
        for (const auto& pt : points){
            dx = pt[0] - location[0];
            dy = pt[1] - location[1];

            // The point is on top of the viewer.
            if (dx == 0 && dy == 0){
                same_spot += 1;
                continue;
            }

            // Get the angle and wrap it.
            angle_ = atan2(dy, dx) * 180.0 / M_PI;
            if (angle_ < 0) angle_ += 360.0;
            pt_angles.push_back(angle_);
        }

        // Sort the angles.
        sort(pt_angles.begin(), pt_angles.end());

        // Angle wrapping means need to duplicate angles for search
        vector<double> wrap_angles = pt_angles;
        for (double a: pt_angles)
            wrap_angles.push_back(a + 360.0);

        // Use the angle given. That is the band. Step through the vector keeping track of the max via sliding window.
        unsigned int max_seen {0};
        int left {0};

        for (unsigned int right = 0; right < wrap_angles.size() ; right++){
            // Build the FoV
            while (wrap_angles[right] - wrap_angles[left] > angle){
                left++;
            }
            max_seen = max(max_seen, (right - left + 1));
        }


        return same_spot + max_seen;
    }
};

int main() {
    Solution sol;

    // Test 1
    vector<vector<int>> points {{2,1}, {2,2}, {3,3}};
    int angle = 90;
    vector<int> location {1, 1};
    int result = sol.visiblePoints(points, angle, location);
    cout << "Visible points: " << result << endl;

    // Test 2
    points = {{2,1},{2,2},{3,4},{1,1}};
    angle = 90;
    location = {1,1};
    result = sol.visiblePoints(points, angle, location);
    cout << "Visible points: " << result << endl;

    // Test 3
    points = {{1,0},{2,1}};
    angle = 13;
    location = {1,1};
    result = sol.visiblePoints(points, angle, location);
    cout << "Visible points: " << result << endl;

    return 0;
}