#include <cstdio>
#include <cstring>

char dic[10001][16];
int n;
char str[20];

bool isCorrect()
{
    int i;
    bool ok = 0;
    for(i = 0; i < n; i++)
    {
        if(!strcmp(str, dic[i]))
        {
            ok = 1;
            break;
        }
    }
    return ok;
}

void action()
{
    int i, j, leni, count;
    int len = strlen(str);
    printf("%s:", str);
    for(i = 0; i < n; i ++)
    {
        count = 0;
        leni = strlen(dic[i]);
        if(leni == len)
        {
            for(j = 0; j < len; j++)
                if(str[j] != dic[i][j])
                {
                    if(++count > 1)
                        break;
                }
            if(count == 1)
                printf(" %s", dic[i]);
        }
        else if(leni == len + 1)
        {
            for(j = 0; j < leni; j++, count++)
                if(str[count] != dic[i][j])
                {
                    count--;
                    if(j - count > 1)
                        break;
                }
            if(j - count == 1)
                printf(" %s", dic[i]);
        }
        else if(leni == len - 1)
        {
            for(j = 0; j < len; j++, count++)
                if(str[j] != dic[i][count])
                {
                    count --;
                    if(j - count > 1)
                        break;
                }
            if(j - count == 1)
                printf(" %s", dic[i]);
        }
    }
    printf("\n");
}

int main()
{
    n = 0;
    while(~scanf(" %s", dic[n]))
    {
        if(dic[n][0] == '#')
            break;
        n++;
    }
    while(~scanf(" %s", str))
    {
        if(str[0] == '#')
            break;
        if(isCorrect())
            printf("%s is correct\n", str);
        else
            action();
    }
    return 0;
}