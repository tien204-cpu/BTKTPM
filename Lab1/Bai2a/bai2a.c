#include <stdio.h>

int f1(int x) {
        if (x > 10)
            return 2 * x;
        else
            return -x;
}
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d\n",f1(a));
    return 0;
}