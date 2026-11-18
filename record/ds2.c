#include <stdio.h>

int insert(int a[], int n);
int delete(int a[], int n);
void traverse(int a[], int n);

int main(void)
{
    int a[100], n, i, ch;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    while(1)
    {
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Traverse\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                n = insert(a, n);
                break;
            case 2:
                n = delete(a, n);
                break;
            case 3:
                traverse(a, n);
                break;

            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Please enter right choice\n");
        }

        if (ch == 0)
        {
            break;
        }
    }
    return 0;
}
int insert(int a[], int n)
{
    int loc, element, i;
    printf("Enter the location: ");
    scanf("%d", &loc);
    printf("Enter the element: ");
    scanf("%d", &element);
    for (i = n; i >= loc; i--)
    {
        a[i] = a[i - 1];
    }
    a[loc - 1] = element;
    n = n + 1;

    return n;
}
int delete(int a[], int n)
{
    int loc, i;
    printf("Enter the location to delete: ");
    scanf("%d", &loc);
    for (i = loc - 1; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n = n - 1;
    return n;
}
void traverse(int a[], int n)
{
    int i;
    printf("Array elements are:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

