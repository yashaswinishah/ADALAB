Implement Recursive Binary search and Linear search and determine the time required to
search an element. Repeat the experiment for different values of N  and plot a graph of the time taken versus N. 


#include <stdio.h>
#include<stdlib.h>
#include<time.h>  

int array[100];
int search,c,n,i,j;
int number;

void linear_search()
{ 
  
 printf("numbers in the array are:\n");
  for(int i=0;i<n;i++)
  {
   printf("%d\n",array[i]);
  }
  
  printf("Enter the number to be searched\n");
  scanf("%d",&search);
  
  for( j=0;j<n;j++)
  {
    if(array[j]==search)
    {
      printf("The element is present in the array at position-%d\n",(j+1));
      break;
    }
  }
  
  if(j==n)
  {
    printf("The number is not present\n");
  }
}
  
void binary_search()
{
 
int c, first, middle, last;
int temp;

   for (i = 0; i < n; ++i) 
  {
      for (j = i + 1; j < n; ++j)
            { 
             if (array[i] > array[j]) 
                {
                    temp =  array[i];
                    array[i] = array[j];
                    array[j] = temp;
                  
                }
 
            }
 
        }
  
       
  printf("numbers...\n");
  for(j=0;j<n;j++)
  {
    printf("%d\n",array[j]);
  }
  
printf("Enter the element to be searched\n");
scanf("%d",&search);

first=0;
last=n-1;
middle = (first+last)/2;
 while (first <= last) {
    if (array[middle] < search)
      first = middle + 1;
    else if (array[middle] == search) {
      printf("%d found at location %d.\n", search, middle+1);
      break;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", search);

}

int main()
{
  int choice;
  clock_t start,end;
  double tm;
  
  printf("Enter the number of elements\n");
 scanf("%d",&n);
  for( i=0;i<n;i++)
  {
    
    number=rand()%100;

    array[i]=number;
  }
  
  while(1)
  {
    printf("\nenter 1.for linear search\n 2. for binary search\n ");
    scanf("%d",&choice);
   switch(choice)
   {
    case 1:start=clock();
           linear_search();
           end=clock();
           tm=((double)(end-start))/CLOCKS_PER_SEC;
           printf("the time taken by linear search=%1f\n",tm);
           break;
    case 2:start=clock();
           binary_search();
           end=clock();
             tm=((double)(end-start))/CLOCKS_PER_SEC;
           printf("the time taken by binary search=%1f\n",tm);
           break;       
   }
  }
  return 0;
}
