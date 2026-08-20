# The binary this exercise builds
NAME := game

# Compiler and the gauntlet's mandatory flags //-Iraylib, when include -> look inside raylib/include
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17 -Iraylib/include

# List every .cpp file in the exercise here, too long I'm sorry
SRCS := main.cpp codes/unit.cpp codes/MarchingZone.cpp codes/Level.cpp codes/UnitZone.cpp codes/LevelManager.cpp codes/Levels/Level1.cpp codes/Levels/Level2.cpp codes/Levels/Level3.cpp codes/Levels/Level4.cpp codes/Levels/Level5.cpp codes/Levels/Level6.cpp codes/Levels/Level7.cpp codes/Levels/Level8.cpp
OBJS := $(SRCS:.cpp=.o)
RAYS := -Lraylib/lib -Wl,-rpath,'$$ORIGIN/raylib/lib' -lraylib

# `make` / `make all`: build the binary -Lraylib = look inside raylib libraries in /lib, finds the path to lib, also link to library.lib
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(RAYS)

# Compile each .cpp into a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# `make clean`: remove object files
clean:
	rm -f $(OBJS)

# `make fclean`: remove objects AND the binary
fclean: clean
	rm -f $(NAME)

# `make re`: rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re