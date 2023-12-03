##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile
##

NAME		=	nanotekspice

CFLAGS		=	-I$(EXCEPT_DIR) -I$(PARSER_DIR) -I$(CIRCUIT_DIR) -I$(COMPO_DIR) -I$(PIN_DIR) -I$(INPUT_DIR) -I$(OUTPUT_DIR) -I$(TRUE_DIR) -I$(FALSE_DIR) -I$(CLOCK_DIR) -I$(AND_DIR) -I$(OR_DIR) -I$(XOR_DIR) -I$(NOT_DIR) -I$(C4001_DIR) -I$(C4008_DIR) -I$(C4011_DIR) -I$(C4013_DIR) -I$(C4030_DIR) -I$(C4040_DIR) -I$(C4069_DIR) -I$(C4071_DIR) -I$(C4081_DIR) -I$(C4094_DIR)

CPPFLAGS	=	 -std=c++20 -W -Wall -Wextra -Werror $(CFLAGS)

SRC_DIR		=	./src/

TEST_DIR	=	./tests/

EXCEPT_DIR	=	$(SRC_DIR)Exception/

PARSER_DIR	=	$(SRC_DIR)Parser/

CIRCUIT_DIR	=	$(SRC_DIR)Circuit/

COMPO_DIR	=	$(SRC_DIR)Components/

PIN_DIR		=	$(COMPO_DIR)Pin/

INPUT_DIR	=	$(COMPO_DIR)Input/
OUTPUT_DIR	=	$(COMPO_DIR)Output/
TRUE_DIR	=	$(COMPO_DIR)True/
FALSE_DIR	=	$(COMPO_DIR)False/
CLOCK_DIR	=	$(COMPO_DIR)Clock/
AND_DIR		=	$(COMPO_DIR)AND/
OR_DIR		=	$(COMPO_DIR)OR/
XOR_DIR		=	$(COMPO_DIR)XOR/
NOT_DIR		=	$(COMPO_DIR)NOT/
C4001_DIR 	=	$(COMPO_DIR)C4001/
C4008_DIR 	=	$(COMPO_DIR)C4008/
C4011_DIR 	=	$(COMPO_DIR)C4011/
C4013_DIR 	=	$(COMPO_DIR)C4013/
C4030_DIR 	=	$(COMPO_DIR)C4030/
C4040_DIR 	=	$(COMPO_DIR)C4040/
C4069_DIR 	=	$(COMPO_DIR)C4069/
C4071_DIR 	=	$(COMPO_DIR)C4071/
C4081_DIR 	=	$(COMPO_DIR)C4081/
C4094_DIR	=	$(COMPO_DIR)C4094/

SRCS		=	$(SRC_DIR)main.cpp			\
				$(SRC_DIR)NanoTekSpice.cpp	\
				$(EXCEPT_DIR)Exception.cpp	\
				$(PARSER_DIR)Parser.cpp		\
				$(CIRCUIT_DIR)Circuit.cpp	\
				$(PIN_DIR)Pin.cpp			\
				$(INPUT_DIR)Input.cpp		\
				$(OUTPUT_DIR)Output.cpp		\
				$(TRUE_DIR)True.cpp			\
				$(FALSE_DIR)False.cpp		\
				$(CLOCK_DIR)Clock.cpp		\
				$(AND_DIR)AND.cpp			\
				$(OR_DIR)OR.cpp				\
				$(XOR_DIR)XOR.cpp			\
				$(NOT_DIR)NOT.cpp			\
				$(C4001_DIR)C4001.cpp		\
				$(C4008_DIR)C4008.cpp		\
				$(C4011_DIR)C4011.cpp		\
				$(C4013_DIR)C4013.cpp		\
				$(C4030_DIR)C4030.cpp		\
				$(C4040_DIR)C4040.cpp		\
				$(C4069_DIR)C4069.cpp		\
				$(C4071_DIR)C4071.cpp		\
				$(C4081_DIR)C4081.cpp		\
				$(C4094_DIR)C4094.cpp		\

OBJS		=	$(SRCS:.cpp=.o)

VAL_TO		=	--track-origins=yes
VAL_SL		=	--show-leak-kinds=all
VAL_LC		=	--leak-check=full

all: $(NAME)
	@echo "Build ok!"

$(NAME): $(OBJS)
	g++ -o $(NAME) $(OBJS) $(CPPFLAGS)

debug: CPPFLAGS += -g3
debug: $(NAME)
	@echo "Build debug ok!"

tests_run: fclean $(NAME)
	make -C $(TEST_DIR)
	@echo "Build tests_run ok!"
	gcovr --html --html-details -o $(TEST_DIR)cov.html
	gcovr

clean:
	$(RM) $(OBJS)
	make clean -C $(TEST_DIR) -s
	@echo "Clean ok!"

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(TEST_DIR) -s
	@echo "Fclean ok!"

re: fclean all

.PHONY: all debug tests_run clean fclean re