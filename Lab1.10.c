#include <stdio.h>

int main()
{
    int clearanceLevel, age, isActive;

    if (scanf("%d %d %d", &clearanceLevel, &age, &isActive) != 3)
        return 1;

    int ok = 0;

    if (clearanceLevel == 3 && isActive == 1)
        ok = 1;
    else if (clearanceLevel == 2)
    {
        if (age >= 25 && isActive == 1)
            ok = 1;
    }

    if (ok)
        printf("Access Granted");
    else
        printf("Access Denied");

    return 0;
}
