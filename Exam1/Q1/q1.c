#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define PI 3.141592654

float d;
float L;
float Lc;
float W;

float T;
float FAx;
float FAy;
float FA;
float fiA;

void calculate()
{
	T = W * L * (Lc / d);
	FAx = T * (d / Lc);
	FAy = W*((L - d) / d);
	FA = sqrt((pow(FAx, 2) + pow(FAy, 2)));
	fiA = (atan(FAy / FAx)) * (180 / PI);

}

int main()
{
	bool flag = true;
	while (flag)
	{
		printf("Enter d\n");
		scanf("%f", &d);
		printf("Enter L\n");
		scanf("%f", &L);
		printf("Enter Lc\n");
		scanf("%f", &Lc);
		printf("Enter W\n");
		scanf("%f", &W);

		if (d < 0 || L < 0 || Lc < 0 || W < 0)
		{
			printf("Error. One of your inputs is less than zero. Program will now terminate.");
			flag = false;
		}
		else
		{
			calculate();
			printf("T:%f\nFAx:%f\nFAy:%f\nFA:%f\nfiA:%f\n", T, FAx, FAy,FA, fiA);

			printf("\n\n\n");

		}
	}

	

	
}