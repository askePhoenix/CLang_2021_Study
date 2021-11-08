#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


void print_array(int *, int);

void bubble_sort(int *, int);

void bubble_sort_recursive(int *, int, int, int);

int main() {
    int data[] = {12, 34, 51, 22, 91, 12, 15, 31, 42, 11};
    int size;
    int key;

    size = sizeof(data) / sizeof(data[0]);
    bubble_sort_recursive(data, size, 0, 0);

    printf("data = ");
    print_array(data, size);

    printf("찾을 값(키) : ");
    scanf("%d", &key);
    for (int i = 0; i < size; ++i) {
        if (data[i] == key) {
            printf("찾은 원소의 인덱스: %d\n", i);
        }
    }

    return 0;
}

void print_array(int arr[], int size) {

    for (int j = 0; j < size; ++j) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}

void bubble_sort(int arr1[], int cnt) {
    int temp;

    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt - i; ++j) {
            if (arr1[j] > arr1[j + 1]) {
                temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }
}

void bubble_sort_recursive(int arr1[], int cnt, int i, int j) {
    int temp;

    if (arr1[j] > arr1[j + 1]) {
        temp = arr1[j];
        arr1[j] = arr1[j + 1];
        arr1[j + 1] = temp;
    }
    j++;
    if (j >= cnt - i) {
        j = 0;
        i++;
    }

    if (i == cnt)
        return;
    bubble_sort_recursive(arr1, cnt, i, j);
}

