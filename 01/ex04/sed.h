#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

std::string	read_file(std::string filename);
void		write_file(std::string filename, std::string content);
std::string	replace(std::string orig, char *s1, char *s2);
