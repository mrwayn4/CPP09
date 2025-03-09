#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int parseargs(char **av, std::vector<int>& v, int ac);
void sort(std::vector<int>&);