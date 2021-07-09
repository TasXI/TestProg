/*
* @file Project1.c
* @author ������� ��������� ��������, ��. 515�
* @date   02.07.2021
* @brief  ��������
* ���������� ����������� ����� ��� ����� ����� ������ �����.
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

	printf("������� ���������� ����� � ���� ����� x+yi.\n");
	if ((scanf_s("%lF+%lFi", &dot_val, &dot_coeff) != 2) || (getchar() != '\n'))
	{
		printf("������!\n");
		exit(-11);
	}

	printf("������� ����������� ������ ax+by+c=0 � ���� ax+by+c.\n");
	if ((scanf_s("%lFx+%lFy+%lF", &valx, &valy, &valc) != 3) || (getchar() != '\n'))
	{
		printf("������!\n");
		exit(-22);
	}


	double newposX_dot; 
	double newposY_dot;

	cmiror_dot(valx, valy, valc, dot_val, dot_coeff, &newposX_dot, &newposY_dot);
	
	printf("%lf:%lf\n",newposX_dot,newposY_dot);

	return;
}