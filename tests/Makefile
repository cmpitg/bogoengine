UTF8_SRC = \
	../src/utf8small.c \
	../src/utf8small.h

UNITTEST_SRC = \
	../src/unittest.c \
	../src/unittest.h

SRC_FILES = $(UTF8_SRC) $(UNITTEST_SRC)

INCLUDE          = ../src/
TEST_DATA_DIR    = ../test_data
BUILD_TEST_DIR   = ../build

TEST_UTF8_INPUT  = $(TEST_DATA_DIR)/utf8_input.txt
TEST_UTF8_SRC    = test_utf8.c
TEST_UTF8_EXEC   = $(BUILD_TEST_DIR)/test_utf8

test: test_utf

test_utf: $(TEST_UTF8_SRC)
	@mkdir -p $(BUILD_TEST_DIR)
	@$(CC) -o $(TEST_UTF8_EXEC) \
		-I$(INCLUDE) \
		$(TEST_UTF8_SRC) \
		$(SRC_FILES)
	@$(TEST_UTF8_EXEC) < $(TEST_UTF8_INPUT)

clean:
	rm -rf \
		$(BUILD_TEST_DIR) \
		*.o *.i *.gch *.a
