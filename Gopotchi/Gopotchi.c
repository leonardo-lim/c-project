// Anggota Kelompok :
// - Christopher Chandra Widjaja (2440025292)
// - Juan Trilnardo Defrin (2440021230)
// - Leonardo (2440022901)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include "Models.c"
#include "UserCheck.c"
#define s Sleep(100);
#define ss Sleep(250);
#define PAUSE system("pause")
#define CLEAR system("cls")

void mainMenu();
void newGame();
void loadGame();
void howToPlay();
void howToPlay2();
void credits();
void exitGame();
void cheatMenu();
void showDateTime();
void intro();
void gamePlay();
void deleteUser(int menu);
void change(int counter);
int getNumber();
void chooseGame();
void inventoryMenu();
void chooseCategory();
void dailyNeeds();
void pet();
void petPreview();

int room; // 1 (Bedroom), 2 (Bathroom), 3 (Main Room), 4 (PlayGround), 5 (Kitchen)
int currentLevel, currentExp, maxExp, coins, currentUser;
int healthBar, happyBar, cleanBar, energyBar, hungryBar;
int sleepCheck, petCheck, welcomeCheck = 0;
char userName[20], key;

int checkHourMinute(int ch, int h, int cm, int m, int hourToFull){
	int bar;

	if ((ch + 24 - h) > hourToFull) {
		bar = -1;
	} else {
		if (cm < m) {
			bar = ((ch + 23 - h) * 60 + (cm + 60 - m));
		} else {
			bar = ((ch + 24 - h) * 60 + (cm - m));
		}
	}

	return bar;
}

int checkTimeConsumption(int year, int month, int day, int hour, int minute, int hourToFull){
	int bar = -1, leapCheck = 0;
	
	time_t now = time(NULL);
	struct tm *now_tm = localtime(&now);

	int currentYear = now_tm->tm_year + 1900;
	int currentMonth = now_tm->tm_mon + 1;
	int currentDay = now_tm->tm_mday;
	int currentHour = now_tm->tm_hour;
	int currentMinute = now_tm->tm_min;
	
	if (currentYear == year) {
		if (currentMonth == month) {
			if (currentDay == day) {
				if (currentHour == hour) {
					bar = (currentMinute - minute);
				} else if (currentHour <= hour + hourToFull) {
					if (currentMinute < minute) {
						bar = ((currentHour - hour - 1) * 60 + (currentMinute + 60 - minute));
					} else {
						bar = ((currentHour - hour) * 60 + (currentMinute - minute));
					}
				}
			} else if (currentDay == day + 1) {
				bar = checkHourMinute(currentHour, hour, currentMinute, minute, hourToFull);
			}
		} else if (currentMonth == month + 1) {
			if (month == 2) {
				if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) leapCheck = 1;

				if (leapCheck == 1) {
					if (day == 29 && currentDay == 1) {
						bar = checkHourMinute(currentHour, hour, currentMinute, minute, hourToFull);
					}
				} else {
					if (day == 28 && currentDay == 1) {
						bar = checkHourMinute(currentHour, hour, currentMinute, minute, hourToFull);
					}
				}
			} else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
				if (day == 31 && currentDay == 1) {
					bar = checkHourMinute(currentHour, hour, currentMinute, minute, hourToFull);
				}
			} else {
				if (day == 30 && currentDay == 1) {
					bar = checkHourMinute(currentHour, hour, currentMinute, minute, hourToFull);
				}
			}
		}
	} else if (currentYear == year + 1) {
		if (month == 12 && currentMonth == 1) {
			if (day == 31 && currentDay == 1) {
				bar = checkHourMinute(currentHour, hour, currentMinute, minute, hourToFull);
			}
		}
	}

	return bar;
}

