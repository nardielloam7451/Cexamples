#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Anthony Nardiello
//Lab 6
//3-10-19

//The Program takes in a string and then prints out its one element, two element, and three element substring

void one_ele_subs(char *string){
	//prints out the single subset of the string
	if(*string){
		printf("{%c}\n", *string);//prints out the one element substring
		one_ele_subs(++string);//recursively moves to the next element
	}
}

void two_ele_subs(char *string){
	//prints the two element substring of the string
	int i=0;
	//catches the first element of the string
	int len= strlen(string);//calculates a changing version of the length, compared to the one we used initially
	if(len>=2){ //establishes the base case of the string when we are down to only two elements in the string
		int j;
		for(j=i+1; j<len;j++)
		{
			printf("{%c,%c}\n",string[i], string[j]);//prints out the substring
		}
	}
	else return;
	two_ele_subs(++string);//recursive call to go through the string
}

void three_ele_subs(char *string){
	//prints the three element subset of the string
	int i=0;

	int len=strlen(string);//calculates a changing version of the length
	if(len>=3){
		int g;
		int j;
		for(j=i+1; j<len-1;j++){//catches the element at 1
			for(g=j+1;g<len;g++)//catches the element at 2
			{
			printf("{%c,%c,%c}\n",string[i], string[j], string[g]);//prints out the three element subset of the string
			}
		}
	}
	else return;
	three_ele_subs(++string);
}



int main(int argc, char *argv[]){
	int length;
	//initialises the original string variable and the length variable
	if(argc==1){
		printf("You must run this program with an argument\n");//if there is only one argument then it simply errors out
		return(0);
	}
	else{
		length=strlen(argv[1]);//calculates the length of the string
	}
	if(length==4){ //checks to see if the string is the right amount of characters
		one_ele_subs(argv[1]); //finds and prints the one element subset of the string
		two_ele_subs(argv[1]); //finds and prints the two element subset of the string
		three_ele_subs(argv[1]); //finds and prints the three element subset of the string
	}else{ //prints error message if the string is too long or too short
		printf("The string you entered is not valid. Please try again.\n");
	}
	return(0);
}
