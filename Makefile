CC = cc
CFLAGS = -Wall -Werror -Wextra
EFLAGS = -Iinclude

BUILD = build
BIN = $(BUILD)/bin
NAME = $(BIN)/codexion
OBJDIR = $(BUILD)/obj

SRC = main.c \
	  src/parse_input.c \
	  src/parse_utils.c \
	  src/coders.c

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


$(OBJDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(EFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(BUILD)

re: fclean all

.PHONY: all clean fclean re
