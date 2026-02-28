TARGET  := miniraster
BUILDDIR := build

CXX ?= g++
CXXFLAGS ?= -O2

ifeq ($(OS),Windows_NT)
	EXE := .exe
	RM := rmdir /S /Q $(BUILDDIR)
	MKDIR_CMD = if not exist "$(dir $@)" mkdir "$(dir $@)"
else
	EXE :=
	RM := rm -rf $(BUILDDIR)
	MKDIR_CMD = mkdir -p $(dir $@)
endif

SRCS := $(wildcard *.cpp) $(wildcard */*.cpp)
OBJS := $(patsubst %.cpp,$(BUILDDIR)/%.o,$(SRCS))
TARGET_FULL := $(TARGET)$(EXE)

all: $(TARGET_FULL)

$(TARGET_FULL): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILDDIR)/%.o: %.cpp
	@$(MKDIR_CMD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-$(RM)
