#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct User {
	char username[20];
	char password[20];
	float balance;
};

void Login(int lineCount);
int LineCount();
void Menu(char* choice);
void Accept(char* answer);
void CheckBalance();
void Deposit();
void Withdraw();
void UpdateFile(int lineCount);

static char accountUsername[20], accountPassword[20];
static float accountBalance;

int main(void) {
	static char choice;
	static char answer;

	printf("\n\t\tWelcome to the ATM\n\n");

	Login(LineCount());

	do {
		Menu(&choice);
		Accept(&answer);
		system("cls");
		if(answer == '1') {
			switch(choice) {
				case '1':	CheckBalance();							break;
				case '2':	Deposit();	UpdateFile(LineCount());	break;
				case '3':	Withdraw();	UpdateFile(LineCount());	break;
				case '4':	continue;								break;
				default:	printf("You have entered an invalid option. Please try again.\n");	break;
			}
		}
	} while(choice != '4' || answer != '1');
	
	system("pause");
	return 0;
}

void Login(int lineCount) {
	static int isLogged = 0;
	int i, j;
	struct User user;
	
	for(i = 0; i < 3; i++) {
		printf("\nUsername: ");
		scanf("%s", accountUsername);
		printf("Password: ");
		scanf("%s", accountPassword);

		for(j = 0; j < lineCount; j++) {
			
			FILE *file = fopen("users.txt", "r");
			if(file == NULL) {
				perror("There was an error opening the file.\n");
				exit(1);
			}
			fscanf(file, "%s %s %f", user.username, user.password, &user.balance);
			if((strcmp(user.username, accountUsername) == 0) && (strcmp(user.password, accountPassword) == 0)) {
				accountBalance = user.balance;
				isLogged++;
			}
			fclose(file);
		}
		if(isLogged != 0) {
			break;
		}	
		printf("\n\t\tYou have %d attempts left.\n", (2 - i));
	}
	
	if(isLogged == 0) {
			printf("\nYou have reached the maximum number of attempts. Exiting the program.\n");
			system("pause");
			exit(1);
		}

	printf("\n\t\tLogin successful.\n\n");
	system("pause");
	system("cls");
}

int LineCount() {
	int lineCount = 0;
	char ch;

	FILE *file = fopen("users.txt", "r");
	if(file == NULL) {
		perror("There was an error opening the file.\n");
		exit(1);
	}
	while((ch = fgetc(file)) != EOF) {
		if(ch == '\n') {
			lineCount++;
		}
	}
	if(ch != '\n' && lineCount > 0) {
		lineCount++;
	}
	fclose(file);

	return lineCount;
}

void Menu(char* choice) {
	printf(	"\n1- Check balance\n"
	        "2- Deposit money\n"
	        "3- Withdraw money\n"
	        "4- Exit the program\n"
	        "Select the operation you want to perform: ");
	scanf(" %s", choice);
}

void Accept(char *answer) {

	printf("\nDo you want to continue with the operation?\n");
	printf("Continue = 1 ");
	printf("Cancel = 0\n");
	printf("Answer: ");
	scanf(" %s", answer);
}

void CheckBalance() {
	printf("\n\n-----------------------------------------------------\n");
	printf("\nBalance: ");
	printf("%.2f", accountBalance);
	printf("\n\n-----------------------------------------------------\n\n");
	system("pause");
	system("cls");
}

void Deposit() {
	float deposited;

	printf("\nEnter the amount of money you want to deposit: ");
	scanf("%f", &deposited);

	accountBalance += deposited;
	printf("\n\n\t\tTransaction successful.");

	CheckBalance();
}

void Withdraw() {
	float withdrawn, temp;

	printf("\nEnter the amount of money you want to withdraw: ");
	scanf("%f", &withdrawn);

	temp = accountBalance - withdrawn;

	if (temp >= 0) {
		accountBalance -= withdrawn;
		printf("\n\n\t\tTransaction successful.");
	} else {
		printf("\n\n\t\tYour balance is insufficient.");
	}

	CheckBalance();
}

void UpdateFile(int lineCount) {
	int i;
	struct User account;

	FILE *file1 = fopen("users.txt", "r");
	FILE *file2 = fopen("newUsers.txt", "w");
	if(file1 == NULL || file2 == NULL) {
		perror("There was an error opening the file.\n");
		exit(1);
	}

	for(i = 1; i < lineCount; i++) {
		fscanf(file1, "%s %s %f", &account.username, &account.password, &account.balance);
		if(strcmp(account.username, accountUsername) == 0) {
			fprintf(file2, "%s %s %.2f\n", account.username, account.password, accountBalance);
			continue;
		}
		fprintf(file2, "%s %s %.2f\n", account.username, account.password, account.balance);
	}
	fclose(file1);
	fclose(file2);
	remove("users.txt");
	rename("newUsers.txt", "users.txt");
}