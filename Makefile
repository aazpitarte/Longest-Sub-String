
CC = g++
FILES = longest_substr.cpp
FLAGS = -std=c++11 -g
EXE = run

all: $(FILES)
	$(CC) $(FILES) -o $(EXE) $(FLAGS)

clean:
	rm run.exe
	
