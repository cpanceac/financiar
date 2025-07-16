// for now we assume governement tax is 10% but the program should be fixed to read govt tax from user

#include "stdio.h"

int main()
{
	int val, t, i, j, bar_len; //Default tax value
	float f, final, interest, gain, max_gain, tax = 10;

	printf("For now we assume governement tax is 10%\n");

	printf("Enter initial value: ");
	scanf("%d", &val);
	
	printf("Enter timeframe: ");
	scanf("%d", &t);

	printf("Enter interest: ");
	scanf("%f", &f);

	// Initial value
	final = val;

	// We compute the max gain (and final value)
	for(i=0; i<t; i++){
		interest = final * f / 100;
		final = final + interest - interest * tax / 100;
	}
	
	max_gain = final - val;
	
	// Reset to do the printing
	final = val;
	
	for(i=0; i<t; i++){
		interest = final * f / 100;
		final = final + (interest - interest * tax / 100);
		gain = final - val;
		
		bar_len = (int)(100 * gain / max_gain);

		// Nice graph
		printf("%2d | ", i + 1);
    
        for (int j = 0; j < bar_len; j++) printf("*");
	        printf(" +%.2f\n", gain);				
	}

	printf("Summary\n");
	printf("-------\n\n");
	
	printf("Interest rate: %.2f%\n", f);
	printf("Tax: %.2f%\n", tax);
	printf("Years: %d\n\n", t);

	printf("Initial deposit: %d\n", val);	
	printf("After %d years, final deposit is: %.2f\n", t, val + max_gain);
}
