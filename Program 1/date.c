#include <stdio.h>
#include <string.h>
#include "classes.h"

//this file takes in the classList, sorts based upon the times offered on a specific date, and then prints out all classes on that day


void classDate(struct Class classList[], int numClasses, char* class_day, FILE* fptr){
	int i, dayClasses=0;//variables that will be used in the print statement
	for(i=0; i<numClasses;++i){
	//takes the amount of classes, and only counts those that are the dates we want
		if(strcmp(classList[i].days_offered, class_day)==0){
			dayClasses++;
		}
	}
	sort(classList,numClasses, class_day);//sorts the data by the date of the class;
	fprintf(fptr, "Classes by Day:\n");	
	printClasses(classList, dayClasses, fptr);
	fprintf(fptr, "\n");

}
