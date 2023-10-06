#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define N 4
#define M 256
#define CASE1 10
#define CASE2 100
#define CASE3 1000
#define CASE4 10000

void ascendingorder(int32_t *Array);
int32_t pow(int32_t num1,int32_t num2);
int32_t element_length(int32_t *Array);

int32_t main()
{
		int32_t Arr[N] = {5,6,11,130},temp1,temp2,a,b;
		uint8_t i,j,temp;

		ascendingorder(Arr);

		for(i=0;i<N;i++)
		{
				a = element_length(&Arr[i]);
					for(j=(i+1);j<N;j++)
					{
							b = element_length(&Arr[j]);
									temp1 = Arr[i]*(pow(10,b))+ Arr[j];
									temp2 = Arr[j]*(pow(10,a)) + Arr[i];
			
									if(temp1 < temp2)
									{
											temp = Arr[i];
											Arr[i] = Arr[j];
											Arr[j] = temp;
									}
					}
		}
		for(i = 0;i < N; i++)
	  	{
				printf("%d",Arr[i]);
        }
		 printf("\n");
		 return 0;

}

void ascendingorder(int32_t *Array)
{
		uint8_t temp,i,j;
		for(i = 0;i < N;i++)
		{
				for(j = (i+1);j < N;j++)
				{
						if(Array[i] > Array[j])
						{
							temp = Array[j];
							Array[j] = Array[i];
							Array[i] = temp;
						}
				}
		}
		for(i = 0;i < N; i++)
         {
                 printf("%d",Array[i]);
         }
         printf("\n");

}

int32_t element_length(int32_t *Array)
{
		uint8_t i = 0;
		for(i = 0; i < N; i++)
		{
				if(Array[i] < CASE1)
				{
						return 1;
				}
				else if((Array[i] >= CASE1) && (Array[i] < CASE2))
				{
						return 2;
				}
				else if((Array[i] >= CASE2) && (Array[i] < CASE3))
				{
						return 3;
				}
				else if((Array[i] >= CASE3) &&(Array[i] < CASE4))
				{
						return 4;
				}
		}
}
						
int32_t pow(int32_t num1,int32_t num2)
{
		int32_t a,res=1;
		for(a = 1;a <= num2;a++)
		{
				res = res * num1;
		}
		return res;
}

