TARGET = cw
CXX = g++

CORE = ./core/
HEADER = ./header/
LIB = ./lib/
BIN = ./bin/

CXXFLAGS = -I$(HEADER) -I$(LIB)EditorPNG/header -Wl,-rpath=$(LIB)EditorPNG/lib/ -L$(LIB)EditorPNG/lib/ -lEditorPNG

SRC = $(wildcard $(CORE)*.cpp)
OBJ = $(patsubst $(CORE)%.cpp, $(BIN)%.o, $(SRC))

all : create_bin_folder $(TARGET)

$(TARGET) : $(OBJ)
	$(CXX) $^ $(CXXFLAGS) -o $@

$(BIN)%.o : $(CORE)%.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

create_bin_folder :
	@mkdir -p $(BIN)

build_lib :
	cd $(LIB)EditorPNG; make

clean:
	@rm $(TARGET)
	@rm -rf $(BIN)