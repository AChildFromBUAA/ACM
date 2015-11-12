/*  poj 2533
 *  LIS
 */

#include <cstdio>

int a[10010];
int n, count;
int t[10010];

int bs(int l, int r, int num) {
    int ans = -1;
    while(l<=r) {
        int m = (l+r) >> 1;
        if(num <= t[m] && num > t[m-1]) {
            ans = m;
            break;
        } else if(num > t[m]) {
            l = m+1;
        } else {
            r = m-1;
        }

    }
    return ans;
}


void LIS() {
    int j;
    count = 1;
    t[0] = a[0];
    for(int i=1; i < n; i++) {
        if(a[i] < t[0]) {
            j=0;
        } else if(a[i] > t[count-1]) {
            j = count++;
        } else {
            j = bs(0, count-1, a[i]);
        }
        t[j] = a[i];
    }
}

int main()
{
    while(~scanf("%d", &n)) {
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        LIS();
        printf("%d\n", count);
    }
}