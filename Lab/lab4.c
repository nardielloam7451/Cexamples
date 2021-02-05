#include <stdio.h>
//Anthony Nardiello
//2-21-19
//Lab 4

//A lab which calculates takes in a value of x and y points and calculates the area of a polygon. 

int get_corners(double x[], double y[]){
	//reads from a file the coordinates of the points of the polygon.
	int i=0, no_items;
	//initializes the no_items and the array values
	do{
		no_items = scanf("%lf%lf", &x[i],&y[i]);//inserts the elements into the array line by line

		i++;//counts the number of items that are being added to the array
	}while(no_items >0);

	i--;//to get the right count of items read
	return(i);
}

double polygon_area(double x[], double y[], int num_items){
	//takes the x and y coordinates and uses them to calculate the are of the polygon
	int i;
	double area;
	for(i=0;i<(num_items-2);i++)
	{//this factors in the fact that the last point should be the same as the first point
		area+=((x[i+1]+x[i])*(y[i+1]-y[i]));//takes the product of two coordinates, and adds them to the current total
	}
	area=(-area/2);//divides the current area total by 2
	return(area);
}

void output_corners(double x[], double y[], double area, int num_item)
{//outputs the coordinates, the area, and the number of items into a nice table
	int i;

	printf("x	y\n");//prints the top of the column
	printf("_______________\n");
	for(i=0;i<(num_item);i++)//prints the x and y coordinates of the polygon
	{
		printf("%.1lf	%.1lf\n",x[i],y[i]);
	}
	printf("_______________\n");
	printf("The area of the polygon is %.1lf square units\n", area);//prints the area of the polygon after printing the table
	
}

int main(void){
	double poly_area,  x_val[20],  y_val[20];//initializes the area, and x and y arrays
	int item_count;//initializes the number of items in the array counter
	
	item_count=get_corners(x_val, y_val);
	//sets the values in the arrays, and initalizes the number of elements in each array
	
	poly_area=polygon_area(x_val, y_val, item_count);
	//calculates the area for the polygon, then returns that area value
	
	output_corners(x_val, y_val, poly_area, item_count);
	//prints out the coordinates and the area

	return(0);
}
