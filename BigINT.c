#include <stdio.h>
#include<string.h>
#include <time.h>


void delay(int number_of_seconds)
{

    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
int multiplyBigInt(char x[],char y[])
{

    int l1 = strlen(x);
    int l2 = strlen(y);
    int a[l1],b[l2];
    int i,j,tmp;
    int ans[l1+l2];
    for(int i=0;i<l1+l2;i++)
    {
        ans[i]=0;
    }
    for(i = l1-1,j=0;i>=0;i--,j++)
    {
        a[j] = x[i]-'0';
    }
    for(i = l2-1,j=0;i>=0;i--,j++)
    {
        b[j] = y[i]-'0';
    }
    for(i = 0;i < l2;i++)
    {
        for(j = 0;j < l1;j++)
        {
            ans[i+j] += b[i]*a[j];
        }
    }
    for(i = 0;i < l1+l2;i++)
    {
        tmp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + tmp;
    }
    for(i = l1+l2; i>= 0;i--)
    {
        if(ans[i] > 0)
            break;
    }
    printf("Product : ");
    for(i=l1+l2-1;i >= 0;i--)
    {
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}

int compareBigInt(int a[],int b[],int l1,int l2)
{
    if(l1>l2)
    {
        return 1; 
    }
    else if(l1<l2)
    {
        return 2;
    }
    else if(l1==l2)
    {
        for(int i=0;i<l1;i++)
        {
            if(a[i]>b[i])
            {
                return 1;
            }
            else if(a[i]<b[i])
            {
                return 2;
            }
        }
    }
    return 0;
}

int subtractBigInt(int arr1[],int arr2[],int n1,int n2,char sign)
{
    int i=n1-1;
    int j = n2 - 1;
	int k = 0;
	int res[310];
		while(1) {

	    if(arr1[i] - arr2[j] < 0) {

	        res[k++] = 10 + arr1[i] - arr2[j];

	        if(arr1[i-1] == 0) {
    	        int x = i-1;
    	        while(arr1[x] == 0) {
        	        arr1[x] = 9;
        	        x--;
    	        }
    	        arr1[x]--;
	        }
	        else
	            arr1[i-1]--;
	    }
	    else {
	        res[k++] = arr1[i] - arr2[j];
	    }

      if(j == 0)
      break;

      i--;
      j--;
	}

	i--;

	while(i >= 0) {
	    res[k++]  = arr1[i];
	    i--;
	}

	if(res[k-1] == 0)
	k--;
	printf("the result of subtraction of two bigints= %c",sign);
	for(int i=k-1;i>=0;i--)
	{
	  printf("%d",res[i]);
	}
	printf("\n");

	return 0;
}

int SumBigInt(int a[], int b[], int n, int m)
{
   int sum[n+1];
   int i = n - 1, j = m - 1, k = n ;
   int c = 0, s = 0;
   while (j >= 0) {
      s = a[i] + b[j] + c;
      sum[k] = (s % 10);
      c = s / 10;
      k--;
      i--;
      j--;
   }
   while (i >= 0) {
      s = a[i] + c;
      sum[k] = (s % 10);
      c = s / 10;
      i--;
      k--;
   }
   sum[0]=c;
   printf("the result of addition of two bigints= ");
   for (int i = 0; i <= n; i++) {
      printf("%d",sum[i]);
   }
   printf("\n");
}
int main()
{

    char x[310];
    char y[310];
    printf("enter the first number:");
    scanf("%s",x);
    printf("\n enter the second number:");
    scanf("%s",y);
    printf("\n");
    int l1,l2;
    l1=strlen(x);
    l2=strlen(y);
    int a[l1];
    int b[l2];
    for(int i=0;i<l1;i++)
    {
        a[i]=x[i]-48;
    }
    for(int i=0;i<l2;i++)
    {
        b[i]=y[i]-48;
    }
    l1=sizeof(a)/sizeof(a[0]);
    l2=sizeof(b)/sizeof(b[0]);
    jump:
    delay(1000);
    printf("\n");
    printf("Enter what operation you want to do :\nenter 1 to add\nenter 2 to subtract \nenter 3 to multiply\nenter 0 to exit\n");
    int status;
    scanf("%d",&status);

    if(status==1)
    {
      if (l1 >= l2)
      {
            SumBigInt(a, b, l1, l2);
      }
      else
      {
            SumBigInt(b, a, l2, l1);
      }
    }
    if(status==2)
    {
        int s=compareBigInt(a,b,l1,l2);
        if(s==1)
       {
        	subtractBigInt(a,b,l1,l2,'+');
       }
         else if(s==2)
       {
        	subtractBigInt(b,a,l2,l1,'-');
       }
       else if(s==0)
       {
           printf("subtraction of the two given numbers = 0 \n");
       }
    }
    if(status==3)
    {
       multiplyBigInt(x,y);
    }
    if(status!=0)
    {
        goto jump;
    }

}
