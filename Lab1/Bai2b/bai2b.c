#include <stdio.h>

int f1(int x) {
    if (x > 10)
        return 2 * x;
    else if (x > 0)
        return -x;
    else
        return 2 * x;
}
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d\n",f1(a));
    return 0;
}