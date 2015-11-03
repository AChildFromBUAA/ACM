/*  poj 3181
 *  完全背包＋大整数
 */

#include <cstdio>
#include <cstring>

const long long BIG_NUMBER = 1e18;
long long f[1010];
long long p[1010];

int max(int a, int b) {
    return a > b ? a : b;
}

int main()
{
    int n, k;
    while(~scanf("%d%d", &n, &k)) {
        memset(f, 0, sizeof(f));
        memset(p, 0, sizeof(p));
        f[0] = 1;
        // w[i] = i;
        // v[] = {1};
        // f[i][w] = f[i-1][w] + f[i-1][w-w[i]]
        for(int i=1; i < k + 1; i++) {
            for(int v=i; v <= n; v++) {
                f[v] = f[v] + f[v-i];
                p[v] = p[v] + p[v-i];
                p[v] += f[v] / BIG_NUMBER;
                f[v] = f[v] % BIG_NUMBER;
                
            }
        }
        if(p[n]) {
            printf("%lld", p[n]);
        }
        printf("%lld\n", f[n]);
    }
}