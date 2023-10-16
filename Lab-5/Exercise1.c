#include <stdio.h>
#include <stdlib.h>

#define NUM_MONTHS 12

double calculateAverage(double sales[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += sales[i];
    }
    return sum / count;
}

void printSalesReport(const char *months[], double sales[], int count) {
    printf("Monthly sales report for 2022:\n");
    printf("Month\tSales\n");
    for (int i = 0; i < count; i++) {
        printf("%s $%.2f\n", months[i], sales[i]);
    }
    printf("\n");  
}

void printSalesSummary(const char *months[], double sales[], int count) {
    double minSale = sales[0];
    double maxSale = sales[0];
    double avgSale = calculateAverage(sales, count);
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < count; i++) {
        if (sales[i] < minSale) {
            minSale = sales[i];
            minIndex = i;
        }
        if (sales[i] > maxSale) {
            maxSale = sales[i];
            maxIndex = i;
        }
    }

    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", minSale, months[minIndex]);
    printf("Maximum sales: $%.2f (%s)\n", maxSale, months[maxIndex]);
    printf("Average sales: $%.2f\n\n");  
}

void printMovingAverages(const char *months[], double sales[], int count) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < count - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s - %s $%.2f\n", months[i], months[i + 6], sum / 6);
    }
    printf("\n");  
}

void printSalesReportDescending(const char *months[], double sales[], int count) {
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");

    int indices[NUM_MONTHS];
    for (int i = 0; i < count; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sales[indices[i]] < sales[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        int j = indices[i]; 
        printf("%s $%.2f\n", months[j], sales[j]);
    }
    printf("\n");  
}

int main() {
    const char *months[NUM_MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    double sales[NUM_MONTHS];
    int count = 0;

    FILE *file = fopen("sales_input.txt", "r");
    if (file == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    for (int i = 0; i < NUM_MONTHS; i++) {
        if (fscanf(file, "%lf", &sales[i]) != 1) {
            printf("Error reading data from the input file.\n");
            return 1;
        }
        count++;
    }
    fclose(file);

    printSalesReport(months, sales, count);

    printSalesSummary(months, sales, count);

    printMovingAverages(months, sales, count);

    printSalesReportDescending(months, sales, count);

    return 0;
}
