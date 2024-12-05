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