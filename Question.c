#include<stdio.h>
#include<stdlib.h>

int get_size(){
    int n;
    scanf("%d" , &n);
    return n;
}

void input_in_array(int **p , int n ){
    *p = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {scanf("%d", &(*p)[i]);}
}

int search_key(){
    int key;
    scanf("%d", &key);
    return key;
}

int search_in_array(int *p, int n, int key){
    for(int i=0;i<n;i++){
        if(key==p[i]){
            return i;
        }
    }
    return -1;
}

int main()
{
    int sizea,sizeb,*a,*b,key1,key2,posi1,posi2;
    float average;  
    printf("Enter the total number of elements in 1st array: ");
    sizea=get_size();
    printf("Enter the %d values one by one in 1st array: ",sizea);
    input_in_array(&a,sizea);
    printf("Enter the total number of elements in 2nd array: ");
    sizeb=get_size();
    printf("Enter the %d values one by one in 2nd array: ",sizeb);
    input_in_array(&b,sizeb);
    printf("Search in 1st array: ");
    key1 = search_key();
    posi1 = search_in_array(a, sizea, key1);
    printf("Search in 2nd array: ");
    key2 = search_key();
    posi2 = search_in_array(b, sizeb, key2);
    average = (float)(key1+key2)/2;
    printf("Average of %d and %d is: %.2f\n" ,key1,key2, average);
    free(a);
    free(b);
    return 0;
}
