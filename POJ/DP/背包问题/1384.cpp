/*  poj 1384
 *  完全背包问题
 */

#include <cstdio>

int v[510], w[510];
const int maxn = 500*50001;

int min(int a, int b) {
    return a < b ? a : b;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int f[10010];
        f[0] = 0;
        for(int i=1; i < 10010; i++) {
            f[i] = maxn;
        }
        
        int a, b;
        scanf("%d%d", &a, &b);
        int u = b - a;
        
        int n;
        scanf("%d", &n);
        for(int i=0; i < n; i++) {
            scanf("%d%d", &v[i], &w[i]);
        }
        
        // f[j] = min(f[j], f[j - w[i]] + v[i]);
        for(int i=0; i < n; i++) {
            for(int j=w[i]; j <= u; j++) {
                f[j] = min(f[j], f[j - w[i]] + v[i]);
            }
        }
        
        if(f[u] != maxn) {
            printf("The minimum amount of money in the piggy-bank is %d.\n", f[u]);
        } else {
            printf("This is impossible.\n");
        }
        
    }
}