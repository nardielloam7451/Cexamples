#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Anthony Nardiello
//CSCI 112 Lab 5
//3-4-19


//The program takes in an integer, and prints out its factorial

void fact_calc(int fact_num, int factor, char *newString){
	//takes the integer, and takes the factorial of it and places it in the string
	int i;
	char *tempstr = (char*)malloc(sizeof(char)*25);
	if(fact_num==0) //checks to see if the factorial is 0 and if it is hard codes that value
	{
		strcpy(newString,"1");
	}
	else{
		for(i=fact_num;i>1;i--)
		{
			sprintf(tempstr, " %d X", i);//places the next number in the factorial in the string
			strcat(newString, tempstr);
			factor*=i;//calculates the factorial 
		}
		sprintf(tempstr, " 1 = %d", factor);
		strcat(newString, tempstr);
	}
}

void print_string(int fact_num, char *newString){
	//prints the string with special formatting
	printf("***************************************************\n");
	printf("%d! = ",fact_num);
	printf("%s\n", newString);
	printf("***************************************************\n");
}

int main(void){
	
	int num, factorial=1; //initializes the values for the factorial and the number  
	
	do{
		printf("Enter an integer between 0 and 9 or -1 to quit\n");
		scanf("%d", &num);//prompts the user for the number
		char *fact_string =(char*)malloc(sizeof(char)*25);
		if(num > 9)
		{
			printf("Invalid Entry\n");	//if the number is greater than 9, it tells the user for the invalid entry
		}
		else if(num < 0)
		{//if the number is a negative 1 or less, removes the user from the program
			return(0);
		}
		else
		{//otherwise calculates the factorial of the user given number
			fact_calc(num, factorial, fact_string);
			print_string(num, fact_string);
		}
	}
	while(num >= 0);
	return(0);
}
