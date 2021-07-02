/*
* @file project.c
* @author ������� ��������� ��������, ��. 515�
* @date   02.07.2021
* @brief  ��������
* ���������� ����������� ����� ��� ����� ����� ������ �����.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>


int main()
{
	setlocale(LC_ALL,"Rus");
	printf("������� ���������� ����� � ���� ����� x+yi.\n");
	double dot_val, dot_coeff;
	double valx, valy, valc;
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
	if ((valx == 0) || (valy == 0))
	{
		printf("������! ������������ x ��� y �� ������ �������� ����.\n");
		exit(-33);
	}

	double Y_Xequally0 = (-valc) / valy;
	double k = valx / valy;

	double corner = atan(k);

	double newposX_dot = ((- dot_val) * cos(corner)) - ((Y_Xequally0 - dot_coeff) * sin(corner));
	double newposY_dot = ((- dot_val) * sin(corner)) + ((Y_Xequally0 - dot_coeff) * cos(corner));

	newposX_dot = -newposX_dot;
	newposY_dot = newposY_dot;

	double accnewposX_dot = newposX_dot;

	newposX_dot = ((newposX_dot * cos(corner)) + (newposY_dot * sin(corner)));
	newposY_dot = ((accnewposX_dot * sin(corner)) - (newposY_dot * cos(corner)));

	newposY_dot -= Y_Xequally0;
	newposY_dot *= -1;
	
	printf("%lf:%lf\n",newposX_dot,newposY_dot);

	return;
}