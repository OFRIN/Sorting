#include <stdio.h>

typedef int ElementType;

void insertion_sort(ElementType *vars, int start, int end, int gap)
{
	int key = 0;

	for (int i = start + gap, j = 0; i < end; i+=gap)
	{
		key = vars[i];

		// >> shift (gap)
		for (j = i - gap; j >= 0 && vars[j] > key; j-=gap)
			vars[j + gap] = vars[j];

		vars[j + gap] = key;
	}
}

void shell_sort(ElementType *vars, int length)
{
	for (int gap = length / 2; gap > 0; gap /= 2)
	{
		for (int i = 0; i < gap; i++)
		{
			insertion_sort(vars, i, length, gap);
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

	shell_sort(vars, 5);

	printf("# after : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", vars[i]);
	printf("\n");

	system("pause");
}
