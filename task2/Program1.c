/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: c787t481
 */

#define MONTHS 12
const char *months[] = {"January", "Feb", "March", "April", "May", "June", "July", "August", "Sept", "October", "Nov", "Dec"};

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void salesReport(float sales[MONTHS]) {

	printf("Monthly sales report for 2022:\n");
	printf("Month\tSales\n");
	for (int i = 0; i < MONTHS; i++){
		printf("%s\t%.2f\n", months[i], sales[i]);
	}
}

void minMaxAvg(float sales[MONTHS]) {

	//defining our variables
	float min = sales[0], max = sales[0], avg=0;
	int minLocation = 0, maxLocation = 0;

	//finding the minimum, max, and average value of the array
	for (int i = 0; i < MONTHS; i++) {

		if (sales[i] < min) {
			min = sales[i];
			minLocation = i;
		}
		if (sales[i] > max) {
			max = sales[i];
			maxLocation = i;
		}
		avg += sales[i];
	}
	avg /= MONTHS;

	printf("\nSales summary:\n");
	printf("Minimum Sales:\t %.2f\t(%s)\n",min,months[minLocation]);
	printf("Maximum Sales:\t %.2f\t(%s)\n",max,months[maxLocation]);
}

void movingAvg(float sales[MONTHS]) {

	printf("\nSix-Month Moving Average Report:\n");

	for (int i = 0; i < 7; i++) {
		float avg = 0;

		for (int j = i; j < i+6; j++) {
			avg += sales[j];
		}
		avg /= MONTHS/2;

		printf("%s\t-\t%s\t$%.2f\n",months[i],months[i+5],avg);
	}
}

void highLow(float sales[MONTHS]) {

	float temp;
	int temp1;
	int newMonth[12] = {0,1,2,3,4,5,6,7,8,9,10,11,12};


	for (int i = 0; i < MONTHS; ++i) {
		for (int j = i + 1; j < MONTHS; ++j) {
			if (sales[i] < sales[j]) {

				temp = sales[i];
				sales[i] = sales[j];
				sales[j] = temp;

				temp1 = newMonth[i];
				newMonth[i] = newMonth[j];
				newMonth[j] = temp1;
			}
		}
	}

	printf("\nSales Report (Highest to Lowest):\n");
	printf("Month\tSales\n");
	for (int i = 0; i < MONTHS; i++) {
		printf("%s\t%.2f\n", months[newMonth[i]], sales[i]);
	}
}

int main() {

	//initializing our variables
	float sales[MONTHS];
	int i;

	//reading the file
	FILE *infile;
	infile = fopen("input.txt","r");

	//appending values to our list
	for (i=0; i<MONTHS; i++) {
		fscanf(infile, "%f", &sales[i]);
	}

	//running functions
	salesReport(sales);
	minMaxAvg(sales);
	movingAvg(sales);
	highLow(sales);

	return 0;
}
