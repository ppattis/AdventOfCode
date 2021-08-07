mod utils;

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
	let mut wrapping_paper = 0;
	let mut ribbon = 0;
	
    for line in input
    {
	    let mut dimensions = [0; 3];
		for (i, v) in line.split('x').enumerate()
		{
			let value = v.parse::<i32>().unwrap();
			dimensions[i] = value;
		}
		
		let l = dimensions[0];
		let w = dimensions[1];
		let h = dimensions[2];
			
		let area_1 = l*w;
		let area_2 = w*h;
		let area_3 = h*l;
		let perim_1 = 2*l + 2*w;
		let perim_2 = 2*w + 2*h;
		let perim_3 = 2*h + 2*l;
		
		wrapping_paper += 2*area_1 + 2*area_2 + 2*area_3 + min(min(area_1, area_2), area_3);
		ribbon += min(min(perim_1, perim_2), perim_3) + l*w*h;

    }

    println!("Advent of Code 2015 Day 02 :");
	println!("  Part 1 : {}", wrapping_paper);
	println!("  Part 2 : {}", ribbon);
}