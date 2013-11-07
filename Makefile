#CFLAGS=-O2 -Wall -std=c99 -save-temps -Wshadow -fmudflap

CC = gcc
CFLAGS = -O2 -pipe

.PHONY: clean clean-src clean-test

#
# Cleaning
#

clean: clean-test clean-src

clean-src:
	@cd src; make clean

clean-test:
	@cd tests; make clean

#
# Testing
#

test:
	@cd tests; make test


#
# Trying out
#

tryout:
	@cd src; make tryout

tryout_unittest:
	@cd src; make tryout_unittest
