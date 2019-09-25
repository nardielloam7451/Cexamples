#include <stdio.h>
#include "classes.h"

void printClasses(struct Class classList[], int numClasses, FILE* fptr){
	
	
	int i;
	for(i=0;i<numClasses;i++){
		if(classList[i].class_year==1){//if the class is a freshman class, prints freshman
			fprintf(fptr,"%s	%-46s%-5s	%-5s%s\n", classList[i].number, classList[i].title, "Freshman", classList[i].days_offered, classList[i].times_offered);
		}
		else if(classList[i].class_year==2){//if the class is a sophomore class, prints sophomore
			fprintf(fptr,"%s	%-46s%-5s	%-5s%s\n", classList[i].number, classList[i].title, "Sophomore", classList[i].days_offered, classList[i].times_offered);
		}
		else if(classList[i].class_year==3){//if the class is a junior class, prints junior
			fprintf(fptr,"%s	%-46s%-5s	%-5s%s\n", classList[i].number, classList[i].title, "Junior", classList[i].days_offered, classList[i].times_offered);
		}
		else if(classList[i].class_year==4){//if the class is a senior class, prints senior 
			fprintf(fptr,"%s	%-46s%-5s	%-5s%s\n", classList[i].number, classList[i].title, "Senior", classList[i].days_offered, classList[i].times_offered);
		}
	}
}
