##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile
##

NAME		=	unit_tests

CFLAGS		=	-I$(EXCEPT_DIR) -I$(PARSER_DIR) -I$(CIRCUIT_DIR) -I$(COMPO_DIR) -I$(PIN_DIR) -I$(INPUT_DIR) -I$(OUTPUT_DIR) -I$(TRUE_DIR) -I$(FALSE_DIR) -I$(CLOCK_DIR) -I$(C4001_DIR) -I$(AND_DIR) -I$(OR_DIR) -I$(XOR_DIR) -I$(NOT_DIR) -I$(C4008_DIR) -I$(C4011_DIR) -I$(C4013_DIR) -I$(C4030_DIR) -I$(C4040_DIR) -I$(C4069_DIR) -I$(C4071_DIR) -I$(C4081_DIR) -I$(C4094_DIR)

CPPFLAGS	=	-W -Wall -Wextra -Werror

LDFLAGS		=	--coverage -lcriterion

COVFLAGS	=	-lcriterion -lgcov

SRC_DIR		=	../src/

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

EXCEPT_DIR	=	$(SRC_DIR)Exception/

PARSER_DIR	=	$(SRC_DIR)Parser/

SRC_TESTS	=	$(PARSER_DIR)Parser.cpp		\
				$(EXCEPT_DIR)Exception.cpp	\
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

UT_FILES	=	Tests_Parser.cpp			\
				Tests_Exception.cpp			\
				Tests_Circuit.cpp			\
				Tests_Components.cpp		\
				Tests_Gates.cpp				\

SRC_OBJS	=	$(SRC_TESTS:.c=.o)

UT_OBJS		=	$(UT_FILES:.c=.o)

all: $(NAME)
	@echo "Build ok!"

$(NAME) :
	g++ -c $(SRC_TESTS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)
	g++ -c $(UT_FILES) $(CPPFLAGS) $(CFLAGS)
	g++ -o $(NAME) *.o $(CPPFLAGS) $(CFLAGS) $(COVFLAGS)
	./$(NAME)


clean:
	$(RM) *.html
	$(RM) *.css
	$(RM) $(SRC_DIR)*.gcno
	$(RM) $(SRC_DIR)*.gcda
	$(RM) $(TEST_DIR)*.gcda
	$(RM) $(TEST_DIR)*.gcno
	$(RM) $(TEST_DIR)*.o
	$(RM) $(TESTS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
