CC=g++
CFLAGS=--std=c++11
ODIR=obj
_OBJ = benchmark.o main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(ODIR)/main.o: main.cpp
	$(CC) -c -o $@ $< $(CFLAGS);

$(ODIR)/benchmark.o: benchmark.cpp
	$(CC) -c -o $@ $< $(CFLAGS);

run:
	./main

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ core 
	rm main