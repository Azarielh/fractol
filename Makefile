# Compilation Settings
CC =			cc
CFLAGS =		-Wall -Wextra -MMD -MP -I./libft -I./minilibx-linux
MLX_FLAGS =		-lmlx -lXext -lX11 -lm

NAME =			fractol

# _____________________  SRCS  __________________________

# libft dir
LIBFT_DIR =		libft/

# libft files
LIBFT_A =		libft.a
LIBFT_H =		libft.h

# MinilibX dir
MLX_DIR =		minilibx-linux/

# MinilibX files
MLX_A =			libmlx.a
MLX_H =			mlx.h

# FRACTOL file

FRACTOL_H = 	includes/fractol.h
MAIN = 			fractol.c

# FRACTOL dir

INC_DIR = 		includes/

HANDLERS = 		srcs/win_handler.c\
				srcs/controls/mouse_handler.c\
				srcs/controls/keys_handler.c\

RENDERS = 		srcs/fractals_tools.c\
				srcs/choose_fractal.c\
				srcs/render/mandelbrot.c\
				srcs/render/julia.c

COLORS =		srcs/colors/clr_initialization.c\
				srcs/colors/clr_tools.c\

SECURE_ACTION = srcs/secure_action/safe_init.c\
				srcs/secure_action/safe_win_opener.c\
				srcs/secure_action/clean_exit.c

OUTPUT = 		srcs/output/exit_error.c\
				srcs/output/instructions.c\

# Define the source files
SRCS = $(MAIN) $(OUTPUT) $(SECURE_ACTION) $(HANDLERS) $(RENDERS) $(COLORS) srcs/pars.c\

# _____________________  DEFINE OBJECT DESTINATION  __________________________

# This will create a list of object files from the list of source files
OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# _____________________  SRCS  __________________________

# Setting up an custom error message
COMPIL_ERROR = "$(RED)[ERROR] Compilation failed$(RESET)"
MISSING_FILE = "est manquant ou introuvable. Vérifiez que tous les fichiers source sont présents.\n"

.PHONY: all clean fclean re force
all: print-banner check_sources $(NAME)

# Print a banner
print-banner:
	@cols=$$(tput cols); \
	printf '%*s\n' "$${cols}" '' | tr ' ' '='; \
	echo "FRACTOL !"; \
	printf '%*s\n' "$${cols}" '' | tr ' ' '='

# Check source files
check_sources:
	@for file in $(SRCS); do \
		if [ ! -f $$file ]; then \
			printf "$(RED)[ERROR] Le fichier $$file "$(MISSING_FILE)" $(RESET)"; \
		fi; \
	done

# Compile the object files
$(OBJS_DIR)%.o: %.c 
	@mkdir -p $(dir $@)
	@printf "$(BLUE)$(notdir $@) $(RESET)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) $< -c -o $@ && echo "$(GREEN)>>> SUCCESS $(RESET)" || { echo "$(ERROR_MSG)"; exit 1; }
-include $(OBJECT:.o=.d)

# Create lib with ar rc
${NAME}: check_sources ${LIBFT_DIR} ${MLX_DIR} ${OBJS}
	@gcc ${CFLAGS} ${OBJS} -L$(LIBFT_DIR) -lft -L${MLX_DIR} -lmlx ${MLX_FLAGS} -o $(NAME) || { echo "$(ERROR_MSG)"; exit 1; }
	@echo "$(GREEN)=============== All Fractol function has been compiled ===============$(RESET)"

# Get libft``
$(LIBFT_DIR):
	@printf "$(YELLOW)1/  Building libft...........................................\n$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory || @printf "Issue while attempting compiling libft"
	@cp $(LIBFT_DIR)$(LIBFT_H) $(INC_DIR) && cp $(LIBFT_DIR)ansi_format.h $(INC_DIR)

# Get Mlx
${MLX_DIR}${MLX_A}:
	@printf "$(YELLOW)1/  Building MinilibX...........................................\n$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory || @printf "Issue while attempting compiling MiniLibX"

# Use to force libft to relink if something has changed within
force:

# Clean it all up
clean:
	@rm -rf $(OBJS_DIR) && echo "$(YELLOW)=============== All object files has been removed ===============$(RESET)"

fclean: clean
	@rm -f  $(NAME) && echo "$(YELLOW)=============== $(NAME) has been removed ===============$(RESET)"

re: fclean all

# ________________ Color codes ________________________

RESET      = \\033[0m
RED        = \\033[31m
GREEN      = \\033[32m
YELLOW     = \\033[33m
BLUE       = \\033[34m
MAGENTA    = \\033[35m
CYAN       = \\033[36m
WHITE      = \\033[37m
BOLD       = \\033[1m