#include <stdio.h>
#include <stdlib.h>
int iterativeBinarySearch_char(char array[], int start_index, int end_index, char element)
{
    while (start_index <= end_index)
    {
        int middle = start_index + (end_index- start_index )/2;
        if (array[middle] == element)
            return middle;
        if (array[middle] < element)
            start_index = middle + 1;
        else
            end_index = middle - 1;
    }
    return -1;
}
int iterativeBinarySearch_Int(int array[], int start_index, int end_index, int element)
{
    while (start_index <= end_index)
    {
        int middle = start_index + (end_index- start_index )/2;
        if (array[middle] == element)
            return middle;
        if (array[middle] < element)
            start_index = middle + 1;
        else
            end_index = middle - 1;
    }
    return -1;
}
int insertion_sort_int(int array[],int n)
{
    int temp,current,small;
    int i,j;
    small=array[0];

    for(i=1; i<n; i++)
    {
        small=array[i];
        for(j=i-1; j>=0 && small<array[j] ; j--)
        {
            array[j+1]=array[j];
        }
        array[j+1]=small;

    }


}

void insertion_sort_char(char array[],int n)
{
    char small;
    int i,j;
    small=array[0];

    for(i=1; i<n; i++)
    {
        small=array[i];
        for(j=i-1; j>=0 && small<array[j] ; j--)
        {
            array[j+1]=array[j];
        }
        array[j+1]=small;

    }


}

void swap_elements_int(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition_int(int a[],int l,int h)
{
    int pivot;
    pivot=a[h];
    int i =(l-1);
    for(int j=l; j<=h-1; j++)
    {
        if(a[j]<pivot)
        {

            i++;
            swap_elements_int(&a[i],&a[j]);
        }

    }
    swap_elements_int(&a[i+1],&a[h]);
    return(i+1);
}
void quicksort_int(int a[],int l,int h)
{
    if(l<h)
    {
        int j=partition_int(a,l,h);
        quicksort_int(a,l,j-1);
        quicksort_int(a,j+1,h);
    }
}
void swap_elements_char(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
int partition_char(char a[],int l,int h)
{
    char pivot;
    pivot=a[h];
    int i =(l-1);
    for(int j=l; j<=h-1; j++)
    {
        if(a[j]<pivot)
        {

            i++;
            swap_elements_char(&a[i],&a[j]);
        }

    }
    swap_elements_char(&a[i+1],&a[h]);
    return(i+1);

}
void quicksort_char(char a[],int l,int h)
{
    if(l<h)
    {
        int j=partition_char(a,l,h);
        quicksort_char(a,l,j-1);
        quicksort_char(a,j+1,h);

    }

}
void printArray_char(char a[], int size)
{
    int i;

    printf("\n{");
    for (i=0; i < size; i++)
    {
        if(i<size-1)
        {
            printf("%c,", a[i]);
        }
        else
        {
            printf("%c}", a[i]);
        }
    }

}
void printArray_int(int a[], int size)
{
    int i;

    printf("\n{");
    for (i=0; i < size; i++)
    {
        if(i<size-1)
        {
            printf("%d,", a[i]);
        }
        else
        {
            printf("%d}", a[i]);
        }
    }

}

int main()
{
    int Input_choice,Sort_Choice,Search_Choice,size,element_int=0;
    char element_char;
    printf("Enter Array Size: ");
    scanf("%d",&size);
    char arr_char[size];
    int  arr_int[size];


    printf("To Enter Characters Press 1 , To Enter Numbers Press 2\n");
    scanf("%d",&Input_choice);
    if(Input_choice==1)
    {


        for(int i=0; i<size; i++)
        {
            printf(" Enter a Char : \n");

            scanf("%s",&arr_char[i]);

        }
    }
    if(Input_choice==2)
    {


        for(int i=0; i<size; i++)
        {
            printf(" Enter an Integer: \n");

            scanf("%d",&arr_int[i]);

        }
    }


    printf("Enter 1 to apply Insertion Sort algorithm , Enter 2 to apply Quick Sort Algorithm : ");
    scanf("%d",&Sort_Choice);

    switch(Sort_Choice)
    {
    case 1:
        if(Input_choice==1)
        {
            insertion_sort_char(&arr_char,size);
            printArray_char(arr_char,size);
        }

        else
        {

            insertion_sort_int(&arr_int,size);
            printArray_int(arr_int,size);

        }

        break;
    case 2:
        if(Input_choice==1)
        {
            quicksort_char(arr_char,0,size-1);
            printArray_char(arr_char,size);

        }

        else
        {
            quicksort_int(arr_int,0,size-1);
            printArray_int(arr_int,size);

        }

        break;
    }
    printf("\nPress 1 for Binary Search\nPress 0 to Exit the Program\n");
    scanf("%d",&Search_Choice);
    if(Search_Choice==1&&Input_choice==1)
    {
        printf("\nEnter The Key to found : ");
        scanf(" %c",&element_char);
        int found_index = iterativeBinarySearch_char(arr_char, 0, size-1, element_char);
        if(found_index == -1 )
        {
            printf("Element not found in the array ");
        }
        else
        {
            printf("Element found at position : %d",found_index+1);

        }

    }
    if(Search_Choice==1&&Input_choice==2)
    {
        printf("\nEnter The Key to found : ");
        scanf("%d",&element_int);
        int found_index = iterativeBinarySearch_Int(arr_int, 0, size-1, element_int);
        if(found_index == -1 )
        {
            printf("Element not found in the array ");
        }
        else
        {
            printf("Element found at position : %d",found_index+1);

        }

    }
    return 0;

}
