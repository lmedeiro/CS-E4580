//============================================================================
// Name        : abundant.cc
// Author      : Luiz Fernando Medeiros
// Version     :
// Copyright   : Free to use, without any guarantees ! 
// Description : Prerequisite test: Generating N abundant numbers in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

int sum_items_in_array(vector<int> input_array)
{
	int sum_of_items = 0;
	vector<int>::const_iterator i;
	for (i=input_array.begin(); i != input_array.end(); ++i)
	{
		sum_of_items = sum_of_items + (*i);
	}
	return sum_of_items;
}

vector<int> get_proper_divisors(int number_to_check)
{
	int denominator = 1;
	vector<int> proper_divisors;
	int remainder = 0;
	while (denominator < number_to_check)
	{
		remainder = number_to_check % denominator;
		if(remainder == 0)
		{
			proper_divisors.push_back(denominator);
		}
		denominator++;
	}

	return proper_divisors;
}

int get_abundance(int number_to_check)
{
	vector<int> divisors = get_proper_divisors(number_to_check);
	int sum_of_divisors = sum_items_in_array(divisors);
	int abundance = sum_of_divisors - number_to_check;
	return abundance;
}

int main(int argc, char *argv[]) {
	int number_of_abundance_numbers = atoi(argv[1]);
	int number_to_check = 1;
	while (number_of_abundance_numbers>0)
	{
		int abundance = get_abundance(number_to_check);
		if (abundance > 0)
		{
			number_of_abundance_numbers--;
			cout << number_to_check << '\n';
		}
		number_to_check++;
	}
	return 0;
}
