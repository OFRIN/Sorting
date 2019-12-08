#include <stdio.h>

typedef int ElementType;

void selection_sort(ElementType *vars, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int min_index = i;

		for (int j = i + 1; j < length; j++)
		{
			if (vars[min_index] > vars[j])
				min_index = j;
		}

		if (min_index != i)
		{
			ElementType temp = vars[i];
			vars[i] = vars[min_index];
			vars[min_index] = temp;
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

	selection_sort(vars, 5);

	printf("# after : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", vars[i]);
	printf("\n");

	system("pause");
}
