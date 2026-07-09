#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
    // bool isPalindrome(int x) {
    //     // Palindromes are not negative
    //     if (x<0){return 0;}

    //     string s_in = to_string(x);
    //     return equal(s_in.begin(), s_in.end(), s_in.rbegin());
    // };

    bool isPalindromeInt(int x) {
        if (x<0){return 0;}

        long long digit {0};
        const long long original = x;

        while (x > 0){
            digit = digit * 10 + (x % 10);
            x /= 10;
        }
        return (digit == original);
    };
};

int main () {
    Solution sol;
    cout << sol.isPalindromeInt(121) << endl;
    cout << sol.isPalindromeInt(-121) << endl;
    cout << sol.isPalindromeInt(10) << endl;

    return 0;
}