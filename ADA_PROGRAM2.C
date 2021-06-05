Implement Recursive Binary search and Linear search and determine the time required to
search an element.


#include <stdio.h>
#include <time.h>
clock_t start,end;
int linear_search(int arr[],int n,int k)
{
if(n<0)
return 0;
if(arr[n] ==k)
return 1;
return linear_search(arr,n-1,k);
}
int binary_search(int arr[],int start,int end,int k)
{
if(start>end)
return 0;
int mid =(start+end)/2;
if(arr[mid]==k)
return 1;
else if(arr[mid]>k)
end=mid-1;
else
start=mid+1;
return binary_search(arr,start,end,k);
}
int main()
{
int n,i;
printf("Enter the size of array: ");
scanf("%d",&n);
int choice;
int arr[n],k;
printf("The elements of array: \n");
for(i=0;i<n;i++)

{
arr[i] = i+1;
scanf("%d",&arr[i]);}
printf("\n");
printf("Enter the element to be searched: \n");
scanf("%d",&k);
while(choice!=3)
{
printf("\n 1.Linear search");
printf("\n 2.Binary search");
printf("\n 3.Exit");
printf("\nEnter your choice: ");
scanf("%d",&choice);
if (choice==1)
{
start=clock();
for(i=0;i<80000000;i++);
int a = linear_search(arr,n-1,k);
end = clock();
if(a==1)
printf("Element found");
else
printf("Element not found\n");
printf("\nTime taken to search value in %d numbers is %f secs\n",n,(((double)(end-start))/CLOCKS_PER_SEC));
}
else if(choice == 2)
{
start=clock();
for(i=0;i<80000000;i++);
int b=binary_search(arr,0,n-1,k);
end = clock();
if (b==1)
printf("Element  found");
else
printf("Element not found");
printf("\n Time taken to search value in %d numbers is %f secs\n",n,(((double)(end-start))/CLOCKS_PER_SEC));
}
else if (choice==3)
break;
else
printf("Invalid choice: ");
}
}
