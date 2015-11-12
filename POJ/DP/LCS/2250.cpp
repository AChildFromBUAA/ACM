/*  poj 2250
 *  LCS
 */

#include <cstdio>
#include <cstring>

char strs[110][50];
char strs1[110][50], strs2[110][50];
int size1, size2;
//int lcsLen;
int n;
int f[110][110];

void LCS() {
    for(int i=1; i <= size1; i++) {
        for(int j=1; j <= size2; j++) {
            if(!strcmp(strs1[i-1], strs2[j-1])) {
                f[i][j] = f[i-1][j-1] + 1;
            } else {
                f[i][j] = f[i][j-1] > f[i-1][j] ? f[i][j-1] : f[i-1][j];
            }
            //lcsLen = f[i][j] > lcsLen ? f[i][j] : lcsLen;
        }
    }
}

void find() {
    for(int i=size1, j=size2; i>0 && j>0; ) {
        if(!strcmp(strs1[i-1], strs2[j-1])) {
            strcpy(strs[n++], strs1[i-1]);
            i--;
            j--;
        } else if(f[i][j-1] > f[i-1][j]) {
            j--;
        } else {
            i--;
        }
    }
}

int main()
{
    while(~scanf("%s",strs1[0])) {
        size1 = 1;
        while(strcmp(strs1[size1-1], "#")) {
            scanf("%s", strs1[size1++]);
        }
        size1--;
        scanf("%s", strs2[0]);
        size2 = 1;
        while(strcmp(strs2[size2-1], "#")) {
            scanf("%s", strs2[size2++]);
        }
        size2--;
        n = 0;
        LCS();
        find();
        for(int i=n-1; i>-1; i--) {
            printf("%s ", strs[i]);
        }
        printf("\n");
    }
}