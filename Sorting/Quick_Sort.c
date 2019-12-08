#include <stdio.h>

typedef int ElementType;

int partition(ElementType *vars, int start, int end)
{
	int left = start;
	int right = end + 1;

	// 1. select pivot
	int pivot = vars[left];

	// 2. loop
	do {
		
		do {
			left++;
		} while (left <= end && vars[left] < pivot);

		do {
			right--;
		} while (right >= start && vars[right] > pivot);

		// printf("left = %d, right = %d\n", left, right);

		if (left < right)
		{
			int temp = vars[left];
			vars[left] = vars[right];
			vars[right] = temp;
		}

	} while (left < right);

	// 3. swap
	int temp = vars[start];
	vars[start] = vars[right];
	vars[right] = temp;

	/*printf("# quick_sort(%d -> %d) : ", start, end);
	for (int i = 0; i < 5; i++)
		printf("%d ", vars[i]);
	printf("\n");*/

	return right;
}

void quick_sort(ElementType *vars, int left, int right)
{
	if (left < right)
	{
		int pivot = partition(vars, left, right);

		quick_sort(vars, left, pivot - 1);
		quick_sort(vars, pivot + 1, right);
	}
}

int main()
{
	ElementType vars[] = { 5,4,3,2,1 };

	printf("# before : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", vars[i]);
	printf("\n");

	quick_sort(vars, 0, 5 - 1);

	printf("# after : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", vars[i]);
	printf("\n");

	system("pause");
}