#include<stdio.h>
#include<stdlib.h>
#include<math.h>	
#include<locale.h>

int cmiror_dot(double valx, double valy, double valc, double dot_val, double dot_coeff, double* n_newposX_dot, double* n_newposY_dot)
{
	if ((valx == 0) || (valy == 0))
	{
		printf("Ошибка! Коэффициенты x или y не должны равнятся нулю.\n");
		return 0;
	}

	double Y_Xequally0 = (-valc) / valy;
	double k = valx / valy;

	double corner = atan(k);

	double newposX_dot = ((-dot_val) * cos(corner)) - ((Y_Xequally0 - dot_coeff) * sin(corner));
	double newposY_dot = ((-dot_val) * sin(corner)) + ((Y_Xequally0 - dot_coeff) * cos(corner));

	newposX_dot = -newposX_dot;
	newposY_dot = newposY_dot;

	double accnewposX_dot = newposX_dot;

	newposX_dot = ((newposX_dot * cos(corner)) + (newposY_dot * sin(corner)));
	newposY_dot = ((accnewposX_dot * sin(corner)) - (newposY_dot * cos(corner)));

	newposY_dot -= Y_Xequally0;
	newposY_dot *= -1;
	*n_newposX_dot = newposX_dot;
	*n_newposY_dot = newposY_dot;

	return 1;
}