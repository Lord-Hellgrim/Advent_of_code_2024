
#include "../advent.h"

int main() {
    
    String puzzle_input = get_puzzle_input_string("puzzle_input.txt");

    int current = 0;
    IntArray left = new_int_array(puzzle_input.len);
    IntArray right = new_int_array(puzzle_input.len);

    int order = 4;
    int i = 0;
    while (puzzle_input.pointer[i] != 0) {
        if (puzzle_input.pointer[i] == ' ') {
            if (current != 0) { 
                int_array_push(current, &left);
                current = 0;
                order = 4;
            }
        } else if (puzzle_input.pointer[i] == '\n') {
            int_array_push(current, &right);
            current = 0;
            order = 4;
        } else {
            current += (puzzle_input.pointer[i] - 0x30) * power(10, order);
            order -= 1;
        }
        i += 1;
    }

    // quickSort(left.pointer, 0, left.end-1);
    // quickSort(right.pointer, 0, right.end-1);

    IntArray simlist = new_int_array(left.cap);

    for (int l = 0; l < left.end; l++) {
        int temp = count_instances(left.pointer[l], &right, 0);
        int_array_push(temp, &simlist);
        printf("%d: %d\n", left.pointer[l], temp);

    }

    size_t similarity = 0;
    for (int i = 0; i < left.end; i++) {
        similarity += left.pointer[i] * simlist.pointer[i];
    }

    printf("score: %ld\n", similarity);


}