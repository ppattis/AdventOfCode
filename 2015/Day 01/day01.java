//
//  Advent of Code 2015
//  Day 01
//
//  By PatchesTheDipstick
//

import java.io.FileReader;
import java.lang.StringBuilder;
import java.util.Scanner;


class AoC2015Day01
{
	
	public static void main(String[] args)
	{
		String input;
		try
		{
			Scanner inFile = new Scanner(new FileReader("input.txt"));
			
			StringBuilder inBuilder = new StringBuilder();
			while (inFile.hasNext())
			{
				inBuilder.append(inFile.next());
			}
			inFile.close();
			input = inBuilder.toString();
		} catch (Exception e)
		{
			System.out.println("Oops...");
			return;
		}
		int floorEndedOn = 0;
		int pointWentUnderground = 0;
		int currFloor = 0;
		boolean hasGoneUnder = false;
		for (int index = 0; index < input.length(); ++index)
		{
			if (input.charAt(index) == '(')
				currFloor++;
			else
				currFloor--;
			if (!hasGoneUnder && currFloor < 0)
			{
				hasGoneUnder = true;
				pointWentUnderground = index + 1;
			}
		}
		floorEndedOn = currFloor;
		
		System.out.println("Advent of Code 2015 Day 01:");
		System.out.println("    Answer one: " + floorEndedOn);
		System.out.println("    Answer two: " + pointWentUnderground);
	
	}

}