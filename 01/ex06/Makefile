NAME		:=	HarlFilter
CLASSES		:=	Harl
CPP_FILES	:=	main.cpp

HPPS		:=	$(CLASSES:=.hpp)
CPPS		:=	$(CLASSES:=.cpp) $(CPP_FILES)
OBJS		:=	$(CPPS:.cpp=.o)

CXX			:=	g++
CPPFLAGS	:=	-Wall -Wextra -Werror
CXXFLAGS	:=	-std=c++98 -pedantic

all:		$(NAME)

$(NAME):	$(OBJS) $(HPPS)
			$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

test:		all
			./$(NAME) DEBUG
			./$(NAME) INFO
			./$(NAME) WARNING
			./$(NAME) ERROR
			./$(NAME) sjdghfjgh

.PHONY:		all clean fclean re
