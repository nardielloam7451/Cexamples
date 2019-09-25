#include <stdio.h>
#include <string.h>
#include "classes.h"

//This funciton sorts through the entire class list and swaps the classes in the order specified by the function call.  

void sort(struct Class classList[], int numClasses, char* sort_parameter){
//looks at the specific sort parameter added in and sorts the class based on that parameter
	int i, j, doswap=0;
	struct Class temp;
	
	for(i=0;i<numClasses;++i){
		for(j=i;j<numClasses;j++){
			if(strcmp(sort_parameter, "Number\0")==0){//sorts based upon the number
				doswap=strcmp(classList[i].number,classList[j].number);
				if(doswap>0){
					temp=classList[i];
					classList[i]=classList[j];
					classList[j]=temp;	
				}
			}
			else if(strcmp(sort_parameter, "MWF\0")==0){//sorts the data based upon day
				doswap=strcmp(classList[i].days_offered, classList[j].days_offered);
				if(doswap>0){
					temp=classList[i];
					classList[i]=classList[j];
					classList[j]=temp;
				}
				else if(doswap==0){
					//sorts based upon time if it's the same day
					doswap=strcmp(classList[i].times_offered, classList[j].times_offered);
					if(doswap>0){
						temp=classList[i];
						classList[i]=classList[j];
						classList[j]=temp;
					}
				}
			}
			else if(strcmp(sort_parameter, "TR\0")==0){//sorts the data based upon if the user said Tuesday or Thursday
				doswap=strcmp(classList[i].days_offered, classList[j].days_offered);
				if(doswap<0){
					temp=classList[i];
					classList[i]=classList[j];
					classList[j]=temp;
				}
				else if(doswap==0){
					//sorts based upon times if classes are on the same day
					doswap=strcmp(classList[i].times_offered, classList[j].times_offered);
					if(doswap>0){
						temp=classList[i];
						classList[i]=classList[j];
						classList[j]=temp;
					}
				}
			}
			else if(strcmp(sort_parameter, "1\0")==0){//sorts the data based upon freshman class
				if(classList[i].class_year>classList[j].class_year){
					temp=classList[i];
					classList[i]=classList[j];
					classList[j]=temp;
				}
			}
			else if(strcmp(sort_parameter, "2\0")==0){//sorts the data based upon sophomore class
				if(classList[j].class_year==2){
					if(classList[i].class_year<classList[j].class_year||classList[i].class_year>classList[j].class_year){
						temp=classList[i];
						classList[i]=classList[j];
						classList[j]=temp;
					}
				}
			}
			else if(strcmp(sort_parameter, "3\0")==0){//sorts based upon junior classes
				if(classList[j].class_year==3){
					if(classList[i].class_year<classList[j].class_year||classList[i].class_year>classList[j].class_year){
						temp=classList[i];
						classList[i]=classList[j];
						classList[j]=temp;
					}
				}
			}
			else if(strcmp(sort_parameter, "4\0")==0){//sorts based upon the senior classes
				if(classList[i].class_year<classList[j].class_year){
					temp=classList[i];
					classList[i]=classList[j];
					classList[j]=temp;
				}
			}
		}
	}
}

