#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classes.h"

void classType(struct Class classList[], int numClasses, char* chosenYear, FILE* fptr){
	//takes the classList, counts how many of those classes exist, and then pass that in as the chosen array
	int chosenType;
	int i, year=0;
	chosenType=atoi(chosenYear);//converts the string value into an int
	fprintf(fptr, "Classes offered to a specific year:\n");
	for(i=0;i<=numClasses;i++){
		//takes the array and looks to see which class are taken in the specific work we are looking for. 
		if(classList[i].class_year==chosenType){
			year++;
		}
	}
	sort(classList,numClasses,chosenYear);//sorts the array based upon the parameter value
	printClasses(classList, year,fptr);//prints the specific number of values we are looking for
	fprintf(fptr, "\n");
}
