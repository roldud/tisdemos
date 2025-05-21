# trustinsoft/demos
# Copyright (C) 2022-2023 TrustInSoft
# mailto:contact AT trust-in-soft DOT com
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 3 of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
# 
SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`
GCC_VERSION := $(shell gcc --version | head -n 1 | cut -d ' ' -f 4 | cut -d '.' -f 1)

TARGET := increment
FILES := test_driver.c $(TARGET).c Unity/src/unity.c
OBJS := test_driver.o $(TARGET).o Unity/src/unity.c
COMPILER := gcc

.PHONY: all test

all:
	@echo "make test:       Runs tests"
	@echo "make clean:      Cleans everything to revert to the beginning of the demo"

test:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. -IUnity/src -DUNITY_INCLUDE_CONFIG_H -fprofile-arcs -ftest-coverage $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -I. -IUnity/src  -DUNITY_INCLUDE_CONFIG_H -fprofile-arcs -ftest-coverage $(FILES) -o $(TARGET) && ./$(TARGET)
	@echo ""
	@# With gcc 11 and higher the coverage files have a different name.
	@# Temporarily fixing by changing file name to the expected name
	@if [ $(GCC_VERSION) -ge 11 ]; then \
	mv $(TARGET)-$(TARGET).gcno $(TARGET).gcno; \
	mv $(TARGET)-$(TARGET).gcda $(TARGET).gcda; \
	fi
	gcov $(TARGET).c

cov:
	$(shell if [ -f $(TARGET).gcno ]then; gcov $(TARGET)-$(TARGET).c; else; gcov $(TARGET).c; fi)

clean:
	@echo "Cleaning..."
	@rm -rf $(TARGET) *.gc* compile_commands.json _results *.log tis_report.html tis_misra_report
	@echo "Reverting increment.c to original..."
	@git checkout -q -- increment.c
	
tis-misra:
	tis-misra --title "DEMO" increment.c
	@printf "\nCheck generated test report $(FONT_CYAN)tis_misra_report/index.html$(FONT_RESET)\n\n"
