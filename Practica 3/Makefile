SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

all:$(BIN)/sp2

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************

$(BIN)/sp2: $(OBJ)/sp2.o $(OBJ)/Sopa_Letras.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/sp2 $(OBJ)/sp2.o $(OBJ)/Sopa_Letras.o $(OBJ)/diccionario.o

$(OBJ)/sp2.o: $(SRC)/Sp2.cpp $(INC)/Diccionario.h $(INC)/Sopa_Letras.h
	$(CXX) $(CPPFLAGS) $(SRC)/Sp2.cpp -o $(OBJ)/sp2.o

$(OBJ)/diccionario.o: $(SRC)/Diccionario.cpp $(INC)/Diccionario.h
	$(CXX) $(CPPFLAGS) $(SRC)/Diccionario.cpp -o $(OBJ)/diccionario.o

$(OBJ)/Sopa_Letras.o: $(SRC)/Sopa_Letras.cpp $(INC)/Sopa_Letras.h $(INC)/Matriz_Dispersa.h $(SRC)/Matriz_Dispersa.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/Sopa_Letras.cpp -o $(OBJ)/Sopa_Letras.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
