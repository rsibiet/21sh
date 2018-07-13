# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomo-chan <tomo-chan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/10 10:00:41 by mressier          #+#    #+#              #
#    Updated: 2016/06/02 14:23:38 by rsibiet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

LIBFT_PATH = libft/
LIBFT = libft/libft.a

ifdef DEBUG
	FLAGS = -Wall -Wextra -Werror -g
else
	FLAGS = -Wall -Wextra -Werror
endif

TMP = .tmp/

INCLUDES = -I ./includes -I $(LIBFT_PATH)includes/

##Modify

##sources :

MAIN =		main.c \
			get_env.c \
			create_tree_and_launch.c \
			exit_shell.c \
			init_shell.c \
			core.c

EXEC_CMD =	exec_cmd_with_env_paths.c \
			get_cmd_and_argv.c \
			launch_exec_cmd.c \
			exec_built_in.c \
			exec_bin.c \
			exec_pipe.c \
			handle_cmd.c \
			exec_redir.c \
			exec_cmd_by_type.c \
			heredoc.c \
			get_fd_redir_flags.c

PATHS =		get_valid_paths.c \
			is_a_valid_dir_path.c

SIGNAL =	sig_handler.c \
			sig_handler_exec.c \
			sig_handler_heredoc.c

PARSER =	is_a_builtin_cmd.c \
			is_a_complete_exec_cmd.c \
			get_type_commande.c \
			replace_all_tilde.c \
			replace_dollar_var_by_env_var.c \
			get_var_in_dollar_var.c \
			parse_commande.c

DISPLAY =	ft_puterror_twopart.c \
			prompt.c \
			prompt_opt_v_env.c \
			usage_error.c \
			disp_help.c

BUILTIN =	ft_env_builtin.c \
			ft_exit_builtin.c \
			ft_setenv_builtin.c \
			ft_unsetenv_builtin.c \
			ft_env_parse_flags.c \
			ft_cd_builtin.c \
			parse_cd_cmd.c \
			cd_create_dir.c \
			set_env_with_params_values.c \
			move_dir.c \
			parse_cd_dir.c \
			ft_help_builtin.c \
			ft_help_builtin2.c \
			get_type_builtin.c \
			hashtable.c \
			hashtable_tools.c \
			sort_hashtable.c \
			hashtable_cmp.c

TOOLS =		save_env.c \
			cut_dir.c \
			is_separator.c \
			add_space_around_separator_char.c \
			is_a_direct_path.c \
			is_a_redir_char.c \
			sh_strintrim.c \
			is_quote.c \
			sh_strsplit.c \
			str_cmp_char.c \
			get_new_cmd_without_redir.c \
			delete_quote.c \
			create_list_with_dir_content.c

BINTREE =	new_bin.c \
			del_bin.c \
			create_tree.c \
			disp_tree.c \
			tree_on_semi_colons.c \
			tree_with_cmp.c \
			modif_t_bin.c \
			modif_branch.c \
			redir_left_right_modif.c \
			pipe_modif.c \
			get_output_name.c

THREAD =	ft_fork.c \
			ft_pipe.c

TERMCAPS =	termcaps_21sh.c \
			termcaps_21sh2.c \
			insert_char.c \
			command_21sh.c \
			move_cursor.c \
			move_cursor_3.c \
			historique_21sh.c \
			home_end_key.c \
			delete_cmd.c \
			research_in_hist.c \
			research_in_hist2.c \
			autocompletion.c \
			quotes_21sh.c \
			quotes_21sh2.c \
			brackets.c \
			brackets2.c \
			del_cmd_hist.c \
			copy_cut.c \
			copy_cut2.c \
			disp_cut_part.c \
			ctrl_d_21sh.c \
			save_history.c \
			ft_putchar_int.c \
			clear_screen.c \
			init_termcaps.c \
			stick_ext.c \
			nav_history.c

SRC_MAIN = $(addprefix srcs/main/, $(MAIN))

SRC_EXEC_CMD = $(addprefix srcs/exec_cmd/, $(EXEC_CMD))

SRC_PATHS = $(addprefix srcs/paths/, $(PATHS))

SRC_SIGNAL = $(addprefix srcs/signal/, $(SIGNAL))

SRC_PARSER = $(addprefix srcs/parser/, $(PARSER))

SRC_DISPLAY = $(addprefix srcs/display/, $(DISPLAY))

SRC_BUILTIN = $(addprefix srcs/built_in/, $(BUILTIN))

SRC_TOOLS = $(addprefix srcs/tools/, $(TOOLS))

SRC_BINTREE = $(addprefix srcs/bintree/, $(BINTREE))

SRC_THREAD = $(addprefix srcs/thread/, $(THREAD))

SRC_TERMCAPS = $(addprefix srcs/termcaps/, $(TERMCAPS))

SRCS = $(SRC_MAIN) $(SRC_EXEC_CMD) $(SRC_PATHS) $(SRC_SIGNAL) $(SRC_PARSER) $(SRC_DISPLAY) $(SRC_BUILTIN) $(SRC_TOOLS) $(SRC_BINTREE) $(SRC_THREAD) $(SRC_TERMCAPS)

OBJ = $(SRCS:%.c=.tmp/%.o)

all: compile_lib prepare $(NAME)

compile_lib:
	@make -C $(LIBFT_PATH)

prepare:
	@mkdir -p .tmp/srcs/main
	@mkdir -p .tmp/srcs/exec_cmd
	@mkdir -p .tmp/srcs/paths
	@mkdir -p .tmp/srcs/signal
	@mkdir -p .tmp/srcs/parser
	@mkdir -p .tmp/srcs/display
	@mkdir -p .tmp/srcs/built_in
	@mkdir -p .tmp/srcs/tools
	@mkdir -p .tmp/srcs/bintree
	@mkdir -p .tmp/srcs/thread
	@mkdir -p .tmp/srcs/termcaps

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME) -L $(LIBFT_PATH) -lft -ltermcap
	@echo "\\n\033[36;1m $(NAME) has successfully been created ღ \033[0;0m\\n"

.tmp/%.o: %.c
	@tput civis
	@printf "\033[2K [ \033[36;1mcompiling $(NAME) \033[0m] $<\r"
	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $<
	@tput cnorm

clean:
	@echo "\033[41m[Clean objects in $(NAME)]\033[0;0m\\n"
	@rm -rf .tmp
	@rm -rf $(NAME).dSYM

fclean: clean
	@echo "\033[44m[Delete $(NAME)]\033[0;0m\\n"
	@rm -rf $(NAME)
	@rm -rf .tmp/

lclean : 
	@make -C $(LIBFT_PATH) clean

lfclean :
	@make -C $(LIBFT_PATH) fclean

allclean : lfclean fclean

lre: fclean all

re : fclean lfclean all
