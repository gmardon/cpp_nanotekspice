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

CMPT_P				=	$(SRCS_P)components/
CMPT				=	$(CMPT_P)AComponent.cpp	\
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

SRCS_P				=	srcs/
SRCS				=	$(CMPT)				\
						$(SRCS_P)test.cpp	\
						$(SRCS_P)Pin.cpp	\
						$(SRCS_P)Create.cpp	\
						$(SRCS_P)Parser.cpp	\
						$(SRCS_P)Tristate.cpp

OBJS					=		$(SRCS:.cpp=.o)

CXXFLAGS			+= 	-Wall -Wextra -pedantic -std=c++11 -g

INCLUDE				=	./include

RM					=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CXX) $(OBJS) -o $(NAME)
		@$(ECHO) $(HIGHLIGHTED)"COMPILATION SUCCEEDED ON "$(NOW)$(DEFAULT)

clean:
		@$(RM) $(OBJS)
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