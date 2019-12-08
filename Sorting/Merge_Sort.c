#include <stdio.h>

typedef int ElementType;

ElementType sorted[5] = { 0, };

// i: 정렬된 왼쪽 리스트에 대한 인덱스
// j: 정렬된 오른쪽 리스트에 대한 인덱스
// k: 정렬될 리스트에 대한 인덱스
/* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */
void merge(ElementType *vars, int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	/* 분할 정렬된 list의 합병 */
	while (i <= mid && j <= right) {
		if (vars[i] <= vars[j])
			sorted[k++] = vars[i++];
		else
			sorted[k++] = vars[j++];
	}

	// 남아 있는 값들을 일괄 복사
	if (i>mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = vars[l];
	}
	// 남아 있는 값들을 일괄 복사
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = vars[l];
	}

	// 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
	for (l = left; l <= right; l++) {
		vars[l] = sorted[l];
	}
}

void merge_sort(ElementType *vars, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		
		merge_sort(vars, left, mid);
		merge_sort(vars, mid + 1, right);

		merge(vars, left, mid, right);
	}
}

int main()
{
	ElementType vars[] = { 5,4,3,2,1 };

	printf("# before : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", vars[i]);
	printf("\n");

	merge_sort(vars, 0, 5 - 1);

	printf("# after : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", sorted[i]);
	printf("\n");

	system("pause");
}