#include "advent.h"

int test_abs() {
    int j = 1000;
    for (int i = -1000; i < 0; i++) {
        if (abs(i) != j) {
            printf("i: %d, j: %d\n", i, j);
            return -1;
        }
        j--;
    }

    for (int x = 0; x < 1000; x++) {
        if (abs(x) != x) {
            printf("x: %d\n", x);
            return -1;
        }
    }

    return 1;
}

int test_int_array() {
    IntArray test_array = new_int_array(1000);

    int_array_push(5, &test_array);

    return 1;
}

int test_quicksort() {
    IntArray test_array = new_int_array(100);

    for (int i = 100; i > 0; i--) {
        int_array_push(i, &test_array);
    }

    // print_int_array(&test_array);
    quickSort(test_array.pointer, 0, test_array.end-1);
    for (int j = 0; j < test_array.end; j++) {
        if (test_array.pointer[j] != j+1) {
            printf("j: %d, arr[j]: %d\n", j, test_array.pointer[j]);
            return -1;
        }
    }

    return 1;
}

int test_binary_search() {
    int test_array[5] = {1,2,6,9,10};

    int index = binary_search(2, test_array, 0, 5);

    if (index != 1) {
        return -1;
    }

    return 1;

    
}

int main() {

    if (test_abs() != -1) {
        printf("Test_abs passed!\n");
    }

    if (test_int_array() != -1) {
        printf("Test_int_array passed!\n");
    }

    if (test_quicksort() != -1) {
        printf("Test_quicksort passed!\n");
    }

    if (test_binary_search() != -1) {
        printf("Test_binary_search passed!\n");
    }

    printf("All tests passed!\n");

}