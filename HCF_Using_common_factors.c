#include <stdio.h>

int main()
{
    int x, y, i1 = 0, i2 = 0, k;
    printf("Enter the first number: ");
    scanf("%d", &x);
    printf("Enter the second number: ");
    scanf("%d", &y);

    int a1[200];
    int a2[200];

    for (k = 2; k <= x; k++)
    {
        if (x % k == 0)
        {
            scanf("%d", &a1[i1]);
            i1++;
        }
    }

    for (k = 2; k <= y; k++)
    {
        if (y % k == 0)
        {
            scanf("%d", &a2[i2]);
            i2++;
        }
    }

    int a3[100];
    int i3 = 0, k1 = 0, k2 = 0;

    while (k1 < i1 && k2 < i2)
    {
        if (a1[k1] == a2[k2])
        {
            a3[i3] = a1[k1];
            i3++;
            k1++;
            k2++;
        }
        else if (a1[k1] < a2[k2])
        {
            k1++;
        }
        else
        {
            k2++;
        }
    }

    printf("%d", a3[i3 - 1]);

    return 0;
}
