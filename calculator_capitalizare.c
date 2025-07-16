#include "stdio.h"

int main()
{
	int val, t, i, tax = 10; //Default tax value
	float f, final, interest;

	printf("Enter initial value: ");
	scanf("%d", &val);
	
	final = val;

	printf("Enter timeframe: ");
	scanf("%d", &t);

	printf("Enter interest: ");
	scanf("%f", &f);
	
	for(i=0; i<t; i++){
		interest = final * f / 100;
		final = final + interest - interest * tax / 100;
		
		printf("Year: %d\tCurrent value is: %.2f\n", i+1, final);
	}
		
	printf("\nFinal value after %d years is: %.2f\n", t, final);
	printf("Note: tax on interest is %d %.", tax);
}
