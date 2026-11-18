 #include <stdio.h>
void sum1() {
	int a, b;
	printf("Enter two numbers: \n");
	scanf("%d %d", &a, &b);
	printf("Sum = %d\n", a + b);
}

void sum2(int a, int b) {
	printf("Sum = %d\n", a + b);
}

int sum3() {
	int a, b;
	printf("Enter two numbers: \n");
	scanf("%d %d", &a, &b);
	return a + b;
}

int sum4(int a, int b) {
	return a + b;
}
int main() {
	int choice, num1, num2, result;

	do {
    	printf("1. Function without argument & without return type\n");
    	printf("2. Function with argument & without return type\n");
    	printf("3. Function without argument & with return type\n");
    	printf("4. Function with argument & with return type\n");
    	printf("5. Exit\n");
    	printf("Enter your choice 1 to 5: ");
    	scanf("%d", &choice);

    	switch (choice) {
        	case 1:
            	sum1();
            	break;
        	case 2:
            	printf("Enter two numbers: \n");
            	scanf("%d %d", &num1, &num2);
            	sum2(num1, num2);
            	break;
        	case 3:
            	result = sum3();
            	printf("Sum = %d\n", result);
            	break;
        	case 4:
            	printf("Enter two numbers: \n");
            	scanf("%d %d", &num1, &num2);
            	result = sum4(num1, num2);
            	printf("Sum = %d\n", result);
            	break;
        	case 5:
            	printf("Exiting program...\n");
            	break;
        	default:
            	printf("Invalid choice! Please select 1 to 5.\n");
    	}
	} while (choice != 5);

	return 0;
}



