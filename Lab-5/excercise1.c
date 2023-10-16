#include <stdio.h>
#include <stdlib.h>

#define NUM_MONTHS 12

// Function to calculate the average of an array of numbers
double calculateAverage(double sales[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += sales[i];
    }
    return sum / count;
}

// Function to print the sales report
void printSalesReport(const char *months[], double sales[], int count) {
    printf("Monthly sales report for 2022:\n");
    printf("Month\tSales\n");
    for (int i = 0; i < count; i++) {
        printf("%s $%.2f\n", months[i], sales[i]);
    }
    printf("\n");  // Add a newline after the report
}

// Function to print the sales summary
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
    printf("Average sales: $%.2f\n\n");  // Add a newline after the summary
}

// Function to print the six-month moving averages
void printMovingAverages(const char *months[], double sales[], int count) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < count - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s - %s $%.2f\n", months[i], months[i + 6], sum / 6);
    }
    printf("\n");  // Add a newline after the moving averages
}

// Function to print the sales report in descending order
void printSalesReportDescending(const char *months[], double sales[], int count) {
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");

    // Create an array of indices and initialize them to 0, 1, 2, ...
    int indices[NUM_MONTHS];
    for (int i = 0; i < count; i++) {
        indices[i] = i;
    }

    // Sort the indices based on the corresponding sales values in descending order
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
        int j = indices[i]; // Add this line to define 'j' before using it
        printf("%s $%.2f\n", months[j], sales[j]);
    }
    printf("\n");  // Add a newline after the descending report
}

int main() {
    const char *months[NUM_MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    double sales[NUM_MONTHS];
    int count = 0;

    // Read monthly sales from the input file
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

    // Print the sales report
    printSalesReport(months, sales, count);

    // Print the sales summary
    printSalesSummary(months, sales, count);

    // Print the six-month moving averages
    printMovingAverages(months, sales, count);

    // Print the sales report in descending order
    printSalesReportDescending(months, sales, count);

    return 0;
}
