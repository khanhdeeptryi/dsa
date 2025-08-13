
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void ChenChuoiTaiVitriK(char s[], char s1[], int k);
void Chuanhoa(char s[]);
int myStrlen(char s[], int k);
bool myStrcat(char s[], char s1[], char s2[]);
void myStrcpy(char s[], int vt, char s1[], int k);
int myStrstr(char s[], char s1[]);


int main()
{
    char s[MAX];

    fflush(stdin);
    fgets(s,MAX,stdin);

    char s1[MAX];
    myStrcpy(s1, 0, s, 0);
    Chuanhoa(s1);
    cout << s << endl << s1 << endl;
    return 0;
}

int myStrlen(char s[], int k) {
    if (!s) return 0;
    int i = k;
    while (s[i] != '\0') i++;
    return i - k;
}

void myStrcpy(char s[], int vt, char s1[], int k) {
    if (!s || !s1) return;
    int i = k, j = vt;
    while (s[i] != '\0') s[j++] = s1[i++];
    s[j] = '\0';
}

bool mystrcat(char s[], char s1[], char s2[]) {
    if (!s || !s1 || !s2) return false;
    int len1 = myStrlen(s1, 0);
    int len2 = myStrlen(s2, 0);
    if (len1 + len2 > MAX) return false;
    int j = 0;
    for (int i = 0; i < len1; i++) s[j++] = s1[i];
    for (int i = 0; i < len2; i++) s[j++] = s2[i];
    s[j] = '\0';
    return true;
}

int myStrstr(char s[], char s1[]) {
    if (!s || !s1) return -1;
    int n = myStrlen(s, 0);
    int m = myStrlen(s1, 0);
    if (m == 0) return 0;
    for (int i = 0; i + m <= n; i++) {
        int k = 0;
        while (k < m && s[i + k] == s1[k]) k++;
        if (k == m) return i;
    }
    return -1;
}

// Insert string s1 into s at position k (shifts the remainder to the right). Best-effort without strict overflow handling.
void ChenChuoiTaiVitriK(char s[], char s1[], int k) {
    if (!s || !s1) return;
    int len = myStrlen(s, 0);
    int ins = myStrlen(s1, 0);
    if (k < 0) k = 0;
    if (k > len) k = len;
    // Shift right
    int newLen = len + ins;
    if (newLen >= MAX) newLen = MAX - 1;
    for (int i = newLen; i >= k + ins; --i) {
        int from = i - ins;
        if (from >= 0 && from <= len) s[i] = s[from];
    }
    // Copy s1
    for (int i = 0; i < ins && (k + i) < MAX - 1; ++i) {
        s[k + i] = s1[i];
    }
    s[newLen] = '\0';
}

// Normalize periods in-place:
// - Remove all spaces before '.'
// - Ensure exactly one space after '.', unless it is the last visible character or before newline/end
void Chuanhoa(char s[]) {
    if (!s) return;

    char out[MAX];
    int i = 0;                  // read index
    int j = 0;                  // write index
    int n = myStrlen(s, 0);

    // Keep newline at end (from fgets) if present; we will handle content up to n, but avoid placing spaces before '\n'.
    // Process up to but not including trailing '\0'
    while (i < n && s[i] != '\0') {
        if (s[i] == '.') {
            // Remove spaces before '.' in output
            while (j > 0 && out[j - 1] == ' ') j--;

            // Place '.'
            if (j < MAX - 1) out[j++] = '.';
            i++; // consume '.'

            // Skip all spaces in input after '.'
            while (i < n && s[i] == ' ') i++;

            // If next char is not end or newline, ensure exactly one space after '.'
            if (i < n && s[i] != '\0' && s[i] != '\n') {
                if (j < MAX - 1) out[j++] = ' ';
            }
        } else {
            // Regular char: just copy
            if (j < MAX - 1) out[j++] = s[i];
            i++;
        }
    }

    // Trim trailing spaces before potential newline or end
    while (j > 0 && out[j - 1] == ' ') j--;

    // Preserve a single ending newline if original had it
    bool hadNewline = (n > 0 && s[n - 1] == '\n');
    if (hadNewline) {
        if (j < MAX - 1) out[j++] = '\n';
    }

    out[j] = '\0';
    myStrcpy(s, 0, out, 0);
}
