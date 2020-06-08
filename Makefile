GPP = g++
NAME = sfml-app
LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJ_DIR = obj
SRC_DIR = src
OBJ = $(OBJ_DIR)/main.o \
	  $(OBJ_DIR)/game.o \
	  $(OBJ_DIR)/entity.o\
	  $(OBJ_DIR)/enemy.o\
	  $(OBJ_DIR)/food.o\
	  $(OBJ_DIR)/player.o\
	  $(OBJ_DIR)/handle_text.o\
	  $(OBJ_DIR)/renderer.o\
	  $(OBJ_DIR)/updater.o
OBJ_PATH = ./$(OBJ_DIR)/
SRC_PATH = ./$(SRC_DIR)/


$(NAME): $(OBJ_DIR) $(OBJ)
	$(GPP) $(OBJ_PATH)*.o $(LINKER_FLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_PATH)main.o: $(SRC_PATH)main.cpp
	$(GPP) -c -o $@ $<

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp $(SRC_PATH)%.hpp
	$(GPP) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)
	rm $(NAME)
