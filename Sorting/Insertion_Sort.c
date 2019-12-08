#include <stdio.h>

typedef int ElementType;

void insertion_sort(ElementType *vars, int length)
{
	int key = 0;

	for (int i = 1, j = 0; i < length; i++)
	{
		key = vars[i];

		// >> shift
		for (j = i - 1; j >= 0 && vars[j] > key; j--)
			vars[j + 1] = vars[j];
		
		vars[j + 1] = key;
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

	insertion_sort(vars, 5);

	printf("# after : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", vars[i]);
	printf("\n");

	system("pause");
}
