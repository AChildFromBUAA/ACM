/* poj 3624
 * 01背包问题
 */

#include <cstdio>

const int maxn = 3410;
int w[maxn], d[maxn], f[12900];

int max(int a, int b) {
    return a > b ? a : b;
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        for(int i=0; i < n; i++) {
            scanf("%d%d", &w[i], &d[i]);
        }
        //f[v] = max{f[v], f[v - w[i]] + d[i];
        for(int i=0; i < n; i++) {
            for(int v=m; v>=w[i]; v--) {
                f[v] = max(f[v], f[v - w[i]] + d[i]);
            }
        }
        printf("%d\n", f[m]);
    }
}
