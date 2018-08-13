#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void showZodiacMenu ();  
int getZodiacIndexByYear (int year);
int getZodiacIndexByWord (string* animals, char* word);  
void UppercaseZodiac (char* z);  
void PrintZodiacByElement( string* animals, string* elements); 
void PrintZodiacCompatibility();

const int NUMSIGNS = 12;
const int WORDLEN = 80;
const int NUMELEMENTS = 5;

int main(){
	string zodAnimals[] = {"RAT", "OX", "TIGER", "RABBIT", "DRAGON", "SNAKE", "HORSE", "GOAT", "MONKEY", "ROOSTER", "DOG", "PIG"};
	string zodElements[] = {"water", "earth", "wood", "wood", "earth", "fire", "fire", "earth", "metal", "metal", "earth", "water"};
	int birthYearOne, birthYearTwo, choice;
	bool breakOut = false;
	char animalName[WORDLEN];
	
	srand(time(NULL));
	
	do{
	
	showZodiacMenu();
	cin >> choice;
	
		switch(choice){
			case 1:
					cout << "Enter your birth year: \n";
					cin >> birthYearOne;
					if(birthYearOne > 0){
						cout << "The zodiac animal for " << birthYearOne << " is " << zodAnimals[getZodiacIndexByYear(birthYearOne)] << endl;
						cout << "The element for " << birthYearOne << " is " << zodElements[getZodiacIndexByYear(birthYearOne)] << endl;
					}
					else {
						cout << "You have entered an invalid year.  Please pick again.\n";
						continue;
					}
					break;
			case 2:
					cout << "Enter person one's birth year: \n";
					cin >> birthYearOne;
					cout << "Enter person two's birth year: \n";
					cin >> birthYearTwo;
					if(birthYearOne <=0 || birthYearTwo <=0) {
						cout << "You have entered an invalid year.  Please pick again.\n";
						continue;
					}
					cout << "\nThe zodiac animal for person one is " << zodAnimals[getZodiacIndexByYear(birthYearOne)] << endl;
					cout << "The element for person one is " << zodElements[getZodiacIndexByYear(birthYearOne)] << endl;
					cout << "\nThe zodiac animal for person two is " << zodAnimals[getZodiacIndexByYear(birthYearTwo)] << endl;
					cout << "The element for person two is " << zodElements[getZodiacIndexByYear(birthYearTwo)] << endl;
					
					PrintZodiacCompatibility();
					
					break;
			case 3:
					cout << "Enter the name of a zodiac animal.\n";
					cin >> animalName;
					if(getZodiacIndexByWord(zodAnimals, animalName) >=0)
						cout << "The element of " << animalName << " is " << zodElements[getZodiacIndexByWord(zodAnimals, animalName)] << endl;
					else {
						cout << "That is not the name of a zodiac animal.  Please enter a valid name.\n";
						continue;
					}
					break;
			case 4:
					PrintZodiacByElement(zodAnimals, zodElements);
					break;
			case 5:
					breakOut = true;
					break;
			default:
					cout << "Invalid input.  Try again.\n";
					break;
			
		}
		if(breakOut) break;
		
	}while(choice !=5);
	
	return 0;
}

void showZodiacMenu (){
	cout << "\n\nWelcome to the Chinese Zodiac Program!\n";
	cout << "What would you like to do?\n";
	cout << "\t1.  Find out your Zodiac Animal and Element from your birth year.\n";
	cout << "\t2.  Find out the Zodiac Animals, Elements, and Compatibility of two\n\t    people from their birth years.\n";
	cout << "\t3.  Find out the Zodiac element of an Animal.\n";
	cout << "\t4.  Print out the Zodiac Animals by Element.\n";
	cout << "\t5.  Quit.\n";
}

int getZodiacIndexByYear (int year){
	
	return ((year+8)%12);
	
}

int getZodiacIndexByWord (string* animals, char* word){
	string* A = animals;
	char* W = word;
	
	for(int i=0; i<WORDLEN; i++,W++)
		UppercaseZodiac(W);
	W=word;
	
	
	for(int i=0; i<NUMSIGNS; i++, A++)
	{
		if(W==*A)
			return i;
	}
	return -1;
}

void UppercaseZodiac (char* z){
	
		*z = toupper(*z);	
}

void PrintZodiacByElement( string* animals, string* elements){
	string* A, *E;
	int j = 1;
	
	while(j<=5)
	{
		A = animals;
		E = elements;
		
		if(j==1){
			cout << "The WATER animal signs:\n";
			for(int i=0;i<NUMSIGNS;i++,A++,E++){
				if(*E=="water")
					cout << "\t\t" << *A << endl;
			}
			cout << endl;
		}
		else if(j==2){
			cout << "The WOOD animal signs:\n";
			for(int i=0;i<NUMSIGNS;i++,A++,E++){
				if(*E=="wood")
					cout << "\t\t" << *A << endl;
			}
			cout << endl;
		}
		else if(j==3){
			cout << "The FIRE animal signs:\n";
			for(int i=0;i<NUMSIGNS;i++,A++,E++){
				if(*E=="fire")
					cout << "\t\t" << *A << endl;
			}
			cout << endl;
		}
		else if(j==4){
			cout << "The METAL animal signs:\n";
			for(int i=0;i<NUMSIGNS;i++,A++,E++){
				if(*E=="metal")
					cout << "\t\t" << *A << endl;
			}
			cout << endl;
		}
		else{
			cout << "The EARTH animal signs:\n";
			for(int i=0;i<NUMSIGNS;i++,A++,E++){
				if(*E=="earth")
					cout << "\t\t" << *A << endl;
			}
			cout << endl;
		}
		j++;
	}
}

void PrintZodiacCompatibility(){
	switch(rand()%6){
		case 0:  
				cout << "\nYou two are a Perfect Match!\n";
				break;
		case 1:
				cout << "\nYou two are Pretty Good.\n";
				break;
		case 2:
				cout << "\nYou two are Complementary.\n";
				break;
		case 3:
				cout << "\nYou two are Average.\n";
				break;
		case 4:
				cout << "\nYou Could Go Either Way.\n";
				break;
		case 5:
				cout << "\nYou two are Not So Good.\n";
				break;			
	}
}
