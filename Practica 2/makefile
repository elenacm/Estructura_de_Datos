SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

all:$(BIN)/prueba $(BIN)/prueba_sp

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************


$(BIN)/prueba: $(OBJ)/prueba.o
	$(CXX) -o $(BIN)/prueba $(OBJ)/prueba.o

$(OBJ)/prueba.o: $(SRC)/prueba.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/prueba.cpp -o  $(OBJ)/prueba.o


$(BIN)/prueba_sp: $(OBJ)/prueba_sp.o $(OBJ)/Sopa_Letras.o
	$(CXX) -o $(BIN)/prueba_sp $(OBJ)/prueba_sp.o $(OBJ)/Sopa_Letras.o $(OBJ)/Matriz_Dispersa.o


$(OBJ)/prueba_sp.o: $(SRC)/prueba_sp.cpp $(INC)/Matriz_Dispersa.h
	$(CXX) $(CPPFLAGS)  $(SRC)/prueba_sp.cpp -o  $(OBJ)/prueba_sp.o


$(OBJ)/Sopa_Letras.o: $(SRC)/Sopa_Letras.cpp $(INC)/Sopa_Letras.h
	$(CXX) $(CPPFLAGS)  $(SRC)/Sopa_Letras.cpp -o  $(OBJ)/Sopa_Letras.o

#Ejemplo para compilar matriz_dispersa usando como tipo rep vector dinamico
$(OBJ)/Matriz_Dispersa.o: $(SRC)/Matriz_Dispersa.cpp $(INC)/Matriz_Dispersa.h  $(INC)/Vector_Dinamico.h $(SRC)/Vector_Dinamico.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/Matriz_Dispersa.cpp -o  $(OBJ)/Matriz_Dispersa.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
