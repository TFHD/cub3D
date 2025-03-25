# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pretty_compile.mk                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/14 16:26:20 by mrouves           #+#    #+#              #
#    Updated: 2025/03/25 18:07:37 by mrouves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define TITLE

┌────────────────────┐
│░█▀▀░█░█░█▀▄░▀▀█░█▀▄│
│░█░░░█░█░█▀▄░░▀▄░█░█│
│░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░│
└────────────────────┘

endef
export TITLE
text-style 		= $(shell tput $1)$2$(shell tput sgr0)
PRINT_TITLE		:= $(shell $(info $(call text-style,setaf 6, $(TITLE))))

BOLD			= \033[1m
OK_COLOR		= \033[0;32m
ERROR_COLOR		= \033[0;31m
WARN_COLOR		= \033[0;33m
NO_COLOR		= \033[m
OK_STRING		= "[✓]"
ERROR_STRING	= "[✖]"
WARN_STRING		= "[⚠]"
COM_STRING		= "Compiling"

define run_and_test
printf "%b" "$(COM_STRING) $(@F)$(NO_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
if [ $$RESULT -ne 0 ]; then \
  printf "%-60b%b" "$(COM_STRING) $(BOLD)$@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\r"; \
elif [ -s $@.log ]; then \
  printf "%-60b%b" "$(COM_STRING) $(BOLD)$@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\r"; \
else  \
  printf "%-40b%b" "$(COM_STRING) $(BOLD)$(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\r"; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef
