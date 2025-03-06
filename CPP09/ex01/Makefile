SRC = main.cpp RPN.cpp
RM = rm -f
NAME = RPN
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = RPN.hpp
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