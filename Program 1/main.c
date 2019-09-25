#include <stdio.h>
#include <string.h>
#include "classes.h"

//Anthony Nardiello
//CSCI 112 Program 1
//4-11-19


//this program takes in a set of classes, and prompts the user on how they want to veiw the classes, whether it is through simply printing them in order, or by looking up specific days, times, or years when the class should be taken

//this file takes in the data and prompts the user for their selections
int LineToClass(struct Class* newClass, FILE* fptr){
	char *result; 
	char line[81];
	int i=0;
	while (fgets(line, 80, fptr)!=NULL){
		result = strtok(line, " ");
		strcpy(newClass[i].number, result);
		result= strtok(NULL, "$");
		strcpy(newClass[i].title, result);
		result=strtok(NULL, " ");
		strcpy(newClass[i].days_offered, result);
		result=strtok(NULL, " ");
		strcpy(newClass[i].times_offered, result);
		result=strtok(NULL, "\n");	
		sscanf(result, "%d", &newClass[i].class_year);
		i++;
	}
	return(i);
	

}

int main(void){
	FILE* in;//variable for the file name
	FILE* output;
	struct Class classList[45];//initalizes the data structure array that will hold the list of all classes

	in=fopen("/public/csci112sp19/pgm1/classes.txt", "r");//opens the file for reading in
	output=fopen("output.txt","w");//opens the file for writing
	int num_classes=LineToClass(classList, in);//initalizes how many classes exist in the class list
	int user_selection=0;//itializes the user selection variable
	char days[10];//variable to hold the day combinations a user can ask for
	char times[25];//variable to hold the time combinations a user can ask for
	char  newType[5];//variable to hold the year that a user can ask for
	while(user_selection!=5){//asks the user to selection one of 5 options, taking itself down if the user  selects the number 5
		printf("1. Print all Classes by CSCI number order\n");
		printf("2. Print all Classes available on either MWF or TR\n");
		printf("3. Print a Class available at a specific time\n");
		printf("4. Print all Classes by Year (Freshman, Sophomore, etc.)\n");
		printf("5. Press 5 to Quit\n");
		scanf("%d", &user_selection);//collects the user choice
		switch(user_selection){
			case 1://prints out all the classes by CSCI number
				classOrder(classList, num_classes, output);
				break;
			case 2://asks which days the user would like classes printed from
				printf("Do you want to print MWF or TR classes?\n");
				scanf("%s", days);
				classDate(classList, num_classes, days, output);
				break;
			case 3://asks the user which days and times they would like a specific class to be shown from
				printf("Do you want MWF or TR Times?\n");
				scanf("%s", days);
				printf("Please Enter the time you would like to see:\n");
				scanf("%s", times);
				classTime(classList, num_classes, days, times, output);
				break;
			case 4://prints the classes in order of what class group can take them		
				printf("Please select a year (1-4) you would like to find: \n");
				scanf("%s", newType);//querys the user for the year they would like to find
				classType(classList, num_classes, newType, output);
				break;
			case 5://breaks out of the switch if the option 5 was chosen.
				break;
			default://prints out an erro message when the prompt is not correct
				printf("You used the incorrect input, please try again!");
				break;			
		}
	}
	fclose(in);//closes the file
	fclose(output);//closes the file
	return(0);
}

