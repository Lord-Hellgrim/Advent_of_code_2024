#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {

    // Initialize pivot to be the first element
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // Find the first element greater than
        // the pivot (from starting)
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }

        // Find the first element smaller than
        // the pivot (from last)
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {

        // call partition function to find Partition Index
        int pi = partition(arr, low, high);

        // Recursively call quickSort() for left and right
        // half based on Partition Index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

typedef struct {
    char* pointer;
    size_t len;
} String;


String get_puzzle_input_string(char* file_name) {
    FILE* puzzle_input_file = fopen(file_name, "r");

    if (puzzle_input_file == NULL) {
        String err = {NULL, 0};
        return err;
    }

    fseek(puzzle_input_file, 0, SEEK_END);
    long size = ftell(puzzle_input_file);
    fseek(puzzle_input_file, 0, 0);

    char* puzzle_input = malloc(size*2);

    size_t bytes_read = fread(puzzle_input, 1, size, puzzle_input_file);

    String ret = {puzzle_input, bytes_read};

    return ret;
}



typedef struct {
    int* pointer;
    size_t cap;
    size_t end;
} IntArray;

IntArray new_int_array(size_t cap) {
    int* pointer = malloc(cap);
    IntArray array = {pointer, cap, 0};
    return array;
}

void destroy_int_array(IntArray* array) {
    free(array->pointer);
    array->cap = 0;
    array->end = 0;
}

size_t int_array_push(int number, IntArray* array) {
    if (array->end > array->cap) {
        return 0;
    }

    array->pointer[array->end] = number;
    array->end++;
    return 1;

}

void print_int_array(IntArray* array) {
    size_t i = 0;
    while (i < array->end) {
        printf("%d\n", array->pointer[i]);
        i += 1;
    }
}

int is_same_bytes(void* a, void* b, int size) {
    char* x = (char*)a;
    char* y = (char*)b;

    for (int i = 0; i < size; i++) {
        if (x[i] != y[i]) {
            return 0;
        }
    }
    return 1;
}

int binary_search(int needle, int* haystack, int start, int stop) {

    if (needle == haystack[0]) {
        return 0;
    } else {
        stop = stop / 2;
        while (stop > 0) {
            if (needle < haystack[stop]) {
                stop = stop / 2;
            } else if (needle > haystack[stop]) {
                stop = stop + stop/2;
            } else {
                return stop;
            }
        }

    }

    return -1;
}

int count_instances(int needle, IntArray* haystack, int sorted) {
    int count = 0;

    int trigger = 0;
    for (int i = 0; i < haystack->end; i++) {
        if (haystack->pointer[i] == needle) {
            trigger = 1;
            count++;
        } else if (trigger && sorted) {
            break;
        }
    }
    return count;
}


int power(int base, int power) {

    int ret = 1;

    for (int i = 0; i < power; i++) {
        ret *= base;
    }

    return ret;

}

int abs(int input) {
    if (input < 0) {
        return input - input - input;
    } else {
        return input;
    }
}