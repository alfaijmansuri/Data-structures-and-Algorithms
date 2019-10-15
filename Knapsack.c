#include<stdio.h>
void swap(float *x, float *y)
{
	float t;
	t = *x;
	*x = *y;
	*y = t;
}
void knapsack(int n, float wt[], float profit[], int w)
{
	int i;
	float tp=0.0;
	for(i=0;wt[i]<w;w-=wt[i],++i)
		tp+=profit[i];
	tp+=((w/wt[i])*profit[i]);
	printf("\nThe maximum profit is : %f \n",tp);
}
int main()
{
	int i, j, w, n;
	printf("\nEnter the value of 'W' : ");
	scanf("%d",&w);
	printf("\nEnter the value of 'n' : ");
	scanf("%d",&n);
	float wt[n], profit[n], ratio[n];
	printf("\nEnter the weights : ");
	for(i=0;i<n;++i)
		scanf("%f",&wt[i]);
	printf("\nEnter the profits : ");
	for(i=0;i<n;++i)
		scanf("%f",&profit[i]);
	for(i=0;i<n;++i)
		ratio[i] = (profit[i] / wt[i]);
	for(i=0;i<n;++i)
	{
		for(j=i+1;j<n;++j)
		{
			if(ratio[i]<ratio[j])
			{
				swap(&ratio[i],&ratio[j]);
				swap(&profit[i],&profit[j]);
				swap(&wt[i],&wt[j]);
			}
		}
	}
	/*for(i=0;i<n;++i)
		printf("%f ",ratio[i]);
	printf("\n");
	for(i=0;i<n;++i)
		printf("%f ",wt[i]);
	printf("\n");
	for(i=0;i<n;++i)
		printf("%f ",profit[i]);*/
	knapsack(n,wt,profit,w);
	return 0;
}
//fractional_knapsack.c
