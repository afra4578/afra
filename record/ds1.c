
#include <stdio.h>

int sum1(int a, int b)
{
    return a + b;
}

void sum2(int a, int b)
{
    printf("Sum = %d\n", a + b);
}

int sum3()
{
    int a, b;

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    return a + b;
}

void sum4()
{
    int a, b;

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    printf("Sum = %d\n", a + b);
}


int main()
{
    int ch, a = 0, b = 0;

    while (1)
    {
        printf("\n--- OPERATIONS ---\n");
        printf("1. Sum with arguments and return type\n");
        printf("2. Sum with arguments and no return type\n");
        printf("3. Sum without arguments and return type\n");
        printf("4. Sum without arguments and no return type\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter a and b: ");
                scanf("%d %d", &a, &b);
                printf("Sum = %d\n", sum1(a, b));
                break;

            case 2:
                printf("Enter a and b: ");
                scanf("%d %d", &a, &b);
                sum2(a, b);
                break;

            case 3:
                printf("Sum = %d\n", sum3());
                break;

            case 4:
                sum4();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Please enter right choice\n");
        }

        if (ch == 5)
        {
            break;
        }
    }

    return 0;
}


