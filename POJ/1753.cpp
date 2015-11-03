#include <cstdio>
#include <cstring>

int chessboard[4][4];

void change(int i)
{
    int y = i % 4, x = i >> 2;
    chessboard[x][y] = chessboard[x][y] == 0 ? 1 : 0;
    if(x > 0) chessboard[x - 1][y] = chessboard[x - 1][y] == 0 ? 1 : 0;
    if(x < 3) chessboard[x + 1][y] = chessboard[x + 1][y] == 0 ? 1 : 0;
    if(y > 0) chessboard[x][y - 1] = chessboard[x][y - 1] == 0 ? 1 : 0;
    if(y < 3) chessboard[x][y + 1] = chessboard[x][y + 1] == 0 ? 1 : 0;
}

bool check()
{
    bool ok = 1;
    int jud = chessboard[0][0];
    int i, j;
    for(i = 0 ; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
            if(chessboard[i][j] != jud)
            {
                ok = 0;
                break;
            }
        if(!ok)
            break;
    }
    return ok;
}

void dfs(int i, int count, int deep, bool& flag)
{
    if(deep == count)
    {
        flag = check();
        return;
    }
    if(i > 15 || flag)  return;
    change(i);
    dfs(i + 1, count + 1, deep, flag);
    if(!flag)
    {
        // change this is wrong, so change back
        change(i);
        dfs(i + 1, count, deep, flag);
    }
}

int main()
{
    char line[5];
    while(~scanf(" %s", line))
    {
        memset(chessboard, 0, sizeof(chessboard));
        int i, j;
        for(i = 0; i < 4; i ++)
        {
            for(j = 0; j < 4; j++)
                chessboard[i][j] = line[j] == 'b' ? 1 : 0;
            if(i < 3)
            scanf(" %s", line);
        }
        bool flag = 0;
        int deep;
        for(deep = 0; deep < 17; deep++)
        {
            dfs(0, 0, deep, flag);
            if(flag)
                break;
        }
        if(flag)
            printf("%d\n", deep);
        else
            printf("Impossible\n");
    }
    return 0;
}
