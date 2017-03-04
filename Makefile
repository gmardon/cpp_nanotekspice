NAME				=		nanotekspice

CXX					=		g++

NOW 				:=	$(shell date +"%d %h %g:%R")

DEFAULT				=		"\033[00m"
GREEN				=		"\033[0;32m"
HIGHLIGHTED			=		"\033[2;102m"
DELETION 			=		"\033[2;103m"
TEAL				=		"\033[1;34m"
RED					=		"\033[1;31m"
ECHO				=		/bin/echo -e

CMPT_P				=	$(SRC_P)components/
CMPT				=	$(CMPT_P)AComponent.cpp	\
						$(CMPT_P)Tristate.cpp	\
						$(CMPT_P)Pin.cpp		\
						$(CMPT_P)True.cpp		\
						$(CMPT_P)False.cpp		\
						$(CMPT_P)Input.cpp		\
						$(CMPT_P)Clock.cpp		\
						$(CMPT_P)Output.cpp		\
						$(CMPT_P)c4001.cpp		\
						$(CMPT_P)c4008.cpp		\
						$(CMPT_P)c4011.cpp		\
						$(CMPT_P)c4013.cpp		\
						$(CMPT_P)c4017.cpp		\
						$(CMPT_P)c4030.cpp		\
						$(CMPT_P)c4040.cpp		\
						$(CMPT_P)c4069.cpp		\
						$(CMPT_P)c4071.cpp		\
						$(CMPT_P)c4081.cpp

PARSER_P			=	$(SRC_P)parser/
PARSER				=	$(PARSER_P)Parser.cpp	\
						$(PARSER_P)Create.cpp	\

ERROR_P				=	$(SRC_P)errors/
ERROR				=	$(ERROR_P)ErrorParser.cpp

CMD_P				=	$(SRC_P)commands/
CMD					=	$(CMD_P)Commands.cpp

SRC_P				=	src/
SRC					=	$(SRC_P)main_parser.cpp	\
						$(CMPT)					\
						$(PARSER)				\
						$(CMD)					\
						$(ERROR)

OBJ					=		$(SRC:.cpp=.o)

CXXFLAGS			+= 	-Wall -Wextra -pedantic -std=c++11 -g

INCLUDE				=	./include

RM					=	rm -vf

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CXX) $(OBJ) -o $(NAME)
		@$(ECHO) $(HIGHLIGHTED)"COMPILATION SUCCEEDED ON "$(NOW)$(DEFAULT)

clean:
		@$(RM) $(OBJ)
		@$(ECHO) $(DELETION)"OBJs PROPERLY DELETED"$(DEFAULT)

fclean:		clean
		@$(RM) $(NAME)
		@$(ECHO) $(DELETION)"BINARY PROPERLY DELETED"$(DEFAULT)

re:		fclean all

.PHONY:		all clean fclean re

.cpp.o:
		@$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c $< -o $@  && \
		$(ECHO) $(GREEN) " [OK] " $(TEAL) $< $(DEFAULT) || \
		$(ECHO) $(RED) " [XX] " $(TEAL) $< $(DEFAULT)