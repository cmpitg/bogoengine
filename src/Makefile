UTF8_SRC = utf8small.c utf8small.h
UNITTEST_SRC = unittest.h unittest.c

INCLUDE = ./

.PHONY: clean tryout

clean:
	rm -rf \
		*.o *.i *.gch *.a \
		tryout_unittest_pass \
		tryout_unittest_fail \
		tryout_exec

tryout: tryout/tryout.c
	$(CC) -o tryout_exec \
		tryout/tryout.c $(UTF8_SRC) -I$(INCLUDE)
	./tryout_exec <../tests/test_utf8_input.txt

tryout_unittest:
	$(CC) -o tryout_unittest_pass \
		tryout/tryout_unittest_pass.c $(UNITTEST_SRC) -I$(INCLUDE)
	$(CC) -o tryout_unittest_fail \
		tryout/tryout_unittest_fail.c $(UNITTEST_SRC) -I$(INCLUDE)
	./tryout_unittest_pass
	./tryout_unittest_fail
