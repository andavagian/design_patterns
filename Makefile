CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

SRC = $(shell find . -name '*.cpp')
OUTDIR = out
BIN = $(patsubst ./%.cpp,$(OUTDIR)/%,$(SRC))

all: $(BIN)

$(OUTDIR)/%: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OUTDIR)

re: clean all

.PHONY: all clean re
