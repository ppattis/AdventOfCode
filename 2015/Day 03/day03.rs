mod utils;
use std::collections::HashMap;

fn min(a: i32, b: i32) -> i32
{
	if a < b
	{
		a
	} else
	{
		b
	}
}


fn main()
{
    let input = utils::read_input_file("input.txt").expect("Could not load file...");
	let mut santa_one_x = 0;
	let mut santa_one_y = 0;
	let mut santa_two_x = 0;
	let mut santa_two_y = 0;
	let mut robo_x = 0;
	let mut robo_y = 0;
	let mut part_one = HashMap::new();
	let mut part_two = HashMap::new();
	let mut santa_or_nah = "santa";
	
	part_one.insert(format!("{},{}", santa_one_x.to_string(), santa_one_y.to_string()), 1);
	part_two.insert(format!("{},{}", santa_two_x.to_string(), santa_two_y.to_string()), 1);
	let robo_coord = format!("{},{}", robo_x.to_string(), robo_y.to_string());
	let a = part_two.entry(robo_coord).or_insert(0);
	*a += 1;
	
    for line in input
    {
		for direction in line.chars()
		{
			if direction == 'v'
			{
				santa_one_y -= 1;
				if santa_or_nah == "santa"
				{
					santa_two_y -= 1;
				} else
				{
					robo_y -= 1;
				}
			}
			if direction == '^'
			{
				santa_one_y += 1;
				if santa_or_nah == "santa"
				{
					santa_two_y += 1;
				} else
				{
					robo_y += 1;
				}
			}
			if direction == '<'
			{
				santa_one_x -= 1;
				if santa_or_nah == "santa"
				{
					santa_two_x -= 1;
				} else
				{
					robo_x -= 1;
				}
			}
			if direction == '>'
			{
				santa_one_x += 1;
				if santa_or_nah == "santa"
				{
					santa_two_x += 1;
				} else
				{
					robo_x += 1;
				}
			}
			let one_coord = format!("{},{}", santa_one_x.to_string(), santa_one_y.to_string());
			let one = part_one.entry(one_coord).or_insert(0);
	        *one += 1;
			let mut two_coord = String::new();
            if santa_or_nah == "santa"
			{
				two_coord = format!("{},{}", santa_two_x.to_string(), santa_two_y.to_string());
				santa_or_nah = "nah";
			} else
			{
				two_coord = format!("{},{}", robo_x.to_string(), robo_y.to_string());
				santa_or_nah = "santa";
			}
			let two = part_two.entry(two_coord).or_insert(0);
	        *two += 1;
		}
    }

    println!("Advent of Code 2015 Day 02 :");
	println!("  Part 1 : {}", part_one.len());
	println!("  Part 2 : {}", part_two.len());
}