# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cperrard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:05:51 by cperrard          #+#    #+#              #
#    Updated: 2018/09/17 13:28:00 by cperrard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	./src/ft_atoi.c \
		./src/ft_check_arg.c \
		./src/ft_check_arg_2.c \
		./src/ft_check_flags.c \
		./src/ft_htoa.c \
		./src/ft_htoa2.c \
		./src/ft_itoa.c \
		./src/ft_itoa2.c \
		./src/ft_itoa3.c \
		./src/ft_memdel.c \
		./src/ft_other.c \
		./src/ft_other2.c \
		./src/ft_other3.c \
		./src/ft_other4.c \
		./src/ft_otoa.c \
		./src/ft_prec_min_nbr.c \
		./src/ft_prec_min_oxu.c \
		./src/ft_prec_min_p.c \
		./src/ft_prec_min_str.c \
		./src/ft_precision.c \
		./src/ft_precision2.c \
		./src/ft_print_char.c \
		./src/ft_print_hexa.c \
		./src/ft_print_nbr.c \
		./src/ft_print_octal.c \
		./src/ft_print_p.c \
		./src/ft_print_str.c \
		./src/ft_print_unsigned.c \
		./src/ft_printf.c \
		./src/ft_putchar.c \
		./src/ft_putstr.c \
		./src/ft_strcmp.c \
		./src/ft_strdup.c \
		./src/ft_strlen.c \
		./src/ft_utoa.c \

SRCO = ./ft_atoi.o \
		./ft_check_arg.o \
		./ft_check_arg_2.o \
		./ft_check_flags.o \
		./ft_htoa.o \
		./ft_htoa2.o \
		./ft_itoa.o \
		./ft_itoa2.o \
		./ft_itoa3.o \
		./ft_memdel.o \
		./ft_other.o \
		./ft_other2.o \
		./ft_other3.o \
		./ft_other4.o \
		./ft_otoa.o \
		./ft_prec_min_nbr.o \
		./ft_prec_min_oxu.o \
		./ft_prec_min_p.o \
		./ft_prec_min_str.o \
		./ft_precision.o \
		./ft_precision2.o \
		./ft_print_char.o \
		./ft_print_hexa.o \
		./ft_print_nbr.o \
		./ft_print_octal.o \
		./ft_print_p.o \
		./ft_print_str.o \
		./ft_print_unsigned.o \
		./ft_printf.o \
		./ft_putchar.o \
		./ft_putstr.o \
		./ft_strcmp.o \
		./ft_strdup.o \
		./ft_strlen.o \
		./ft_utoa.o \


HDR = ./inc/ft_printf.h

all : $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC)
	@ar rc $(NAME) $(SRCO)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
