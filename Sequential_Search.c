#include<stdio.h>

int no_of_element()
{
    int size;
    printf("Enter the required element in array: ");
    scanf("%d", &size);
    return size;
}

void input_in_array(int *lst, int size)
{
    for(int i=0;i<size;i++)
    {
        scanf("%d" , &lst[i]);
    }
}

int search()
{
    int key;
    printf("Search: ");
    scanf("%d", &key);
    return key;
}

int main()
{
    int key, size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int lst[size];
    printf("Enter the elements of the array: ");
    input_in_array(lst,size);
    key = search();
    int i=0;
    while(i<size) 
    {
        if(key == lst[i])
        {
            printf("Item found at %d\n" ,i);
            return 0;
        }
        else
        {
            i=i+1;
        }
    }
    printf("Item not found\n");
    return 0;
}
