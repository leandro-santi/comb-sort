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
	int i,
		gap = n, /* Gap inicial do tamanho do array */
		swapped = 1; /* Variavel para verificar se houve movimentacao */

	/* Enquanto o gap for valido ou tenham ocorrido trocas... */
	while (gap > 1 || swapped) {
		swapped = 0; /* Reseta a variavel de validacao */
		gap = gap * 10 / 13; /* Reduz o gap */

		/* Variacao Comb11...
		 * gap = gap == 9 || gap == 10 ? 11 : gap;
		 */

		/* Compara e troca os valores dentro do espaco do gap */
		for (i = 0; i + gap < n; i++) {
			if ((*a)[i] > (*a)[i + gap]) {
				swap(i, i + gap, a); /* Troca os valores */
				swapped = 1; /* Registra movimentacao */
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
