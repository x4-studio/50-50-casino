#include <windows.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <ctime>

//My random function, replaced by default random gen

/*unsigned long long randomizer(long int maxRand)
{
	static unsigned long seed = time(0);
	seed = (2281337999 * seed + 14486661337);
		return seed % maxRand;
}*/

using namespace std;

const int cells = 10000000;
int dayArray[cells];
long moreThanTen;
long long maxCoins = 10;
long long maxDays;
int maxDaysCounter = 0;
int minDaysCounter = 0;
int moreThanMiddle = 0;
long long middleDays;
long long currCoins;
long long coins = 10;
long long diffCount;
double cell = cells * 1.0;
long long i = 0;
long long j=0;
long long k = 0;
double long percentage;

int main()
{
SetConsoleTitle("50-50 casino");
srand(time(0));
{
	while(i != cells)
	{
		diffCount = rand() % 9999;
		k++;
		if(diffCount > 4499)
		{
			coins+=1;
		}
		else if(diffCount < 4500)
		{
			coins-=2;
		}
		currCoins = coins;
		if(currCoins > maxCoins)
		{
			maxCoins = currCoins;
		}
		if(coins <= 0)
		{
			coins = 0;
			i++;
			dayArray[j+=1] = k; //Write the number of days from each attempt into a single array element
			percentage = (i/cell)*100.0;
			cout << "\b\b\b\b\b\b\b\b\b\b\b" << percentage << "%";
			coins = 10;
			k = 0;
		}
	}
	system("cls");
	//Statistical sample of array elements
	maxDays = dayArray[1];
	for (int f = 0; f < cells; f++) 
	{
        if (dayArray[f] > maxDays) {
            maxDays = dayArray[f];
        }
    }
    int minDays = dayArray[cells-1];
    for (int f = cells-1; f > 0; f--) 
	{
        if (dayArray[f] < minDays) {
            minDays = dayArray[f];
        }
    }
    for (int f = 0; f < cells; f++) 
	{
        middleDays += dayArray[f];
    }
    
    for (int f = cells-1; f > 0; f--) 
	{
        if (dayArray[f] == minDays) {
            minDaysCounter++;
        }
    }
    middleDays = middleDays/cells;
    for (int f = 0; f < cells; f++) 
	{
        if(dayArray[f] < middleDays)
        {
        	moreThanMiddle++;
        }
    }
    for (int f = 0; f < cells; f++) 
	{
        if (dayArray[f] == maxDays) {
            maxDaysCounter++;
        }
    }
    for (int f = 0; f < cells; f++) 
	{
        if (dayArray[f] > 10) {
            moreThanTen++;
        }
    }
    //Output
	cout << "Steps: " << i << endl;
	cout << "Average \"days\": " << middleDays << " (" << (moreThanMiddle/cell)*100.0 << "% tests better than average)" << endl;
	cout << "Maximum of days: " << maxDays << " (x" << maxDaysCounter << ")" << endl;
	cout << "Minimum of days: " << minDays << " (x" << minDaysCounter << " = ";
	printf("%.2f", (minDaysCounter/cell)*100.0);
	cout << "% of all tests)" << endl;
	cout << "More than 10 days: " << moreThanTen << " or ";
	printf("%.2f", (moreThanTen/cell)*100.0);
	cout << "% of all tests" << endl;
	cout << "Maximum of coins: " << maxCoins << endl;
	_getch();
	return 0;
}
}
