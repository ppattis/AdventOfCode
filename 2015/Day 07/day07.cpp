//
//  Advent of Code 2015
//  Day 01
//
//  By PatchesTheDipstick
//


//  System includes...

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

#define NT_VALUE  0
#define NT_SET    1
#define NT_AND    2
#define NT_OR     3
#define NT_LSHIFT 4
#define NT_RSHIFT 5
#define NT_NOT    6

class Input
{
	protected:
	
	unsigned int value;
	std::string output;
	
	public:
	void setValue(int new_value)
	{
		value = new_value;
	}
	
	std::string getOutput()
	{
		return output;
	}
	virtual int getValue() = 0;
};

class Schematic
{
	private:
	
	std::vector<Input *> gates;
	
	public:
	
	void clear()
	{
		gates.clear();
	}
	
	void addGate(Input *new_gate)
	{
		gates.push_back(new_gate);
	}
	
	void setGateValue(std::string output, int value)
	{
		bool keep_looking = true;
		for (int a = 0; a < gates.size() && keep_looking; a++)
		{
			if (gates[a]->getOutput() == output)
			{
				gates[a]->setValue(value);
				keep_looking = false;
			}
		}
	}
	
	int lookupValue(std::string wire)
	{
		int return_value = 0;
		bool keep_looking = true;
		
		if (isNumber(wire))
		{
			return_value = stoi(wire);
		}
		else
		{
			//std::cout << "Looking up the value on wire " << wire << std::endl;
			for (int a = 0; a < gates.size() && keep_looking; a++)
			{
				//std::cout << gates[a]->getOutput() << std::endl;
				if (gates[a]->getOutput() == wire)
				{
					return_value = gates[a]->getValue();
					keep_looking = false;
					
				}
			}
		}
		return (return_value);
	}
};

Schematic *circuit = new Schematic();
Schematic *circuit2 = new Schematic();

class WireInput : public Input
{
	private:
	
	std::string wire;
	
	public:
	
	WireInput(std::string new_wire, std::string new_output)
	{
		output = new_output;
		wire = new_wire;
		if (isNumber(wire))
		{
			value = stoi(wire);
		}
		else
		{
			value = 0;
		}
	}
	
	int getValue()
	{
		if (value == 0)
		{
			value = (circuit->lookupValue(wire));
		}
		return (value);
	}
};

class AndGate : public Input
{
	private:
	
	std::vector<std::string> operands;
	
	public:
	
	AndGate(std::string lho, std::string rho, std::string op)
	{
		output = op;
		operands.push_back(lho);
		operands.push_back(rho);
		value = 0;
	}
	
	int getValue()
	{
		if (value == 0)
		{
			value = (circuit->lookupValue(operands[0]) & circuit->lookupValue(operands[1]));
		}
		return value;
	}
};

class OrGate : public Input
{
	private:
	
	std::vector<std::string> operands;
	
	public:
	
	OrGate(std::string lho, std::string rho, std::string op)
	{
		output = op;
		operands.push_back(lho);
		operands.push_back(rho);
		value = 0;
	}
	
	int getValue()
	{
		//std::cout << "Or Gate value " << value << std::endl;
		if (value == 0)
		{
			value = (circuit->lookupValue(operands[0]) | circuit->lookupValue(operands[1]));
		}
		return value;
	}
};

class NotGate : public Input
{
	private:
	
	std::string wire;
	
	public:
	
	NotGate(std::string new_wire, std::string new_output)
	{
		output = new_output;
		wire = new_wire;
		if (isNumber(wire))
		{
			value = (~(stoi(wire)));
		}
		else
		{
			value = 0;
		}
	}
	
	int getValue()
	{
		if (value == 0)
		{
			value = (~(circuit->lookupValue(wire)));
		}
		return value;
	}
};

class LeftShift : public Input
{
	private:
	
	std::string wire;
	int shift;
	
	public:
	
	LeftShift(std::string new_wire, int new_shift, std::string new_output)
	{
		wire = new_wire;
		shift = new_shift;
		output = new_output;
		if (isNumber(wire))
		{
			value = (stoi(wire) << shift);
		}
		else
		{
			value = 0;
		}
	}
	
	int getValue()
	{
		if (value == 0)
		{
			value = (circuit->lookupValue(wire) << shift);
		}
		return value;
	}
};

class RightShift : public Input
{
	private:
	
	std::string wire;
	int shift;
	
	public:
	
	RightShift(std::string new_wire, int new_shift, std::string new_output)
	{
		//std::cout << "RightShift Constructor..." << std::endl;
		this->wire = new_wire;
		//std::cout << "wire assigned value..." << std::endl;
		this->shift = new_shift;
		//std::cout << "shift assigned value..." << std::endl;
		output = new_output;
		//std::cout << "output assigned value..." << std::endl;
		if (isNumber(wire))
		{
			//std::cout << "wire is a number..." << std::endl;
			value = (stoi(wire) >> shift);
		}
		else
		{
			//std::cout << "wire is not a number...." << std::endl;
			value = 0;
		}
		//std::cout << "Constructor complete..." << std::endl;
	}
	
	int getValue()
	{
		if (value == 0)
		{
			value = (circuit->lookupValue(wire) >> shift);
		}
		return value;
	}
};

void setCircuit(std::vector<std::string> input)
{
	for (int a = 1; a < input.size(); a++)
	{
		//std::cout << "<" << input[a] << ">" << std::endl;
		std::vector<std::string> line = parseLine(input[a], " ");
		//std::cout << "here" << std::endl;
		
		if (line[1] == "->")
		{
			//std::cout << "WireInput" << std::endl;
			circuit->addGate(new WireInput(line[0], line[2]));
		}
		
		else if (line[1] == "AND")
		{
			//std::cout << "AndGate" << std::endl;
			circuit->addGate(new AndGate(line[0], line[2], line[4]));
		}
		
		else if (line[1] == "OR")
		{
			//std::cout << "OrGate" << std::endl;
			circuit->addGate(new OrGate(line[0], line[2], line[4]));
		}
		
		else if (line[0] == "NOT")
		{
			//std::cout << "Not Gate" << std::endl;
			circuit->addGate(new NotGate(line[1], line[3]));
		}
		
		else if (line[1] == "LSHIFT")
		{
			//std::cout << "Left Shift" << std::endl;
			circuit->addGate(new LeftShift(line[0], stoi(line[2]), line[4]));
		}
		
		else
		{
			//std::cout << "Right Shift " << line.size() << std::endl;
			std::string wire = line[0];
			int shift = stoi(line[2]);
			std::string output = line[4];
			//std::cout << wire << " " << shift << " " << output << std::endl;
			circuit->addGate(new RightShift(wire, shift, output));
		}
	}
}	

int main(int argc, char** argv)
{
	
	std::vector<std::string> input = getInput("input.txt");
	setCircuit(input);
	int part_one = circuit->lookupValue("a");
	circuit->clear();
	setCircuit(input);
	circuit->setGateValue("b", part_one);
	int part_two = circuit->lookupValue("a");
	
	std::cout << "Advent of Code 2015 Day 07" << std::endl;
	std::cout << "Part one : " << part_one << std::endl;
	std::cout << "Part two : " << part_two << std::endl;
	
	return (0);
}
