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

CMPT_P				=	components/
CMPT				=	$(SRCS_P)AComponent.cpp	\
						$(SRCS_P)Pin.cpp		\
						$(SRCS_P)True.cpp		\
						$(SRCS_P)False.cpp		\
						$(SRCS_P)Input.cpp		\
						$(SRCS_P)Clock.cpp		\
						$(SRCS_P)Output.cpp		\
						$(SRCS_P)c4001.cpp		\
						$(SRCS_P)c4008.cpp		\
						$(SRCS_P)c4011.cpp		\
						$(SRCS_P)c4013.cpp		\
						$(SRCS_P)c4017.cpp		\
						$(SRCS_P)c4030.cpp		\
						$(SRCS_P)c4040.cpp		\
						$(SRCS_P)c4069.cpp		\
						$(SRCS_P)c4071.cpp		\
						$(SRCS_P)c4081.cpp

SRCS_P				=	srcs/
SRCS				=	$(SRCS_P)$(CMPT)	\
						$(SRCS_P)test.cpp	\
						$(SRCS_P)pin.cpp	\
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