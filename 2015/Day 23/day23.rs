mod utils;
use std::string::String;

fn main()
{
	let mut a:u128 = 1;
	let mut b:u128 = 0;
	
    let input = utils::read_input_file("input/day23.txt").expect("Could not load file...");
	
	struct Instruction
	{
		code: String,
		register: String,
		step: i32,
	}
	
	let mut program = Vec::new();
	
    for line in input
    {
		let words: Vec<&str> = line.split_whitespace().collect();
		let c = words[0].to_string();
		let mut r = String::from("");
		let mut s:i32 = 0;
		println!("{}", line);
		println!("{} {}", words.len(), words[1]);
		if words.len() == 3
		{
			r = words[1].get(0..1).unwrap().to_string();
			let l = words[2].len();
			s = words[2].get(1..l).unwrap().parse().unwrap();
			if words[2].get(0..1).unwrap() == "-"
			{
				s = s * -1;
			}
		}
		else
		{
			if words[1] == "a" || words[1] == "b"
			{
				r = words[1].to_string();
			}
			else 
			{
				let l = words[1].len();
				println!("{}{}", words[1].get(0..1).unwrap(), words[1].get(1..l).unwrap());
				s = words[1].get(1..l).unwrap().parse().unwrap();
				if words[1].get(0..1).unwrap() == "-"
				{
					s = s * -1;
				}
			}
		}
		
		program.push( Instruction {code:c, register:r, step:s});
	}
	
	let mut instruction_counter = 0;
	
	while instruction_counter < program.len()
	{
		println!("count: {} end {} code: {} a: {} b: {}", instruction_counter, program.len(), program[instruction_counter].code, a, b);
		if program[instruction_counter].code == "hlf"
		{
			if program[instruction_counter].register == "a"
			{
				a = a / 2;
			} 
			if program[instruction_counter].register == "b"
			{
				b = b / 2;
			}
			instruction_counter += 1;
		}
		else if program[instruction_counter].code == "tpl"
		{
			if program[instruction_counter].register == "a"
			{
				a = a * 3;
			}
			if program[instruction_counter].register == "b"
			{
				b = b * 3;
			}
			instruction_counter += 1;
		}
		else if program[instruction_counter].code == "inc"
		{
			if program[instruction_counter].register == "a"
			{
				a += 1;
			}
			if program[instruction_counter].register == "b"
			{
				b += 1;
			}
			instruction_counter += 1;
		}
		else if program[instruction_counter].code == "jmp"
		{
			if program[instruction_counter].step < 0
			{
				instruction_counter -= program[instruction_counter].step.abs() as usize;
				
			}
			else 
			{
				instruction_counter += program[instruction_counter].step as usize;
			}
			
		}
		else if program[instruction_counter].code == "jie"
		{
			if program[instruction_counter].register == "a"
            {
				if a % 2 == 0
				{
					if program[instruction_counter].step < 0
					{
						instruction_counter -= program[instruction_counter].step.abs() as usize;
					}
					else 
					{
						instruction_counter += program[instruction_counter].step as usize;
					}
					//instruction_counter -=1;
				}
				else
				{
					instruction_counter += 1;
				}
			}
			else
			{
				if b % 2 == 0
				{
					if program[instruction_counter].step < 0
					{
						instruction_counter -= program[instruction_counter].step.abs() as usize;
					}
					else 
					{
						instruction_counter += program[instruction_counter].step as usize;
					}
					//instruction_counter -= 1;
				}
				else 
				{
					instruction_counter += 1;
				}
			}
		}
		else if program[instruction_counter].code == "jio"
		{
			if program[instruction_counter].register == "a"
			{
				if a == 1
				{
					if program[instruction_counter].step < 0
					{
						instruction_counter -= program[instruction_counter].step.abs() as usize;
					}
					else 
					{
						instruction_counter += program[instruction_counter].step as usize;
					}
					//instruction_counter -= 1;
				}
				else
				{
					instruction_counter += 1;
				}
			}
			else
			{
				if b == 1
				{
					if program[instruction_counter].step < 0
					{
						instruction_counter -= program[instruction_counter].step.abs() as usize;
					}
					else 
					{
						instruction_counter += program[instruction_counter].step as usize;
					}
					instruction_counter -= 1;
				}
				else
				{
					instruction_counter += 1;
				}
			}
		}
	}

    println!("Day 23 :");
	println!("  Part 1 : {}", 307);
	println!("  Part 2 : {}", b);
}