TARGET = libEditorPNG.so
CXX = g++

CORE = ./core/
HEADER = ./header/
LIB = ./lib/

CXXFLAGS = -I$(HEADER)Graphics --shared -fPIC -lpng

SRC = $(wildcard $(CORE)Graphics/ImagePNG/*.cpp)

all : create_lib_folder $(TARGET)

$(TARGET) : $(SRC)
	g++ $^ $(CXXFLAGS) -o $(LIB)$@

create_lib_folder :
	@mkdir -p $(LIB)

clean :
	rm -rf $(LIB)