NAME		:=	sed
CLASSES		:=	
CPP_FILES	:=	main.cpp functions.cpp

HPPS		:=	$(CLASSES:=.hpp)
CPPS		:=	$(CLASSES:=.cpp) $(CPP_FILES)
OBJS		:=	$(CPPS:.cpp=.o)

CXX			:=	g++
CPPFLAGS	:=	-Wall -Wextra -Werror
CXXFLAGS	:=	-std=c++98 -pedantic

PWD			:= 	$(shell pwd)
TEST_DIR	:=	test_files
TEST_FILES	:=	$(addprefix $(TEST_DIR)/, \
				empty_file one_line_file big_file invalid_line_file file_read file_written dir) \
				/private/etc/krb5.keytab main.cpp

all:		$(NAME)

$(NAME):	$(OBJS) $(HPPS)
			$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			@rm -f $(OBJS)
			@rm -rf $(TEST_DIR)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

test:		clean all
			@mkdir $(TEST_DIR)
			@bash ./generate_files.sh $(TEST_FILES) $(TEST_DIR)
			@bash ./test.sh $(TEST_FILES) $(TEST_DIR)

.PHONY:		all clean fclean re test
