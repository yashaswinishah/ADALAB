-- Sort a given set of N integer elements using Heap Sort technique and compute its time taken.
#include <stdio.h>
#include <conio.h>
void bottom_up_heapify(int n, int a[], int p)
{
    int item, c;
    c = 2 * p + 1;
    item = a[p];
    while (c <= n - 1)
    {
        if (c + 1 <= n - 1)
        {
            if (a[c] < a[c + 1])
                c++;
        }
        if (item < a[c])
        {
            a[p] = a[c];
            p = c;
            c = 2 * p + 1;
        }
        else
            break;
    }
    a[p]=item;
}
void top_down_heapify(int n, int a[])
{
    int k, c, key, p;
    for (k = 0; k < n; k++)
    {
        key = a[k];
        c = k;
        p = (c - 1) / 2;
        while (c > 0 && key > a[p])
        {
            a[c] = a[p];
            c = p;
            p = (c - 1) / 2;
        }
        a[c] = key;
    }
}
void heap_sort(int n, int a[])
{
    int i, temp;
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        bottom_up_heapify(i, a, 0);
    }
}
void main()
{
    int i, n, a[20];
    printf("Enter the value of n\n");
    scanf("%d", &n);
    int b[n];
    printf("Enter the elements to sort\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    top_down_heapify(n, a);
    heap_sort(n, a);
    printf("The sorted vector is\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
