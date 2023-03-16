# VARIABLES
NAME		=	push_swap

BONUS		=	checker

CC			=	cc

RM			=	rm -rf

FLAGS		=	-Wall -Wextra -Werror

HEADER		=	push_swap.h

HEADER_B	=	checker.h

LIBFT		=	libft.a


# DIRECTORIES
D_HEADER	=	incs/

D_HEADER_B	=	incs_bonus/

D_SRCS		=	SRCS/

D_SRCS_B	=	SRCS_C/

D_OBJS		=	objs/

D_OBJS_B		=	objs/

D_LIBFT		=	libft/


# FILES SO_LONG
LST_SRCS		=	main.c \
					extract_data.c \
					utils.c \
					error.c \
					create_lsts.c \
					sort.c \
					instructions.c \
					instructions_double.c \
					check_sorted_list.c \
					algo.c \
					move_cost.c \
					total_moves.c \
					move_lst.c

LST_SRCS_B		=	checker.c \
					extract_data_bonus.c \
					error_bonus.c \
					utils_bonus.c \
					create_lsts_bonus.c \
					sort_bonus.c \
					instructions_bonus.c \
					instructions_double_bonus.c \
					check_sorted_list_bonus.c \
					valid_instruction.c


LST_OBJS	=	$(LST_SRCS:.c=.o)

LST_OBJS_B	=	$(LST_SRCS_B:.c=.o)

SRCS		=	$(addprefix $(D_SRCS), $(LST_SRCS))

SRCS_B		=	$(addprefix $(D_SRCS_B), $(LST_SRCS_B))

INCS		=	$(addprefix $(D_HEADER), $(HEADER))

INCS_B		=	$(addprefix $(D_HEADER_B), $(HEADER_B))

OBJS		=	$(addprefix $(D_OBJS), $(LST_OBJS))

OBJS_B		=	$(addprefix $(D_OBJS_B), $(LST_OBJS_B))

LIBFTLIB	=	$(addprefix $(D_LIBFT), $(LIBFT))


# RULES
all		:	lib $(NAME)

lib :
		$(MAKE) -C $(D_LIBFT)

$(NAME)	:	$(OBJS)
			$(CC) $(OBJS) $(LIBFTLIB) -o $(NAME)

$(D_OBJS)%.o	:	$(D_SRCS)%.c $(INCS) Makefile $(LIBFTLIB)
					mkdir -p $(D_OBJS)
					$(CC) $(FLAGS) -I $(D_HEADER) -c $< -o $@

bonus	:	lib $(OBJS_B)
			$(CC) $(OBJS_B) $(LIBFTLIB) -o $(BONUS)

$(D_OBJS_B)%.o	:	$(D_SRCS_B)%.c $(INCS_B) Makefile $(LIBFTLIB)
					mkdir -p $(D_OBJS_B)
					$(CC) $(FLAGS) -I $(D_HEADER_B) -c $< -o $@

clean	:
			$(RM) $(OBJS)
			$(RM) $(OBJS_B)
			$(RM) $(D_OBJS)
			$(RM) $(D_OBJS_B)
			$(MAKE) clean -C $(D_LIBFT)

fclean	:
			$(MAKE) clean
			$(RM) $(NAME)
			$(RM) $(BONUS)
			$(MAKE) fclean -C $(D_LIBFT)

re		:	fclean all

.PHONY	:	all clean fclean re lib bonus
