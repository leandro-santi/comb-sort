#include <stdio.h>
#include <stdlib.h>

void
swap(int i, int j, int *a[])
{
	int tmp = (*a)[i];

	(*a)[i] = (*a)[j];
	(*a)[j] = tmp;
}

void
sort(int n, int *a[])
{
	int i, gap = n, swapped = 1;

	while (gap > 1 || swapped) {
		swapped = 0;
		gap = gap * 10 / 13;
		/* Comb11 variation speed hack:
		 * gap = gap == 9 || gap == 10 ? 11 : gap;
		 */

		for (i = 0; i + gap < n; i++) {
			if ((*a)[i] > (*a)[i + gap]) {
				swap(i, i + gap, a);
				swapped = 1;
			}
		}
	}

}

int*
readinta(int n)
{
	int i,
		*a = (int*) malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
		scanf("%d", a + i);
	
	return a;
}

void
printa(int n, int *a)
{
	while (1 < n--)
		printf("%d ", *(a++));

	printf("%d\n", *a);
}

int
main(int argc, char *argv[])
{
	int n, *a;

	scanf("%d", &n);
	a = readinta(n);
	sort(n, &a);
	printa(n, a);

	return 0;
}
