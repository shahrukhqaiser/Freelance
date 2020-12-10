#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter number of digits\n");
	scanf("%d", &n);

	int* arr = calloc(n, sizeof(int));

	printf("Enter the reference number with %d digits\n",n);
	for (int i = 0; i < n; i++)
	{
		printf("Enter digit #%d\n",i+1);
		scanf("%d", &arr[i]);
	}

	int* arr2 = calloc(n, sizeof(int));

	printf("Enter any number with %d digits\n",n);
	for (int i = 0; i < n; i++)
	{
		printf("Enter digit #%d\n", i + 1);
		scanf("%d", &arr2[i]);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d * * *  %d\n", arr[i], arr2[i]);
	}

}