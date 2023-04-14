//
//
//	Tests inspired by https://gehrcke.de/2011/06/reading-files-in-c-using-ifstream-dealing-correctly-with-badbit-failbit-eofbit-and-perror/
//
//


#include "functions.cpp"

#include <sstream>

#define OK "\x1b[32;49mOK\x1b[0m"
#define KO "\x1b[31;49mKO\x1b[0m"

void	assert_null(void *ptr)
{
	if (ptr == NULL)
		std::cout << OK << std::endl;
	else
		std::cout << KO << std::endl;
}

void	assert_not_null(void *ptr)
{
	if (ptr != NULL)
		std::cout << OK << std::endl;
	else
		std::cout << KO << std::endl;
}

void	assert_str_equal(std::string s1, char *s2)
{
	if (s1 == s2)
		std::cout << OK << std::endl;
	else
		std::cout << KO << std::endl;
}

void	assert_str_size(std::string str, int size)
{
	if (str && str.length() == size)
		std::cout << OK << std::endl;
	else
		std::cout << KO << std::endl;
}

void	test_read_non_existing_file(char *filename)
{
	assert_null(read_file(filename));
}

void	test_read_empty_file(char *filename)
{
	assert_str_equal(read_file(filename), "");
}

void	test_read_big_file(char *filename, int expected_size)
{
	std::string	res = read_file(filename);
	assert_not_null(res);
	assert_
}

void	test_read_one_line_file(char *filename)
{
	read_file(filename);
}

void	test_read_invalid_line_file(char *filename)
{
	read_file(filename);
}

void	test_read_file_read(char *filename)
{
	read_file(filename);
}

void	test_read_file_written(char *filename)
{
	read_file(filename);
}

void	test_read_file_denied(char *filename)
{
	read_file(filename);
}

void	test_read_directory(void)
{
	read_file(filename);
}

void	test_write_non_existing_file(void)
{
}

void	test_write_file_override_content(void)
{
}

void	test_write_file_no_permission(void)
{
}

void	test_replace_works_like_std_replace(void)
{
}

void	test_replace_empty_orig(void)
{
}

void	test_replace_empty_s1(void)
{
}

void	test_replace_empty_s2(void)
{
}

int	main(int argc, char **argv)
{

	char	*ne_file = argv[1];
	char	*empty_file = argv[2];
	char	*big_file = argv[3];

	std::stringstream	ss;
	std::string			big_file_size_str = argv[4];
	int					big_file_size;
	ss << big_file_size_str;
	ss >> big_file_size;
	
	char	*one_line_file = argv[5];
	char	*invalid_line_file = argv[6];
	char	*file_read = argv[7];
	char	*file_written = argv[8];
	char	*file_denied = argv[9];
	char	*directory = argv[10];

	test_read_non_existing_file(ne_file);
}
