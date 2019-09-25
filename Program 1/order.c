#include <stdio.h>
#include "classes.h"


void classOrder(struct Class classList[], int numClasses, FILE* fptr){
	//takes the class list, sorts it by CSCI Number, and then prints the list
	char para[10]= "Number";
	sort(classList,numClasses, para);
	fprintf(fptr, "Classes by Number:\n");
	printClasses(classList, numClasses, fptr);
	fprintf(fptr,"\n");
}
