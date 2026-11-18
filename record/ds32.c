#include <stdio.h>

void linearSearch(int nums[], int n, int key) {
	int i;
	for (i = 0; i < n; i++) {
    	if (nums[i] == key) {
        	printf("Found at %d\n", i);
        	return;
    	}
	}
	printf("Not found\n");
}

void sort(int nums[], int n) {
	for (int i = 0; i < n - 1; i++) {
    	for (int j = 0; j < n - i - 1; j++) {
        	if (nums[j] > nums[j + 1]) {
            	int temp = nums[j];
            	nums[j] = nums[j + 1];
            	nums[j + 1] = temp;
        	}
    	}
	}
}

void binarySearch(int nums[], int n, int key) {
	int first = 0;
	int last = n - 1;
	sort(nums, n);
    
	while (first <= last) {
    	int mid = first + (last - first) / 2;

    	if (nums[mid] == key) {
        	printf("Found at %d\n", mid);
        	return;
    	} else if (nums[mid] < key) {
        	first = mid + 1;
    	} else {
        	last = mid - 1;
    	}
	}
    
	printf("Not found\n");
}


int main() {
	int nums[100], n, i, ch, key;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	i = 0;
	printf("Enter elements:\n");
	while (i < n) {
    	scanf("%d", &nums[i]);
    	i = i + 1;
	}

	while (1) {
    	printf("1. Linear Search\n");
    	printf("2. Binary Search\n");
    	printf("3. Exit\n");
    	printf("Enter choice: ");
    	scanf("%d", &ch);

    	if (ch == 3) {
        	printf("Exiting...\n");
        	break;
    	}

    	printf("Enter key to search: ");
    	scanf("%d", &key);

    	switch (ch) {
        	case 1:
            	linearSearch(nums, n, key);
            	break;
        	case 2:
            	binarySearch(nums, n, key);
            	break;
        	default:
            	printf("Enter a right choice\n");
            	break;
    	}
	}

	return 0;
}

