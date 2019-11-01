source = $(wildcard *.cpp)

object = $(patsubst %.cpp, %.o, $(source))

main : $(object)
	g++ -o $@ $(object)

%.o : %.cpp
	g++ -c $<

clean :
	rm *.o *.exe main
