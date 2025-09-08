#include <stdio.h>
#include <math.h>

int f3(int x) {
    if (log(x * x * cos(x)) < 3 * x)
        return 2 * x;
    else
        return 2 * x;
}
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d\n",f3(a));
    return 0;
}