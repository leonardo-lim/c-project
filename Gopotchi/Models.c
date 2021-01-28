#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#define barX 22
#define barY 3
#define faceX 11
#define faceY 7
#define posEye 3
#define leftEye 3
#define rightEye 7
#define sleepEye 246
#define sizeItem 43
#define PAUSE system("pause")
#define CLEAR system("cls")

struct badMoodSmall {
	int face[faceY][faceX];
} badMoodSmall;

struct sadSmall {
	int face[faceY][faceX];
} sadSmall;

struct neutralSmall {
	int face[faceY][faceX];
} neutralSmall;

struct shockSmall {
	int face[faceY][faceX];
} shockSmall;

struct sickSmall {
	int face[faceY][faceX];
} sickSmall;

struct deadSmall {
	int face[faceY][faceX];
} deadSmall;

struct happySmall {
	int face[faceY][faceX];
} happySmall;

struct moneySmall {
	int face[faceY][faceX];
} moneySmall;

struct badMoodBig {
	int face[faceY][faceX];
} badMoodBig;

struct sadBig {
	int face[faceY][faceX];
} sadBig;

struct neutralBig {
	int face[faceY][faceX];
} neutralBig;

struct shockBig {
	int face[faceY][faceX];
} shockBig;

struct sickBig {
	int face[faceY][faceX];
} sickBig;

struct deadBig {
	int face[faceY][faceX];
} deadBig;

struct happyBig {
	int face[faceY][faceX];
} happyBig;

struct moneyBig {
	int face[faceY][faceX];
} moneyBig;

struct bar0 {
	int bar[barY][barX];
} bar0;

struct bar5 {
	int bar[barY][barX];
} bar5;

struct bar10 {
	int bar[barY][barX];
} bar10;

struct bar15 {
	int bar[barY][barX];
} bar15;

struct bar20 {
	int bar[barY][barX];
} bar20;

struct bar25 {
	int bar[barY][barX];
} bar25;

struct bar30 {
	int bar[barY][barX];
} bar30;

struct bar35 {
	int bar[barY][barX];
} bar35;

struct bar40 {
	int bar[barY][barX];
} bar40;

struct bar45 {
	int bar[barY][barX];
} bar45;

struct bar50 {
	int bar[barY][barX];
} bar50;

struct bar55 {
	int bar[barY][barX];
} bar55;

struct bar60 {
	int bar[barY][barX];
} bar60;

struct bar65 {
	int bar[barY][barX];
} bar65;

struct bar70 {
	int bar[barY][barX];
} bar70;

struct bar75 {
	int bar[barY][barX];
} bar75;

struct bar80 {
	int bar[barY][barX];
} bar80;

struct bar85 {
	int bar[barY][barX];
} bar85;

struct bar90 {
	int bar[barY][barX];
} bar90;

struct bar95 {
	int bar[barY][barX];
} bar95;

struct bar100 {
	int bar[barY][barX];
} bar100;

struct shop {
	char nama[20];
	int jenis, harga, healthBar, happyBar, cleanBar, energyBar, hungryBar;
} shop[10][sizeItem];

struct printedShop {
	char nama[20];
	int jenis, harga, healthBar, happyBar, cleanBar, energyBar, hungryBar;
} printedShop[sizeItem];

struct inventory {
	char nama[20];
	int jenis, jumlah, healthBar, happyBar, cleanBar, energyBar, hungryBar;
} inventory[3][sizeItem];

struct defaultInventory {
	char nama[20];
	int jenis, jumlah, healthBar, happyBar, cleanBar, energyBar, hungryBar;
} defaultInventory[sizeItem];

struct choosedInventory {
	char nama[20];
	int jenis, jumlah, healthBar, happyBar, cleanBar, energyBar, hungryBar;
} choosedInventory[sizeItem];

struct level {
	int lvl, exp;
} level[50];

int item, searchedItem, checkShop = 1;

void setColor(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

// Print Function (Start)
void printm(char text[]){
	int space, len;
	
	len = strlen(text);
	space = (51 - len) / 2;
	
	if (len % 2 == 0) space++;
	
	for (int i = 0; i < space; i++) printf(" ");
	printf("%s\n", text);
}

void prints(char text[], char name[]){
	int space, add, len, len2, totalLen, i = 0;
	
	len = strlen(text);
	len2 = strlen(name);
	totalLen = len + len2;

	space = (51 - (totalLen - 2)) / 2;
	if (totalLen % 2 == 0) space++;

	for (int i = 0; i < space; i++) printf(" ");

	while (true) {
		if (text[i] == '%' && text[i + 1] == 's') {
			add = i + 2;
			break;
		} else {
			printf("%c", text[i]);
			i++;
		}
	}

	printf("%s", name);

	while (add < len) {
		printf("%c", text[add]);
		add++;
	}

	printf("\n");
}

void printd(char text[], int value){
	int space, add, len, len2, totalLen, i = 0;
	char num[10];
	
	itoa(value, num, 10);
	len = strlen(text);
	len2 = strlen(num);
	totalLen = len + len2;

	space = (51 - (totalLen - 2)) / 2;
	if (totalLen % 2 == 0) space++;

	for (int i = 0; i < space; i++) printf(" ");

	while (true) {
		if (text[i] == '%' && text[i + 1] == 'd') {
			add = i + 2;
			break;
		} else {
			printf("%c", text[i]);
			i++;
		}
	}

	printf("%s", num);

	while (add < len) {
		printf("%c", text[add]);
		add++;
	}

	printf("\n");
}

void printe(int num){
	while (num--) printf("\n");
}

void printChi(int coins){
	printf("\n\t\t\t%c%c%c\n", 219, 219, 219);
	printf("\t\t      %c C %c %d\n", 219, 219, coins);		
	printf("\t\t      %c%c%c\n", 219, 219, 219);
}
// Print Function (End)

// Windows Function (Start)
void setWindowSize(){
	system("mode 51, 23");
	SMALL_RECT WinRect = {0, 0, 1000, 1000};
	SMALL_RECT* WinSize = &WinRect;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);
}

