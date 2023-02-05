NAME = roots

CC = g++

FILES = \
	input.cpp \
	engine.cpp \
	main.cpp \
	player.cpp \
	render.cpp \
	update.cpp \
	hitbox.cpp \
	collision.cpp

SRC_DIR = ./src
SRC := $(patsubst %, $(SRC_DIR)/%, $(FILES))

OBJ_DIR = ./obj
OBJ = $(patsubst %, $(OBJ_DIR)/%, $(FILES:.cpp=.o))

HEADERS = \
	-I /opt/homebrew/Cellar/sfml/2.5.1_2/include

FLAGS = \
	-Wall -Wextra -Werror -flto -Ofast

LIBLINKS = \
	-L /opt/homebrew/Cellar/sfml/2.5.1_2/lib \
	-lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(HEADERS) $(LIBLINKS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(HEADERS) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	/bin/rm -rf $(OBJ_DIR)

fclean: clean clean-sfml
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean clean-sfml fclean re
