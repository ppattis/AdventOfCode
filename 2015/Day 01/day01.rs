use std::env;
use std::fs;

fn main()
{
    let contents = fs::read_to_string("input.txt")
	    .expect("Something F'ed up!");
		
	let mut current_floor = 0;
	let mut when_underground = 0;
	let mut count = 0;
	for c in contents.chars()
	{
		count = count + 1;
		if c == '(' 
		{
			current_floor = current_floor + 1;
		}
		if c == ')'
		{
			current_floor = current_floor - 1;
			if current_floor < 0 && when_underground == 0
			{
				when_underground = count;
			}
		}
	}
	println!("AoC 2015 Day 01 :");
	println!("  Part 1 : {}", current_floor);
	println!("  Part 2 : {}", when_underground);
}