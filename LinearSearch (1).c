#include<stdio.h>
#define MAX 100
int main()
{
	int i,m,n,a[MAX],p=1;
	printf("Enter the number of elements present: ");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched: ");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		if(m==a[i])
		{
			p=0;
			printf("Element found");
			break;
		}
	}
	if(p==1)
	printf("Element not found");
}
