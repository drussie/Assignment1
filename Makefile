all: cmdline forking marcosOndruska firstname moGood cleanUp

marcosOndruska: marcosOndruska.o
	cc -o marcosOndruska marcosOndruska.c

cmdline: cmdline.o
	cc -o cmdline cmdline.c 

forking: forking.o
	cc -o forking forking.c	

firstname: firstname.o 
	cc -o firstname firstname.c 	

moGood: moGood.o 
	cc -o moGood moGood.c

cleanUp: cleanUp.o 
	cc -o cleanUp cleanUp.c 	

clean:
	rm *.o
		