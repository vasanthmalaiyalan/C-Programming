#include <stdio.h>

int main()
{
    int i = 0, j;
    while(++i <= 100)
    {
        j = 1;
        while(j++ <= 200)
        {
            if(j == 150)
                break;
            else
                printf("%d %d\n", i, j);
        }
    }
}
