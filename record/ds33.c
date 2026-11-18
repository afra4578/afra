#include <stdio.h>

void Sorts(int nums[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, nums[100], i;

    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    Sorts(nums, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return 0;
}

