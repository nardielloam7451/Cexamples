#include <stdio.h>
struct Class{
	char number[20];
	char title[50];
	char days_offered[10];
	char times_offered[20];
	int class_year;
};

void classOrder(struct Class classList[], int numClasses, FILE* fptr);

void classDate(struct Class classList[],int numClasses, char* class_day, FILE* fptr);

void classTime(struct Class classList[], int numClasses, char* class_day, char* class_time, FILE* fptr);

void classType(struct Class classList[], int numClasses, char* type, FILE* fptr);

void sort(struct Class classList[], int numClasses, char* sort_parameter);

void printClasses(struct Class classList[], int numClasses, FILE* fptr);

int LineToClass(struct Class* newClass, FILE* fptr);

