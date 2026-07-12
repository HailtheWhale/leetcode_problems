#include <iostream>
#include <string>
#include <unordered_set>


using namespace std;

class Solution{
    public:
        bool canConstruct(string ransomNote, string magazine){
            // Use a frequency array to count magazine bits
            int freq[26] {0};
            for (char c: magazine){
                freq[c - 'a']++;
            }
            // Check random note
            for (char c: ransomNote){
                if (--freq[c-'a'] < 0) return false;
            }

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