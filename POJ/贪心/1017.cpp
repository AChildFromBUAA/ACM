/*  poj 1017
 *  装箱问题
 */

#include <cstdio>
#include <cstring>

int a[7];


int main()
{
    while(~scanf("%d", &a[1])) {
        for(int i=2;i<7;i++) {
            scanf("%d", &a[i]);
        }
        int sum =0;
        for(int i=1; i<7; i++){
            if(a[i] != 0) {
                continue;
            } else {
                sum ++;
            }
        }
        if(sum == 6)
            break;
        
        int cnt = 0;
        // 先装6
        cnt += a[6];
        // 装5
        cnt += a[5];
        a[1] -= a[5] *11;
        if(a[1] < 0)
            a[1] = 0;
        // 装4
        cnt += a[4];
        a[2] -= a[4] * 5;
        if(a[2] < 0) {
            a[1] += 4*a[2]; // a[2] < 0 so +
            if(a[1] < 0)
                a[1] = 0;
            a[2] = 0;
        }
        // 装3
        cnt += (a[3] + 3)/4;
        a[3] %= 4;
        if(a[3]) {
            a[2] -= 7-2*a[3];   // a[3] = {1,2,3} , lefta[2] = {5,3,1}
            if(a[2] >= 0) {
                a[1] -= 8-a[3]; //a[3] = {1,2,3}, lefta[1] = {7,6,5}
            } else {
                a[2] = 0;
                a[1] -= 36-9*a[3]-4*a[2];   // area
                if(a[1] < 0)
                    a[1] = 0;
            }
        }
        // 装2
        cnt += (a[2] + 8)/9;
        a[2] %= 9;
        if(a[2]) {
            a[1] -= 36 - 4*a[2];
            if(a[1] < 0) a[1] = 0;
        }
        // 装1
        cnt += (a[1] + 35) / 36;
        
        printf("%d\n", cnt);
    }
}