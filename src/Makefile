UTF8_SRC = utf8small.c utf8small.h
UNITTEST_SRC = unittest.h unittest.c

TRYOUT_MAIN_SRC           = tryout/tryout.c
TRYOUT_UNITTEST_PASS_SRC  = tryout/tryout_unittest_pass.c
TRYOUT_UNITTEST_FAIL_SRC  = tryout/tryout_unittest_fail.c

SRC_FILES = $(UTF8_SRC) $(UNITTEST_SRC)
BUILD_DIR = ../build

TRYOUT_UNITTEST_PASS_EXEC  = $(BUILD_DIR)/tryout_unittest_pass
TRYOUT_UNITTEST_FAIL_EXEC  = $(BUILD_DIR)/tryout_unittest_fail
TRYOUT_MAIN_EXEC           = $(BUILD_DIR)/tryout_main

INCLUDE = ./

.PHONY: clean tryout

clean:
	rm -rf \
		*.o *.i *.gch *.a \
		$(BUILD_DIR)

tryout: $(TRYOUT_MAIN_SRC)
	@mkdir -p $(BUILD_DIR)

	@$(CC) -o $(TRYOUT_MAIN_EXEC) \
		-I$(INCLUDE) \
		$(UTF8_SRC) \
		$(TRYOUT_MAIN_SRC)
	$(TRYOUT_MAIN_EXEC) < ../test_data/utf8_input.txt

tryout_unittest:
	@mkdir -p $(BUILD_DIR)

	@$(CC) -o $(TRYOUT_UNITTEST_PASS_EXEC) \
		-I$(INCLUDE) \
		$(TRYOUT_UNITTEST_PASS_SRC) \
		$(UNITTEST_SRC)

	@$(CC) -o $(TRYOUT_UNITTEST_FAIL_EXEC) \
		-I$(INCLUDE) \
		$(TRYOUT_UNITTEST_FAIL_SRC) \
		$(UNITTEST_SRC)

	$(TRYOUT_UNITTEST_PASS_EXEC)
	$(TRYOUT_UNITTEST_FAIL_EXEC)
