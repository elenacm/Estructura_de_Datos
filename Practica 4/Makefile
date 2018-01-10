SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11


all:$ $(BIN)/prueba_Ontologias_PreguntasED

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************

$(BIN)/prueba_Ontologias_PreguntasED: $(OBJ)/prueba_Ontologias_PreguntasED.o $(OBJ)/ontologias.o $(OBJ)/sobrecargas.o
	$(CXX) -o $(BIN)/prueba_Ontologias_PreguntasED $(OBJ)/prueba_Ontologias_PreguntasED.o $(OBJ)/ontologias.o $(OBJ)/sobrecargas.o

$(OBJ)/prueba_Ontologias_PreguntasED.o: $(SRC)/prueba_Ontologias_PreguntasED.cpp $(INC)/Ontologias.h
	$(CXX) $(CPPFLAGS) $(SRC)/prueba_Ontologias_PreguntasED.cpp -o $(OBJ)/prueba_Ontologias_PreguntasED.o

$(OBJ)/ontologias.o: $(SRC)/Ontologias.cpp $(INC)/Ontologias.h
	$(CXX) $(CPPFLAGS) $(SRC)/Ontologias.cpp -o $(OBJ)/ontologias.o

$(OBJ)/preguntas.o: $(SRC)/PreguntasED.cpp $(INC)/PreguntasED.h
	$(CXX) $(CPPFLAGS) $(SRC)/PreguntasED.cpp -o $(OBJ)/PreguntasED.o

$(OBJ)/sobrecargas.o: $(SRC)/sobrecargas.cpp $(INC)/sobrecargas.h
	$(CXX) $(CPPFLAGS) $(SRC)/sobrecargas.cpp -o $(OBJ)/sobrecargas.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
