use itertools::Itertools;
use std::collections::HashMap;
use std::collections::HashSet;
use std::iter::once;

pub fn solve(input: &str) -> Option<HashMap<char, u8>> {
    let (lhs, rhs) = input.split_once(" == ").unwrap();
    let lhs: Vec<&str> = lhs.split(" + ").map(|s| s.trim()).collect();
    let rhs = rhs.trim();
    let chars: HashSet<char> = lhs
        .iter()
        .chain(once(&rhs))
        .flat_map(|s| s.chars())
        .collect();

    let firsts: HashSet<char> = lhs
        .iter()
        .chain(once(&rhs))
        .map(|s| s.chars().next().unwrap())
        .collect();

    (0..=9u8)
        .rev()
        .permutations(chars.len())
        .map(|vec| {
            chars
                .iter()
                .cloned()
                .zip(vec.into_iter())
                .collect::<HashMap<char, u8>>()
        })
        .filter(|map| firsts.iter().all(|char| map.get(&char).unwrap_or(&0) != &0))
        .find(|map| is_valid_map(map, &lhs, rhs))
}

fn is_valid_map(map: &HashMap<char, u8>, lhs: &Vec<&str>, rhs: &str) -> bool {
    word_to_num(map, rhs) == lhs.iter().map(|s| word_to_num(map, s)).sum::<u64>()
}

fn word_to_num(map: &HashMap<char, u8>, word: &str) -> u64 {
    word.chars()
        .map(|c| map.get(&c).unwrap())
        .fold(0u64, |acc, num| acc * 10 + *num as u64)
}
