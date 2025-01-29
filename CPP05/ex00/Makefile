SRC = main.cpp  Bureaucrat.cpp
RM = rm -f
NAME = Bureaucrat
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = Bureaucrat.hpp
SRCO = $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(SRCO)
	$(CC) $(FLAGS) $^ -o $@
%.o: %.cpp $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@
clean:
	$(RM) $(SRCO)
fclean: clean
	$(RM) $(NAME)
re: fclean all