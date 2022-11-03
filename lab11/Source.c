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
	printf("Ìîñêîâñêîå âðåìÿ %02d:%02d:%02d \n",mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
	printf("Ìåñÿö %d è ãîä %d ", mytime->tm_mon,1900 + mytime->tm_year);

}

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <math.h>


 void main()
{
    float temp;
	float A[3];
    setlocale(LC_ALL, "rus");
    for (int i = 0; i < 3; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
 
        printf("\n %d", A[i]);
    }

   
}

 int okg(float x)
 {

 }
