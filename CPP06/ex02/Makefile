SRC = main.cpp  Base.cpp
RM = rm -f
NAME = identify
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = Base.hpp A.hpp B.hpp C.hpp
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