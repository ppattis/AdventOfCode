//
//  Advent of Code 2015
//  Day 21
//
//  By PatchesTheDipstick
//


//  System includes...

#include <vector>
#include <iostream>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

struct Player
{
	
	int cost;
	int hit_points;
	int damage;
	int armor;
	bool part_one_win;

bool takeDamage(int damage)
	{
		if (damage - armor <= 0)
		{
			hit_points--;
		}
		else
		{
			hit_points -= damage - armor;
		}
		if (hit_points <= 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};
	
bool fight(Player player, Player boss)
{
	bool return_value = false;
	while ((player.hit_points > 0) && (boss.hit_points > 0))
	{
		if (player.damage - boss.armor <=0)
		{
			boss.hit_points--;
		}
		else
		{
			boss.hit_points -= (player.damage - boss.armor);
		}
		if (boss.damage - player.armor <= 0)
		{
			player.hit_points--;
		}
		else
		{
			player.hit_points -= (boss.damage - player.armor);
		}
	}
	if (boss.hit_points <= 0)
	{
		return_value = true;
	}
	else
	{
		return_value = false;
	}
	return return_value;
}

int main(int argc, char** argv)
{
	std::vector<std::vector<int>> weapons = {{8, 4, 0}, {10, 5, 0}, {25, 6, 0}, {40, 7, 0}, {74, 8, 0}};
	std::vector<std::vector<int>> armor = {{0, 0, 0}, {13, 0, 1}, {31, 0, 2}, {53, 0, 3}, {75, 0, 4}, {102, 0, 5}};
	std::vector<std::vector<int>> rings = {{0, 0, 0}, {0, 0, 0}, {25, 1, 0}, {50, 2, 0}, {100, 3, 0}, {20, 0, 1}, {40, 0, 2}, {80, 0, 3}};
	
	std::vector<Player> players;
	Player new_player;
	Player boss = {0, 103, 9, 2};
	int player_count = 0;
	//  Assemble the vector of possible players...
	for (int a = 0; a < weapons.size(); a++)
	{
		for (int b = 0; b < armor.size(); b++)
		{
			for (int c = 0; c < rings.size(); c++)
			{
				for (int d = 0; d < rings.size(); d++)
				{
					if ((c > 1) && (d > 1) && (c == d))
					{
						//We are skipping this option as it is invalid....
					}
					else
					{
						
						new_player.hit_points = 100;
						new_player.cost = (weapons[a][0] + armor[b][0] + rings[c][0] + rings[d][0]);
						new_player.damage = (weapons[a][1] + armor[b][1] + rings[c][1] + rings[d][1]);
						new_player.armor = (weapons[a][2] + armor[b][2] + rings[c][2] + rings[d][2]);
						new_player.part_one_win = false;
						players.push_back(new_player);
						player_count++;
					}
				}
			}
		}
	}
	for (int a = 0; a < players.size(); a++)
	{
		players[a].part_one_win = fight(players[a], boss);
	}
	int answer_one = 999999999;
	int answer_two = 0;
	for (int a = 0; a < players.size(); a++)
	{
		if ((players[a].part_one_win) && (players[a].cost < answer_one))
		{
			answer_one = players[a].cost;
		}
		if ((!players[a].part_one_win) && (players[a].cost > answer_two))
		{
			answer_two = players[a].cost;
		}
	}
	std::cout << "Day 21 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_one << std::endl;
	std::cout << "    Part 2 : " << answer_two << std::endl;

	return (0);

}
