INCLUDES=-I includes/
CXXFLAGS=-std=c++20 -stdlib=libc++ -lc++abi -g -O0 -Wall -Wextra -Werror -pedantic $(INCLUDES)
CXX=clang++

exec: bin/main.out
	$<

tests: bin/tests.out
	- $<

clean:
	rm -f bin/*

bin/main.out: src/main.cc src/board.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

bin/tests.out: tests/tests.cc src/board.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

src/%.cc: includes/%.hpp
	touch $@

.DEFAULT_GOAL := tests
.PHONY: test clean exec