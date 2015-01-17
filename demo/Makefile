NAME := demo

all: build

build: $(NAME).c
	gcc -o $(NAME) $< -lcurl -ljansson

test: build
	./$(NAME)

memcheck: $(NAME).c
	gcc -o $(NAME) $< -lcurl -ljansson -g -O0
	valgrind --tool=memcheck --leak-check=yes ./$(NAME)

clean:
	rm -f $(NAME)