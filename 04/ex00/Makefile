NAME		:=	animal
CLASSES		:=	Animal WrongAnimal Cat WrongCat Dog
CPP_FILES	:=	main.cpp

HPPS		:=	$(CLASSES:=.hpp)
CPPS		:=	$(CLASSES:=.cpp) $(CPP_FILES)
OBJS		:=	$(CPPS:.cpp=.o)

CXX			:=	c++
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

.PHONY:		all clean fclean re
