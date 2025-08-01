
CFLAGS = -Wall -Wextra -Werror -MMD -MP
NAME = libft.a

# _____________________ SRC DIRECTORIES __________________________

DIR_BOOLEAN = boolean/ft_isalnum.c\
		boolean/ft_isalpha.c\
		boolean/ft_isascii.c\
		boolean/ft_isdigit.c\
		boolean/ft_isprint.c\
		boolean/ft_are_u_1_of_u.c\

DIR_FINDER = finder/ft_strchr.c\
		finder/ft_strrchr.c\
		finder/ft_strnstr.c\
		finder/ft_substr.c

DIR_STR_MANIPULATION = str_manipulation/ft_strjoin.c\
		str_manipulation/ft_strtrim.c\
		str_manipulation/ft_split.c\
		str_manipulation/ft_strmapi.c\
		str_manipulation/ft_striteri.c\
		str_manipulation/ft_strlcpy.c\
		str_manipulation/ft_strlcat.c\
		str_manipulation/ft_strdup.c\


DIR_STR_ANALYSIS = 	str_analysis/ft_strlen.c\
					str_analysis/ft_strncmp.c\
					str_analysis/ft_strcmp.c\

DIR_CONVERTION = convertion/ft_atoi.c\
		convertion/ft_itoa.c\
		convertion/ft_tolower.c\
		convertion/ft_toupper.c\

DIR_MEMORY = memory/ft_bzero.c\
		memory/ft_memchr.c\
		memory/ft_memcmp.c\
		memory/ft_memmove.c\
		memory/ft_memset.c \
		memory/ft_memcpy.c\
		memory/ft_calloc.c\

DIR_OUTPUT = output/ft_putchar_fd.c\
		output/ft_puthex.c\
		output/ft_putnbr_deci.c\
		output/ft_putstr_fd.c\
		output/ft_putnbr_fd.c\
		output/ft_printf.c\
		output/ft_putendl_fd.c


DIR_LIST = list/ft_lstnew.c\
		list/ft_lstadd_front.c\
		list/ft_lstadd_back.c\
		list/ft_lstclear.c\
		list/ft_lstdelone.c\
		list/ft_lstiter.c\
		list/ft_lstlast.c\
		list/ft_lstmap.c\
		list/ft_lstsize.c

# Define the source files
SRCS = $(DIR_BOOLEAN) $(DIR_FINDER) $(DIR_STR_MANIPULATION) $(DIR_STR_ANALYSIS) $(DIR_CONVERTION) $(DIR_MEMORY) $(DIR_OUTPUT) $(DIR_LIST) $(DIR_GNL)

# Setting up an custom error message
ERROR_MSG = "$(RED)[ERROR] Compilation failed$(RESET)"

# This will create a list of object files from the list of source files
OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

DEPS_DIR = .objs/
DEPS = $(addprefix $(DEPS_DIR), $(SRCS:.c=.d))

.PHONY: all clean fclean re
all: $(NAME)

# Compile the object files
$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@echo -n "$(BLUE)$(notdir $@) $(RESET)"
	@cc $(CFLAGS) -I . $< -c -o $@ && echo "$(GREEN)>>> SUCCESS $(RESET)" || { echo "$(ERROR_MSG)"; exit 1; }
-include $(OBJECT:.o=.d)
# Create lib with ar rc
${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS} || { echo "$(ERROR_MSG)"; exit 1; }
	@echo "$(GREEN)======================= All libft function has been compiled =======================$(RESET)"

# Clean it all up
clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f  $(NAME)

re: fclean all
	@echo "$(GREEN)======================= $(NAME) has been recompiled =======================$(RESET)"

-include $(DEPS)
# ________________ Color codes ________________________

RESET      = \033[0m
RED        = \033[31m
GREEN      = \033[32m
YELLOW     = \033[33m
BLUE       = \033[34m
MAGENTA    = \033[35m
CYAN       = \033[36m
WHITE      = \033[37m
BOLD       = \033[1m
