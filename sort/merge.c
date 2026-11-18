#include <stdio.h>

int main() {
    int A[100], B[100], C[200];
    int n1, n2, i = 0, j = 0, k = 0;

    printf("Enter number of elements in first array: ");
    scanf("%d", &n1);
    printf("Enter %d sorted elements of first array: ", n1);
    for (int idx = 0; idx < n1; idx++) {
        scanf("%d", &A[idx]);
    }

    printf("Enter number of elements in second array: ");
    scanf("%d", &n2);
    printf("Enter %d sorted elements of second array: ", n2);
    for (int idx = 0; idx < n2; idx++) {
        scanf("%d", &B[idx]);
    }

    while (i < n1 && j < n2) {
        if (A[i] < B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }

    while (i < n1) {
        C[k++] = A[i++];
    }

    while (j < n2) {
        C[k++] = B[j++];
    }

    printf("\nMerged Sorted Array C: ");
    for (int idx = 0; idx < n1 + n2; idx++) {
        printf("%d ", C[idx]);
    }
    printf("\n");

    return 0;
}
