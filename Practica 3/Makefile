SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

all:$(BIN)/prueba $(BIN)/prueba_sp

pm:$(BIN)/prueba

ps:$(BIN)/prueba_sp

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************


$(BIN)/prueba: $(OBJ)/prueba.o
	$(CXX) -o $(BIN)/prueba $(OBJ)/prueba.o

$(OBJ)/prueba.o: $(SRC)/prueba.cpp $(INC)/Matriz_Dispersa.h $(SRC)/Matriz_Dispersa.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/prueba.o $(SRC)/prueba.cpp


$(BIN)/prueba_sp: $(OBJ)/prueba_sp.o $(OBJ)/Sopa_Letras.o
	$(CXX) -o $(BIN)/prueba_sp $(OBJ)/prueba_sp.o $(OBJ)/Sopa_Letras.o


$(OBJ)/prueba_sp.o: $(SRC)/prueba_sp.cpp $(INC)/Sopa_Letras.h $(INC)/Matriz_Dispersa.h $(SRC)/Matriz_Dispersa.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/prueba_sp.cpp -o  $(OBJ)/prueba_sp.o


$(OBJ)/Sopa_Letras.o: $(SRC)/Sopa_Letras.cpp $(INC)/Sopa_Letras.h $(INC)/Matriz_Dispersa.h $(SRC)/Matriz_Dispersa.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/Sopa_Letras.cpp -o  $(OBJ)/Sopa_Letras.o



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
