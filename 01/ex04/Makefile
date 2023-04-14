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
TEST_FILES	:=	empty_file one_line_file big_file invalid_line_file file_read file_written /private/etc/bashrc dir $(PWD)/main.cpp

all:		$(NAME)

$(NAME):	$(OBJS) $(HPPS)
			$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

test:		
			bash ./generate_files.sh $(TEST_FILES)
			bash ./test.sh $(TEST_FILES)

.PHONY:		all clean fclean re test
