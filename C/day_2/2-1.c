#include "../advent.h"

int report_is_safe(IntArray* report) {
    int ascending = 0;
    int descending = 0;
    int steady = 0;
    
    for (int i = 0; i < report->end; i++) {

    }
}

int main() {

    Arena arena = arena_create(10);

    String puzzle_text = get_puzzle_input_string("puzzle_input.txt", &arena);

    int safe_reports = 0;
    AutoString buf = auto_string_new(10);
    IntArray line = new_int_array(100);
    for (int i = 0; i < puzzle_text.len; i++) {
        if (puzzle_text.pointer[i] == '\n') {
            if (report_is_safe(&line)) {
                safe_reports += 1;
            }
            int_array_clear(&line);
            auto_string_clear(&buf);
        } else if (puzzle_text.pointer[i] == " ") {
            int_array_push(int_from_string(buf.pointer, buf.len), &line);
        } else {
            auto_string_push(puzzle_text.pointer[i], &buf);
        }
    }

}