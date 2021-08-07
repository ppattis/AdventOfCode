//
//  Advent of Code 2015
//  Day 11
//
//  By PatchesTheDipstick
//


//  System includes...


//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

bool isValidPassword(std::string password)
{
	bool straight_count = false;
	for (int a = 0; a < password.length() - 2; a++)
	{
		if ( (password[a] + 1 == password[a + 1]) &&
		     (password[a + 1] + 1 == password[a + 2]))
		{
			straight_count = true;
		}
	}
	if (!straight_count)
	{
		return (false);
	}
	bool forbiden_letters = false;
	for (int a = 0; a < password.length(); a++)
	{
		if ((password[a] == 'i') || (password[a] == 'o') || (password[a] == 'l'))
		{
			forbiden_letters = true;
		}
	}
	if (forbiden_letters)
	{
		return (false);
	}
	bool pair_one = false, pair_two = false;
	for (int a = 0; a < password.length() - 1; a++)
	{
		if (password[a] == password[a + 1])
		{
			if (pair_one)
			{
				pair_two = true;
				break;
			}
			else
			{
				pair_one = true;
				a++;
			}
		}
	}
	if ( (!pair_one) || (!pair_two) )
	{
		return (false);
	}
	return (true);
}

void incrementCharacter(char& in_char)
{
	if (in_char == 'z')
	{
	    in_char = 'a';
	}
	else if ((in_char == 'h') || (in_char == 'n') || (in_char == 'k'))
	{
		in_char += 2;
	}
	else
	{
		in_char++;
	}

}

std::string nextPassword(std::string old_password)
{
	std::string return_value = old_password;
	
	do
	{
		for (int a = old_password.length() - 1; a >= 0; a--)
		{
			incrementCharacter(return_value[a]);
			if (return_value[a] != 'a')
				break;
		}
	} while (!isValidPassword(return_value));
	
	return (return_value);
}

int main(int argc, char** argv)
{
	
	std::string input = "hepxcrrq";
	
	char a = 'a', m = 'm', z = 'z';
	
	std::cout << a << ", " << m << ", " << z << ", ";
	incrementCharacter(a);
	incrementCharacter(m);
	incrementCharacter(z);
	std::cout << a << ", " << m << ", " << z << std::endl;
	std::string answer_1 = nextPassword(input);
	std::string answer_2 = nextPassword(answer_1);
	
	std::cout << "Advent of Code 2015 Day 11 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;

	return (0);

}
