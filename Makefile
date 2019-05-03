CC       := g++ -c
CXXFLAGS := -std=c++0x
CFLAGS   := -I.
RM       := rm -rvf
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := edlin
INCLUDE  := -Iinclude/
SRC      :=                       \
	$(wildcard src/*.cpp)          \
	$(wildcard src/commands/*.cpp) \

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

edlin: $(OBJECTS)
	$(CC) $(CXXFLAGS) $(LIBS) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

clean:
	$(RM) $(OBJ_DIR)/*
	$(RM) $(APP_DIR)/*
