#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

// Function to read data from file and store it in an array
void read_data(char *file_name, float *sales) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }
    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%f", &sales[i]);
    }
    fclose(file);
}

// Function to generate the sales report
void generate_sales_report(float *sales) {
    char *months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};
    printf("Monthly sales report for 2022:\n");
    printf("Month Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s $%.2f\n", months[i], sales[i]);
    }
}

// Function to generate the sales summary report
void generate_summary_report(float *sales) {
    char *months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};
    float max = sales[0];
    float min = sales[0];
    int max_index = 0, min_index = 0;
    float sum = 0;

    for (int i = 1; i < MONTHS; i++) {
        if (sales[i] > max) {
            max = sales[i];
            max_index = i;
        }
        if (sales[i] < min) {
            min = sales[i];
            min_index = i;
        }
        sum += sales[i];
    }
    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[min_index]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[max_index]);
    printf("Average sales: $%.2f\n", sum / MONTHS);
}

// Function to generate the six-month moving average report
void generate_moving_average_report(float *sales) {
    char *months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < MONTHS - 5; i++) {
        float average = 0;
        for (int j = i; j < i + 6; j++) {
            average += sales[j];
        }
        printf("%s - %s $%.2f\n", months[i], months[i + 5], average / 6);
    }
}

// Function to generate the sales report from highest to lowest
void generate_sorted_sales_report(float *sales) {
    char *months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (sales[i] < sales[j]) {
                float temp = sales[i];
                sales[i] = sales[j];
                sales[j] = temp;
                char *temp_month = months[i];
                months[i] = months[j];
                months[j] = temp_month;
            }
        }
    }
    for (int i = 0; i < MONTHS; i++) {
        printf("%s $%.2f\n", months[i], sales[i]);
    }
}

// Main function
int main() {
    float sales[MONTHS];
    read_data("input_file.txt", sales);
    generate_sales_report(sales);
    printf("\n");
    generate_summary_report(sales);
    printf("\n");
    generate_moving_average_report(sales);
    printf("\n");
    generate_sorted_sales_report(sales);
    return 0;
}
