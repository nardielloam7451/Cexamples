#include <stdio.h>
#include <string.h>
#include "classes.h"

void classTime(struct Class classList[],int numClasses, char* class_day, char* class_time, FILE* fptr){
	//takes a specific day and time and prints the class associated for it
	int i;
	fprintf(fptr, "Classes offered at a specific time:\n");
	for(i=0;i<=numClasses;i++){
	//looks for the specific time and date value, and printing that value.
		if(strcmp(classList[i].days_offered, class_day)==0 && strcmp(classList[i].times_offered, class_time)==0){
			//looks through the array for the specific date and time combination
			if(classList[i].class_year==1){//if the classList is a freshman class, prints freshman 
				fprintf(fptr,"%s	%-46s%-5s	%-5s%s\n",classList[i].number, classList[i].title, "Freshman", classList[i].days_offered, classList[i].times_offered);
			}
			else if(classList[i].class_year==2){//if the class is a sophomore class, prints sophomore
				fprintf(fptr,"%s	%-46s%-5s	%-5s%s\n",classList[i].number, classList[i].title, "Sophomore", classList[i].days_offered, classList[i].times_offered);
			}
			else if(classList[i].class_year==3){//if the class is a junior class, prints junior
				fprintf(fptr,"%s	%-46s%-5s	%-5s%s\n",classList[i].number, classList[i].title, "Junior", classList[i].days_offered, classList[i].times_offered);
			
			}
			else if(classList[i].class_year==4){//if the class is a senior class, prints senior
				fprintf(fptr,"%s	%-46s%-5s	%-5s%s\n",classList[i].number, classList[i].title, "Senior",classList[i].days_offered, classList[i].times_offered);
			}
		}
	}
	fprintf(fptr, "\n");
	return;
		
} 
