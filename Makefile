CC      := gcc
CFLAGS  := -Wall -Wextra -Wpedantic
RELEASE_FLAGS := -O2 -DNDEBUG

SRC_DIR     := src
BUILD_DIR   := build
RELEASE_DIR := release

# Finds all .c files in the source directory
SRC   := $(wildcard $(SRC_DIR)/*.c)

# Pattern substitution: maps src/*.c files to build/*.o object files
OBJ   := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Pattern substitution: maps src/*.c files to final release executables
BINS  := $(SRC:$(SRC_DIR)/%.c=$(RELEASE_DIR)/%)

.PHONY: all clean run

all: $(BINS)

# Creates the build or release directories if they do not exist
$(BUILD_DIR) $(RELEASE_DIR):
	mkdir -p $@

# Compiles .c files into .o files; the '|' indicates an order-only 
# dependency on the build directory (it must exist, but needn't be newer)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Links object files into final executables in the release directory
$(RELEASE_DIR)/%: $(BUILD_DIR)/%.o | $(RELEASE_DIR)
	$(CC) $(RELEASE_FLAGS) $< -o $@

# Runs the first executable found in the BINS list
run: all
	./$(firstword $(BINS))

clean:
	rm -rf $(BUILD_DIR) $(RELEASE_DIR)
