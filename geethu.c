#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Structure to hold customer details
typedef struct {
    char name[50];
    float principal;
    float rate;
    float time;
    float interest;
    char type[20]; // "Simple" or "Compound"
} Customer;

// Function prototypes
float simpleInterest(float p, float r, float t);
float compoundInterest(float p, float r, float t);
void saveRecord(Customer c);

int main() {
    int choice;
    Customer c;

    do {
        printf("\n--- Interest Calculation System ---\n");
        printf("1. Calculate Simple Interest\n");
        printf("2. Calculate Compound Interest\n");
        printf("3. View Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Customer Name: ");
                scanf("%s", c.name);
                printf("Enter Principal: ");
                scanf("%f", &c.principal);
                printf("Enter Rate of Interest: ");
                scanf("%f", &c.rate);
                printf("Enter Time (in years): ");
                scanf("%f", &c.time);

                c.interest = simpleInterest(c.principal, c.rate, c.time);
                strcpy(c.type, "Simple");
                printf("Simple Interest = %.2f\n", c.interest);

                saveRecord(c);
                break;

            case 2:
                printf("\nEnter Customer Name: ");
                scanf("%s", c.name);
                printf("Enter Principal: ");
                scanf("%f", &c.principal);
                printf("Enter Rate of Interest: ");
                scanf("%f", &c.rate);
                printf("Enter Time (in years): ");
                scanf("%f", &c.time);

                c.interest = compoundInterest(c.principal, c.rate, c.time);
                strcpy(c.type, "Compound");
                printf("Compound Interest = %.2f\n", c.interest);

                saveRecord(c);
                break;

            case 3: {
                FILE *fp = fopen("records.txt", "r");
                if(fp == NULL) {
                    printf("No records found!\n");
                } else {
                    char line[200];
                    printf("\n--- Saved Records ---\n");
                    while(fgets(line, sizeof(line), fp)) {
                        printf("%s", line);
                    }
                    fclose(fp);
                }
                break;
            }

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 4);

    return 0;
}

// Function to calculate Simple Interest
float simpleInterest(float p, float r, float t) {
    return (p * r * t) / 100;
}

// Function to calculate Compound Interest
float compoundInterest(float p, float r, float t) {
    return p * pow((1 + r/100), t) - p;
}

// Function to save record in file
void saveRecord(Customer c) {
    FILE *fp = fopen("records.txt", "a");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "Name: %s | Principal: %.2f | Rate: %.2f | Time: %.2f | %s Interest: %.2f\n",
            c.name, c.principal, c.rate, c.time, c.type, c.interest);
    fclose(fp);
    printf("Record saved successfully!\n");
}