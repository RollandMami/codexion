CC = cc
CFLAGS = -Wall -Werror -Wextra
EFLAGS = -Icoders/include -Icoders/libutils

BUILD = build
BIN = $(BUILD)/bin
NAME = $(BIN)/codexion
OBJDIR = $(BUILD)/obj

UTILS_DIR = coders/libutils
UTILS = $(UTILS_DIR)/libutils.a

SRC = coders/main.c\
	  coders/src/parse_input.c\
	  coders/src/parse_utils.c\
	  coders/src/coders.c\

OBJ = $(SRC:coders/%.c=$(OBJDIR)/%.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(UTILS)
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(OBJ) -L$(UTILS_DIR) -lutils -o $(NAME)

$(UTILS):
	$(MAKE) -C $(UTILS_DIR)

$(OBJDIR)/%.o: coders/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(EFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)
	$(MAKE) -C $(UTILS_DIR) clean

fclean: clean
	$(RM) $(BUILD)
	$(MAKE) -C $(UTILS_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
