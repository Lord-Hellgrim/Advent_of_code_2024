fn main() {

    let puzzle_text = std::fs::read_to_string("puzzle_input.txt").unwrap();

    let mut left = Vec::new();
    let mut right = Vec::new();

    for pair in puzzle_text.split('\n') {
        let mut split_pair = pair.split_whitespace();
        left.push(split_pair.next().unwrap().parse::<i32>().unwrap());
        right.push(split_pair.next().unwrap().parse::<i32>().unwrap());
    }

    left.sort();
    right.sort();

    let mut diff = 0;
    for i in 0..left.len() {
        diff += abs(left[i] - right[i]);
    }

    println!("diff: {}", diff);
}


pub fn abs(a: i32) -> i32 {
    if a < 0 {
        return a - a - a
    } else {
        return a
    }
}