/*  poj 1934
 *  LCS + dfs
 */


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string strs[10100];
char str1[110], str2[110];
int n;
int lcsLen;
int f[110][110];
int loc1[110][30], loc2[110][30];

void LCS() {
    int x = strlen(str1);
    int y = strlen(str2);
    for(int i = 0; i <= x; i++)
        f[i][0] = 0;
    for(int i = 0; i <= y; i++)
        f[0][i] = 0;
    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y; j++) {
            if(str1[i-1] == str2[j-1]) {
                f[i][j] = f[i-1][j-1] + 1;
            } else {
                f[i][j] = f[i-1][j] > f[i][j-1] ? f[i-1][j] : f[i][j-1];
            }
            lcsLen = lcsLen > f[i][j] ? lcsLen : f[i][j];
        }
    }
}

void loc(char *str, int loc[][30]) {
    int len = strlen(str);
    for(int i = 1; i <= len; i++) {
        for(int j = 0; j < 26; j++) {
            if(str[i-1] == 'a' + j) {
                loc[i][j] = i;
            } else {
                loc[i][j] = loc[i-1][j];
            }
        }
    }
}

void dfs(string ans, int x, int y, int len) {
    if(len == 0) {
        strs[n++] = ans;
        return;
    }
    if(x == -1 || y == -1) return;
    if(str1[x] == str2[y]) {
        dfs(str1[x] + ans, x-1, y-1, len-1);
    } else {
        for(int i=0; i < 26; i++) {
            if(f[loc1[x+1][i]][loc2[y+1][i]] == len) {
                dfs(ans, loc1[x+1][i]-1, loc2[y+1][i]-1, len);
            }
        }
    }
}

int main()
{
    while(cin >> str1 >> str2) {
        lcsLen = 0;
        n = 0;
        LCS();
        loc(str1, loc1);
        loc(str2, loc2);
        dfs("", strlen(str1)-1, strlen(str2)-1, lcsLen);
        sort(strs, strs+n);
        for(int i=0; i < n; i++) {
            cout << strs[i] << "\n";
        }
      
    }
    return 0;
}