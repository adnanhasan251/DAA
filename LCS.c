#include <stdio.h>
#include <string.h>

#define MAX 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the length of LCS and fill memoization table
int lcs(const char *s1, const char *s2, int m, int n, int memo[MAX][MAX]) {
    // Base Case
    if (m == 0 || n == 0) {
        return 0;
    }

    // Already exists in the memo table
    if (memo[m][n] != -1) {
        return memo[m][n];
    }

    // Match
    if (s1[m - 1] == s2[n - 1]) {
        return memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1, memo);
    }

    // Do not match
    return memo[m][n] = max(lcs(s1, s2, m, n - 1, memo), lcs(s1, s2, m - 1, n, memo));
}

// Function to print the LCS using the memoization table
void printLCS(const char *s1, const char *s2, int m, int n, int memo[MAX][MAX]) {
    int index = memo[m][n];
    char lcsStr[index + 1];
    lcsStr[index] = '\0'; // Null-terminate the LCS string

    // Start from the bottom-right corner of the memo table
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If characters match, add to the LCS string
        if (s1[i - 1] == s2[j - 1]) {
            lcsStr[index - 1] = s1[i - 1]; // Add character to the result
            i--;
            j--;
            index--;
        }
        // Move in the direction of the larger value
        else if (memo[i - 1][j] > memo[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("LCS: %s\n", lcsStr);
}

int main() {
    const char *s1 = "AGGTAB";
    const char *s2 = "GXTXAYB";

    int m = strlen(s1);
    int n = strlen(s2);

    int memo[MAX][MAX];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            memo[i][j] = -1;
        }
    }

    int length = lcs(s1, s2, m, n, memo);
    printf("Length of LCS: %d\n", length);

    // Print the LCS string
    printLCS(s1, s2, m, n, memo);

    return 0;
}
