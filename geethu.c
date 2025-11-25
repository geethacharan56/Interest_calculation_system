#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    float principal;
    float rate;
    float time;
    float interest;
    char type[20];
} Customer;

Customer customers[MAX];
int count = 0;

// Function prototypes
float simpleInterest(float p, float r, float t);
float compoundInterest(float p, float r, float t);
void saveToFile();
void loadFromFile();
void addRecord();
void viewRecords();
void updateRecord();
void deleteRecord();

int main() {
    int choice;

    loadFromFile(); // Load records on startup

    do {
        printf("\n=== Interest Calculation System (CRUD Enabled) ===\n");
        printf("1. Add New Record\n");
        printf("2. View Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Remove newline character

        switch(choice) {
            case 1: addRecord(); break;
            case 2: viewRecords(); break;
            case 3: updateRecord(); break;
            case 4: deleteRecord(); break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }

    } while(choice != 5);

    return 0;
}

// ------------------- Interest Functions -------------------

float simpleInterest(float p, float r, float t) {
    return (p * r * t) / 100;
}

float compoundInterest(float p, float r, float t) {
    return p * pow((1 + r / 100), t) - p;
}

// ------------------- CRUD OPERATIONS -------------------

// Add new record
void addRecord() {
    Customer c;
    int typeChoice;

    printf("\nEnter Customer Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0'; // Remove newline

    printf("Enter Principal: ");
    scanf("%f", &c.principal);

    printf("Enter Rate of Interest: ");
    scanf("%f", &c.rate);

    printf("Enter Time (in years): ");
    scanf("%f", &c.time);

    printf("Select Interest Type:\n1. Simple\n2. Compound\nChoice: ");
    scanf("%d", &typeChoice);

    if(typeChoice == 1) {
        c.interest = simpleInterest(c.principal, c.rate, c.time);
        strcpy(c.type, "Simple");
    } else {
        c.interest = compoundInterest(c.principal, c.rate, c.time);
        strcpy(c.type, "Compound");
    }

    customers[count++] = c;

    saveToFile();
    printf("Record added successfully!\n");
}

// View records
void viewRecords() {
    if(count == 0) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Saved Records ---\n");
    for(int i = 0; i < count; i++) {
        printf("\nRecord #%d\n", i + 1);
        printf("Name: %s\n", customers[i].name);
        printf("Principal: %.2f\n", customers[i].principal);
        printf("Rate: %.2f\n", customers[i].rate);
        printf("Time: %.2f\n", customers[i].time);
        printf("%s Interest: %.2f\n", customers[i].type, customers[i].interest);
    }
}

// Update a record
void updateRecord() {
    if(count == 0) {
        printf("No records to update.\n");
        return;
    }

    int index;
    viewRecords();
    printf("\nEnter record number to update: ");
    scanf("%d", &index);
    getchar();

    if(index < 1 || index > count) {
        printf("Invalid record number!\n");
        return;
    }
    index--; // Adjust for array

    printf("Updating record for %s\n", customers[index].name);

    printf("Enter new name: ");
    fgets(customers[index].name, sizeof(customers[index].name), stdin);
    customers[index].name[strcspn(customers[index].name, "\n")] = '\0';

    printf("Enter Principal: ");
    scanf("%f", &customers[index].principal);

    printf("Enter Rate: ");
    scanf("%f", &customers[index].rate);

    printf("Enter Time: ");
    scanf("%f", &customers[index].time);

    int option;
    printf("Select Interest Type:\n1. Simple\n2. Compound\nChoice: ");
    scanf("%d", &option);

    if(option == 1) {
        customers[index].interest = simpleInterest(customers[index].principal,
                                                   customers[index].rate,
                                                   customers[index].time);
        strcpy(customers[index].type, "Simple");
    } else {
        customers[index].interest = compoundInterest(customers[index].principal,
                                                     customers[index].rate,
                                                     customers[index].time);
        strcpy(customers[index].type, "Compound");
    }

    saveToFile();
    printf("Record updated successfully!\n");
}

// Delete a record
void deleteRecord() {
    if(count == 0) {
        printf("No records to delete.\n");
        return;
    }

    int index;
    viewRecords();
    printf("\nEnter record number to delete: ");
    scanf("%d", &index);

    if(index < 1 || index > count) {
        printf("Invalid record number!\n");
        return;
    }
    index--;

    for(int i = index; i < count - 1; i++) {
        customers[i] = customers[i + 1];
    }

    count--;
    saveToFile();
    printf("Record deleted successfully!\n");
}

// ------------------- FILE HANDLING -------------------

void saveToFile() {
    FILE *fp = fopen("records.txt", "w");
    if(!fp) {
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        fprintf(fp, "%s|%.2f|%.2f|%.2f|%s|%.2f\n",
            customers[i].name,
            customers[i].principal,
            customers[i].rate,
            customers[i].time,
            customers[i].type,
            customers[i].interest
        );
    }

    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen("records.txt", "r");
    if(!fp) return;

    while(!feof(fp)) {
        Customer c;
        if(fscanf(fp, "%49[^|]|%f|%f|%f|%19[^|]|%f\n",
                  c.name, &c.principal, &c.rate, &c.time, c.type, &c.interest) == 6) {
            customers[count++] = c;
        }
    }
    fclose(fp);
}
