/*
* @file Project1.c
* @author Тамахин Олександр Олегович, гр. 515б
* @date   02.07.2021
* @brief  Практика
* Дзеркальне відображення точки або точок через задану пряму.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>	
#include<locale.h>
#include"find_dot.h"



int main()
{
	double dot_val, dot_coeff;
	double valx, valy, valc;

	setlocale(LC_ALL,"Rus");

	printf("Введите координату точки в виде формы x+yi.\n");
	if ((scanf_s("%lF+%lFi", &dot_val, &dot_coeff) != 2) || (getchar() != '\n'))
	{
		printf("Ошибка!\n");
		exit(-11);
	}

	printf("Введите коэфициенты прямой ax+by+c=0 в виде ax+by+c.\n");
	if ((scanf_s("%lFx+%lFy+%lF", &valx, &valy, &valc) != 3) || (getchar() != '\n'))
	{
		printf("Ошибка!\n");
		exit(-22);
	}


	double newposX_dot; 
	double newposY_dot;

	cmiror_dot(valx, valy, valc, dot_val, dot_coeff, &newposX_dot, &newposY_dot);
	
	printf("%lf:%lf\n",newposX_dot,newposY_dot);

	return;
}