#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <time.h>

struct tm* mytime;
time_t t;

int main()
{
	setlocale(LC_ALL, "rus");
	t = time(NULL);
	mytime = localtime(&t);
	printf("Московское время %02d:%02d:%02d \n",mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
	printf("Месяц %d и год %d ", mytime->tm_mon,1900 + mytime->tm_year);

}
