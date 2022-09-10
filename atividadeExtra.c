#include <stdio.h>
#include <stdlib.h>

// returns x where (a * x) % b == 1
int mul_inv(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

int teorema_chines(int *n, int *a, int k)
{
	int p, i, prod = 1, sum = 0;

	for (i = 0; i < k; i++) prod *= n[i];

	for (i = 0; i < k; i++) {
		p = prod / n[i];
		sum += a[i] * mul_inv(p, n[i]) * p;
	}

    printf("X = %d , N = %d",sum % prod, prod);
	
	return 0;
}

int main(void)
{
    int k;
	printf("Informe o k \n");
    scanf("%d", &k);

	int n[k],a[k], b[k];

    for(int i = 0; i< k; i++){

        printf("Informe o valor de n%d \n", i+1);
        scanf("%d", &n[i]);

        printf("Informe o valor de a%d \n", i+1);
        scanf("%d", &a[i]);


       /* printf("Informe o valor de b%d \n", i+1);
        scanf("%d", &b[i]);*/

    }
	teorema_chines(n, a, sizeof(n)/sizeof(n[0]));
	return 0;
}
