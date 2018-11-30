CC=g++
CFLAGS=--std=c++11 -O3
ODIR=obj
HDRS=sort_algs.h profile.h benchmark.h

_OBJ=benchmark.o main.o 
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

TEST_IDIR=./tests
TEST_CFLAGS=$(CFLAGS) -DRUN_UNIT_TESTS
_TEST_OBJ=main_test.o sort_algs_test.o #profile_test.o
TEST_OBJ=$(patsubst %,$(ODIR)/%,$(_TEST_OBJ))


# =============================
# Compile/Run Main Application
# =============================

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(ODIR)/main.o: main.cpp
	$(CC) -c -o $@ $< $(CFLAGS);

$(ODIR)/benchmark.o: benchmark.cpp
	$(CC) -c -o $@ $< $(CFLAGS);

# =============================
# Compile/Run Main Tests
# =============================

test: $(TEST_OBJ) $(HDRS)
	$(CC) -o main $^ $(TEST_CFLAGS)

$(ODIR)/main_test.o: main.cpp
	$(CC) -c -o $@ $< $(TEST_CFLAGS)

$(ODIR)/sort_algs_test.o: tests/sort_algs_test.cpp
	$(CC) -c -o $@ $< $(TEST_CFLAGS)

# $(ODIR)/profile_test.o: tests/profile_test.cpp
# 	$(CC) -c -o $@ $< $(CFLAGS)


# =============================
# Utility
# =============================

run:
	./main

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ core 
	rm main