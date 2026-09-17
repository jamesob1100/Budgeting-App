#include <stdio.h>
#include <stdlib.h>

void menu(void);
void saveToFile(float);
void displayFile(void);
void weekBudget(float);

int main(void){

	unsigned int choice = 0;
	float weekEarnings = 0;

	printf("Welcome to Budgeting App V1.0\n");
	menu();
	scanf("%u", &choice);

	while(choice != 4){
	
		switch(choice){

			case 1:
			printf("What are your Earnings this Week?\n");
			scanf("%f", &weekEarnings);
			saveToFile(weekEarnings);
			printf("\n");
			break;
			
			case 2:
			printf("\n");
			displayFile();
			printf("\n");
			break;

			case 3:
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
        printf("2. Display Total Earnings\n");
        printf("3. Display Budget for Current Week\n");
        printf("4. Exit\n");
}

void saveToFile(float wEarnings){

	float earnings = wEarnings;
	char earningsStr[10];

	snprintf(earningsStr, sizeof(earningsStr), "%f", earnings);

	FILE* fptr;
	fptr = fopen("expenditure.txt", "a");
	if (fptr == NULL){
		printf("Unable to Open File\n");
	}
	else{
		printf("File Opened Successfully\n");
		printf("Saving Earnings to File\n");
		fputs(earningsStr, fptr);
		fputs("\n", fptr);
		fclose(fptr);
		printf("Earnings Saved to File\n");
	}	 
}

void displayFile(void){

	char buff[100];

	FILE* fptr;
	fptr = fopen("expenditure.txt", "r");
	if (fptr == NULL){
		printf("Unable to Open File\n");
	}
	else{
		printf("Reading File...\n");
		while (fgets(buff, sizeof(buff), fptr) != NULL){
			printf("%s", buff);
		}
		fclose(fptr);
		printf("***End Of File***\n");
	} 
}

void weekBudget(float weekEarnings){

	float savings = weekEarnings * 0.2;
	float disposable = weekEarnings * 0.3;
	float necessities = weekEarnings * 0.5;

	printf("Your Weekly Budget is:\n");
	printf("Savings: %.2f\n", savings);
	printf("Disposable Income: %.2f\n", disposable);
	printf("Necessities: %.2f\n", necessities);
}