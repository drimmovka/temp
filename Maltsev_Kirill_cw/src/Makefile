TARGET = cw
CXX = g++

CORE_DIR = ./core
HEADER_DIR = ./header
LIB_DIR = ./lib
BIN_DIR = ./bin

CXXFLAGS = -I$(HEADER_DIR) -I$(LIB_DIR)/EditorPNG/header -Wl,-rpath=$(LIB_DIR)/EditorPNG/lib/ -L$(LIB_DIR)/EditorPNG/lib/ -lEditorPNG

SRC = $(wildcard $(CORE_DIR)/*.cpp) $(wildcard $(CORE_DIR)/Handler/*.cpp)
OBJ = $(patsubst %.cpp, $(BIN_DIR)/%.o, $(notdir $(SRC)))

all : create_bin_folder $(TARGET)

$(TARGET) : $(OBJ)
	$(CXX) $^ $(CXXFLAGS) -o $@

$(BIN_DIR)/%.o : $(CORE_DIR)/%.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

$(BIN_DIR)/%.o: $(CORE_DIR)/Handler/%.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

create_bin_folder :
	@mkdir -p $(BIN_DIR)

build_lib :
	cd $(LIB_DIR)/EditorPNG; make

clean:
	@rm -f $(TARGET)
	@rm -rf $(BIN_DIR)