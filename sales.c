#include <stdio.h>
#include <stdlib.h>  // Add this line to include the necessary header file for 'exit'

#define MONTHS 12

void readSalesFromFile(double sales[], const char *filename);
void generateSalesReport(double sales[]);
void generateSalesSummary(double sales[]);
void generateMovingAverage(double sales[]);
void generateSortedSalesReport(double sales[]);

const char *monthName[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main() {
    double sales[MONTHS];

    // Ask the user for the input file
    char filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    // Read sales data from the input file
    readSalesFromFile(sales, filename);

    // Generate and display the reports
    generateSalesReport(sales);
    generateSalesSummary(sales);
    generateMovingAverage(sales);
    generateSortedSalesReport(sales);

    return 0;
}

void readSalesFromFile(double sales[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);  // Add the proper exit function call
    }

    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%lf", &sales[i]);
    }

    fclose(file);
}

void generateSalesReport(double sales[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2lf\n", monthName[i], sales[i]);
    }
    printf("\n");
}

void generateSalesSummary(double sales[]) {
    double minSales = sales[0];
    double maxSales = sales[0];
    double totalSales = 0;

    for (int i = 0; i < MONTHS; i++) {
        totalSales += sales[i];

        if (sales[i] < minSales) {
            minSales = sales[i];
        }
        if (sales[i] > maxSales) {
            maxSales = sales[i];
        }
    }

    double averageSales = totalSales / MONTHS;

    printf("Sales summary:\n");
    printf("Minimum sales: $%.2lf (%s)\n", minSales, monthName[0]);
    printf("Maximum sales: $%.2lf (%s)\n", maxSales, monthName[MONTHS - 1]);
    printf("Average sales: $%.2lf\n\n", averageSales);
}

void generateMovingAverage(double sales[]) {
    printf("Six-Month Moving Average Report:\n");

    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        double average = sum / 6;

        printf("%s - %s $%.2lf\n", monthName[i], monthName[i + 5], average);
    }

    printf("\n");
}

void generateSortedSalesReport(double sales[]) {
    // Sort the sales array in descending order
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - i - 1; j++) {
            if (sales[j] < sales[j + 1]) {
                // Swap the elements
                double temp = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = temp;
            }
        }
    }

    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2lf\n", monthName[i], sales[i]);
    }
}
