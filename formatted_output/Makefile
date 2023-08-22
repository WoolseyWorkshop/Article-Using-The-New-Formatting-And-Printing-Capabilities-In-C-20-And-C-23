# Makefile

TARGET = formatted_output
DOXYGEN_DIR = doxygen

# Choose the compiler.
# CC = clang++
CC = g++-13
# CC = llvm-g++

# Choose the C++ standard.
# C++20 - Includes the <format> library.
# CFLAGS = -Wall -Wextra -std=c++20
# C++23 - Includes the <format> and <print> libraries.
# CFLAGS = -Wall -Wextra -std=c++23
# C++2B - Includes the latest C++ draft specification.
CFLAGS = -Wall -Wextra -std=c++2b

LIBS =

all: $(TARGET)

help:
	@echo "The following targets are available:"
	@echo "  'make' or 'make all' - build program"
	@echo "  'make help'          - print help message"
	@echo "  'make run'           - run program"
	@echo "  'make docs'          - create documentation"
	@echo "  'make clean'         - remove program, documentation, and clean up directory"

$(TARGET): $(TARGET).cpp
	@echo 'Building target: $@ ...'
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

run: $(TARGET)
	@echo 'Running target: $(TARGET) ...'
	./$(TARGET)

docs:
	@echo 'Generating Doxygen documentation ...'
	cd $(DOXYGEN_DIR) && doxygen &> doxygen.log
	cd $(DOXYGEN_DIR)/latex && $(MAKE) pdf &> make_pdf.output

clean:
	@echo 'Cleaning target: $(TARGET) ...'
	$(RM) $(TARGET)
	@echo 'Cleaning Doxygen documentation ...'
	$(RM) $(DOXYGEN_DIR)/doxygen.log
	$(RM) -r $(DOXYGEN_DIR)/html $(DOXYGEN_DIR)/latex
