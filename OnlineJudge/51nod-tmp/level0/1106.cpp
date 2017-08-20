#include <stdio.h>


#define _MAX 5000
int a[_MAX + 1] = {1,1};
int p[_MAX + 1];
int main()
{
    int num = 0;
    for(int i = 2; i <= _MAX; i++)
    {
        if(!a[i])
            p[num++] = i;
        for(int j = 0; j < num && i * p[j] <= _MAX; j++)
        {
            a[i * p[j]] = 1;
            if(!(i % p[j]))
                break;
        }
    }
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n <= _MAX)
        {
            if(!a[n])
                puts("Yes");
            else
                puts("No");
        }
        else
        {
            int ok = 1;
            for(int i = 0; i < num; i++)
                if(n % p[i] == 0)
                    ok = 0;
            if(ok)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
