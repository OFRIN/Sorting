#include <stdio.h>

typedef int ElementType;

ElementType sorted[5] = { 0, };

// i: ���ĵ� ���� ����Ʈ�� ���� �ε���
// j: ���ĵ� ������ ����Ʈ�� ���� �ε���
// k: ���ĵ� ����Ʈ�� ���� �ε���
/* 2���� ������ �迭 list[left...mid]�� list[mid+1...right]�� �պ� ���� */
/* (������ ���ڵ��� ���ĵǴ� ����) */
void merge(ElementType *vars, int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	/* ���� ���ĵ� list�� �պ� */
	while (i <= mid && j <= right) {
		if (vars[i] <= vars[j])
			sorted[k++] = vars[i++];
		else
			sorted[k++] = vars[j++];
	}

	// ���� �ִ� ������ �ϰ� ����
	if (i>mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = vars[l];
	}
	// ���� �ִ� ������ �ϰ� ����
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = vars[l];
	}

	// �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
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