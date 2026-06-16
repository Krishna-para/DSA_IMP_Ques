#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int t[1001][1001];

    int recur(string &text1, string &text2, int i, int j) {
        if (i >= m || j >= n) return 0;
        if (t[i][j] != -1) return t[i][j];
        if (text1[i] == text2[j])
            return t[i][j] = 1 + recur(text1, text2, i+1, j+1);
        return t[i][j] = max(recur(text1, text2, i, j+1), recur(text1, text2, i+1, j));
    }

    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size();
        n = text2.size();
        memset(t, -1, sizeof(t));
        return recur(text1, text2, 0, 0);
    }
};

int main() {
    Solution sol;
    string text1, text2;

    cout << "Enter text1: ";
    cin >> text1;
    cout << "Enter text2: ";
    cin >> text2;

    cout << "LCS Length: " << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}