TARGET = libEditorPNG.so
CXX = g++

CORE_DIR = ./core
HEADER_DIR = ./header
LIB_DIR = ./lib

CXXFLAGS = -I$(HEADER_DIR) --shared -fPIC -lpng

SRC = $(wildcard $(CORE_DIR)/ImagePNG/*.cpp)

all : create_lib_folder $(TARGET)

$(TARGET) : $(SRC)
	g++ $^ $(CXXFLAGS) -o $(LIB_DIR)/$@

create_lib_folder :
	@mkdir -p $(LIB_DIR)

clean :
	rm -rf $(LIB_DIR)