// Main Menu (Start)
void mainMenu(){
	setColor(3);
	printe(6);
	printf("       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	setColor(1);
	printf("       %c W = Up %c S = Down %c Enter = Click %c\n", 186, 186, 186, 186);
	setColor(3);
	printf("       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	setColor(7);

	change(menuCount);

	setColor(3);
	printe(2);
	printm("G O P O T C H I");
	printf("\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);

	if (menuRightSymbol[0] == '>') setColor(1);
	printf("\t\t  %c%c Play Game %c%c\n", menuRightSymbol[0], menuRightSymbol[0], menuLeftSymbol[0], menuLeftSymbol[0]);
	setColor(3);

	if (menuRightSymbol[1] == '>') setColor(1);
	printf("\t\t  %c%c Load Game %c%c\n", menuRightSymbol[1], menuRightSymbol[1],menuLeftSymbol[1], menuLeftSymbol[1]);
	setColor(3);

	if (menuRightSymbol[2] == '>') setColor(1);
	printf("\t\t %c%c How To Play %c%c\n", menuRightSymbol[2], menuRightSymbol[2], menuLeftSymbol[2], menuLeftSymbol[2]);
	setColor(3);

	if (menuRightSymbol[3] == '>') setColor(1);
	printf("\t\t   %c%c Credits %c%c\n", menuRightSymbol[3], menuRightSymbol[3], menuLeftSymbol[3], menuLeftSymbol[3]);
	setColor(3);

	if (menuRightSymbol[4] == '>') setColor(1);
	printf("\t\t  %c%c Exit Game %c%c\n", menuRightSymbol[4], menuRightSymbol[4], menuLeftSymbol[4], menuLeftSymbol[4]);
	setColor(3);

	int check = menuCheck();

	if (check == 0) {
		mainMenu();
		exit(0);
	} else if (check == 99) {
		CLEAR;
		cheatMenu();
		exit(0);
	}
	
	menuRightSymbol[startMenu] = ' ';
	menuLeftSymbol[startMenu] = ' ';
	menuRightSymbol[0] = '>';
	menuLeftSymbol[0] = '<';
	CLEAR;
			
	switch (startMenu) {
		case 0:
			startMenu = 0;
			newGame();
			exit(0);
		case 1:
			startMenu = 0;
			loadGame();
			exit(0);
		case 2:
			startMenu = 0;
			howToPlay();
			exit(0);
		case 3:
			startMenu = 0;
			credits();
			exit(0);
		case 4:
			startMenu = 0;
			exitGame();
			exit(0);
	}
}

void newGame(){
	char name[20] = {0};
	int len, level, statCheck, nameCount = 0;
	
	setColor(3);
	printe(2); happyPrint(1); printe(2);
	printm("Do you want to play with a new user ?");
	printm("\n  Yes(Y)\t\t\t\t    No(N)\n\n");
	
	FILE *p;

	do {
		key = getch();
		
		if (key == 'y' || key == 'Y') {
			p = fopen("User/User1/Status.txt", "r");
			fscanf(p, "%d", &statCheck);
			fclose(p);

			if (statCheck == 1) {
				p = fopen("User/User2/Status.txt", "r");
				fscanf(p, "%d", &statCheck);
				fclose(p);

				if (statCheck == 1) {
					p = fopen("User/User3/Status.txt", "r");
					fscanf(p, "%d", &statCheck);
					fclose(p);

					if (statCheck == 1) {
						CLEAR;
						printe(2); sadPrint(1); printe(2);
						printm("Sorry, you have reached the max number of users.");
						printm("Please delete one of the user.");
						printe(1);
						PAUSE; CLEAR;
						loadGame();
						exit(0);
					}
				}
			}

			CLEAR;
			hatch();
			break;
		} else if (key == 'n' || key == 'N') {
			CLEAR;
			mainMenu();
			exit(0);
		}
	} while(true);

	nameLoop:
		printe(2); happyPrint(1); printe(2);
		printm("What name do you want to call your Gopotchi ?");
		printf("\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf("\t\t   %c %-10s %c\n", 186, name, 186);
		printf("\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
		
		key = getch();
		len = strlen(name);

		if (key != 13) {
			if (len <= 9) {
				if (key == '\b') {
					CLEAR;
					name[nameCount] = 0;
					if (nameCount >= 1) nameCount--;
					name[nameCount] = 0;
					goto nameLoop;
				} else {
					CLEAR;
					name[nameCount] = key;
					nameCount++;
					goto nameLoop;
				}
			} else {
				if (key == '\b') {
					CLEAR;
					name[nameCount] = 0;
					if (nameCount >= 2) nameCount--;
					name[nameCount] = 0;
					goto nameLoop;
				} else {
					CLEAR;
					goto nameLoop;
				}
			}
		} else {
			if (len == 0) {
				CLEAR;
				goto nameLoop;
			}
		}

	FILE *s1 = fopen("User/User1/Status.txt", "r");
	FILE *s2 = fopen("User/User2/Status.txt", "r");
	FILE *s3 = fopen("User/User3/Status.txt", "r");

	fscanf(s1, "%d\n", &status.stat[0]);
	fclose(s1);
	fscanf(s2, "%d\n", &status.stat[1]);
	fclose(s2);
	fscanf(s3, "%d\n", &status.stat[2]);
	fclose(s3);

	time_t now = time(NULL);
	struct tm *now_tm = localtime(&now);

	int currentYear = now_tm->tm_year + 1900;
	int currentMonth = now_tm->tm_mon + 1;
	int currentDay = now_tm->tm_mday;
	int currentHour = now_tm->tm_hour;
	int currentMinute = now_tm->tm_min;
	
	if (status.stat[0] == 1) {
		if (status.stat[1] == 1) {
			if (status.stat[2] == 0) {
				s3 = fopen("User/User3/Name.txt", "w");
				fprintf(s3, "%s", name);
				fclose(s3);
				
				s3 = fopen("User/User3/Status.txt", "w");
				fprintf(s3, "1");
				fclose(s3);
				
				s3 = fopen("User/User3/Level.txt", "w");
				fprintf(s3, "1#0#110");
				fprintf(s3, "\n100#100#100#100#100");
				fclose(s3);

				s3 = fopen("User/User3/Coin.txt", "w");
				fprintf(s3, "100");
				fclose(s3);
				
				s3 = fopen("User/User3/Room.txt", "w");
				fprintf(s3, "3#0");
				fclose(s3);

				s3 = fopen("User/User3/Time.txt", "w");
				fprintf(s3, "%d#%d#%d#%d#%d", currentYear, currentMonth, currentDay, currentHour, currentMinute);
				fclose(s3);

				s3 = fopen("User/User3/PetStatus.txt", "w");
				fprintf(s3, "0");
				fclose(s3);
				
				currentUser = 3;
			}
		} else {
			s2 = fopen("User/User2/Name.txt", "w");
			fprintf(s2, "%s", name);
			fclose(s2);

			s2 = fopen("User/User2/Status.txt", "w");
			fprintf(s2, "1");
			fclose(s2);
			
			s2 = fopen("User/User2/Level.txt", "w");
			fprintf(s2, "1#0#110");
			fprintf(s2, "\n100#100#100#100#100");
			fclose(s2);

			s2 = fopen("User/User2/Coin.txt", "w");
			fprintf(s2, "100");
			fclose(s2);
			
			s2 = fopen("User/User2/Room.txt", "w");
			fprintf(s2, "3#0");
			fclose(s2);

			s2 = fopen("User/User2/Time.txt", "w");
			fprintf(s2, "%d#%d#%d#%d#%d", currentYear, currentMonth, currentDay, currentHour, currentMinute);
			fclose(s2);

			s2 = fopen("User/User2/PetStatus.txt", "w");
			fprintf(s2, "0");
			fclose(s2);
			
			currentUser = 2;
		}
	} else {
		s1 = fopen("User/User1/Name.txt", "w");
		fprintf(s1, "%s", name);
		fclose(s1);

		s1 = fopen("User/User1/Status.txt", "w");
		fprintf(s1, "1");
		fclose(s1);
		
		s1 = fopen("User/User1/Level.txt", "w");
		fprintf(s1, "1#0#110");
		fprintf(s1, "\n100#100#100#100#100");
		fclose(s1);

		s1 = fopen("User/User1/Coin.txt", "w");
		fprintf(s1, "100");
		fclose(s1);
		
		s1 = fopen("User/User1/Room.txt", "w");
		fprintf(s1, "3#0");
		fclose(s1);

		s1 = fopen("User/User1/Time.txt", "w");
		fprintf(s1, "%d#%d#%d#%d#%d", currentYear, currentMonth, currentDay, currentHour, currentMinute);
		fclose(s1);

		s1 = fopen("User/User1/PetStatus.txt", "w");
		fprintf(s1, "0");
		fclose(s1);
		
		currentUser = 1;
	}
	
	currentLevel = 1; currentExp = 0; maxExp = 110; coins = 100;
	healthBar = 100; happyBar = 100; cleanBar = 100; energyBar = 100; hungryBar = 100;
	room = 3; sleepCheck = 0; welcomeCheck = 1;
	
	strcpy(userName, name);
	PAUSE; CLEAR;
	intro();
	exit(0);
}

void loadGame(){
	setColor(3);
	printf("\n\n\n\n");
	printf("\n\n\t       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	setColor(1);
	printf("\t       %c W = Up %c S = Down %c\n", 186, 186, 186);
	setColor(3);
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 187);
	setColor(1);
	printf("\t  %c Enter = Choose %c D = Delete %c\n", 186, 186, 186);
	setColor(3);
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	setColor(7);

	change(counter);
	
	printe(2);
	printm("U S E R D A T A");
	printf("\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	setColor(7);

	int check = userCheck();

	if (check == 0) {
		CLEAR;
		loadGame();
		exit(0);
	} else if (check >= 10 && check <= 12) {
		CLEAR;
		deleteUser(check);
		exit(0);
	}

	int year, month, day, hour, minute, bar;

	FILE *user;

	switch (loadMenu) {
		case 0:
			loadRightSymbol[loadMenu] = ' ';
			loadLeftSymbol[loadMenu] = ' ';
			loadRightSymbol[0] = '>';
			loadLeftSymbol[0] = '<';
			loadMenu = 0;

			CLEAR;
			
			user = fopen("User/User1/Level.txt", "r");
			fscanf(user, "%d#%d#%d", &currentLevel, &currentExp, &maxExp);
			fscanf(user, "\n%d#%d#%d#%d#%d", &healthBar, &happyBar, &cleanBar, &energyBar, &hungryBar);
			fclose(user);

			user = fopen("User/User1/Name.txt", "r");
			fscanf(user, "%[^\n]", &userName);
			fclose(user);

			user = fopen("User/User1/Coin.txt", "r");
			fscanf(user, "%d", &coins);
			fclose(user);
			
			user = fopen("User/User1/Room.txt", "r");
			fscanf(user, "%d#%d", &room, &sleepCheck);
			fclose(user);

			user = fopen("User/User1/Time.txt", "r");
			fscanf(user, "%d#%d#%d#%d#%d", &year, &month, &day, &hour, &minute);
			fclose(user);

			user = fopen("User/User1/PetStatus.txt", "r");
			fscanf(user, "%d", &petCheck);
			fclose(user);

			currentUser = 1;
			break;
		case 1:
			loadRightSymbol[loadMenu] = ' ';
			loadLeftSymbol[loadMenu] = ' ';
			loadRightSymbol[0] = '>';
			loadLeftSymbol[0] = '<';
			loadMenu = 0;

			CLEAR;

			user = fopen("User/User2/Level.txt", "r");
			fscanf(user, "%d#%d#%d", &currentLevel, &currentExp, &maxExp);
			fscanf(user, "\n%d#%d#%d#%d#%d", &healthBar, &happyBar, &cleanBar, &energyBar, &hungryBar);
			fclose(user);

			user = fopen("User/User2/Name.txt", "r");
			fscanf(user, "%[^\n]", &userName);
			fclose(user);

			user = fopen("User/User2/Coin.txt", "r");
			fscanf(user, "%d", &coins);
			fclose(user);
			
			user = fopen("User/User2/Room.txt", "r");
			fscanf(user, "%d#%d", &room, &sleepCheck);
			fclose(user);

			user = fopen("User/User2/Time.txt", "r");
			fscanf(user, "%d#%d#%d#%d#%d", &year, &month, &day, &hour, &minute);
			fclose(user);

			user = fopen("User/User2/PetStatus.txt", "r");
			fscanf(user, "%d", &petCheck);
			fclose(user);
			
			currentUser = 2;
			break;
		case 2:
			loadRightSymbol[loadMenu] = ' ';
			loadLeftSymbol[loadMenu] = ' ';
			loadRightSymbol[0] = '>';
			loadLeftSymbol[0] = '<';
			loadMenu = 0;

			CLEAR;

			user = fopen("User/User3/Level.txt", "r");
			fscanf(user, "%d#%d#%d", &currentLevel, &currentExp, &maxExp);
			fscanf(user, "\n%d#%d#%d#%d#%d", &healthBar, &happyBar, &cleanBar, &energyBar, &hungryBar);
			fclose(user);

			user = fopen("User/User3/Name.txt", "r");
			fscanf(user, "%[^\n]", &userName);
			fclose(user);

			user = fopen("User/User3/Coin.txt", "r");
			fscanf(user, "%d", &coins);
			fclose(user);
			
			user = fopen("User/User3/Room.txt", "r");
			fscanf(user, "%d#%d", &room, &sleepCheck);
			fclose(user);

			user = fopen("User/User3/Time.txt", "r");
			fscanf(user, "%d#%d#%d#%d#%d", &year, &month, &day, &hour, &minute);
			fclose(user);

			user = fopen("User/User3/PetStatus.txt", "r");
			fscanf(user, "%d", &petCheck);
			fclose(user);

			currentUser = 3;
			break;
		case 3:
			loadRightSymbol[loadMenu] = ' ';
			loadLeftSymbol[loadMenu] = ' ';
			loadRightSymbol[0] = '>';
			loadLeftSymbol[0] = '<';
			loadMenu = 0;

			CLEAR;
			mainMenu();
			exit(0);
	}

	// 12 minutes -> decrease 1% (20 hours -> 100%)
	bar = checkTimeConsumption(year, month, day, hour, minute, 20);
	if (bar == -1) bar = 100;
	else bar /= 12;

	if (bar > 0) {
		healthBar -= bar;
		if (healthBar < 0) healthBar = 0;

		happyBar -= bar;
		if (happyBar < 0) happyBar = 0;

		cleanBar -= bar;
		if (cleanBar < 0) cleanBar = 0;

		if (sleepCheck == 0) energyBar -= bar;
		if (energyBar < 0) energyBar = 0;

		hungryBar -= bar;
		if (hungryBar < 0) hungryBar = 0;
	}

	gamePlay();
	exit(0);
}

void howToPlay(){
	CLEAR;
	setColor(3);
	printe(1); printm("How to Play"); printe(1);
	puts(
		" 1.  Gopotchi is a life simulation pet based game.\n"
		" 2.  You will get your Gopotchi by hatching the \n     egg at the first of the game.\n"
		" 3.  There are bars that show Gopotchi's status.\n"
		" 4.  Player should take care his Gopotchi by \n     maintaining the status bar.\n"
		" 5.  Gopotchi can earn Chi by playing minigames.\n"
	);
	
	printf("\n\n\t\t      Exit(E)\t\t   Next(D)\n\n");	
	
	do {
		key = getch();
		
		if (key == 'd' || key == 'D') {
			howToPlay2();
			exit(0);
		} else if (key == 'e' || key == 'E') {
			mainMenu();
			exit(0);
		}
	} while(true);
}

void howToPlay2(){
	CLEAR;
	setColor(3);
	puts(
		"\n\t\t    How to Play\n\n"
		" 6.  There will be a number that show the level of \n     Gopotchi.\n"
		" 7.  Gopotchi can use Chi to buy his daily needs\n     by accessing GotchoShop.\n"
		" 8.  Gopotchi can also use Chi to buy a pet by\n     accessing GotchoShop.\n"
		" 9.  Player can give his pet a name.\n"
		" 10. Have fun!\n"
	);
	
	printf("\n Previous(A)\t      Exit(E)\n\n");
	printf("\n Cheat : ");
	setColor(00);
	puts("Cheat menu can be accessed by typing\n\t\"developermodeon\" in the main menu.");
	
	do {
		key = getch();
		
		if (key == 'a' || key == 'A') {
			howToPlay();
			exit(0);
		} else if (key == 'e' || key == 'E') {
			CLEAR;
			mainMenu();
			exit(0);
		}
	} while(true);
}

void credits(){
	time_t now = time(NULL);
	struct tm *now_tm = localtime(&now);
	int year = now_tm->tm_year + 1900;
	
	setColor(5);

	for (int i = 0; i < 30; i++) puts("");

	printm("Our Developer"); ss puts(""); ss
	printm("Christopher Chandra Widjaja (2440025292)"); ss
	printm("Juan Trilnardo Defrin (2440021230)"); ss
	printm("Leonardo (2440022901)"); ss puts(""); ss puts(""); ss
	printf("\t\t        %c\n", 219); ss
	printf("\t\t        %c%c%c%c%c\n\t\t\t    %c\n", 219, 219, 219, 219, 219, 219); ss
	printf("\t\t     %c%c  G  %c%c\n\t\t      %c\n", 220, 219, 219, 220, 219); ss
	printf("\t\t      %c%c%c%c%c\n", 219, 219, 219, 219, 219); ss
	printf("\t\t        %c\n", 219); ss
	printf("\n\n\t\t   Gopotch%c v1.0\n", 161); ss puts(""); ss
	printm("Built in 2020"); ss puts(""); ss
	printf("      Copyright(C) %d. All rights reserved.\n", year); ss

	for (int i = 0; i < 25; i++) {
		puts(""); ss
	}

	mainMenu();
	exit(0);
}

void exitGame(){
	setColor(3);
	printe(2); shockPrint(1); printe(2);
	printm("Do you really want to quit ?");
	printf("\n  Yes(Y)\t\t\t\t    No(N)\n\n");

	do {
		key = getch();
		
		if (key == 'y' || key == 'Y') {
			CLEAR;
			break;
			exit(0);
		} else if (key == 'n' || key == 'N') {
			CLEAR;
			mainMenu();
			exit(0);
		}
	} while(true);
	
	printe(8);
	printf("\t\t      ");
	s printf("T"); s printf("H"); s printf("A"); s printf("N"); s printf("K"); s printf("S"); s printf(" ");
	s printf("\n\t\t      F"); s printf("O"); s printf("R"); s printf("\n\t\t      P"); s printf("L");
	s printf("A"); s printf("Y"); s printf("I"); s printf("N"); s printf("G"); s printf("\n\n\n\t\t   G");
	s printf("o"); s printf("p"); s printf("o"); s printf("t"); s printf("c"); s printf("h"); s printf("%c", 161);
	s printf(" "); s printf("v"); s printf("1"); s printf("."); s printf("0"); s printf("\n\n\n\n"); s s s s s s s s s s s s s s
	setColor(7);
}

void cheatMenu(){
	setColor(2);
	printe(5);
	printm("Developer Mode : ON");
	printm("===================");
	printe(1);
	printm("Press 1 to max Chi");
	printm("Press 2 to max Level");
	printm("Press 3 to call Developer");
	printm("Press 4 to turn off developer mode");
	setColor(3);

	int coins, statCheck;

	FILE *cheat;

	do {
		key = getch();
		
		if (key == '1') {
			
			CLEAR;
			printe(2); moneyPrint(1); printe(2);
			printm("Which user do you want to transfer Chi ?");
			printe(1);
			printm("1st User(1)");
			printm("2nd User(2)");
			printm("3rd User(3)");

			do {
				key = getch();
				
				if (key == '1') {
					cheat = fopen("User/User1/Status.txt", "r");
					fscanf(cheat, "%d", &statCheck);
					fclose(cheat);

					if (statCheck == 1) {
						cheat = fopen("User/User1/Coin.txt", "w");
						break;
					} else {
						CLEAR;
						printe(2); neutralPrint(1); printe(2);
						printm("Sorry, this user is still empty."); printe(1);
						PAUSE; CLEAR;
						cheatMenu();
						exit(0);
					}
				} else if (key == '2') {
					cheat = fopen("User/User2/Status.txt", "r");
					fscanf(cheat, "%d", &statCheck);
					fclose(cheat);

					if (statCheck == 1) {
						cheat = fopen("User/User2/Coin.txt", "w");
						break;
					} else {
						CLEAR;
						printe(2); neutralPrint(1); printe(2);
						printm("Sorry, this user is still empty."); printe(1);
						PAUSE; CLEAR;
						cheatMenu();
						exit(0);
					}
				} else if (key == '3') {
					cheat = fopen("User/User3/Status.txt", "r");
					fscanf(cheat, "%d", &statCheck);
					fclose(cheat);

					if (statCheck == 1) {
						cheat = fopen("User/User3/Coin.txt", "w");
						break;
					} else {
						CLEAR;
						printe(2); neutralPrint(1); printe(2);
						printm("Sorry, this user is still empty."); printe(1);
						PAUSE; CLEAR;
						cheatMenu();
						exit(0);
					}
				}
			} while(true);

			fprintf(cheat, "100000");
			fclose(cheat);

			CLEAR;
			printe(2); moneyPrint(1); printe(1);
			printChi(100000); printe(1);

			if (key == '1') printm("has been transferred to your first user.");
			else if (key == '2') printm("has been transferred to your second user.");
			else printm("has been transferred to your third user.");
			printe(1);
			
			PAUSE; CLEAR;
			mainMenu();
			exit(0);
		} else if (key == '2') {
			time_t now = time(NULL);
			struct tm *now_tm = localtime(&now);

			int currentYear = now_tm->tm_year + 1900;
			int currentMonth = now_tm->tm_mon + 1;
			int currentDay = now_tm->tm_mday;
			int currentHour = now_tm->tm_hour;
			int currentMinute = now_tm->tm_min;
			int levelnow, expnow, expmax;

			CLEAR;
			printe(2); moneyPrint(1); printe(2);
			printm("Which user do you want to set the level to max ?");
			printe(1);
			printm("1st User(1)");
			printm("2nd User(2)");
			printm("3rd User(3)");
			
			do {
				key = getch();
				
				if (key == '1') {
					cheat = fopen("User/User1/Status.txt", "r");
					fscanf(cheat, "%d", &statCheck);
					fclose(cheat);

					if (statCheck == 1) {
						cheat = fopen("User/User1/Level.txt", "r");
						fscanf(cheat, "%d#%d#%d", &levelnow, &expnow, &expmax);
						fclose(cheat);
						cheat = fopen("User/User1/Level.txt", "w");
						break;
					} else {
						CLEAR;
						printe(2); neutralPrint(1); printe(2);
						printm("Sorry, this user is still empty."); printe(1);
						PAUSE; CLEAR;
						cheatMenu();
						exit(0);
					}
				} else if (key == '2') {
					cheat = fopen("User/User2/Status.txt", "r");
					fscanf(cheat, "%d", &statCheck);
					fclose(cheat);

					if (statCheck == 1) {
						cheat = fopen("User/User2/Level.txt", "r");
						fscanf(cheat, "%d#%d#%d", &levelnow, &expnow, &expmax);
						fclose(cheat);
						cheat = fopen("User/User2/Level.txt", "w");
						break;
					} else {
						CLEAR;
						printe(2); neutralPrint(1); printe(2);
						printm("Sorry, this user is still empty."); printe(1);
						PAUSE; CLEAR;
						cheatMenu();
						exit(0);
					}
				} else if (key == '3') {
					cheat = fopen("User/User3/Status.txt", "r");
					fscanf(cheat, "%d", &statCheck);
					fclose(cheat);

					if (statCheck == 1) {
						cheat = fopen("User/User3/Level.txt", "r");
						fscanf(cheat, "%d#%d#%d", &levelnow, &expnow, &expmax);
						fclose(cheat);
						cheat = fopen("User/User3/Level.txt", "w");
						break;
					} else {
						CLEAR;
						printe(2); neutralPrint(1); printe(2);
						printm("Sorry, this user is still empty."); printe(1);
						PAUSE; CLEAR;
						cheatMenu();
						exit(0);
					}
				}
			} while(true);

			fprintf(cheat, "%d#100000#%d\n100#100#100#100#100", levelnow, expmax);
			fclose(cheat);

			CLEAR;
			printe(2); happyPrint(1); printe(2);

			if (key == '1') printm("Your level is max now at first user.");
			else if (key == '2') printm("Your level is max now at second user.");
			else printm("Your level is max now at third user.");

			printm("All your bar is also full now.");
			printe(1);
			
			if (key == '1') cheat = fopen("User/User1/Time.txt", "w");
			else if (key == '2') cheat = fopen("User/User2/Time.txt", "w");
			else cheat = fopen("User/User3/Time.txt", "w");

			fprintf(cheat, "%d#%d#%d#%d#%d", currentYear, currentMonth, currentDay, currentHour, currentMinute);
			fclose(cheat);
			
			PAUSE; CLEAR;
			mainMenu();
			exit(0);
		} else if (key == '3') {
			CLEAR;
			printe(2); sadPrint(1); printe(2);
			printm("Sorry, this feature is not yet available."); printe(1);

			PAUSE; CLEAR;
			mainMenu();
			exit(0);	
		} else if (key == '4') {
			CLEAR;
			mainMenu();
			exit(0);
		}
	} while(true);

	PAUSE; CLEAR;
	mainMenu();
	exit(0);
}
// Main Menu (End)

// Others (Start)
void change(int counter){
	if (counter < 10) happyPrint(50);
	else if (counter >= 10 && counter < 20) badMoodPrint(50);
	else if (counter >= 20 && counter < 30) sickPrint(50);
	else deadPrint(50);
}

void deleteUser(int menu){
	printe(2); sadPrint(1); printe(2);
	printd("Do you really want to delete Player %d ?", menu - 9);
	printf("\n  Yes(Y)\t\t\t\t    No(N)\n\n");

	do {
		key = getch();
		
		if (key == 'y' || key == 'Y') {
			CLEAR;

			FILE *del;
			
			if (menu == 10) {
				del = fopen("User/User1/Status.txt", "w");
				fprintf(del, "0");
				fclose(del);

				del = fopen("User/User1/Name.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User1/Level.txt", "w");
				fprintf(del, "");
				fclose(del);
				
				del = fopen("User/User1/Coin.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User1/Room.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User1/Time.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User1/PetName.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User1/PetStatus.txt", "w");
				fprintf(del, "0");
				fclose(del);

				del = fopen("User/User1/Inventory.txt", "w");
				for (int j = 0; j < sizeItem; j++) {
					if(j != sizeItem - 1) fprintf(del, "%d#%s#%d#%d#%d#%d#%d#%d\n", defaultInventory[j].jenis, defaultInventory[j].nama, defaultInventory[j].jumlah, defaultInventory[j].healthBar, defaultInventory[j].happyBar, defaultInventory[j].cleanBar, defaultInventory[j].energyBar, defaultInventory[j].hungryBar);
					else fprintf(del, "%d#%s#%d#%d#%d#%d#%d#%d", defaultInventory[j].jenis, defaultInventory[j].nama, defaultInventory[j].jumlah, defaultInventory[j].healthBar, defaultInventory[j].happyBar, defaultInventory[j].cleanBar, defaultInventory[j].energyBar, defaultInventory[j].hungryBar);
				}
				fclose(del);
			} else if (menu == 11) {
				del = fopen("User/User2/Status.txt", "w");
				fprintf(del, "0");
				fclose(del);

				del = fopen("User/User2/Name.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User2/Level.txt", "w");
				fprintf(del, "");
				fclose(del);
				
				del = fopen("User/User2/Coin.txt", "w");
				fprintf(del, "");
				fclose(del);
				
				del = fopen("User/User2/Room.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User2/Time.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User2/PetName.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User2/PetStatus.txt", "w");
				fprintf(del, "0");
				fclose(del);

				del = fopen("User/User2/Inventory.txt", "w");
				for (int j = 0; j < sizeItem; j++) {
					if(j != sizeItem - 1) fprintf(del, "%d#%s#%d#%d#%d#%d#%d#%d\n", defaultInventory[j].jenis, defaultInventory[j].nama, defaultInventory[j].jumlah, defaultInventory[j].healthBar, defaultInventory[j].happyBar, defaultInventory[j].cleanBar, defaultInventory[j].energyBar, defaultInventory[j].hungryBar);
					else fprintf(del, "%d#%s#%d#%d#%d#%d#%d#%d", defaultInventory[j].jenis, defaultInventory[j].nama, defaultInventory[j].jumlah, defaultInventory[j].healthBar, defaultInventory[j].happyBar, defaultInventory[j].cleanBar, defaultInventory[j].energyBar, defaultInventory[j].hungryBar);
				}
				fclose(del);
			} else {
				del = fopen("User/User3/Status.txt", "w");
				fprintf(del, "0");
				fclose(del);

				del = fopen("User/User3/Name.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User3/Level.txt", "w");
				fprintf(del, "");
				fclose(del);
				
				del = fopen("User/User3/Coin.txt", "w");
				fprintf(del, "");
				fclose(del);
				
				del = fopen("User/User3/Room.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User3/Time.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User3/PetName.txt", "w");
				fprintf(del, "");
				fclose(del);

				del = fopen("User/User3/PetStatus.txt", "w");
				fprintf(del, "0");
				fclose(del);

				del = fopen("User/User3/Inventory.txt", "w");
				for (int j = 0; j < sizeItem; j++) {
					if(j != sizeItem - 1) fprintf(del, "%d#%s#%d#%d#%d#%d#%d#%d\n", defaultInventory[j].jenis, defaultInventory[j].nama, defaultInventory[j].jumlah, defaultInventory[j].healthBar, defaultInventory[j].happyBar, defaultInventory[j].cleanBar, defaultInventory[j].energyBar, defaultInventory[j].hungryBar);
					else fprintf(del, "%d#%s#%d#%d#%d#%d#%d#%d", defaultInventory[j].jenis, defaultInventory[j].nama, defaultInventory[j].jumlah, defaultInventory[j].healthBar, defaultInventory[j].happyBar, defaultInventory[j].cleanBar, defaultInventory[j].energyBar, defaultInventory[j].hungryBar);
				}
				fclose(del);
			}

			printe(2); happyPrint(1); printe(2);
			printd("Player %d has been succesfully deleted.", menu - 9); printe(1);
			PAUSE; CLEAR;
			loadGame();
			exit(0);
		} else if (key == 'n' || key == 'N') {
			CLEAR;
			loadGame();
			exit(0);
		}
	} while(true);
}

void showDateTime(){
	int key = 0;
	
	while (key == 0) {
		time_t now = time(NULL);
		struct tm *now_tm = localtime(&now);

		char day[12], month[5];
		int d = now_tm->tm_wday;
		int date = now_tm->tm_mday;
		int m = now_tm->tm_mon;
		int year = now_tm->tm_year + 1900;
		int hour = now_tm->tm_hour;
		int minute = now_tm->tm_min;
		int second = now_tm->tm_sec;
		
		if (m == 0) strcpy(month, "Jan");
		else if (m == 1) strcpy(month, "Feb");
		else if (m == 2) strcpy(month, "Mar");
		else if (m == 3) strcpy(month, "Apr");
		else if (m == 4) strcpy(month, "May");
		else if (m == 5) strcpy(month, "Jun");
		else if (m == 6) strcpy(month, "Jul");
		else if (m == 7) strcpy(month, "Aug");
		else if (m == 8) strcpy(month, "Sep");
		else if (m == 9) strcpy(month, "Oct");
		else if (m == 10) strcpy(month, "Nov");
		else strcpy(month, "Dec");
		
		if (d == 0) strcpy(day, "  Sunday");
		else if (d == 1) strcpy(day, "  Monday");
		else if (d == 2) strcpy(day, "  Tuesday");
		else if (d == 3) strcpy(day, " Wednesday");
		else if (d == 4) strcpy(day, " Thursday");
		else if (d == 5) strcpy(day, "  Friday");
		else strcpy(day, " Saturday");

		CLEAR;
		printe(8);
		printf("\t     %s, %s ", day, month);
		
		if (date < 10) printf("0");
		printf("%d, %d\n\n", date, year);
		
		printf("\t\t   ");
		if (hour < 10) printf("0");
		printf("%d : ", hour);
		
		if (minute < 10) printf("0");
		printf("%d : ", minute);
		
		if (second < 10) printf("0");
		printf("%d\n\n\n", second);

		printm("Back(B)");
		Sleep(1000);
		key = kbhit(); // return 0 -> not pressed, return 1 -> pressed
	}
	
	CLEAR;
	gamePlay();
	exit(0);
}

void printStatusBar(int bar){
	if (bar > 70 && bar <= 100) {
		setColor(2);
		if (bar > 95) printBar100(bar); // 96 - 100
		else if (bar > 90) printBar95(bar); // 91 - 95
		else if (bar > 85) printBar90(bar); // 86 - 90
		else if (bar > 80) printBar85(bar); // 81 - 85
		else if (bar > 75) printBar80(bar); // 76 - 80
		else printBar75(bar); // 71 - 75
		setColor(7);
	} else if (bar > 20 && bar <= 70) {
		setColor(6);
		if (bar > 65) printBar70(bar); // 66 - 70
		else if (bar > 60) printBar65(bar); // 61 - 65
		else if (bar > 55) printBar60(bar); // 56 - 60
		else if (bar > 50) printBar55(bar); // 51 - 55
		else if (bar > 45) printBar50(bar); // 46 - 50
		else if (bar > 40) printBar45(bar); // 41 - 45
		else if (bar > 35) printBar40(bar); // 36 - 40
		else if (bar > 30) printBar35(bar); // 31 - 35
		else if (bar > 25) printBar30(bar); // 26 - 30
		else printBar25(bar); // 21 - 25
		setColor(7);
	} else {
		setColor(4);
		if (bar > 15) printBar20(bar); // 16 - 20
		else if (bar > 10) printBar15(bar); // 11 - 15
		else if (bar > 5) printBar10(bar); // 6 - 10
		else if (bar > 0) printBar5(bar); // 1 - 5
		else printBar0(bar); // 0
		setColor(7);
	}
}

void statusBar(){
	setColor(7);
	printf("\t      Health\n");
	printStatusBar(healthBar);
	printf("\n\t      Happiness\n");
	printStatusBar(happyBar);
	printf("\n\t      Cleanliness\n");
	printStatusBar(cleanBar);
	printf("\n\t      Energy\n");
	printStatusBar(energyBar);
	printf("\n\t      Hunger\n");
	printStatusBar(hungryBar);
	setColor(3);

	printe(2); printm("Back(B)");
	
	do {
		key = getch();

		if (key == 'b' || key == 'B') {
			CLEAR;
			gamePlay();
			exit(0);
		}
	} while(true);
}

void saveExitUser(){
	FILE *save;
	if (currentUser == 1) save = fopen("User/User1/Coin.txt", "w");
	else if (currentUser == 2) save = fopen("User/User2/Coin.txt", "w");
	else save = fopen("User/User3/Coin.txt", "w");
	
	fprintf(save, "%d", coins);
	fclose(save);
	
	if (currentUser == 1) save = fopen("User/User1/Level.txt", "w");
	else if (currentUser == 2) save = fopen("User/User2/Level.txt", "w");
	else save = fopen("User/User3/Level.txt", "w");
	
	fprintf(save, "%d#%d#%d", currentLevel, currentExp, maxExp);
	fprintf(save, "\n%d#%d#%d#%d#%d", healthBar, happyBar, cleanBar, energyBar, hungryBar);
	fclose(save);
	
	if (currentUser == 1) save = fopen("User/User1/Room.txt", "w");
	else if (currentUser == 2) save = fopen("User/User2/Room.txt", "w");
	else save = fopen("User/User3/Room.txt", "w");
	
	fprintf(save, "%d#%d", room, sleepCheck);
	fclose(save);

	if (sleepCheck == 0) {
		time_t now = time(NULL);
		struct tm *now_tm = localtime(&now);

		int currentYear = now_tm->tm_year + 1900;
		int currentMonth = now_tm->tm_mon + 1;
		int currentDay = now_tm->tm_mday;
		int currentHour = now_tm->tm_hour;
		int currentMinute = now_tm->tm_min;

		if (currentUser == 1) save = fopen("User/User1/Time.txt", "w");
		else if (currentUser == 2) save = fopen("User/User2/Time.txt", "w");
		else save = fopen("User/User3/Time.txt", "w");

		fprintf(save, "%d#%d#%d#%d#%d", currentYear, currentMonth, currentDay, currentHour, currentMinute);
		fclose(save);
	}

	CLEAR;
	printe(5); happyPrint(currentLevel); printe(1);
	printm("Your current progress has been saved."); printe(1);

	welcomeCheck = 0;
	PAUSE; CLEAR;
	mainMenu();
	exit(0);
}

void validateFace(){
	if (healthBar <= 10) {
		deadPrint(currentLevel); printe(1);
		printm("I'm about to die!");
	} else if (healthBar <= 30) {
		sickPrint(currentLevel); printe(1);
		printm("I think I need some medicines.");
	} else if (happyBar <= 10) {
		sadPrint(currentLevel); printe(1);
		printm("Cheer me up!");
	} else if (happyBar <= 30) {
		badMoodPrint(currentLevel); printe(1);
		printm("Feels so bored. Bring me to playground!");
	} else if (energyBar <= 20) {
		badMoodPrint(currentLevel); printe(1);
		printm("Feels so tired. I want to sleep!");
	} else if (hungryBar <= 20) {
		sadPrint(currentLevel); printe(1);
		printm("I'm so hungry. I want to eat something.");
	} else if (cleanBar <= 20) {
		sadPrint(currentLevel); printe(1);
		printm("I think my body smells bad. Bring me to bathroom!");
	} else if (healthBar >= 75 && happyBar >= 75 && cleanBar >= 75 && energyBar >= 75 && hungryBar >= 75) {
		happyPrint(currentLevel); printe(1);
		printm("I'm so happy.");
	} else {
		neutralPrint(currentLevel); printe(1);
		printm("I'm okay.");
	}

	setColor(3);
}

void chooseRoom(){
	printe(1);
	if (room == 1 && sleepCheck == 1) printm("Save and Exit(ESC)");
	else printf(" <(A)            Save and Exit(ESC)           (D)> \n");
	printe(1);
}
// Others (End)

// GotchoShop (Start)
void gotchoShop(){
	printe(7);
	printf("\t\t     %c%c%c%c%c%c%c%c%c\n\t\t      O P E N \n\t\t      %c%c%c%c%c%c%c\n\t\t      %c     %c\n\t\t      %c     %c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	printe(2); printm("Welcome to GotchoShop!"); printe(2);
	Sleep(1000); CLEAR;
	chooseCategory();
}

void chooseCategory(){
	printe(2); happyPrint(currentLevel); printe(2);
	printm("What are you looking for ?"); printe(1);
	printm("Daily Needs(1)");
	printm("Pet(2)");
	printm("Back(B)");

	do {
		char key = getch();

		if (key == '1') {
			CLEAR;
			dailyNeeds();
			exit(0);
		} else if (key == '2') {
			if (currentLevel > 20) {
				CLEAR;
				pet();
				exit(0);
			} else {
				CLEAR;
				printe(2); neutralPrint(currentLevel); printe(2);
				printm("Sorry, you need to be level 20 to buy a pet."); printe(1);
				PAUSE; CLEAR;
				chooseCategory();
				exit(0);
			}
		} else if (key == 'b' || key == 'B') {
			CLEAR;
			gamePlay();
			exit(0);
		}
	} while(true);
}

void printSortMenu(int type){
	printe(1);
	printm("Default(0)");
	printm("Sorted Asc by Price(1) | Sorted Desc by Price(2)");
	printm("Sorted Asc by Name(3) | Sorted Desc by Name(4)");
	printm("Back(ESC) | Buy(Enter)");
	printe(1);

	if (type == 0) printm("Type : Default");
	else if (type == 1) printm("Type : Sorted Asc by Price");
	else if (type == 2) printm("Type : Sorted Desc by Price");
	else if (type == 3) printm("Type : Sorted Asc by Name");
	else if (type == 4) printm("Type : Sorted Desc by Name");
}

void dailyNeeds(){
	setScrollableWindowSize();
	
	int i, j, k;
	char search[100] = {'\0'};
	int huruf, temu, countType = 0;
	int type = 0; // 0 is Unsorted
	int checkBuy = 0;

	do{
		item:
		CLEAR;
		printSortMenu(type);

		printf("\n Search : %s \n\n", search);
		sortAll(countType, search, type);

		int number = 1;

		do {
			key = getch();
			
			if (key == 27) {
				checkShop = 0;
				setWindowSize();
				break;
			} else if (key == 13) {
				checkBuy = 1;
				checkShop = 0;
				break;
			}else if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z') || key == 32) {
				search[countType] = key;
				printf("%c", key);
				countType++;
				checkShop = 1;
				break;
			} else if (key == 8) {
				if (countType != 0) {
					search[countType] = '\0';
					countType--;
					search[countType] = '\0';
					printf("\b \b");
					checkShop = 1;
				}
				break;
			} else if (key >= '0' && key <= '4') {
				type = key % '0';
				checkShop = 1;
				break;
			}
		} while(true);

		if (checkShop == 0) break;
		CLEAR;
	} while(true);

	if(checkBuy == 0){
		CLEAR;
		gamePlay();
		exit(0);
	}else{
		int pil;

		do{
			printf("\n Item Number : ");
			pil = getNumber();
			if(pil > searchedItem || pil == 0){
				CLEAR;
				printe(2); neutralPrint(currentLevel); printe(2);
				printd("Item no %d is not available on our list.", pil);
				printe(1);
				PAUSE; CLEAR;
				goto item;
				exit(0);
			}else{
				break;
			}
		}while(true);

		CLEAR;
		printe(2); neutralPrint(currentLevel); printe(2);
		prints("Do you want to buy %s ?", printedShop[pil - 1].nama);
		printm("\n  Yes(Y)\t\t\t\t    No(N)\n\n");

		do{
			key = getch();
			char quantity[4] = {0};
			int price;

			if(key == 'y' || key == 'Y'){
				char key2;
				int countShop = 0;

				do{
					int check = 0;

					if(countShop != 0){
						price = atoi(quantity) * printedShop[pil - 1].harga;
					}else{
						price = 0;
					}

					CLEAR;
					printe(2); neutralPrint(currentLevel); printe(2);
					prints("How many %s do you want to buy ?", printedShop[pil - 1].nama); printe(1);
					if (atoi(quantity) > 1) printd("%d items", atoi(quantity));
					else printd("%d item", atoi(quantity));
					printChi(price);
					printe(2);
					printm("Purchase(Enter)");
					printm("Cancel(C)");

					do{
						key2 = getch();

						if(key2 == 13){
							check = 1;
							break;
						}else if(key2 >= '0' && key2 <= '9'){
							quantity[countShop] = key2;
							if(atoi(quantity) > 100){
								quantity[countShop] = '\0';
								continue;
							}else{
								countShop++;
								break;
							}
						}else if(key2 == 8){
							if(countShop != 0){
								quantity[countShop] = '\0';
								countShop--;
								quantity[countShop] = '\0';
								break;
							}
						}else if(key2 == 'c' || key == 'C'){
							CLEAR;
							dailyNeeds();
							exit(0);
						}
					}while(true);

					if(check == 1){
						if(countShop > 0){
							if(atoi(quantity) > 100){
								CLEAR;
								continue;
							}else{
								break;	
							}
						}
					}
					CLEAR;
				}while(true);
					if(coins - (printedShop[pil - 1].harga * atoi(quantity)) < 0){
						CLEAR;
						printe(2); sadPrint(currentLevel); printe(2);
						printm("Sorry, there are not enough Chi to buy this item."); printe(1);
						PAUSE; CLEAR;
						setWindowSize();
						dailyNeeds();
						exit(0);
					}else{
						CLEAR;
						printe(2); happyPrint(currentLevel); printe(2);
						prints("%s has been added to your Inventory.", printedShop[pil - 1].nama); printe(1);

						for(int i = 0; i < sizeItem; i++){
							if(strcmp(printedShop[pil - 1].nama, inventory[currentUser - 1][i].nama) == 0){
								inventory[currentUser - 1][i].jumlah += atoi(quantity);
								coins -= price; 

								FILE *shop;

								if(currentUser == 1) shop = fopen("User/User1/Inventory.txt", "w");
								else if(currentUser == 2) shop = fopen("User/User2/Inventory.txt", "w");
								else if(currentUser == 3) shop = fopen("User/User3/Inventory.txt", "w");

								for(int j = 0; j < sizeItem; j++){
									if(j != sizeItem - 1) fprintf(shop, "%d#%s#%d#%d#%d#%d#%d#%d\n", inventory[currentUser - 1][j].jenis, inventory[currentUser - 1][j].nama, inventory[currentUser - 1][j].jumlah, inventory[currentUser - 1][j].healthBar, inventory[currentUser - 1][j].happyBar, inventory[currentUser - 1][j].cleanBar, inventory[currentUser - 1][j].energyBar, inventory[currentUser - 1][j].hungryBar);
									else fprintf(shop, "%d#%s#%d#%d#%d#%d#%d#%d", inventory[currentUser - 1][j].jenis, inventory[currentUser - 1][j].nama, inventory[currentUser - 1][j].jumlah, inventory[currentUser - 1][j].healthBar, inventory[currentUser - 1][j].happyBar, inventory[currentUser - 1][j].cleanBar, inventory[currentUser - 1][j].energyBar, inventory[currentUser - 1][j].hungryBar);
								}

								fclose(shop);

								if(currentUser == 1) shop = fopen("User/User1/Coin.txt", "w");
								else if(currentUser == 2) shop = fopen("User/User2/Coin.txt", "w");
								else if(currentUser == 3) shop = fopen("User/User3/Coin.txt", "w");

								fprintf(shop, "%d", coins);
								fclose(shop);

								break;
							}
						}

						PAUSE; CLEAR;
						printe(2); happyPrint(currentLevel); printe(2);
						printm("Do you want to buy again ?");
						printm("\n  Yes(Y)\t\t\t\t    No(N)\n\n");

						do {
							key = getch();

							if (key == 'y' || key == 'Y') {
								CLEAR;
								dailyNeeds();
								exit(0);
							} else if (key == 'n' || key == 'N') {
								CLEAR;
								setWindowSize();
								gamePlay();
								exit(0);
							}
						} while(true);
					}
			}else if(key == 'n' || key == 'N'){
				CLEAR;
				setWindowSize();
				dailyNeeds();
				exit(0);
			}
		}while(true);
	}
}

void purchasePet(int num){
	char name[20] = {0};
	int price, len, nameCount = 0;

	printe(2); printPet(num); printe(1); printm(petName(num)); printe(2);
	printm("Do you want to buy this pet ?");

	if (petCheck == 1) {
		setColor(4);
		printm("Your old pet will be replaced");	
		setColor(3);
	}

	printm("\n  Yes(Y)\t\t\t\t    No(N)\n\n");

	FILE *pet;

	do {
		key = getch();
		
		if (key == 'y' || key == 'Y') {
			CLEAR;
			price = petPrice(num);

			if (coins >= price) {
				coins -= price;
				nameLoop:
				printe(2); printPet(num); printe(2);
				printm("What name do you want to call your pet ?");
				printf("\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
				printf("\t\t   %c %-10s %c\n", 186, name, 186);
				printf("\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
				
				key = getch();
				len = strlen(name);

				if (key != 13) {
					if (len <= 9) {
						if (key == '\b') {
							CLEAR;
							name[nameCount] = 0;
							if (nameCount >= 1) nameCount--;
							name[nameCount] = 0;
							goto nameLoop;
						} else {
							CLEAR;
							name[nameCount] = key;
							nameCount++;
							goto nameLoop;
						}
					} else {
						if (key == '\b') {
							CLEAR;
							name[nameCount] = 0;
							if (nameCount >= 2) nameCount--;
							name[nameCount] = 0;
							goto nameLoop;
						} else {
							CLEAR;
							goto nameLoop;
						}
					}
				} else {
					if (len == 0) {
						CLEAR;
						goto nameLoop;
					}
				}

				time_t now = time(NULL);
				struct tm *now_tm = localtime(&now);

				int currentYear = now_tm->tm_year + 1900;
				int currentMonth = now_tm->tm_mon + 1;
				int currentDay = now_tm->tm_mday;

				if (currentUser == 1) pet = fopen("User/User1/PetName.txt", "w");
				else if (currentUser == 2) pet = fopen("User/User2/PetName.txt", "w");
				else if (currentUser == 3) pet = fopen("User/User3/PetName.txt", "w");

				fprintf(pet, "%s#%d#%d#%d#%d", name, num, currentDay, currentMonth, currentYear);
				fclose(pet);

				if (currentUser == 1) pet = fopen("User/User1/PetStatus.txt", "w");
				else if (currentUser == 2) pet = fopen("User/User2/PetStatus.txt", "w");
				else if (currentUser == 3) pet = fopen("User/User3/PetStatus.txt", "w");

				fprintf(pet, "1");
				fclose(pet);

				if (currentUser == 1) pet = fopen("User/User1/Coin.txt", "w");
				else if (currentUser == 2) pet = fopen("User/User2/Coin.txt", "w");
				else if (currentUser == 3) pet = fopen("User/User3/Coin.txt", "w");

				fprintf(pet, "%d", coins);
				fclose(pet);

				CLEAR;
				printe(2); printPet(num); printe(2);
				prints("Congratulations, %s is yours now.", name); printe(1);

				petCheck = 1;
				PAUSE; CLEAR;
				gamePlay();
				exit(0);
			} else {
				CLEAR;
				printe(2); sadPrint(currentLevel); printe(2);
				printm("Sorry, there are not enough Chi to buy this pet."); printe(1);
				PAUSE; CLEAR;
				petPreview();
				exit(0);
			}
		} else if (key == 'n' || key == 'N') {
			CLEAR;
			petPreview();
			exit(0);
		}
		
	} while(true);
}
	
void petPreview(){
	int num = 1;

	printPet(1);
	for (int i = 0; i < 18; i++) printf(" ");
	for (int i = 0; i < 15; i++) printf("%c", 219);
	for (int i = 0; i < 18; i++) printf(" ");
	printe(2);
	printm(petName(1));
	printChi(petPrice(1));

	pet:
	printe(2);
	printf(" <(A)                 Back(B)                 (D)> \n");
	printe(1);
	printm("Purchase(R)");
	
	do {
		key = getch();
		
		if (key == 'a' || key == 'A') {
			if (num > 1) num--;
			CLEAR;
			printPet(num);
			for (int i = 0; i < 18; i++) printf(" ");
			for (int i = 0; i < 15; i++) printf("%c", 219);
			for (int i = 0; i < 18; i++) printf(" ");
			printe(2);
			printm(petName(num));
			printChi(petPrice(num));
			goto pet;
		} else if (key == 'd' || key == 'D') {
			if (num < 5) num++;
			CLEAR;
			printPet(num);
			for (int i = 0; i < 18; i++) printf(" ");
			for (int i = 0; i < 15; i++) printf("%c", 219);
			for (int i = 0; i < 18; i++) printf(" ");
			printe(2);
			printm(petName(num));
			printChi(petPrice(num));
			goto pet;
		} else if (key == 'b' || key == 'B') {
			CLEAR;
			chooseCategory();
			exit(0);
		} else if (key == 'r' || key == 'R') {
			CLEAR;
			purchasePet(num);
			printm(petName(num));
			printChi(petPrice(num));
			exit(0);
		}
	} while(true);
}

void pet(){
	printe(1); printm("Here's our pet list!"); printe(1);
	printf(
	"    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
	"    %c                 ,*--.                   %c\n"
	"    %c                 |   |        __      _  %c\n" 
	"    %c     .-.         |'-'|      o'')}____//  %c\n"
	"    %c    /'v'\\        |   |       `_/      )  %c\n"
	"    %c   (/___\\)       .___|       (_(_/-(_/   %c\n"
	"    %c                                         %c\n"
	"    %c    Cichi       Gretchi        Dochi     %c\n"
	"    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
	, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	
	printf(
	"    %c           ___                           %c\n" 
	"    %c      ,,  // \\\\         |\\__/,|   (`\\    %c\n"
	"    %c     (_,\\/ \\_/ \\        |_ _  |.--.) )   %c\n"
	"    %c       \\ \\_/_\\_/>       ( T   )     /    %c\n"
	"    %c       /_/  /_/        (((^_(((/(((_/    %c\n"
	"    %c                                         %c\n"
	"    %c        Turchi              Nechi        %c\n"
	"    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
	, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	
	printe(1);
	PAUSE; CLEAR;
	petPreview();
}
// GotchoShop (End)

// MiniGames (Start)
int getNumber(){
	char answer[100];
	int countNumber = 0;

	do {
		char key = getch();

		if (key == 13) {
			break;
		} else if (key == '-') {
			if (countNumber == 0) {
				answer[countNumber] = '-';
				printf("-");
				countNumber++;
			}
		} else if (key >= '0' && key <= '9') {
			answer[countNumber] = key;
			printf("%c", key);
			countNumber++;
		} else if (key == 8) {
			if (countNumber != 0) {
				answer[countNumber] = '\0';
				printf("\b \b");
				countNumber--;
			}
		}
	} while(true);

	return atoi(answer);
}

void mathGame(){
	printe(2); happyPrint(currentLevel); printe(2);
	printm("Are you ready to play ?");
	printf("\n  Yes(Y)\t\t\t\t    No(N)\n\n");

	do {
		key = getch();
		
		if (key == 'y' || key == 'Y') {
			CLEAR;
			break;
			exit(0);
		} else if (key == 'n' || key == 'N') {
			CLEAR;
			chooseGame();
			exit(0);
		}
	} while(true);

	int x, y, num, answer, total, correct = 0, streak = 0, max = 0;

	for (int i = 1; i <= 5; i++) {
		printf(" Question %d\n\n", i);
		num = (rand() % 3) + 1;
		
		if (num == 1) {
			x = (rand() % 300) + 1;
			y = (rand() % 300) + 1;

			printf(" %d + %d = ", x, y);
			answer = getNumber();
			printe(1);

			if (x + y == answer) {
				setColor(2);
				printf(" Great! your answer is correct.\n\n");
				correct += 2;
				streak++;
			} else {
				setColor(4);
				printf(" I think that's a wrong answer.\n");
				printf(" The correct answer is %d.\n\n", x + y);
				streak = 0;
			}
		} else if (num == 2) {
			x = (rand() % 300) + 1;
			y = (rand() % 300) + 1;

			printf(" %d - %d = ", x, y);
			answer = getNumber();
			printe(1);
			
			if (x - y == answer) {
				setColor(2);
				printf(" Good job! You better join Math Competition.\n\n");
				correct += 2;
				streak++;
			} else {
				setColor(4);
				printf(" Oops, your answer is incorrect.\n");
				printf(" The correct answer is %d.\n\n", x - y);
				streak = 0;
			}
		} else {
			x = (rand() % 15) + 1;
			y = (rand() % 15) + 1;
			
			printf(" %d x %d = ", x, y);
			answer = getNumber();
			printe(1);
			
			if (x * y == answer) {
				setColor(2);
				printf(" Amazing, what a perfect answer!\n\n");
				correct += 2;
				streak++;
			} else {
				setColor(4);
				printf(" It's okay, it's quite hard.\n");
				printf(" The correct answer is %d.\n\n", x * y);
				streak = 0;
			}
		}

		if (streak > max) max = streak;
		
		if (streak > 0) {
			setColor(4);
			printf("     %c\n    %c%c%c\n  %c%c%c %c\n %c%c   %c%c\n  %c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
			printf("   Streak x%d\n\n", streak);
		}

		setColor(3);
		PAUSE; CLEAR;
	}

	printe(2);
	
	if (correct == 0) {
		total = 0;
		prints("Unfortunately, %s doesn't get any Chi & XP.", userName);
	} else {
		total = correct * max;
		prints("Nice, %s got", userName);
	}
	
	coins += total;
	currentExp += total;
	happyBar += 5;
	cleanBar -= 5;
	energyBar -= 3;
	hungryBar -= 3;

	if (happyBar > 100) happyBar = 100;
	if (cleanBar < 0) cleanBar = 0;
	if (hungryBar < 0) hungryBar = 0;

	printf("\n\t\t\t%c%c%c\n", 219, 219, 219);
	printf("\t\t      %c C %c %d\n", 219, 219, correct);
	printf("\t\t      %c%c%c\n", 219, 219, 219);
	printf("\n\t\t       %c %c \n\t\t      E %c P %d\n\t\t       %c %c \n\n", 219, 219, 219, correct, 219, 219);	
	PAUSE; CLEAR;

	if (max > 1) {
		printe(2);
		printd("Bonus Chi for %dx streak", max);
		printf("\n\t\t\t%c%c%c\n", 219, 219, 219);
		printf("\t\t      %c C %c %d x%d\n", 219, 219, correct, max);
		printf("\t\t      %c%c%c\n", 219, 219, 219);
		printf("\n\t\t       %c %c \n\t\t      E %c P %d x%d\n\t\t       %c %c \n\n", 219, 219, 219, correct, max, 219, 219);
		PAUSE; CLEAR;
		
		printe(2);
		prints("%s got a total of", userName);
		printf("\n\t\t\t%c%c%c\n", 219, 219, 219);
		printf("\t\t      %c C %c %d\n", 219, 219, total);
		printf("\t\t      %c%c%c\n", 219, 219, 219);
		printf("\n\t\t       %c %c \n\t\t      E %c P %d\n\t\t       %c %c \n\n", 219, 219, 219, total, 219, 219);
		PAUSE; CLEAR;
	}

	gamePlay();
	exit(0);
}

void rpsGame(){
	printe(2); happyPrint(currentLevel); printe(2);
	printm("Are you ready to play ?");
	printf("\n  Yes(Y)\t\t\t\t    No(N)\n\n");

	do {
		key = getch();
		
		if (key == 'y' || key == 'Y') {
			CLEAR;
			break;
			exit(0);
		} else if (key == 'n' || key == 'N') {
			CLEAR;
			chooseGame();
			exit(0);
		}
	} while(true);

	int num, point = 0, streak = 0, max = 0, total, check;

	for (int i = 1; i <= 5; i++) {
		printf(" Round %d\n", i);
		printm(" What do you want to use ?\n");
		happyPrint(currentLevel);
		printe(2); printm("Rock(R) Paper(T) Scissors(Y)"); printe(2);

		check = 0;
		
		while (check == 0) {
			key = getch();

			if (key == 'r' || key == 'R') {
				check = 1;
			} else if (key == 't' || key == 'T') {
				check = 2;
			} else if (key == 'y' || key == 'Y') {
				check = 3;
			}
		}
			
		printf("\t    Opponent is choosing "); ss printf(". "); ss printf(". "); ss printf(". "); ss printe(1);
		CLEAR;
		
		num = (rand() % 3) + 1; // 1 = Rock, 2 = Paper, 3 = Scissors

		if (check == 1) {
			if (num == 1) {
				printe(3); neutralPrint(currentLevel); printe(2);
				printm("Opponent chooses Rock.");
				printm("It's a tie!\n");
				point++;
				streak = 0;
			} else if (num == 2) {
				printe(3); sadPrint(currentLevel); printe(2);
				printm("Opponent chooses Paper.");
				printm("You lose!\n");
				streak = 0;
			} else {
				printe(3); happyPrint(currentLevel); printe(2);
				printm("Opponent chooses Scissors.");
				printm("You win!\n");
				point += 2;
				streak++;
			}
		} else if (check == 2) {
			if (num == 1) {
				printe(3); happyPrint(currentLevel); printe(2);
				printm("Opponent chooses Rock.");
				printm("You win!\n");
				point += 2;
				streak++;
			} else if (num == 2) {
				printe(3); neutralPrint(currentLevel); printe(2);
				printm("Opponent chooses Paper.");
				printm("It's a tie!\n");
				point++;
				streak = 0;
			} else {
				printe(3); sadPrint(currentLevel); printe(2);
				printm("Opponent chooses Scissors.");
				printm("You lose!\n");
				streak = 0;
			} 
		} else if (check == 3) {
			if (num == 1) {
				printe(3); sadPrint(currentLevel); printe(2);
				printm("Opponent chooses Rock.");
				printm("You lose!\n");
				streak = 0;
			} else if (num == 2) {
				printe(3); happyPrint(currentLevel); printe(2);
				printm("Opponent chooses Paper.");
				printm("You win!\n");
				point += 2;
				streak++;
			} else {
				printe(3); neutralPrint(currentLevel); printe(2);
				printm("Opponent chooses Scissors.");
				printm("It's a tie!\n");
				point++;
				streak = 0;
			}
		}
		
		if (streak > max) max = streak;
		
		if (streak > 0) {
			setColor(4);
			printf("     %c\n    %c%c%c\n  %c%c%c %c\n %c%c   %c%c\n  %c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
			printf("   Streak x%d\n\n", streak);
		}

		setColor(3);
		PAUSE; CLEAR;
	}

	printe(2);

	if (point <= 0) {
		total = 0;
		prints("Unfortunately, %s doesn't get any Chi & XP.", userName);
	} else {
		total = point * max * 2;
		prints("Nice, %s got", userName);
	}
	
	coins += total;
	currentExp += total;
	happyBar += 5;
	cleanBar -= 5;
	energyBar -= 3;
	hungryBar -= 3;

	if (happyBar > 100) happyBar = 100;
	if (cleanBar < 0) cleanBar = 0;
	if (hungryBar < 0) hungryBar = 0;
	
	printf("\n\t\t\t%c%c%c\n", 219, 219, 219);
	if (point <= 0) printf("\t\t      %c C %c 0\n", 219, 219);
	else printf("\t\t      %c C %c %d\n", 219, 219, point * 2);
	printf("\t\t      %c%c%c\n", 219, 219, 219);
	if (point <= 0) printf("\n\t\t       %c %c \n\t\t      E %c P 0\n\t\t       %c %c \n\n", 219, 219, 219, 219, 219);
	else printf("\n\t\t       %c %c \n\t\t      E %c P %d\n\t\t       %c %c \n\n", 219, 219, 219, point * 2, 219, 219);	
	PAUSE; CLEAR;

	if (max > 1) {
		printe(2);
		printd("Bonus Chi for %dx streak", max);
		printf("\n\t\t\t%c%c%c\n", 219, 219, 219);
		printf("\t\t      %c C %c %d x%d\n", 219, 219, point * 2, max);
		printf("\t\t      %c%c%c\n", 219, 219, 219);
		printf("\n\t\t       %c %c \n\t\t      E %c P %d x%d\n\t\t       %c %c \n\n", 219, 219, 219, point * 2, max, 219, 219);
		PAUSE; CLEAR;

		printe(2);
		prints("%s got a total of", userName);
		printf("\n\t\t\t%c%c%c\n", 219, 219, 219);
		printf("\t\t      %c C %c %d\n", 219, 219, total);
		printf("\t\t      %c%c%c\n", 219, 219, 219);
		printf("\n\t\t       %c %c \n\t\t      E %c P %d\n\t\t       %c %c \n\n", 219, 219, 219, total, 219, 219);
		PAUSE; CLEAR;
	}

	gamePlay();
	exit(0);
}

void printBlock(int color, int num, int timeSleep){
	setColor(color);
	printe(5);
	
	for (int i = 0; i < 11; i++) {
		if (i == 5) {
			printf("\t       %c%c%c%c%c%c%c%c%c%c%d%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, num, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
		} else {
			printf("\t       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
		}
	}

	printe(2);
	Sleep(timeSleep); CLEAR;
	setColor(3);
}

void colorGame(){
	printe(2); happyPrint(currentLevel); printe(2);
	printm("Are you ready to play ?");
	printf("\n  Yes(Y)\t\t\t\t    No(N)\n\n");

	do {
		key = getch();
		
		if (key == 'y' || key == 'Y') {
			CLEAR;
			break;
			exit(0);
		} else if (key == 'n' || key == 'N') {
			CLEAR;
			chooseGame();
			exit(0);
		}
	} while(true);

	int num, answer, correct = 0, total, max = 0, streak = 0, point = 1, block = 1, timeSleep = 1000;

	if (currentLevel > 20) {
		for (int i = 3; i > 0; i--) {
			printe(10);
			printd("Game will start in %d", i);
			Sleep(1000);
			CLEAR;
		}

		for (int round = 1; round <= 5; round++) {
			printe(10);
			printd("Round #%d", round);
			printd("%d color(s)", block);
			Sleep(1500);
			CLEAR;

			int colorList[block + 1];

			for (int i = 1; i <= block; i++) {
				num = (rand() % 7) + 1; // 1 = Blue, 2 = Green, 3 = Gray, 4 = Red, 5 = Purple, 6 = Yellow, 7 = White
				colorList[i] = num;
	
				if (num == 1) printBlock(1, i, timeSleep);
				else if (num == 2) printBlock(2, i, timeSleep);
				else if (num == 3) printBlock(8, i, timeSleep);
				else if (num == 4) printBlock(4, i, timeSleep);
				else if (num == 5) printBlock(5, i, timeSleep);
				else if (num == 6) printBlock(6, i, timeSleep);
				else printBlock(7, i, timeSleep);
			}
	
			for (int i = 1; i <= block; i++) {
				printe(2); printd("Color %d", i); printe(3);
				setColor(1); printf("\t\t  Blue(1)  ");
				setColor(2); printf("Green(2)\n\n");
				setColor(8); printf("\t     Gray(3)   ");
				setColor(4); printf("Red(4)  ");
				setColor(5); printf("Purple(5)\n\n");
				setColor(6); printf("\t\tYellow(6)  ");
				setColor(7); printf("White(7)\n");
				setColor(3);
	
				do {
					key = getch();
	
					if (key == '1') {
						answer = 1;
						break;
					} else if (key == '2') {
						answer = 2;
						break;
					} else if (key == '3') {
						answer = 3;
						break;
					} else if (key == '4') {
						answer = 4;
						break;
					} else if (key == '5') {
						answer = 5;
						break;
					} else if (key == '6') {
						answer = 6;
						break;
					} else if (key == '7') {
						answer = 7;
						break;
					}
				} while(true);
				
				if (colorList[i] != answer) {
					CLEAR;
					streak = 0;
					printe(2); sadPrint(currentLevel); printe(2);
					setColor(4);
					printm("Sorry, your guess is wrong.");
					printm("The correct order should be :"); printe(1);

					for (int i = 1; i <= block; i++) {
						if (colorList[i] == 1) {
							setColor(1);
							printm("Blue");
						} else if (colorList[i] == 2) {
							setColor(2);
							printm("Green");
						} else if (colorList[i] == 3) {
							setColor(8);
							printm("Gray");
						} else if (colorList[i] == 4) {
							setColor(4);
							printm("Red");
						} else if (colorList[i] == 5) {
							setColor(5);
							printm("Purple");
						} else if (colorList[i] == 6) {
							setColor(6);
							printm("Yellow");
						} else {
							setColor(7);
							printm("White");
						}
					}

					printe(1);
					setColor(3);
					PAUSE; CLEAR;
					break;
				}
	
				if (i == block) {
					CLEAR;
					streak++;
					correct += point;
					printe(2); happyPrint(currentLevel); printe(2);
					setColor(2);
					printm("What a good memorization!"); printe(1);
					setColor(3);
					PAUSE; CLEAR;

					if (streak > max) max = streak;
				}
				
				CLEAR;
			}
			
			point++;
			timeSleep += 50;
			block += 2;
		}
		
		printe(2);

		if (correct <= 0) {
			total = 0;
			prints("Unfortunately, %s doesn't get any Chi & XP.", userName);
		} else {
			total = correct * 2 * max;
			prints("Nice, %s got", userName);
		}
		
		coins += total;
		currentExp += total;
		happyBar += 5;
		cleanBar -= 5;
		energyBar -= 3;
		hungryBar -= 3;

		if (happyBar > 100) happyBar = 100;
		if (cleanBar < 0) cleanBar = 0;
		if (hungryBar < 0) hungryBar = 0;

		printf("\n\t\t\t%c%c%c\n", 219, 219, 219);
		if (correct <= 0) printf("\t\t      %c C %c 0\n", 219, 219);
		else printf("\t\t      %c C %c %d\n", 219, 219, correct * 2);
		printf("\t\t      %c%c%c\n", 219, 219, 219);
		if (correct <= 0) printf("\n\t\t       %c %c \n\t\t      E %c P 0\n\t\t       %c %c \n\n", 219, 219, 219, 219, 219);
		else printf("\n\t\t       %c %c \n\t\t      E %c P %d\n\t\t       %c %c \n\n", 219, 219, 219, correct * 2, 219, 219);	
		PAUSE; CLEAR;

		if (max > 1) {
			printe(2);
			printd("Bonus Chi for %dx streak", max);
			printf("\n\t\t\t%c%c%c\n", 219, 219, 219);
			printf("\t\t      %c C %c %d x%d\n", 219, 219, correct * 2, max);
			printf("\t\t      %c%c%c\n", 219, 219, 219);
			printf("\n\t\t       %c %c \n\t\t      E %c P %d x%d\n\t\t       %c %c \n\n", 219, 219, 219, correct * 2, max, 219, 219);
			PAUSE; CLEAR;
			
			printe(2);
			prints("%s got a total of", userName);
			printf("\n\t\t\t%c%c%c\n", 219, 219, 219);
			printf("\t\t      %c C %c %d\n", 219, 219, total);
			printf("\t\t      %c%c%c\n", 219, 219, 219);
			printf("\n\t\t       %c %c \n\t\t      E %c P %d\n\t\t       %c %c \n\n", 219, 219, 219, total, 219, 219);
			PAUSE; CLEAR;
		}
	} else {
		printe(2); neutralPrint(currentLevel); printe(2);
		printm("Sorry, you need to be level 20 to unlock this game."); printe(1);
		PAUSE; CLEAR;
	}

	gamePlay();
	exit(0);
}

void chooseGame(){
	printe(2); happyPrint(currentLevel); printe(2);
	printm("Choose a game that you want to play!");
	printe(1);
	printm("Math Quiz(1)");
	printm("Rock Paper Scissors(2)");
	printm("Memorize The Color(3)");
	printm("Back(B) ");
	printe(2);

	do {
		key = getch();

		if (key == '1') {
			CLEAR;
			mathGame();
			exit(0);
		} else if (key == '2') {
			CLEAR;
			rpsGame();
			exit(0);
		} else if (key == '3') {
			CLEAR;
			colorGame();
			exit(0);
		} else if (key == 'b' || key == 'B') {
			CLEAR;
			gamePlay();
			exit(0);
		}
	} while(true);
}

void miniGames(){
	printe(5);
	printm(" _______");
	printm("|.-----.|");
	printm("||     ||");
	printm("||_____/|");
	printm("| +   o |");
	printm("|  _ _  |");
	printm("|_______/");
	printe(1); printm("Welcome to MiniGames!"); printe(2);
	Sleep(1000); CLEAR;
	chooseGame();
}
// MiniGames (End)

// Room (Start)
void bedRoom(){
	setColor(4);
	printm("Bedroom"); printe(1);
	setColor(3);

	if (sleepCheck == 1) {
		sleepPrint(currentLevel);
		printe(1); prints("%s is sleeping now.", userName);
	} else {
		validateFace();
	}

	setColor(4);
	for (int i = 0; i < 51; i++) printf("%c", 220);
	printe(1);
	chooseRoom();
	printm("Sleep(E)");
	printm("Wake Up(R)");
	setColor(3);

	time_t now = time(NULL);
	struct tm *now_tm = localtime(&now);

	int year, month, day, hour, minute, health, energy;
	int currentYear = now_tm->tm_year + 1900;
	int currentMonth = now_tm->tm_mon + 1;
	int currentDay = now_tm->tm_mday;
	int currentHour = now_tm->tm_hour;
	int currentMinute = now_tm->tm_min;

	FILE *sleep;

	do {
		key = getch();
		
		if ((key == 'e' || key == 'E') && sleepCheck == 0) {
			if (currentUser == 1) {
				sleep = fopen("User/User1/Time.txt", "w");
			} else if (currentUser == 2) {
				sleep = fopen("User/User2/Time.txt", "w");
			} else {
				sleep = fopen("User/User3/Time.txt", "w");
			}
			
			fprintf(sleep, "%d#%d#%d#%d#%d", currentYear, currentMonth, currentDay, currentHour, currentMinute);
			fclose(sleep);
			
			sleepCheck = 1;
			CLEAR;
			gamePlay();
			exit(0);
		} else if ((key == 'r' || key == 'R') && sleepCheck == 1) {
			if (currentUser == 1) sleep = fopen("User/User1/Time.txt", "r");
			else if (currentUser == 2) sleep = fopen("User/User2/Time.txt", "r");
			else sleep = fopen("User/User3/Time.txt", "r");
			
			fscanf(sleep, "%d#%d#%d#%d#%d", &year, &month, &day, &hour, &minute);
			fclose(sleep);
			
			// 12 minutes -> increase 1% (20 hours required -> 100%)
			health = checkTimeConsumption(year, month, day, hour, minute, 20);
			if (health == -1) health = 100;
			else health /= 12;

			// 3 minutes -> increase 1% (5 hours required -> 100%)
			energy = checkTimeConsumption(year, month, day, hour, minute, 5);
			if (energy == -1) energy = 100;
			else energy /= 3;

			healthBar += health;
			energyBar += energy;

			if (healthBar > 100) healthBar = 100;
			if (energyBar > 100) energyBar = 100;
			if (energyBar <= 20) printf("\a");
			sleepCheck = 0;

			CLEAR;
			gamePlay();
			exit(0);
		} else if ((key == 'a' || key == 'A') && sleepCheck == 0) {
			if (room > 1) room--;
			CLEAR;
			gamePlay();
			exit(0);
		} else if ((key == 'd' || key == 'D') && sleepCheck == 0) {
			if (room < 5) room++;
			CLEAR;
			gamePlay();
			exit(0);
		} else if (key == 27) {
			saveExitUser();
			exit(0);
		}
	} while(true);
}

void bathRoom(){
	setColor(1);
	printm("Bathroom"); printe(1);
	setColor(3);
	validateFace();
	setColor(1);
	for (int i = 0; i < 51; i++) printf("%c", 220);
	printe(1);
	chooseRoom();
	printm("Take a Bath(E)");
	setColor(3);

	do {
		key = getch();
		
		if (key == 'a' || key == 'A') {
			if (room > 1) room--;
			CLEAR;
			gamePlay();
			exit(0);
		} else if (key == 'd' || key == 'D') {
			if (room < 5) room++;
			CLEAR;
			gamePlay();
			exit(0);
		} else if (key == 'e' || key == 'E') {
			cleanBar = 100;
			CLEAR;
			printe(2); neutralPrint(currentLevel); printe(2);
			prints("%s is ready to take a bath.", userName); printe(1);
			PAUSE; CLEAR;

			printe(2); shockPrint(currentLevel); printe(2);
			printm("Hey, don't look at me."); printe(1);
			PAUSE; CLEAR;

			printe(2); happyPrint(currentLevel); printe(2);
			prints("%s is clean now.", userName); printe(1);
			PAUSE; CLEAR;

			gamePlay();
			exit(0);
		} else if (key == 27) {
			saveExitUser();
			exit(0);
		}
	} while(true);
}

void mainRoom(){
	setColor(2);
	printm("Main Room"); printe(1);
	setColor(3);
	validateFace();
	setColor(2);
	for (int i = 0; i < 51; i++) printf("%c", 220);
	printe(1);
	chooseRoom();
	printm("Status Bar(E)");
	printm("Current Time(R)");
	setColor(3);

	do {
		key = getch();

		if (key == 'r' || key == 'R') {
			CLEAR;
			showDateTime();
			exit(0);
		} else if (key == 'e' || key == 'E') {
			CLEAR;
			statusBar();
			exit(0);
		} else if (key == 27) {
			saveExitUser();
			exit(0);
		} else if (key == 'a' || key == 'A') {
			if (room > 1) room--;
			CLEAR;
			gamePlay();
			exit(0);
		} else if (key == 'd' || key == 'D') {
			if (room < 5) room++;
			CLEAR;
			gamePlay();
			exit(0);
		}
	} while(true);
}

void playground(){
	setColor(6);
	printm("Playground"); printe(1);
	setColor(3);
	validateFace();
	setColor(6);
	for (int i = 0; i < 51; i++) printf("%c", 220);
	printe(1);
	chooseRoom();
	printm("Minigames(E)");
	printm("Pet Info(R)");
	setColor(3);

	do {
		key = getch();

		if (key == 'e' || key == 'E') {
			CLEAR;

			if (energyBar >= 10) {
				miniGames();
				exit(0);
			} else {
				setColor(3);
				printe(2); sadPrint(currentLevel); printe(2);
				prints("I think %s is tired.", userName);
				printm("Better let him sleep.");
				printe(1);
				setColor(3);
				PAUSE;
			}

			CLEAR;
			gamePlay();
			exit(0);
		} else if (key == 'r' || key == 'R') {
			if (petCheck == 1) {
				char name[20];
				int num, day, month, year;

				FILE *pet;

				if (currentUser == 1) pet = fopen("User/User1/PetName.txt", "r");
				else if (currentUser == 2) pet = fopen("User/User2/PetName.txt", "r");
				else if (currentUser == 3) pet = fopen("User/User3/PetName.txt", "r");

				fscanf(pet, "%[^#]#%d#%d#%d#%d", &name, &num, &day, &month, &year);
				fclose(pet);

				CLEAR;
				printPet(num); printe(1);
				setColor(1); printm("Pet Name"); setColor(3);
				prints("%s", name); printe(1);
				setColor(1); printm("Adopted Date"); setColor(3);

				printf("\t\t     ");
				if (day < 10) printf("0");
				printf("%d-", day);

				if (month < 10) printf("0");
				printf("%d-%d\n\n", month, year);

				setColor(1); printm("Species"); setColor(3);

				if (num == 1 || num == 2) {
					if (num == 1) printm("Gretchi"); 
					else printm("Cichi");
					printe(1);
					setColor(1); printm("Rarity"); setColor(3);
					printm("Common");
				} else if (num == 3 || num == 4) {
					if (num == 1) printm("Dochi");
					else printm("Turchi");
					printe(1);
					setColor(1); printm("Rarity"); setColor(3);
					printm("Rare");
				} else {
					printm("Nechi");
					printe(1);
					setColor(1); printm("Rarity"); setColor(3);
					printm("Legendary");
				}

				printe(2);
				printm("Back(B)");

				do {
					key = getch();

					if (key == 'b' || key == 'B') {
						CLEAR;
						gamePlay();
						exit(0);
					}
				} while(true);
			} else {
				CLEAR;
				printe(2); neutralPrint(currentLevel); printe(2);
				prints("Seems like %s doesn't have a pet.", userName); printe(1);
				PAUSE; CLEAR;
				gamePlay();
				exit(0);
			}
		} else if (key == 'a' || key == 'A') {
			if (room > 1) room--;
			CLEAR;
			gamePlay();
			exit(0);
		} else if (key == 'd' || key == 'D') {
			if (room < 5) room++;
			CLEAR;
			gamePlay();
			exit(0);
		} else if (key == 27) {
			saveExitUser();
			exit(0);
		}
	} while(true);
}

void kitchen(){
	setColor(5);
	printm("Kitchen"); printe(1);
	setColor(3);
	validateFace();
	setColor(5);
	for (int i = 0; i < 51; i++) printf("%c", 220);
	printe(1);
	chooseRoom();
	printm("Gotcho Shop(E)");
	printm("Inventory(R)");
	setColor(3);
	
	do {
		key = getch();

		if (key == 'e' || key == 'E') {
			CLEAR;
			gotchoShop();
			exit(0);
		} else if (key == 'r' || key == 'R') {
			CLEAR;
			inventoryMenu();
			exit(0);
		}else if (key == 'a' || key == 'A') {
			if (room > 1) room--;
			CLEAR;
			gamePlay();
			exit(0);
		} else if (key == 'd' || key == 'D') {
			if (room < 5) room++;
			CLEAR;
			gamePlay();
			exit(0);
		} else if (key == 27) {
			saveExitUser();
			exit(0);
		}
	} while(true);
}
// Room (End)

void inventoryMenu(){
	setScrollableWindowSize();

	if (!scanInventoryUser(currentUser - 1)) {
		printe(2); neutralPrint(currentLevel); printe(2);
		printm("Looks like your inventory is empty.");
		printe(1);
		PAUSE; CLEAR;
		setWindowSize();
		gamePlay();
		exit(0);
	} else {
		int type = 0, j = 1;

		scanInventoryUser(currentUser - 1);
		printe(1); prints("%s's Inventory", userName); printe(1);

		for (int i = 0; i < sizeItem; i++) {
			if (inventory[currentUser - 1][i].jumlah != 0) {
				if (j < 10) {
					printf(" %d. %-20sQ %d\n", j, inventory[currentUser - 1][i].nama, inventory[currentUser - 1][i].jumlah);
				} else if (j < 100) {
					printf(" %d. %-19sQ %d\n", j, inventory[currentUser - 1][i].nama, inventory[currentUser - 1][i].jumlah);
				} else if (j < 1000) {
					printf(" %d. %-18sQ %d\n", j, inventory[currentUser - 1][i].nama, inventory[currentUser - 1][i].jumlah);
				} else {
					printf(" %d. %-17sQ %d\n", j, inventory[currentUser - 1][i].nama, inventory[currentUser - 1][i].jumlah);
				}

				choosedInventory[j - 1].jenis = inventory[currentUser - 1][i].jenis;
				strcpy(choosedInventory[j - 1].nama, inventory[currentUser - 1][i].nama);
				choosedInventory[j - 1].jumlah = inventory[currentUser - 1][i].jumlah;
				choosedInventory[j - 1].healthBar = inventory[currentUser - 1][i].healthBar;
				choosedInventory[j - 1].happyBar = inventory[currentUser - 1][i].happyBar;
				choosedInventory[j - 1].cleanBar = inventory[currentUser - 1][i].cleanBar;
				choosedInventory[j - 1].energyBar = inventory[currentUser - 1][i].energyBar;
				choosedInventory[j - 1].hungryBar = inventory[currentUser - 1][i].hungryBar;
				j++;
			}
		}

		printe(2);
		printm("Eat/Drink(E)");
		printm("Back(B)");

		do {
			key = getch();

			if (key == 'e' || key == 'E') {
				int pil;

				do {
					printf("\nItem Number : ");
					pil = getNumber();

					if (pil >= j || pil == 0) {
						CLEAR;
						printe(2); neutralPrint(currentLevel); printe(2);
						printd("Item no %d is not available on our list.", pil);
						printe(1);
						PAUSE; CLEAR;
						inventoryMenu();
						exit(0);
					} else {
						break;
					}
				} while(true);

				CLEAR;

				healthBar += choosedInventory[pil - 1].healthBar;
				if (healthBar > 100) healthBar = 100;
				else if (healthBar < 0) healthBar = 0;

				happyBar += choosedInventory[pil - 1].happyBar;
				if (happyBar > 100) happyBar = 100;
				else if (happyBar < 0) happyBar = 0;

				cleanBar += choosedInventory[pil - 1].cleanBar;
				if (cleanBar > 100) cleanBar = 100;
				else if (cleanBar < 0) cleanBar = 0;

				energyBar += choosedInventory[pil - 1].energyBar;
				if (energyBar > 100) energyBar = 100;
				else if (energyBar < 0) energyBar = 0;

				hungryBar += choosedInventory[pil - 1].hungryBar;
				if (hungryBar > 100) hungryBar = 100;
				else if (hungryBar < 0) hungryBar = 0;

				setColor(7);
				printe(2);
				printm("Your health bar has been updated.");

				if(choosedInventory[pil - 1].healthBar > 0) {
					printd("+ %d", choosedInventory[pil - 1].healthBar);	
					printe(2); happyPrint(currentLevel); printe(2);
				}else{
					printd("- %d", abs(choosedInventory[pil - 1].healthBar));	
					printe(2); sadPrint(currentLevel); printe(2);
				}

				printStatusBar(healthBar);
				Sleep(1000);
				CLEAR;

				printe(2);
				printm("Your happiness bar has been updated.");

				if(choosedInventory[pil - 1].happyBar > 0) {
					printd("+ %d", choosedInventory[pil - 1].happyBar);	
					printe(2); happyPrint(currentLevel); printe(2);
				}else{
					printd("- %d", abs(choosedInventory[pil - 1].happyBar));	
					printe(2); sadPrint(currentLevel); printe(2);
				}

				printStatusBar(happyBar);
				Sleep(1000);
				CLEAR;

				printe(2);
				printm("Your cleanliness bar has been updated.");

				if(choosedInventory[pil - 1].cleanBar > 0) {
					printd("+ %d", choosedInventory[pil - 1].cleanBar);	
					printe(2); happyPrint(currentLevel); printe(2);
				}else{
					printd("- %d", abs(choosedInventory[pil - 1].cleanBar));	
					printe(2); sadPrint(currentLevel); printe(2);
				} 

				printStatusBar(cleanBar);
				Sleep(1000);
				CLEAR;

				printe(2);
				printm("Your energy bar has been updated.");

				if(choosedInventory[pil - 1].energyBar > 0) {
					printd("+ %d", choosedInventory[pil - 1].energyBar);	
					printe(2); happyPrint(currentLevel); printe(2);
				}else{
					printd("- %d", abs(choosedInventory[pil - 1].energyBar));	
					printe(2); sadPrint(currentLevel); printe(2);
				} 

				printStatusBar(energyBar);
				Sleep(1000);
				CLEAR;

				printe(2);
				printm("Your hunger bar has been updated.");

				if(choosedInventory[pil - 1].hungryBar > 0) {
					printd("+ %d", choosedInventory[pil - 1].hungryBar);	
					printe(2); happyPrint(currentLevel); printe(2);
				}else{
					printd("- %d", abs(choosedInventory[pil - 1].hungryBar));	
					printe(2); sadPrint(currentLevel); printe(2);
				} 

				printStatusBar(hungryBar);
				setColor(3);
				Sleep(1000);
				CLEAR;

				for(int i = 0; i < sizeItem; i++){
					if(strcmp(choosedInventory[pil - 1].nama, inventory[currentUser - 1][i].nama) == 0){
						inventory[currentUser - 1][i].jumlah--;
						break;
					}
				}

				FILE *inven;

				if(currentUser == 1) inven = fopen("User/User1/Inventory.txt", "w");
				else if(currentUser == 2) inven = fopen("User/User2/Inventory.txt", "w");
				else if(currentUser == 3) inven = fopen("User/User3/Inventory.txt", "w");

				for(int j = 0; j < sizeItem; j++){
					if(j != sizeItem - 1) fprintf(inven, "%d#%s#%d#%d#%d#%d#%d#%d\n", inventory[currentUser - 1][j].jenis, inventory[currentUser - 1][j].nama, inventory[currentUser - 1][j].jumlah, inventory[currentUser - 1][j].healthBar, inventory[currentUser - 1][j].happyBar, inventory[currentUser - 1][j].cleanBar, inventory[currentUser - 1][j].energyBar, inventory[currentUser - 1][j].hungryBar);
					else fprintf(inven, "%d#%s#%d#%d#%d#%d#%d#%d", inventory[currentUser - 1][j].jenis, inventory[currentUser - 1][j].nama, inventory[currentUser - 1][j].jumlah, inventory[currentUser - 1][j].healthBar, inventory[currentUser - 1][j].happyBar, inventory[currentUser - 1][j].cleanBar, inventory[currentUser - 1][j].energyBar, inventory[currentUser - 1][j].hungryBar);
				}

				fclose(inven);

				setWindowSize();
				gamePlay();
				exit(0);
			} else if (key == 'b' || key == 'B') {
				CLEAR;
				setWindowSize();
				gamePlay();
				exit(0);
			}
		} while(true);
	}
}

void intro(){
	printe(2); happyPrint(1); printe(2);
	prints("Congratulations, %s has been born safely.", userName);
	printe(1);
	PAUSE; CLEAR;

	printe(2); happyPrint(1); printe(2);
	prints("Take care your %s to keep him smiling :)", userName);
	printe(1);
	PAUSE; CLEAR;

	printe(4);
	printf("\t\t\t%c%c%c\n", 219, 219, 219);
	printf("\t\t      %c C %c 100\n", 219, 219);
	printf("\t\t      %c%c%c\n", 219, 219, 219);
	printe(2);
	prints("This is your first reward, %s.", userName);
	printe(1);
	PAUSE; CLEAR;

	gamePlay();
	exit(0);
}

void welcomeBack(){
	welcomeCheck = 1;

	printe(2); happyPrint(currentLevel); printe(2);
	prints("Welcome back, %s miss you.", userName);

	Sleep(1000); CLEAR;
	gamePlay();
}

void levelUp(){
	int level = 0, exp;
	
	currentLevel++;
	currentExp = currentExp - maxExp;
	coins += currentLevel * 30;

	FILE *xp = fopen("Level/Level.txt", "r");
	while (level <= currentLevel) {
		fscanf(xp, "%d#%d\n", &level, &exp);
		level++;
	}
	fclose(xp);

	maxExp = exp;

	CLEAR;
	printe(2);

	if (currentLevel == 21) {
		happyPrint(21);
		printe(2);
		prints("%s has grown up. I have become an adult!", userName);
		printm("Thank you for taking care of me this much."); printe(1);
		PAUSE; CLEAR;
	}
	
	printe(2); happyPrint(currentLevel); printe(2);

	prints("Congratulations, %s level up!", userName);
	printf("\n\t\tLevel %d -> Level %d\n\n", currentLevel - 1, currentLevel);
	PAUSE; CLEAR;
	
	printe(2); happyPrint(currentLevel); printe(2);
	
	prints("Here's an extra Chi for %s.", userName);
	printf("\n\t\t\t%c%c%c\n", 219, 219, 219);
	printf("\t\t      %c C %c %d\n", 219, 219, currentLevel * 30);
	printf("\t\t      %c%c%c\n\n", 219, 219, 219);
	PAUSE; CLEAR;
	
	gamePlay();
}

void gamePlay(){
	if (currentLevel == 50 && currentExp >= maxExp) {
		printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf(" %c MAX %c %-10s %c\t\t\t %c%c%c\n", 186, 186, userName, 186, 219, 219, 219);
		setColor(1);
		printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t\t       %c C %c ", 204, 205, 205, 205, 205, 203, 202, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 188, 219, 219);
	} else {
		printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf(" %c %-2d %c %-10s %c\t\t\t %c%c%c\n", 186, currentLevel, 186, userName, 186, 219, 219, 219);
		setColor(1);
		printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t\t       %c C %c ", 204, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 188, 219, 219);
	}

	setColor(3);

	if (coins < 1000) {
		printf("%d\n", coins);
	} else if (coins < 10000) {
		printf("%d.%dK\n", coins / 1000, (coins % 1000) / 100);
	} else if (coins < 100000) {
		printf("%d.%dK\n", coins / 1000, (coins % 1000) / 100);
	} else if (coins < 1000000) {
		printf("%dK\n", coins / 1000);
	} else {
		printf("%d.%dM\n", coins / 1000000, (coins % 1000000) / 100000);
	}

	if (currentLevel == 50 && currentExp >= maxExp) {
		printf(" %c XP %c %-3d/%-3d %c\t\t       %c%c%c\n", 186, 186, maxExp, maxExp, 186, 219, 219, 219);
	} else {
		while (currentExp >= maxExp) levelUp();
		printf(" %c XP %c %-3d/%-3d %c\t\t       %c%c%c\n", 186, 186, currentExp, maxExp, 186, 219, 219, 219);
	}

	printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	
	if (welcomeCheck == 0) welcomeBack();

	if (room == 1) bedRoom();
	else if (room == 2) bathRoom();
	else if (room == 3) mainRoom();
	else if (room == 4) playground();
	else if (room == 5) kitchen();
}

int main(){
	SetConsoleTitle("                                                                                                              G  O  P  O  T  C  H  I");
	setWindowSize();
	setFontSize();
	srand(time(0));

	scanBar0(); scanBar5(); scanBar10(); scanBar15();
	scanBar20(); scanBar25(); scanBar30(); scanBar35();
	scanBar40(); scanBar45(); scanBar50(); scanBar55(); 
	scanBar60(); scanBar65(); scanBar70(); scanBar75(); 
	scanBar80(); scanBar85(); scanBar90(); scanBar95(); scanBar100();

	badMoodSmallScan(); sadSmallScan(); neutralSmallScan(); shockSmallScan();
	sickSmallScan(); deadSmallScan(); happySmallScan(); moneySmallScan();
	badMoodBigScan(); sadBigScan(); neutralBigScan(); shockBigScan();
	sickBigScan(); deadBigScan(); happyBigScan(); moneyBigScan();

	scanGotchoShop();
	scanGotchoAscPrice();
	scanGotchoDescPrice();
	scanGotchoAscName();
	scanGotchoDescName();
	scanInventoryUser(0);
	scanInventoryUser(1);
	scanInventoryUser(2);
	scanDefaultInventory();

	levelScan();
	loadingScreen();
	mainMenu();

	return 0;
}
