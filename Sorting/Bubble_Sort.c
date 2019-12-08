#include <stdio.h>

typedef int ElementType;

void bubble_sort(ElementType *vars, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (vars[j] > vars[j + 1])
			{
				ElementType temp = vars[j];
				vars[j] = vars[j + 1];
				vars[j + 1] = temp;
			}
		}
	}
}

/*
# before : 5 4 3 2 1
# after : 1 2 3 4 5
*/
int main()
{
	ElementType vars[] = { 5,4,3,2,1 };
	
	printf("# before : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", vars[i]);
	printf("\n");

	bubble_sort(vars, 5);

	printf("# after : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", vars[i]);
	printf("\n");

	system("pause");
}