void setScrollableWindowSize(){
	system("mode 51, 55");
	SMALL_RECT WinRect = {0, 0, 50, 22};
	SMALL_RECT* WinSize = &WinRect;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);
}

void setFontSize(){
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    fontInfo.dwFontSize.X = 15;
    fontInfo.dwFontSize.Y = 31;
    fontInfo.FontWeight = 600;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &fontInfo);
}
// Windows Function (End)

void levelScan(){
	FILE *lvl = fopen("Level/Level.txt", "r");
	int i = 0;
	while (fscanf(lvl, "%d#%d\n", &level[i].lvl, &level[i].exp) != EOF) {
		i++;
	}
	fclose(lvl);
}

void badMoodSmallScan(){
	FILE *op = fopen("Models/Small/BadMood.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &badMoodSmall.face[i][0], &badMoodSmall.face[i][1], &badMoodSmall.face[i][2], &badMoodSmall.face[i][3], &badMoodSmall.face[i][4], &badMoodSmall.face[i][5], &badMoodSmall.face[i][6], &badMoodSmall.face[i][faceY], &badMoodSmall.face[i][8], &badMoodSmall.face[i][9], &badMoodSmall.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void badMoodPrint(int level){
	int j, k;

	setColor(5);
	if(level <= 20){
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", badMoodSmall.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}else{
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", badMoodBig.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}
	setColor(3);
}

void sadSmallScan(){
	FILE *op = fopen("Models/Small/Sad.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &sadSmall.face[i][0], &sadSmall.face[i][1], &sadSmall.face[i][2], &sadSmall.face[i][3], &sadSmall.face[i][4], &sadSmall.face[i][5], &sadSmall.face[i][6], &sadSmall.face[i][faceY], &sadSmall.face[i][8], &sadSmall.face[i][9], &sadSmall.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void sadPrint(int level){
	setColor(1);
	int j, k;
	if(level <= 20){
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", sadSmall.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}else{
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", sadBig.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}
	setColor(3);
}

void neutralSmallScan(){
	FILE *op = fopen("Models/Small/Neutral.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &neutralSmall.face[i][0], &neutralSmall.face[i][1], &neutralSmall.face[i][2], &neutralSmall.face[i][3], &neutralSmall.face[i][4], &neutralSmall.face[i][5], &neutralSmall.face[i][6], &neutralSmall.face[i][faceY], &neutralSmall.face[i][8], &neutralSmall.face[i][9], &neutralSmall.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void neutralPrint(int level){
	int j, k;
	if(level <= 20){
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", neutralSmall.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}else{
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", neutralBig.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}
}

void shockSmallScan(){
	FILE *op = fopen("Models/Small/Shock.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &shockSmall.face[i][0], &shockSmall.face[i][1], &shockSmall.face[i][2], &shockSmall.face[i][3], &shockSmall.face[i][4], &shockSmall.face[i][5], &shockSmall.face[i][6], &shockSmall.face[i][faceY], &shockSmall.face[i][8], &shockSmall.face[i][9], &shockSmall.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void shockPrint(int level){
	int j, k;
	setColor(4);
	if(level <= 20){
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", shockSmall.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}else{
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", shockBig.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}
	setColor(3);
}

void sickSmallScan(){
	FILE *op = fopen("Models/Small/Sick.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &sickSmall.face[i][0], &sickSmall.face[i][1], &sickSmall.face[i][2], &sickSmall.face[i][3], &sickSmall.face[i][4], &sickSmall.face[i][5], &sickSmall.face[i][6], &sickSmall.face[i][faceY], &sickSmall.face[i][8], &sickSmall.face[i][9], &sickSmall.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void sickPrint(int level){
	int j, k;
	setColor(2);
	if(level <= 20){
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", sickSmall.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}else{
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", sickBig.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}
	setColor(3);
}

void deadSmallScan(){
	FILE *op = fopen("Models/Small/Dead.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &deadSmall.face[i][0], &deadSmall.face[i][1], &deadSmall.face[i][2], &deadSmall.face[i][3], &deadSmall.face[i][4], &deadSmall.face[i][5], &deadSmall.face[i][6], &deadSmall.face[i][faceY], &deadSmall.face[i][8], &deadSmall.face[i][9], &deadSmall.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void deadPrint(int level){
	int j, k;
	setColor(8);
	if(level <= 20){
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", deadSmall.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}else{
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", deadBig.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}
	setColor(3);
}

void happySmallScan(){
	FILE *op = fopen("Models/Small/Happy.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &happySmall.face[i][0], &happySmall.face[i][1], &happySmall.face[i][2], &happySmall.face[i][3], &happySmall.face[i][4], &happySmall.face[i][5], &happySmall.face[i][6], &happySmall.face[i][faceY], &happySmall.face[i][8], &happySmall.face[i][9], &happySmall.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void happyPrint(int level){
	int j, k;
	setColor(6);
	if(level <= 20){
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", happySmall.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}else{
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", happyBig.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}
	setColor(3);
}

void sleepPrint(int level){
	int j, k;
	setColor(1);
	if(level <= 20){
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				if (j == posEye && (k == leftEye || k == rightEye)) printf("%c", sleepEye);
				else printf("%c", happySmall.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}else{
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				if (j == posEye && (k == leftEye || k == rightEye)) printf("%c", sleepEye);
				else printf("%c", happyBig.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}
	setColor(3);
}

void moneySmallScan(){
	FILE *op = fopen("Models/Small/Money.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &moneySmall.face[i][0], &moneySmall.face[i][1], &moneySmall.face[i][2], &moneySmall.face[i][3], &moneySmall.face[i][4], &moneySmall.face[i][5], &moneySmall.face[i][6], &moneySmall.face[i][faceY], &moneySmall.face[i][8], &moneySmall.face[i][9], &moneySmall.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void moneyPrint(int level){
	int j, k;
	setColor(2);
	if(level <= 20){
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", moneySmall.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}else{
		for(j = 0; j < faceY; j++){
			printf("\t\t    ");
			for(k = 0; k < faceX; k++){
				printf("%c", moneyBig.face[j][k]);
			}
			if(j == 6){
				continue;
			}else{
				puts("");
			}
		}
	}
	setColor(3);
}

void badMoodBigScan(){
	FILE *op = fopen("Models/Big/BadMood.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &badMoodBig.face[i][0], &badMoodBig.face[i][1], &badMoodBig.face[i][2], &badMoodBig.face[i][3], &badMoodBig.face[i][4], &badMoodBig.face[i][5], &badMoodBig.face[i][6], &badMoodBig.face[i][faceY], &badMoodBig.face[i][8], &badMoodBig.face[i][9], &badMoodBig.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void sadBigScan(){
	FILE *op = fopen("Models/Big/Sad.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &sadBig.face[i][0], &sadBig.face[i][1], &sadBig.face[i][2], &sadBig.face[i][3], &sadBig.face[i][4], &sadBig.face[i][5], &sadBig.face[i][6], &sadBig.face[i][faceY], &sadBig.face[i][8], &sadBig.face[i][9], &sadBig.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void neutralBigScan(){
	FILE *op = fopen("Models/Big/Neutral.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &neutralBig.face[i][0], &neutralBig.face[i][1], &neutralBig.face[i][2], &neutralBig.face[i][3], &neutralBig.face[i][4], &neutralBig.face[i][5], &neutralBig.face[i][6], &neutralBig.face[i][faceY], &neutralBig.face[i][8], &neutralBig.face[i][9], &neutralBig.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void shockBigScan(){
	FILE *op = fopen("Models/Big/Shock.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &shockBig.face[i][0], &shockBig.face[i][1], &shockBig.face[i][2], &shockBig.face[i][3], &shockBig.face[i][4], &shockBig.face[i][5], &shockBig.face[i][6], &shockBig.face[i][faceY], &shockBig.face[i][8], &shockBig.face[i][9], &shockBig.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void sickBigScan(){
	FILE *op = fopen("Models/Big/Sick.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &sickBig.face[i][0], &sickBig.face[i][1], &sickBig.face[i][2], &sickBig.face[i][3], &sickBig.face[i][4], &sickBig.face[i][5], &sickBig.face[i][6], &sickBig.face[i][faceY], &sickBig.face[i][8], &sickBig.face[i][9], &sickBig.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void deadBigScan(){
	FILE *op = fopen("Models/Big/Dead.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &deadBig.face[i][0], &deadBig.face[i][1], &deadBig.face[i][2], &deadBig.face[i][3], &deadBig.face[i][4], &deadBig.face[i][5], &deadBig.face[i][6], &deadBig.face[i][faceY], &deadBig.face[i][8], &deadBig.face[i][9], &deadBig.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void happyBigScan(){
	FILE *op = fopen("Models/Big/Happy.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &happyBig.face[i][0], &happyBig.face[i][1], &happyBig.face[i][2], &happyBig.face[i][3], &happyBig.face[i][4], &happyBig.face[i][5], &happyBig.face[i][6], &happyBig.face[i][faceY], &happyBig.face[i][8], &happyBig.face[i][9], &happyBig.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void moneyBigScan(){
	FILE *op = fopen("Models/Big/Money.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d\n", &moneyBig.face[i][0], &moneyBig.face[i][1], &moneyBig.face[i][2], &moneyBig.face[i][3], &moneyBig.face[i][4], &moneyBig.face[i][5], &moneyBig.face[i][6], &moneyBig.face[i][faceY], &moneyBig.face[i][8], &moneyBig.face[i][9], &moneyBig.face[i][10]) != EOF){
		i++;
	}
	fclose(op);
}

void scanBar0(){
	FILE *op = fopen("Models/Bar/Bar0.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar0.bar[i][0], &bar0.bar[i][1], &bar0.bar[i][2], &bar0.bar[i][3], &bar0.bar[i][4], &bar0.bar[i][5], &bar0.bar[i][6], &bar0.bar[i][7], &bar0.bar[i][8], &bar0.bar[i][9], &bar0.bar[i][10], &bar0.bar[i][11], &bar0.bar[i][12], &bar0.bar[i][13], &bar0.bar[i][14], &bar0.bar[i][15], &bar0.bar[i][16], &bar0.bar[i][17], &bar0.bar[i][18], &bar0.bar[i][19], &bar0.bar[i][20], &bar0.bar[i][21]) != EOF){
		i++;
	}
}

void printBar0(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar0.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar5(){
	FILE *op = fopen("Models/Bar/Bar5.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar5.bar[i][0], &bar5.bar[i][1], &bar5.bar[i][2], &bar5.bar[i][3], &bar5.bar[i][4], &bar5.bar[i][5], &bar5.bar[i][6], &bar5.bar[i][7], &bar5.bar[i][8], &bar5.bar[i][9], &bar5.bar[i][10], &bar5.bar[i][11], &bar5.bar[i][12], &bar5.bar[i][13], &bar5.bar[i][14], &bar5.bar[i][15], &bar5.bar[i][16], &bar5.bar[i][17], &bar5.bar[i][18], &bar5.bar[i][19], &bar5.bar[i][20], &bar5.bar[i][21]) != EOF){
		i++;
	}
}

void printBar5(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar5.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar10(){
	FILE *op = fopen("Models/Bar/Bar10.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar10.bar[i][0], &bar10.bar[i][1], &bar10.bar[i][2], &bar10.bar[i][3], &bar10.bar[i][4], &bar10.bar[i][5], &bar10.bar[i][6], &bar10.bar[i][7], &bar10.bar[i][8], &bar10.bar[i][9], &bar10.bar[i][10], &bar10.bar[i][11], &bar10.bar[i][12], &bar10.bar[i][13], &bar10.bar[i][14], &bar10.bar[i][15], &bar10.bar[i][16], &bar10.bar[i][17], &bar10.bar[i][18], &bar10.bar[i][19], &bar10.bar[i][20], &bar10.bar[i][21]) != EOF){
		i++;
	}
}

void printBar10(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar10.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar15(){
	FILE *op = fopen("Models/Bar/Bar15.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar15.bar[i][0], &bar15.bar[i][1], &bar15.bar[i][2], &bar15.bar[i][3], &bar15.bar[i][4], &bar15.bar[i][5], &bar15.bar[i][6], &bar15.bar[i][7], &bar15.bar[i][8], &bar15.bar[i][9], &bar15.bar[i][10], &bar15.bar[i][11], &bar15.bar[i][12], &bar15.bar[i][13], &bar15.bar[i][14], &bar15.bar[i][15], &bar15.bar[i][16], &bar15.bar[i][17], &bar15.bar[i][18], &bar15.bar[i][19], &bar15.bar[i][20], &bar15.bar[i][21]) != EOF){
		i++;
	}
}

void printBar15(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar15.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar20(){
	FILE *op = fopen("Models/Bar/Bar20.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar20.bar[i][0], &bar20.bar[i][1], &bar20.bar[i][2], &bar20.bar[i][3], &bar20.bar[i][4], &bar20.bar[i][5], &bar20.bar[i][6], &bar20.bar[i][7], &bar20.bar[i][8], &bar20.bar[i][9], &bar20.bar[i][10], &bar20.bar[i][11], &bar20.bar[i][12], &bar20.bar[i][13], &bar20.bar[i][14], &bar20.bar[i][15], &bar20.bar[i][16], &bar20.bar[i][17], &bar20.bar[i][18], &bar20.bar[i][19], &bar20.bar[i][20], &bar20.bar[i][21]) != EOF){
		i++;
	}
}

void printBar20(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar20.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar25(){
	FILE *op = fopen("Models/Bar/Bar25.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar25.bar[i][0], &bar25.bar[i][1], &bar25.bar[i][2], &bar25.bar[i][3], &bar25.bar[i][4], &bar25.bar[i][5], &bar25.bar[i][6], &bar25.bar[i][7], &bar25.bar[i][8], &bar25.bar[i][9], &bar25.bar[i][10], &bar25.bar[i][11], &bar25.bar[i][12], &bar25.bar[i][13], &bar25.bar[i][14], &bar25.bar[i][15], &bar25.bar[i][16], &bar25.bar[i][17], &bar25.bar[i][18], &bar25.bar[i][19], &bar25.bar[i][20], &bar25.bar[i][21]) != EOF){
		i++;
	}
}

void printBar25(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar25.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar30(){
	FILE *op = fopen("Models/Bar/Bar30.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar30.bar[i][0], &bar30.bar[i][1], &bar30.bar[i][2], &bar30.bar[i][3], &bar30.bar[i][4], &bar30.bar[i][5], &bar30.bar[i][6], &bar30.bar[i][7], &bar30.bar[i][8], &bar30.bar[i][9], &bar30.bar[i][10], &bar30.bar[i][11], &bar30.bar[i][12], &bar30.bar[i][13], &bar30.bar[i][14], &bar30.bar[i][15], &bar30.bar[i][16], &bar30.bar[i][17], &bar30.bar[i][18], &bar30.bar[i][19], &bar30.bar[i][20], &bar30.bar[i][21]) != EOF){
		i++;
	}
}

void printBar30(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar30.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar35(){
	FILE *op = fopen("Models/Bar/Bar35.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar35.bar[i][0], &bar35.bar[i][1], &bar35.bar[i][2], &bar35.bar[i][3], &bar35.bar[i][4], &bar35.bar[i][5], &bar35.bar[i][6], &bar35.bar[i][7], &bar35.bar[i][8], &bar35.bar[i][9], &bar35.bar[i][10], &bar35.bar[i][11], &bar35.bar[i][12], &bar35.bar[i][13], &bar35.bar[i][14], &bar35.bar[i][15], &bar35.bar[i][16], &bar35.bar[i][17], &bar35.bar[i][18], &bar35.bar[i][19], &bar35.bar[i][20], &bar35.bar[i][21]) != EOF){
		i++;
	}
}

void printBar35(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar35.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar40(){
	FILE *op = fopen("Models/Bar/Bar40.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar40.bar[i][0], &bar40.bar[i][1], &bar40.bar[i][2], &bar40.bar[i][3], &bar40.bar[i][4], &bar40.bar[i][5], &bar40.bar[i][6], &bar40.bar[i][7], &bar40.bar[i][8], &bar40.bar[i][9], &bar40.bar[i][10], &bar40.bar[i][11], &bar40.bar[i][12], &bar40.bar[i][13], &bar40.bar[i][14], &bar40.bar[i][15], &bar40.bar[i][16], &bar40.bar[i][17], &bar40.bar[i][18], &bar40.bar[i][19], &bar40.bar[i][20], &bar40.bar[i][21]) != EOF){
		i++;
	}
}

void printBar40(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar40.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar45(){
	FILE *op = fopen("Models/Bar/Bar45.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar45.bar[i][0], &bar45.bar[i][1], &bar45.bar[i][2], &bar45.bar[i][3], &bar45.bar[i][4], &bar45.bar[i][5], &bar45.bar[i][6], &bar45.bar[i][7], &bar45.bar[i][8], &bar45.bar[i][9], &bar45.bar[i][10], &bar45.bar[i][11], &bar45.bar[i][12], &bar45.bar[i][13], &bar45.bar[i][14], &bar45.bar[i][15], &bar45.bar[i][16], &bar45.bar[i][17], &bar45.bar[i][18], &bar45.bar[i][19], &bar45.bar[i][20], &bar45.bar[i][21]) != EOF){
		i++;
	}
}

void printBar45(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar45.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar50(){
	FILE *op = fopen("Models/Bar/Bar50.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar50.bar[i][0], &bar50.bar[i][1], &bar50.bar[i][2], &bar50.bar[i][3], &bar50.bar[i][4], &bar50.bar[i][5], &bar50.bar[i][6], &bar50.bar[i][7], &bar50.bar[i][8], &bar50.bar[i][9], &bar50.bar[i][10], &bar50.bar[i][11], &bar50.bar[i][12], &bar50.bar[i][13], &bar50.bar[i][14], &bar50.bar[i][15], &bar50.bar[i][16], &bar50.bar[i][17], &bar50.bar[i][18], &bar50.bar[i][19], &bar50.bar[i][20], &bar50.bar[i][21]) != EOF){
		i++;
	}
}

void printBar50(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar50.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar55(){
	FILE *op = fopen("Models/Bar/Bar55.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar55.bar[i][0], &bar55.bar[i][1], &bar55.bar[i][2], &bar55.bar[i][3], &bar55.bar[i][4], &bar55.bar[i][5], &bar55.bar[i][6], &bar55.bar[i][7], &bar55.bar[i][8], &bar55.bar[i][9], &bar55.bar[i][10], &bar55.bar[i][11], &bar55.bar[i][12], &bar55.bar[i][13], &bar55.bar[i][14], &bar55.bar[i][15], &bar55.bar[i][16], &bar55.bar[i][17], &bar55.bar[i][18], &bar55.bar[i][19], &bar55.bar[i][20], &bar55.bar[i][21]) != EOF){
		i++;
	}
}

void printBar55(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar55.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar60(){
	FILE *op = fopen("Models/Bar/Bar60.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar60.bar[i][0], &bar60.bar[i][1], &bar60.bar[i][2], &bar60.bar[i][3], &bar60.bar[i][4], &bar60.bar[i][5], &bar60.bar[i][6], &bar60.bar[i][7], &bar60.bar[i][8], &bar60.bar[i][9], &bar60.bar[i][10], &bar60.bar[i][11], &bar60.bar[i][12], &bar60.bar[i][13], &bar60.bar[i][14], &bar60.bar[i][15], &bar60.bar[i][16], &bar60.bar[i][17], &bar60.bar[i][18], &bar60.bar[i][19], &bar60.bar[i][20], &bar60.bar[i][21]) != EOF){
		i++;
	}
}

void printBar60(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar60.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar65(){
	FILE *op = fopen("Models/Bar/Bar65.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar65.bar[i][0], &bar65.bar[i][1], &bar65.bar[i][2], &bar65.bar[i][3], &bar65.bar[i][4], &bar65.bar[i][5], &bar65.bar[i][6], &bar65.bar[i][7], &bar65.bar[i][8], &bar65.bar[i][9], &bar65.bar[i][10], &bar65.bar[i][11], &bar65.bar[i][12], &bar65.bar[i][13], &bar65.bar[i][14], &bar65.bar[i][15], &bar65.bar[i][16], &bar65.bar[i][17], &bar65.bar[i][18], &bar65.bar[i][19], &bar65.bar[i][20], &bar65.bar[i][21]) != EOF){
		i++;
	}
}

void printBar65(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar65.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar70(){
	FILE *op = fopen("Models/Bar/Bar70.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar70.bar[i][0], &bar70.bar[i][1], &bar70.bar[i][2], &bar70.bar[i][3], &bar70.bar[i][4], &bar70.bar[i][5], &bar70.bar[i][6], &bar70.bar[i][7], &bar70.bar[i][8], &bar70.bar[i][9], &bar70.bar[i][10], &bar70.bar[i][11], &bar70.bar[i][12], &bar70.bar[i][13], &bar70.bar[i][14], &bar70.bar[i][15], &bar70.bar[i][16], &bar70.bar[i][17], &bar70.bar[i][18], &bar70.bar[i][19], &bar70.bar[i][20], &bar70.bar[i][21]) != EOF){
		i++;
	}
}

void printBar70(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar70.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar75(){
	FILE *op = fopen("Models/Bar/Bar75.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar75.bar[i][0], &bar75.bar[i][1], &bar75.bar[i][2], &bar75.bar[i][3], &bar75.bar[i][4], &bar75.bar[i][5], &bar75.bar[i][6], &bar75.bar[i][7], &bar75.bar[i][8], &bar75.bar[i][9], &bar75.bar[i][10], &bar75.bar[i][11], &bar75.bar[i][12], &bar75.bar[i][13], &bar75.bar[i][14], &bar75.bar[i][15], &bar75.bar[i][16], &bar75.bar[i][17], &bar75.bar[i][18], &bar75.bar[i][19], &bar75.bar[i][20], &bar75.bar[i][21]) != EOF){
		i++;
	}
}

void printBar75(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar75.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar80(){
	FILE *op = fopen("Models/Bar/Bar80.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar80.bar[i][0], &bar80.bar[i][1], &bar80.bar[i][2], &bar80.bar[i][3], &bar80.bar[i][4], &bar80.bar[i][5], &bar80.bar[i][6], &bar80.bar[i][7], &bar80.bar[i][8], &bar80.bar[i][9], &bar80.bar[i][10], &bar80.bar[i][11], &bar80.bar[i][12], &bar80.bar[i][13], &bar80.bar[i][14], &bar80.bar[i][15], &bar80.bar[i][16], &bar80.bar[i][17], &bar80.bar[i][18], &bar80.bar[i][19], &bar80.bar[i][20], &bar80.bar[i][21]) != EOF){
		i++;
	}
}

void printBar80(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar80.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar85(){
	FILE *op = fopen("Models/Bar/Bar85.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar85.bar[i][0], &bar85.bar[i][1], &bar85.bar[i][2], &bar85.bar[i][3], &bar85.bar[i][4], &bar85.bar[i][5], &bar85.bar[i][6], &bar85.bar[i][7], &bar85.bar[i][8], &bar85.bar[i][9], &bar85.bar[i][10], &bar85.bar[i][11], &bar85.bar[i][12], &bar85.bar[i][13], &bar85.bar[i][14], &bar85.bar[i][15], &bar85.bar[i][16], &bar85.bar[i][17], &bar85.bar[i][18], &bar85.bar[i][19], &bar85.bar[i][20], &bar85.bar[i][21]) != EOF){
		i++;
	}
}

void printBar85(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar85.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar90(){
	FILE *op = fopen("Models/Bar/Bar90.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar90.bar[i][0], &bar90.bar[i][1], &bar90.bar[i][2], &bar90.bar[i][3], &bar90.bar[i][4], &bar90.bar[i][5], &bar90.bar[i][6], &bar90.bar[i][7], &bar90.bar[i][8], &bar90.bar[i][9], &bar90.bar[i][10], &bar90.bar[i][11], &bar90.bar[i][12], &bar90.bar[i][13], &bar90.bar[i][14], &bar90.bar[i][15], &bar90.bar[i][16], &bar90.bar[i][17], &bar90.bar[i][18], &bar90.bar[i][19], &bar90.bar[i][20], &bar90.bar[i][21]) != EOF){
		i++;
	}
}

void printBar90(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar90.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar95(){
	FILE *op = fopen("Models/Bar/Bar95.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar95.bar[i][0], &bar95.bar[i][1], &bar95.bar[i][2], &bar95.bar[i][3], &bar95.bar[i][4], &bar95.bar[i][5], &bar95.bar[i][6], &bar95.bar[i][7], &bar95.bar[i][8], &bar95.bar[i][9], &bar95.bar[i][10], &bar95.bar[i][11], &bar95.bar[i][12], &bar95.bar[i][13], &bar95.bar[i][14], &bar95.bar[i][15], &bar95.bar[i][16], &bar95.bar[i][17], &bar95.bar[i][18], &bar95.bar[i][19], &bar95.bar[i][20], &bar95.bar[i][21]) != EOF){
		i++;
	}
}

void printBar95(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar95.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void scanBar100(){
	FILE *op = fopen("Models/Bar/Bar100.txt", "r");
	int i = 0;
	while(fscanf(op, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &bar100.bar[i][0], &bar100.bar[i][1], &bar100.bar[i][2], &bar100.bar[i][3], &bar100.bar[i][4], &bar100.bar[i][5], &bar100.bar[i][6], &bar100.bar[i][7], &bar100.bar[i][8], &bar100.bar[i][9], &bar100.bar[i][10], &bar100.bar[i][11], &bar100.bar[i][12], &bar100.bar[i][13], &bar100.bar[i][14], &bar100.bar[i][15], &bar100.bar[i][16], &bar100.bar[i][17], &bar100.bar[i][18], &bar100.bar[i][19], &bar100.bar[i][20], &bar100.bar[i][21]) != EOF){
		i++;
	}
}

void printBar100(int pers){
	int j, k;
	for(j = 0; j < barY; j++){
		printf("\t      ");
		for(k = 0; k < barX; k++){
			printf("%c", bar100.bar[j][k]);
		}
		if(j == 1){
			printf(" %d %%", pers);
		}
		if(j == barY - 1){
			continue;
		}else{
			puts("");
		}
	}
}

void hatch(){
	char x[400] = "\n\n\n\t           xxxxxxxxxx\n\t          xxx       xxx\n\t         xxx        xxxxx\n\t        x            xxxx\n\t       x       xxx       x\n\t       x       xxx       x\n\t       xx               xx\n\t        xx             xx\n\t         xx      xxxxxxx\n\t        xxxxxxxxxxxxxxxxxx\n\n\t\t     Hold on!\n\t      The egg is cracking . . . ";
	char y[400] = "\n\n\n\n\t            xxxxxxxxxx\n\t          xxx        xxx\n\t         xxx         xxxxx\n\t        x             xxxx\n\t        x       xxx       x\n\t        x       xxx       x\n\t         xx              xx\n\t          xx       xxxxxxx\n\t         xxxxxxxxxxxxxxxxxx\n\n\t\t     Hold on!\n\t      The egg is cracking . . . ";
	
	int len;
	
	setColor(2);
	
	for (int j = 0; j < 3; j++) {
		len = strlen(x);

		for (int i = 0; i < len; i++) {
			if (x[i] == 'x') {
				printf("%c", 219);
			} else {
				printf("%c", x[i]);
			}
		}
		
		Sleep(700);
		CLEAR;
		
		len = strlen(y);
		
		for (int i = 0; i < len; i++) {
			if (y[i] == 'x') {
				printf("%c", 219);
			} else {
				printf("%c", y[i]);
			}
		}
		
		Sleep(1000);
		CLEAR;
	}
}

void loadingScreen(){
	setColor(4);
	printe(5);
	printm(".-\"-.");
	printm("_/.-.-.\\_");
	printm("( ( o o ) )");
	printm("G |/  \"  \\| G");
	printm("\\ .-. /");
	printm("/`\"\"\"`\\");
	printm("/       \\");
	printe(1); printBar0(0); printe(1);
	printm("Loading");
	Sleep(700); CLEAR;

	setColor(4);
	printe(5);
	printm(".-\"-.");
	printm("_/_-.-_\\_");
	printm("/ __} {__ \\");
	printm("O / //  \"  \\\\ \\ O");
	printm("/ / \\'---'/ \\ \\");
	printm("\\ \\_/`\"\"\"`\\_/ /");
	printm("\\           /");
	printe(1); printBar20(20); printe(1);
	printm("Loading");
	Sleep(700); CLEAR;

	setColor(6);
	printe(5);
	printm(".-\"-.");
	printm("_/.-.-.\\_");
	printm("/|( o o )|\\");
	printm("P | //  \"  \\\\ | P");
	printm("/ / \\'---'/ \\ \\");
	printm("\\ \\_/`\"\"\"`\\_/ /");
	printm("\\           /");
	printe(1); printBar40(40); printe(1);
	printm("Loading");
	Sleep(700); CLEAR;
	
	setColor(6);
	printe(5);
	printm(".-\"-.");
	printm("_/.-.-.\\_");
	printm("( ( o o ) )");
	printm("O |/  \"  \\| O");
	printm("\\'/^\\'/");
	printm("/`\\ /`\\");
	printm("/  /|\\  \\");
	printe(1); printBar60(60); printe(1);
	printm("Loading");
	Sleep(700); CLEAR;

	setColor(2);
	printe(5);
	printm(".-\"-.");
	printm("_/.-.-.\\_");
	printm("( ( o o ) )");
	printm("T |/  \"  \\| T");
	printm("\\ .-. /");
	printm("/`\"\"\"`\\");
	printm("/       \\");
	printe(1); printBar80(80); printe(1);
	printm("Loading");
	Sleep(700); CLEAR;

	setColor(2);
	printe(5);
	printm(".-\"-.");
	printm("_/_-.-_\\_");
	printm("/ __} {__ \\");
	printm("C H I / //  \"  \\\\ \\ C H I");
	printm("/ / \\'---'/ \\ \\");
	printm("\\ \\_/`\"\"\"`\\_/ /");
	printm("\\           /");
	printe(1); printBar100(100); printe(1);
	printm("Loading");
	Sleep(1000); CLEAR;
}

// Pet (Start)
void printPet(int num){
	printf("\n\n");

	if (num == 1) {
		printf(
			"\t\t       ,*--.\n" 
			"\t\t       |   |\n"
			"\t\t       |'-'|\n"
			"\t\t       |   |\n"
			"\t\t       .___|\n"
		);
	} else if (num == 2){	
		printf(
			"\n\n"
			"\t\t        .-.\n"
			"\t\t       /'v'\\\n"
			"\t\t      (/___\\)\n"
		);
	} else if (num == 3) {
		printf(
			"\n"
			"\t\t      __      _\n"
			"\t\t    o'')}____//\n"
			"\t\t    `_/      )\n"
			"\t\t     (_(_/-(_/\n"
		);
	} else if (num == 4) {
		printf(
			"\t\t         ___\n"
			"\t\t    ,,  // \\\\\n"
			"\t\t   (_,\\/ \\_/ \\\n"
			"\t\t     \\ \\_/_\\_/>\n"
			"\t\t     /_/  /_/\n"
		);
	} else {
		printf(
			"\n"
			"\t\t   |\\__/,|   (`\\\n"
			"\t\t   |_ _  |.--.) ).\n"
			"\t\t   ( T   )     /\n"
			"\t\t  (((^_(((/(((_/\n"
		);
	}
}

int petPrice(int num){
	int price;

	if (num == 1) price = 1000;
	else if (num == 2) price = 1500;
	else if (num == 3) price = 2500;
	else if (num == 4) price = 5000;
	else price = 15000;

	return price;
}

char *petName(int num){
	if (num == 1) return "Gretchi";
	else if (num == 2) return "Cichi";
	else if (num == 3) return "Dochi";
	else if (num == 4) return "Turchi";
	else return "Nechi";
}
// Pet (End)

// GotchoShop (Start)
void iSwap(int *a, int *b){
	int temp = *a; 
	*a = *b; 
	*b = temp;
}

void scanGotchoShop(){
	int i = 0, j;
	FILE *gs = fopen("Shop/Shop.txt", "r");
	
	while(fscanf(gs,"%d#%[^#]#%d#%d#%d#%d#%d#%d\n",&shop[0][i].jenis,&shop[0][i].nama,&shop[0][i].harga,&shop[0][i].healthBar,&shop[0][i].happyBar,&shop[0][i].cleanBar,&shop[0][i].energyBar,&shop[0][i].hungryBar) != EOF){	
		i++;
	}
	item = i;
	for(i = 1; i < 10; i++){
		for(j = 0; j < item; j++){
			shop[i][j].jenis = shop[0][j].jenis;
			strcpy(shop[i][j].nama, shop[0][j].nama);
			shop[i][j].harga = shop[0][j].harga;
			shop[i][j].healthBar = shop[0][j].healthBar;
			shop[i][j].happyBar = shop[0][j].happyBar;
			shop[i][j].cleanBar = shop[0][j].cleanBar;
			shop[i][j].energyBar = shop[0][j].energyBar;
			shop[i][j].hungryBar = shop[0][j].hungryBar;
		}
	}
}

void scanGotchoAscPrice(){
	int i,j,k;
	char temp[100];
	for(i=0; i<item-1; i++) {
		for(j=i+1; j<item; j++) {
			if(shop[1][j].harga < shop[1][i].harga) {
				iSwap(&shop[1][j].jenis, &shop[1][i].jenis);
				strcpy(temp, shop[1][i].nama);
				strcpy(shop[1][i].nama, shop[1][j].nama);
				strcpy(shop[1][j].nama, temp);
				iSwap(&shop[1][j].harga, &shop[1][i].harga);
				iSwap(&shop[1][j].healthBar, &shop[1][i].healthBar);
				iSwap(&shop[1][j].happyBar, &shop[1][i].happyBar);
				iSwap(&shop[1][j].cleanBar, &shop[1][i].cleanBar);
				iSwap(&shop[1][j].energyBar, &shop[1][i].energyBar);
				iSwap(&shop[1][j].hungryBar, &shop[1][i].hungryBar);
			}
		}
	}
}

void scanGotchoDescPrice(){
	int i,j,k;
	char temp[100];
	for(i = 0; i < item - 1; i++) {
		for(j = i + 1; j < item; j++) {
			if(shop[2][j].harga > shop[2][i].harga) {
				iSwap(&shop[2][j].jenis, &shop[2][i].jenis);
				strcpy(temp, shop[2][i].nama);
				strcpy(shop[2][i].nama, shop[2][j].nama);
				strcpy(shop[2][j].nama, temp);
				iSwap(&shop[2][j].harga, &shop[2][i].harga);
				iSwap(&shop[2][j].healthBar, &shop[2][i].healthBar);
				iSwap(&shop[2][j].happyBar, &shop[2][i].happyBar);
				iSwap(&shop[2][j].cleanBar, &shop[2][i].cleanBar);
				iSwap(&shop[2][j].energyBar, &shop[2][i].energyBar);
				iSwap(&shop[2][j].hungryBar, &shop[2][i].hungryBar);
			}
		}
	}
}

void scanGotchoAscName(){
	int i,j,k;
	char temp[100];
	for(i=0; i<item - 1; i++) {
		for(j=i+1; j<item; j++) {
			if(strcmp(shop[3][j].nama, shop[3][i].nama) < 0) {				
				iSwap(&shop[3][j].jenis, &shop[3][i].jenis);
				strcpy(temp, shop[3][i].nama);
				strcpy(shop[3][i].nama, shop[3][j].nama);
				strcpy(shop[3][j].nama, temp);
				iSwap(&shop[3][j].harga, &shop[3][i].harga);
				iSwap(&shop[3][j].healthBar, &shop[3][i].healthBar);
				iSwap(&shop[3][j].happyBar, &shop[3][i].happyBar);
				iSwap(&shop[3][j].cleanBar, &shop[3][i].cleanBar);
				iSwap(&shop[3][j].energyBar, &shop[3][i].energyBar);
				iSwap(&shop[3][j].hungryBar, &shop[3][i].hungryBar);
			}
		}
	}
}

void scanGotchoDescName(){
	int i,j,k;
	char temp[100];
	for(i=0; i<item - 1; i++) {
		for(j=i+1; j<item; j++) {
			if(strcmp(shop[4][j].nama, shop[4][i].nama) > 0) {
				iSwap(&shop[4][j].jenis, &shop[4][i].jenis);
				strcpy(temp, shop[4][i].nama);
				strcpy(shop[4][i].nama, shop[4][j].nama);
				strcpy(shop[4][j].nama, temp);
				iSwap(&shop[4][j].harga, &shop[4][i].harga);
				iSwap(&shop[4][j].healthBar, &shop[4][i].healthBar);
				iSwap(&shop[4][j].happyBar, &shop[4][i].happyBar);
				iSwap(&shop[4][j].cleanBar, &shop[4][i].cleanBar);
				iSwap(&shop[4][j].energyBar, &shop[4][i].energyBar);
				iSwap(&shop[4][j].hungryBar, &shop[4][i].hungryBar);
			}
		}
	}
}

void sortAll(int count, char search[], int type){
	int kata[sizeItem], temu;
	int number = 1;

	if(count != 0){
		for(int i = 0; i < item; i++) {
			kata[i] = strlen(shop[type][i].nama);
		}
		
		int huruf = strlen(search);
		
		checkShop = 0;
		
		for(int i=0; i < item; i++) {
			kata[i] = strlen(shop[type][i].nama);
		}

		huruf = strlen(search);
		checkShop = 0;

		for(int i=0; i<item; i++) {
			for(int j=0; j<kata[j]; j++) {
				temu = 1;
				for(int k=0; k<huruf; k++) {
					if(shop[type][i].nama[j+k] != search[k]) {
						temu = 0;
						break;
					}
				}

				if(temu == 1) {
					checkShop = 1;
					if (number < 10) {
						printf(" %d. %-20sC %d\n", number, shop[type][i].nama, shop[type][i].harga);
					} else if (number < 100) {
						printf(" %d. %-19sC %d\n", number, shop[type][i].nama, shop[type][i].harga);
					} else if (number < 1000) {
						printf(" %d. %-18sC %d\n", number, shop[type][i].nama, shop[type][i].harga);
					} else {
						printf(" %d. %-17sC %d\n", number, shop[type][i].nama, shop[type][i].harga);
					}
					printedShop[number - 1].jenis = shop[type][i].jenis;
					strcpy(printedShop[number - 1].nama, shop[type][i].nama);
					printedShop[number - 1].harga = shop[type][i].harga;
					printedShop[number - 1].healthBar = shop[type][i].healthBar;
					printedShop[number - 1].happyBar = shop[type][i].happyBar;
					printedShop[number - 1].cleanBar = shop[type][i].cleanBar;
					printedShop[number - 1].energyBar = shop[type][i].energyBar;
					printedShop[number - 1].hungryBar = shop[type][i].hungryBar;
					number++;
					break;	
				}		
			}
		}

		if (checkShop == 0) {
			printf("Sorry, %s is not available in GotchoShop.\n", search);
		}

		searchedItem = number - 1;
	}else{
		for(int i = 0; i < item; i++){
			if (i < 9) {
				printf(" %d. %-20sC %d\n", number, shop[type][i].nama, shop[type][i].harga);
			} else if (i < 99) {
				printf(" %d. %-19sC %d\n", number, shop[type][i].nama, shop[type][i].harga);
			} else if (i < 999) {
				printf(" %d. %-18sC %d\n", number, shop[type][i].nama, shop[type][i].harga);
			} else {
				printf(" %d. %-17sC %d\n", number, shop[type][i].nama, shop[type][i].harga);
			}

			printedShop[number - 1].jenis = shop[type][i].jenis;
			strcpy(printedShop[number - 1].nama, shop[type][i].nama);
			printedShop[number - 1].harga = shop[type][i].harga;
			printedShop[number - 1].healthBar = shop[type][i].healthBar;
			printedShop[number - 1].happyBar = shop[type][i].happyBar;
			printedShop[number - 1].cleanBar = shop[type][i].cleanBar;
			printedShop[number - 1].energyBar = shop[type][i].energyBar;
			printedShop[number - 1].hungryBar = shop[type][i].hungryBar;
			number++;
		}
		
		searchedItem = number - 1;
	}
}

bool scanInventoryUser(int userNow){
	int check = 0;

	FILE *shop;

	if (userNow == 0) shop = fopen("User/User1/Inventory.txt", "r");
	else if (userNow == 1) shop = fopen("User/User2/Inventory.txt", "r");
	else if (userNow == 2) shop = fopen("User/User3/Inventory.txt", "r");

	for(int i = 0; i < sizeItem; i++){
		fscanf(shop,"%d#%[^#]#%d#%d#%d#%d#%d#%d\n",&inventory[userNow][i].jenis,&inventory[userNow][i].nama,&inventory[userNow][i].jumlah,&inventory[userNow][i].healthBar,&inventory[userNow][i].happyBar,&inventory[userNow][i].cleanBar,&inventory[userNow][i].energyBar,&inventory[userNow][i].hungryBar);
		if (inventory[userNow][i].jumlah != 0) check = 1;
	}

	fclose(shop);

	if (check == 0) return false;
	else return true;
}

int scanDefaultInventory(){
	FILE *shop = fopen("Shop/DefaultInventory.txt", "r");

	for(int i = 0; i < sizeItem; i++){
		fscanf(shop,"%d#%[^#]#%d#%d#%d#%d#%d#%d\n",&defaultInventory[i].jenis,&defaultInventory[i].nama,&defaultInventory[i].jumlah,&defaultInventory[i].healthBar,&defaultInventory[i].happyBar,&defaultInventory[i].cleanBar,&defaultInventory[i].energyBar,&defaultInventory[i].hungryBar);
	}

	fclose(shop);
}
// GotchoShop (End)
