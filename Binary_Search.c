#include <stdio.h>

int size_of_array() {
    int size;
    printf("No of elements required: ");
    scanf("%d", &size);
    return size;
}

void input_array(int *lst, int size) {
    printf("Enter the elements one by one: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &lst[i]);
    }
}

void bubble_sort(int *lst, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (lst[j] > lst[j + 1]) {
                int temp = lst[j];
                lst[j] = lst[j + 1];
                lst[j + 1] = temp;
            }
        }
    }
}

int want_to_search() {
    int key;
    printf("Search: ");
    scanf("%d", &key);
    return key;
}

int main() {
    int key;
    int lst[1000], size;
    size = size_of_array();
    input_array(lst, size);
    
    bubble_sort(lst, size);

    key = want_to_search();

    int lowerbound = 0;
    int upperbound = size - 1; 

    while (lowerbound <= upperbound) {
        int mid = (upperbound + lowerbound) / 2;
        if (key == lst[mid]) {
            printf("Item: %d found at index: %d\n", key, mid);
            return 0;
        } else {
            if (key > lst[mid]) {
                lowerbound = mid + 1;
            } else {
                upperbound = mid - 1;
            }
        }
    }

    printf("Item: %d not found in the database\n", key);
    return 0;
}
