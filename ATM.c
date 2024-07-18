#include<stdio.h>
#include<windows.h>
#include<string.h>
#define RED 12		// color definitions
#define GREEN 10
#define YELLOW 14
#define WHITE 15
#define BLUE 9

struct User{
	char username[20];
	char password[20];
	float balance;
};

void Login(int lineCount);
int LineCount();
void Menu(char* choice);

int main(void){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
	
	int i;
	static char choice;
	
	printf("\n\t\tWelcome to the ATM\n\n");
	
	Login(LineCount());

	do{
		Menu(&choice);
		
		
	}while(choice != 4);
	
	system("pause");
	return 0;
}

void Login(int lineCount){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int i, j, isLogged = 0;
	char username[20], password[20];
	struct User user;
	
	FILE *file = fopen("users.txt", "r");
	if(file == NULL){
		SetConsoleTextAttribute(hConsole, 12);
		perror("There was an error opening the file.\n");
		exit(1);
	}
	
	for(i = 0; i < 3; i++){
		SetConsoleTextAttribute(hConsole, 9);
		
		printf("\n\t\tUsername: ");
		scanf("%s", username);
		printf("\t\tPassword: ");
		scanf("%s", password);
		
		for(j = 0; j < lineCount; j++){
			fscanf(file, "%s %s %f", user.username, user.password, &user.balance);
			
			if(strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0){
				isLogged++;
			}
		}
		
		if(i == 2 && isLogged == 0){
			SetConsoleTextAttribute(hConsole, 12);
			printf("\nYou have reached the maximum number of attempts. Exiting the program.\n");
			SetConsoleTextAttribute(hConsole, 9);
			system("pause");
			exit(1);
		}
		else if(isLogged != 0){
			break;
		}
		SetConsoleTextAttribute(hConsole, 14);
		printf("\n\t\tYou have %d attempts left.\n", (2 - i));
	}
	fclose(file);

	SetConsoleTextAttribute(hConsole, 10);
	printf("\n\t\tLogin successful.\n");
}

int LineCount(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int lineCount = 0;
	char ch;
	
	FILE *file = fopen("users.txt", "r");
	if(file == NULL){
		SetConsoleTextAttribute(hConsole, 12);
		perror("There was an error opening the file.\n");
		exit(1);
	}
	while((ch = fgetc(file)) != EOF){
		if(ch == '\n'){
			lineCount++;
		}
	}
	if(ch != '\n' && lineCount > 0){
		lineCount++;
	}
	fclose(file);
	
	return lineCount;
}

void Menu(char* choice){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
	printf(	"\n1- Check balance\n"
			"2- Deposit money\n"
			"3- Withdraw money\n"
			"4- Exit the program\n"
			"Select the operation you want to perform: ");
	scanf(" %s", choice);
}