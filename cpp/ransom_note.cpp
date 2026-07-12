#include <iostream>
#include <string>
#include <unordered_set>


using namespace std;

class Solution{
    public:
        bool canConstruct(string ransomNote, string magazine){
            // Convert the magazine to letters that can be sorted.
            unordered_multiset<char> mag_pieces{};
            cout << "Letters available: ";
            for (auto& letter: magazine){
                cout << letter << " ";
                mag_pieces.insert(letter);
            }
            cout << endl;

            cout << "Ransom Note: " << ransomNote << endl;
            for (auto& letter: ransomNote){
                // Check if the letter exists in the pieces available.
                if (!mag_pieces.count(letter)) {
                    return false;
                }
                // If it does, then we remove a letter.
                mag_pieces.erase(mag_pieces.find(letter));
            }
            // If can get through the entire ransom letter, then can be decoded.
            return true;

        }
};


int main(){
    Solution sol;

    // Test 1
    string ransomNote = "a";
    string magazine = "b";
    cout << sol.canConstruct(ransomNote, magazine) << endl << endl;


    // Test 3
    ransomNote = "aa";
    magazine = "ab";
    cout << sol.canConstruct(ransomNote, magazine) << endl << endl;


    // Test 3
    ransomNote = "aa";
    magazine = "aab";
    cout << sol.canConstruct(ransomNote, magazine) << endl << endl;

    return 0;
}