pub fn is_armstrong_number(num: u32) -> bool {
    let mut sum = 0u64;
    let mut n = num; //copying the num
    let mut digits = 0;
    while n != 0 {
        n /= 10;
        digits += 1;
    }
    let mut n = num; //again copying
    while n != 0 {
        sum += (n % 10).pow(digits) as u64;
        n /= 10;
    }
    sum == num as u64
}
