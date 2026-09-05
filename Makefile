CC      := clang
CFLAGS  := -Wall -Wextra -std=c99 $(shell sdl2-config --cflags)
LDFLAGS := $(shell sdl2-config --libs) -lSDL2_image -lSDL2_mixer -lSDL2_ttf

SANFLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer -g -O0

SRC_DIR     := src
BUILD_DIR   := build
DEBUG_DIR   := $(BUILD_DIR)/debug
TARGET      := $(BUILD_DIR)/adventure
DEBUG_TARGET:= $(DEBUG_DIR)/adventure

# Recursively find all .c files under SRC_DIR (including subdirectories)
rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SRCS       := $(call rwildcard,$(SRC_DIR)/,*.c)
OBJS       := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEBUG_OBJS := $(SRCS:$(SRC_DIR)/%.c=$(DEBUG_DIR)/%.o)

.PHONY: all debug run run-debug clean

all: $(TARGET)

debug: $(DEBUG_TARGET)

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(DEBUG_TARGET): $(DEBUG_OBJS) | $(DEBUG_DIR)
	$(CC) $(DEBUG_OBJS) -o $@ $(LDFLAGS) $(SANFLAGS)

# mkdir -p on $(dir $@) so nested subdirectories under build/ get created
# on demand, since the object files now mirror src/'s subdirectory structure.
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(SANFLAGS) -c $< -o $@

$(BUILD_DIR) $(DEBUG_DIR):
	mkdir -p $@

run: all
	./$(TARGET)

run-debug: debug
	./$(DEBUG_TARGET)

clean:
	rm -rf $(BUILD_DIR)