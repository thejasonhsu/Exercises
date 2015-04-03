#include <stdio.h>

void main() {
	int number, number_squared, number_cubed;

	printf("Number\tSquare\tCube\n");
	printf("------\t------\t----\n");

	number = 0;
	number_squared = number * number;
	number_cubed = number * number * number;

	printf("%d\t%d\t%d\n", number, number_squared, number_cubed);

	number = 1;
	number_squared = number * number;
	number_cubed = number * number * number;

	printf("%d\t%d\t%d\n", number, number_squared, number_cubed);

	number = 2;
	number_squared = number * number;
	number_cubed = number * number * number;

	printf("%d\t%d\t%d\n", number, number_squared, number_cubed);

	number = 3;
	number_squared = number * number;
	number_cubed = number * number * number;

	printf("%d\t%d\t%d\n", number, number_squared, number_cubed);

	number = 4;
	number_squared = number * number;
	number_cubed = number * number * number;

	printf("%d\t%d\t%d\n", number, number_squared, number_cubed);

	number = 5;
	number_squared = number * number;
	number_cubed = number * number * number;

	printf("%d\t%d\t%d\n", number, number_squared, number_cubed);

	printf("Enter a number: ");
	scanf("%d", &number);

	number_squared = number * number;
	number_cubed = number * number * number;

	printf("%d\t%d\t%d\n", number, number_squared, number_cubed);


}
