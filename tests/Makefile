UTF8_SRC = \
	../src/utf8small.c \
	../src/utf8small.h

UNITTEST_SRC = \
	../src/unittest.c \
	../src/unittest.h

INCLUDE = ../src/

TEST_UTF8_INPUT = test_utf8_input.txt
TEST_UTF8_SRC = test_utf8.c

test: test_utf

test_utf: $(TEST_UTF8SRC)
	$(CC) -o test_utf8 $(TEST_UTF8_SRC) $(UTF8_SRC) $(UNITTEST_SRC) -I$(INCLUDE)
	./test_utf8 < $(TEST_UTF8_INPUT)
	make clean

clean:
	rm -rf \
		test_utf8 \
		*.o *.i *.gch *.a
