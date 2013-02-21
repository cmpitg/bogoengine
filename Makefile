#CFLAGS=-O2 -Wall -std=c99 -save-temps -Wshadow -fmudflap

CC = gcc
CFLAGS = -O2 -std=c99 -pipe

.PHONY: clean clean-src clean-test

test:
	cd tests; make test

clean: clean-test clean-src

clean-src:
	cd src; make clean

clean-test:
	cd tests; make clean

tryout:
	cd src; make tryout

tryout_unittest:
	cd src; make tryout_unittest
