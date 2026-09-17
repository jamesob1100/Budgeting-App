/*
Author: James OBrien
Budgeting App in C Language
This program allows users to input their weekly earnings, save them to a file, display total earnings,
and calculate a budget for the current week based on the earnings.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//struct for expenditure
typedef struct{
	char date[11];
	char category[30];
	char description[100];
	float amount;
} Expenditure;

//struct for income
typedef struct{
	char date[11];
	float income;
} Income;

void menu(void);                   //menu function
float income(void);                //function to enter income
void transaction(void);            //function to enter expenditure
void displayEearningsFile(void);   //function to display all income
void displayExpenditureFile(void); //function to display all expenditure
void weekBudget(float);             //function to calculate budget for the week

int main(void){

	unsigned int choice = 0;
    float weekEarnings = 0;

	printf("Welcome to Budgeting App V1.0\n");
	menu();
	scanf("%u", &choice);

	while(choice != 6){
	
		switch(choice){

            //enter weekly income and save it to file
			case 1: 
            printf("\n");
			weekEarnings = income();
			printf("\n");
			break;
			
			case 2:
			printf("\n");
            transaction();
			printf("\n");
			break;

			case 3:
            printf("\n");
			displayEearningsFile();
            printf("\n");
			break;

            case 4:
			printf("\n");
			displayExpenditureFile();
			printf("\n");
			break;

            case 5:
			printf("\n");
			weekBudget(weekEarnings);
			printf("\n");
			break;

			default:
			puts("Invalid Choice\n");
			menu();
			break;
		}
		
		menu();
		scanf("%u", &choice);
	}

	puts("Thank you for Using Budgeting App");
	
}

void menu(void){
        printf("Enter Choice:\n");
        printf("1. Enter Weekly Earnings\n");
        printf("2. Enter Transaction\n");
        printf("3. Display Total Earnings\n");
        printf("4. Display Total Expenses\n");
        printf("5. Display Budget for Current Week\n");
        printf("6. Exit\n");
}

float income(void){
	
    Income weekIncome;
    char earningsStr[20];

    printf("What are your Earnings this Week?\n");
	scanf("%f", &weekIncome.income);

    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);

    if (currentTime == NULL || strftime(weekIncome.date, sizeof(weekIncome.date), "%Y-%m-%d", currentTime) == 0) {
        
        fprintf(stderr, "Unable to determine the current date.\n");
    }

	snprintf(earningsStr, sizeof(earningsStr), "%.2f", weekIncome.income);

	FILE* fptr;
	fptr = fopen("earnings.csv", "a");
	if (fptr == NULL){
		printf("Unable to Open File\n");
	}
	else{
		printf("Saving Earnings to File...\n");
		fprintf(fptr, "%s,%s\n", weekIncome.date, earningsStr);
		fclose(fptr);
	}	 
    return weekIncome.income;
}

void transaction(void){

    Expenditure exp;
    char amountStr[20];

    printf("Enter Transaction Details:\n");
    printf("Category: ");
    scanf("%s", exp.category);
    printf("Description: ");
    scanf("%s", exp.description);
    printf("Amount: ");
    scanf("%f", &exp.amount);

    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);

    if (currentTime == NULL || strftime(exp.date, sizeof(exp.date), "%Y-%m-%d", currentTime) == 0) {
        
        fprintf(stderr, "Unable to determine the current date.\n");
    } 

    snprintf(amountStr, sizeof(amountStr), "%.2f", exp.amount);

    FILE* fptr;
    fptr = fopen("expenditure.csv", "a");
    if (fptr == NULL){
        printf("Unable to Open File\n");
    }
    else{
        printf("Saving Transaction to File...\n");
        fprintf(fptr, "%s,%s,%s,%s\n", exp.date, exp.category, exp.description, amountStr);
        fclose(fptr);
    }	 
}

void displayExpenditureFile(void){

	char buff[100];

	FILE* fptr;
	fptr = fopen("expenditure.csv", "r");
	if (fptr == NULL){
		printf("Unable to Open File\n");
	}
	else{
		while (fgets(buff, sizeof(buff), fptr) != NULL){
			printf("%s", buff);
		}
		fclose(fptr);
	} 
}

void displayEearningsFile(void){

	char buff[100];

	FILE* fptr;
	fptr = fopen("earnings.csv", "r");
	if (fptr == NULL){
		printf("Unable to Open File\n");
	}
	else{
		while (fgets(buff, sizeof(buff), fptr) != NULL){
			printf("%s", buff);
		}
		fclose(fptr);
	} 
}

void weekBudget(float weekIncome){

	float savings = weekIncome * 0.2;
	float disposable = weekIncome * 0.3;
	float necessities = weekIncome * 0.5;

	printf("Your Weekly Budget for %.2f is:\n", weekIncome);
	printf("Savings: %.2f\n", savings);
	printf("Disposable Income: %.2f\n", disposable);
	printf("Necessities: %.2f\n", necessities);
}