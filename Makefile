CC=gcc
CFLAGS=-I.
DEPS = func.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

funfuncircularlinkedlists: funfuncircularlinkedlists.o menufunc.o func.o
	$(CC) -o funfuncircularlinkedlists funfuncircularlinkedlists.o menufunc.o func.o
clean:
	$(RM) funfuncircularlinkedlists.o menufunc.o func.o funfuncircularlinkedlists
