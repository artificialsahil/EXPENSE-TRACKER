#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_EXPENSES 100

struct Expense {
    char name[50];
    float amount;
};
int main () {
    struct Expense e[MAX_EXPENSES];
    int expense_count = 0;
    int choice;
    float total_expense = 0;

    while(1) {
        printf("---EXPENSE TRACKER MENU---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Amount\n");
        printf("4. Save TO File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (expense_count >= MAX_EXPENSES) {
                printf("Expense limit reached!\n");
                continue;
            }
            printf("Enter expense name: ");
            scanf("%s", e[expense_count].name);
            printf("Enter expense amount: ");
            scanf("%f", &e[expense_count].amount);
            expense_count++;
            printf("Expense added successfully!\n");
        }
         else if (choice == 2) {
            if(expense_count == 0) {
                printf("No expenses recorded.\n");
                continue;
            }
            printf("---Recorded Expenses---\n");
            for (int i = 0; i < expense_count; i++) {
                printf("%d. %s - $%.2f\n", i + 1, e[i].name, e[i].amount);
            }

                
        }
        else if (choice == 3) {
            total_expense = 0;
            for (int i = 0; i < expense_count; i++) {
                total_expense += e[i].amount;
            }
            printf("Total Expense Amount: $%.2f\n", total_expense);
        }
        else if (choice == 4) {
            FILE *file = fopen("expenses.txt", "w");
            if (file == NULL) {
                printf("Error opening file!\n");
                continue;
            }
            for (int i = 0; i < expense_count; i++) {
                fprintf(file, "%s - $%.2f\n", e[i].name, e[i].amount);
            }
            fclose(file);
            printf("Expenses saved to expenses.txt successfully!\n");
        }
        else if(choice == 5) {
            printf("Exiting Expense Tracker. Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }

    }
    return 0;
}