#include <stdio.h>

int f2(int x) {
    if (x < 10)
        return 2 * x;
    else if (x < 2)
        return -x;
    else
        return 2 * x;
}
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d\n",f2(a));
    return 0;
}