#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <time.h>

struct tm* mytime;
time_t t;

int triangle(int x, int y, int a, int b);
int  square(int x, int y, int a, int b);
int figure(int x, int y, int b);
float St(int a, int b);
int Ss(int a, int b);
float Sf(int a);
int names(int j);

void main()
{
	int tr = 1;
	while (tr != 0)
	{

		int j, p,t1,t2;
		int x, y, X, Y;
		char c;
		int a, b, r;
		char name;
		setlocale(LC_ALL, "rus");
		t = time(NULL);
		mytime = localtime(&t);
		printf("\nВыберите фигуру:\n");
		printf("1.Прямоугольний треугольник\n");
		printf("2.Прямоугольник\n");
		printf("3.Дельтоид\n");
		printf("0.Закончить работу программы\n");
		scanf("%d", &j);
		system("cls");
		switch (j)
		{
		case 1:
			printf("Выберите действие:\n");
			printf("1.Рассчитать площадь фигуры:\n");
			printf("2.Вывести определение фигуры:\n");
			printf("3.Нарисовать фигуру:\n");
			scanf("%d", &p);
			system("cls");
			switch (p)
			{
			case 1:
				printf("Введите значения катетов a и b:\n");
				scanf("%d\n", &a);
				scanf("%d", &b);
				printf("Площадь = %f\n", St(a, b));
				break;

			case 2:
				names(j);
				break;

			case 3:
				printf("Введите значения катетов a и b:\n");
				scanf("%d", &a);
				scanf("%d", &b);
				X = fmax(a, b) * 2;
				Y = fmax(a, b) * 2;
				for (y = Y / 2; y >= -(Y / 2); --y)
				{
					for (x = -(X / 2); x <= X / 2; ++x)
					{
						if (triangle(x, y, a, b))  printf("* ");
						else printf("  ");
					}
					printf("\n");
				}
				break;

			default:
				printf("Ошибка\n\n");
				break;
			}
			break;

		case 2:
			printf("Выберите действие:\n");
			printf("1.Рассчитать площадь фигуры:\n");
			printf("2.Вывести определение фигуры:\n");
			printf("3.Нарисовать фигуру:\n");
			scanf("%d", &p);
			system("cls");
			switch (p)
			{
			case 1:
				printf("Введите значения сторон a и b:\n");
				scanf("%d", &a);
				scanf("%d", &b);
				printf("Площадь = %d\n", Ss(a, b));
				break;

			case 2:
				names(j);
				break;

			case 3:
				printf("Введите значения сторон a и b:\n");
				scanf("%d", &a);
				scanf("%d", &b);
				X = fmax(a, b) * 2;
				Y = fmax(a, b) * 2;
				for (y = Y / 2; y >= -(Y / 2); --y)
				{
					for (x = -(X / 2); x <= X / 2; ++x)
					{
						if (square(x, y, a, b))  printf("* ");
						else printf("  ");
					}
					printf("\n");
				}
			default:
				printf("Ошибка\n\n");
				break;
			}
			break;

		case 3:
			printf("Выберите действие:\n");
			printf("1.Рассчитать площадь фигуры:\n");
			printf("2.Вывести определение фигуры:\n");
			printf("3.Нарисовать фигуру:\n");
			scanf("%d", &p);
			system("cls");

			switch (p)
			{
			case 1:
				printf("Введите радиус: \n");
				scanf("%d", &r);
				printf("Введите малую сторону: \n");
				scanf("%d", &a);
				printf("Площадь = %f\n", Sf(a));
				break;

			case 2:
				names(j);
				break;

			case 3:
				printf("Введите радиус: \n");
				scanf("%d", &r);
				printf("Введите малую сторону: \n");
				scanf("%d", &a);

				

				t1 = mytime->tm_sec;

				X = r * 2;
				Y = r * 2;
				b = sqrt(pow(2 * r, 2) - pow(a, 2));

				for (y = -(Y / 2); y <= Y / 2; ++y)
				{
					for (x = -(X / 2); x <= X / 2; ++x)
					{
						if (figure(x, y, r)) printf("* ");
						else printf("  ");
					}
					printf("\n");
				}
				t2 = mytime->tm_sec;
				printf("Время выполнения программы в секундах = %d", t2-t1);
				break;

			default:
				break;
			}

			break;
		case 0:
			tr = 0;

			break;
		default:
			printf("Ошибка\n\n");
			break;
		}

	}

}

int triangle(int x, int y, int a, int b)
{
	if ((y >= 0) && (x >= 0) && (((a / b) * x) + y <= a)) return 1;
	else return 0;
}
int square(int x, int y, int a, int b)
{
	if ((x >= 0) && (y >= 0) && (a >= y) && (b >= x)) return 1;
	else return 0;
}

int figure(int x, int y, int b)
{
	if ((y > ((x - b) / 2)) && (y < -((x - b) / 2)) && (y < x + b) && (y > -(x + b))) return 1;
	else return 0;
}

float St(int a, int b)
{
	return ((a * b) / 2.);
}

int Ss(int a, int b)
{
	return (a * b);
}

float Sf(int a)
{
	return (((3 * a) * (4 * a)) / 2.);
}

int names(int j)
{
	if (j == 1) return printf("Прямоугольный треугольник\n");
	else
	{
		if (j == 2) return printf("Прямоугольник\n");
		else
		{
			if (j == 3) return printf("Дельтоид\n");
		}
	}
}