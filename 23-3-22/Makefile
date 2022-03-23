$(CC) = gcc

appln:	calc_main.o calc_mean.o calc_sub.o
	$(CC) calc_main.o calc_mean.o calc_sub.o -o appln


calc_main.o: calc_main.c calc_mean.h
	     $(CC) -c calc_main.c

calc_mean.o: calc_mean.c calc_mean.h
	     $(CC) -c calc_mean.c

calc_sub.o: calc_sub.c calc_mean.h
	    $(CC) -c calc_sub.c

clean:
	rm -f *.o
	
