#include <stdio.h>

//Lab 1
//Anthony Nardiello
//1-18-19

int main(void){
//program for mileage reimbursement

	double beginning, end , traveled, amount;
	printf("MILEAGE REIMBURSEMENT CALCULATOR\n");//name of the program
	printf("Enter beginning odometer reading=>");//prompts user for reading
	scanf("%lf", &beginning);
	printf("Enter ending odometer reading=>");//prompts user for reading
	scanf("%lf", &end);
	traveled = end-beginning;//calculates the miles traveled in the trip
	amount = traveled*.35;//calculates reimbursement amount
	printf("You traveled %.1lf. At $0.35  per mile, your reimbursement is $%.2lf.\n",traveled, amount);
	return(0);
}
