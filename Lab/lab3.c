#include <stdio.h>
#include <math.h>
//Anthony Nardiello
//Lab 3
//2-06-19

//Program calculates the monthly payments of a loan depending on the number of months the user wants to pay off the loan in.

void loan_Management(double interest,double  principal, int  payments){
	//initalizes the monthly interest, the amount paid to the principle, and the amount paid to the interest
	double intMonth, amount, intAmount, monthPay;
	//Translates the interest from percent into decimal form
	interest = (interest/100);
	//calculates the monthly interest amount based upon the initial interest amount
	intMonth = (interest/12);
	
	int i;
	amount = ((intMonth*principal)/(1-pow((1+intMonth),-payments))); //calculates the monthly payment
	printf("Principal		$%.2lf	Payment		$%.2lf\n",principal, amount);
	printf("Annual Interest		%.1lf%c		Term		%d months\n", interest*100,37,payments);
	printf("Payment    Interest    Principal   Principal Balance\n");
	for(i=1;i<=payments;i++){
		intAmount = (intMonth*principal);//calculates the monthly principal
		monthPay=amount-intAmount;//calculates the monthly payment after the interest is taken out.
		principal-=monthPay;//takes off the monthly payment from the principal
		if(principal<=0){//if the principle is less then zero, add the negative to last payment.
			monthPay+=principal;
			principal=0;
		}
		printf("%d          %.2lf        %.2lf      %.2lf\n",i, intAmount, monthPay, principal);
	}
	monthPay+=intAmount;//readds the interest back into the last payment.
	printf("Final Payment   %.2lf\n",monthPay);
}


int main(void){
	//initializes the interest, principle amount, and number of payments
	double interest, principle;
	int payments;
	
	//Asks the user for the interest rate, principle amount, and number of payments
	printf("Enter the Annual Interest rate: ");
	scanf("%lf", &interest);

	printf("Enter the Principal Loan Amount: ");
	scanf("%lf", &principle);

	printf("Enter the Number of Payments: ");
	scanf("%d", &payments);

	//places these values into another function
	loan_Management(interest, principle, payments);
	
	return(0);
}
