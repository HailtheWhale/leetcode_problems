#include <iostream>
#include <vector>


using namespace std;

class Solution{
    public:
        bool dfs(int course, vector<vector<int>>& graph, vector<int>& state){
            if (state[course] == 1) return false; // cycle
            if (state[course] == 2) return true; // already checked
            
            state[course] = 1; // visiting

            for (int next : graph[course]){
                if (!dfs(next, graph, state)) return false;
            }

            state[course] = 2; // mark as visited
            return true;
        }

        bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
            vector<vector<int>> graph(numCourses);

            // Build the graph
            for (auto& p : prerequisites){
                // Each p is a pair of vals.
                graph[p[1]].push_back(p[0]);
            }

            cout << "Graph contents: " << endl;
            for (auto& i: graph){
                for (auto& j: i){
                    cout << j << " ";
                }
            }
            cout << endl;

            vector<int> state(numCourses, 0);

            // Run DFS on every course
            for (int course = 0; course < numCourses; course++){
                if (!dfs(course, graph, state)) return false;
            }
            return true;

        }
};


int main() {
    Solution sol;

    // Test 1
    int numCourses {3};
    vector<vector<int>> prerequisites {{1,0}};
    bool finish = sol.canFinish(numCourses, prerequisites);
    cout << "Can finish: "<< finish << endl;

    // Test 2
    numCourses=2;
    prerequisites = {{1,0}, {0,1}};
    finish = sol.canFinish(numCourses, prerequisites);
    cout << "Can finish: "<< finish << endl;

    return 0;
}