SHELL				=	/bin/zsh
# Executable name
NAME1				=	checker
NAME2				=	push_swap
LIBFT				=	libft.a
# Compilation mode
WALL				=   yes
WEXTRA              =   yes
WERROR              =   yes
FSANITIZE           =   yes
DEBUG               =   yes
O2                  =   yes
CC                  :=  gcc
GEN                 :=  "Generation in mode"
ifeq ($(WALL), yes)
   CC              :=  $(CC) -Wall
   GEN             :=  $(GEN) all
endif
ifeq ($(WEXTRA), yes)
   CC              :=  $(CC) -Wextra
   GEN             :=  $(GEN) extra
endif
ifeq ($(WERROR), yes)
   CC              :=  $(CC) -Werror
   GEN             :=  $(GEN) error
endif
ifeq ($(FSANITIZE), yes)
   CC              :=  $(CC) -fsanitize=address
   GEN             :=  $(GEN) sanitize
endif
ifeq ($(DEBUG), yes)
   CC              :=  $(CC) -g3
   GEN             :=  $(GEN) debug
endif
ifeq ($(O2),yes)
   CC              :=  $(CC) -O2 -flto -march=native
   GEN             :=  $(GEN) O2
endif
ifeq ($(GEN), "Generation in mode")
   GEN             :=  $(GEN) no flags
endif

# Name

LIB_NAME			=	ft_atoi.c 				\
						ft_bzero.c 				\
						ft_calloc.c				\
						ft_isalnum.c			\
						ft_isalpha.c			\
						ft_isascii.c			\
						ft_isdigit.c			\
						ft_isprint.c			\
						ft_itoa.c				\
						ft_memccpy.c			\
						ft_memchr.c				\
						ft_memcmp.c				\
						ft_memcpy.c				\
						ft_memmove.c			\
						ft_memset.c				\
						ft_putchar_fd.c			\
						ft_putendl_fd.c			\
						ft_putnbr_fd.c			\
						ft_putnbr_base.c		\
						ft_putstr_fd.c			\
						ft_split.c				\
						ft_strchr.c				\
						ft_strdup.c				\
						ft_strjoin.c			\
						ft_strjoinfree.c		\
						ft_strlcat.c			\
						ft_strlcpy.c			\
						ft_strlen.c				\
						ft_strmapi.c			\
						ft_strncmp.c			\
						ft_strnstr.c			\
						ft_strrchr.c			\
						ft_strtrim.c			\
						ft_substr.c				\
						ft_tolower.c			\
						ft_toupper.c			\
						ft_isinset.c			\
						ft_join_tab.c			\
						ft_push_tab.c			\
						ft_macro.c				\
						ft_print_nbr.c			\
						ft_print_unbr.c			\
						ft_print_unbr_utils.c	\
						ft_print_cs.c			\
						ft_print_n.c			\
						ft_printf.c				\
						ft_lstadd_back_bonus.c 	\
						ft_lstadd_front_bonus.c	\
						ft_lstclear_bonus.c		\
						ft_lstdelone_bonus.c	\
						ft_lstiter_bonus.c		\
						ft_lstlast_bonus.c		\
						ft_lstmap_bonus.c		\
						ft_lstnew_bonus.c		\
						ft_lstsize_bonus.c		\

SRC_NAME			=	main.c					\
						lstint_tools.c			\
						lstint_tools2.c			\
						ps_push.c				\
						ps_rr.c					\
						ps_ss.c					\
						frees.c					\
						ops.c					\
						exit.c					\
						check.c					\
						print.c					\
						fill.c					\
						sort.c					\
						sort3a.c				\
						sort3b.c				\
						sort3_tools.c			\
						append.c				\
						merge.c					\
						append_sorted.c			\
						merge_front.c			\

INCLUDE_NAME		=	libft.h					\
						ft_printf.h				\
						push_swap.h				\

# Path
SRC_PATH			=	./src/
LIB_PATH			=	./libft/
OBJ_PATH			=	./obj/
OBJ_LIB_PATH		=	./libft/obj/
INCLUDE_PATH		=	./include/
# Name + Path
SRC					=	$(addprefix $(SRC_PATH),		$(SRC_NAME))
LIB					=	$(addprefix $(LIB_PATH),		$(LIB_NAME))
OBJ_LIB				=	$(patsubst  $(LIB_PATH)%.c,		$(OBJ_LIB_PATH)%.o, $(LIB))
OBJ					=	$(patsubst  $(SRC_PATH)%.c,		$(OBJ_PATH)%.o, $(SRC))
INCLUDE				=	$(addprefix $(INCLUDE_PATH),	$(INCLUDE_NAME))

# Text format
_DEF                =   $'\033[0m
_END                =   $'\033[0m
_GRAS               =   $'\033[1m
_SOUL               =   $'\033[4m
_CLIG               =   $'\033[5m
_SURL               =   $'\033[7m
# Colors
_BLACK              =   $'\033[30m
_RED                =   $'\033[31m
_GREEN              =   $'\033[32m
_YELLOW             =   $'\033[33m
_BLUE               =   $'\033[34m
_PURPLE             =   $'\033[35m
_CYAN               =   $'\033[36m
_GREY               =   $'\033[37m
# Background
_IBLACK             =   $'\033[40m
_IRED               =   $'\033[41m
_IGREEN             =   $'\033[42m
_IYELLOW            =   $'\033[43m
_IBLUE              =   $'\033[44m
_IPURPLE            =   $'\033[45m
_ICYAN              =   $'\033[46m
_IGREY              =   $'\033[47m

.PHONY: all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ) $(LIBFT)
	@echo "\n$(NAME1) : $(GEN)"
	@echo "\n$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)      COMPILING $(NAME1)$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@$(CC) -o $(NAME1) -I $(INCLUDE_PATH) $(OBJ) $(LIBFT)
	@echo "\n$(_WHITE)$(_BOLD)$@\t$(_END)$(_GREEN)[OK]\n$(_END)"

$(NAME2): $(OBJ) $(LIBFT)
	@echo "\n$(NAME2) : $(GEN)"
	@echo "\n$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)      COMPILING $(NAME2)$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@$(CC) -o $(NAME2) -I $(INCLUDE_PATH) $(OBJ) $(LIBFT)
	@echo "\n$(_WHITE)$(_BOLD)$@\t$(_END)$(_GREEN)[OK]\n$(_END)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCLUDE)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -I $(INCLUDE_PATH) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)\t"	\
		"COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"

$(LIBFT): $(OBJ_LIB)
	@echo "$(_YELLOW)      COMPILING $(LIBFT)$(_END)"
	@ar rc $(LIBFT) $(OBJ_LIB)
	@ranlib $(LIBFT)

$(OBJ_LIB_PATH)%.o: $(LIB_PATH)%.c $(INCLUDE)
	@mkdir -p $(OBJ_LIB_PATH)
	@$(CC) -I $(INCLUDE_PATH) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)\t"	\
		"COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"

clean:
	@rm -rf $(OBJ_PATH) $(OBJ_LIB_PATH)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(OBJ_PATH) \\n \\t\\t $(OBJ_LIB_PATH)"$(_END)"

fclean: clean
	@rm -f $(NAME1) $(NAME2) $(LIBFT)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(NAME1) $(NAME2) \\n\\t\\t $(LIBFT)

re: fclean all