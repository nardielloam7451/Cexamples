#include <stdio.h>
#include <math.h>
//Anthony Nardiello
//Lab 2 CSCI 112
//1-30-19
//
//Program Calculates the BMI for an indiviual using their weight and height (in inches)

int BMI_calc(double wt, double ht){
//Calculates the BMI, then Prints it out alongside the classification, weight, and height
	
	//calculates BMI
	double BMI;
	BMI = ((703*wt)/(pow(ht,2.0)));
	//Classifies BMI as underweight if between 0 and 18.5
	if(BMI>1.0 && BMI<18.5){
		printf("Your BMI is %.1lf, or Underweight for your Weight (lbs) %.2lf and Height (in) %.1lf.\n", BMI, wt, ht);
		return(0);
	}//Classifies BMI as normal if between 18.5 and 25.0
	else if(BMI>18.5&& BMI< 25.0){
		printf("Your BMI is %.1lf, or Normal for your Weight (lbs) %.2lf and Height (in) %.1lf.\n", BMI, wt, ht);
		return(0);
	}//Classifies BMI as overweight if between 25.0 and 30.0
	else if(BMI>25.0 && BMI<30.0){
		printf("Your BMI is %.1lf, or Overweight for your Weight (lbs) %.2lf and Height (in) %.1lf.\n", BMI, wt, ht);
		return(0);
	}//Classifies BMI as Obese if above 30.0
	else if(BMI>30.0){
		printf("Your BMI is %.1lf, or Obese for your Weight (lbs) %.2lf and Height %.1lf.\n", BMI, wt, ht);
		return(0);
	}//if invalid, tells the user it is invalid
	else{
		printf("Error. Your Height/Weight values are invalid and do not give a valid answer. Please try again.\n");
		return(0);
	}	
}

int main(void){

	double  weight, height;
	printf("BMI Calculator\n");//Announces the name of the Program

	printf("Enter your Weight=>");//Prompts the User for their Weight
	scanf("%lf", &weight);

	printf("Enter your Height in Inches=>");//Prompts the User for their Height
	scanf("%lf", &height);

	BMI_calc(weight, height);
	return(0);
}
