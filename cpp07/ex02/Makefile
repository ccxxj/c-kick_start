NAME = Array
FLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude
SRCS = main.cpp
# SRCS = mainProvided.cpp
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	clang++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	clang++ -c $(FLAGS) -o $@ $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

