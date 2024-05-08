# OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

# program.exe: program.o Cuenca.o Barco.o Cjt_ciudades.o Ciudad.o Cjt_productos.o Producto.o Inventario.o
# 	g++ -o program.exe *.o

# Cuenca.o: Cuenca.cc Cuenca.hh Cjt_ciudades.hh Cjt_productos.hh Barco.hh BinTree.hh
# 	g++ -c Cuenca.cc $(OPCIONS)

# Cjt_ciudades.o: Cjt_ciudades.cc Cjt_ciudades.hh Ciudad.hh
# 	g++ -c Cjt_ciudades.cc $(OPCIONS)

# Ciudad.o: Ciudad.cc Ciudad.hh Inventario.hh Cjt_productos.hh 
# 	g++ -c Ciudad.cc $(OPCIONS)

# Inventario.o: Inventario.cc Inventario.hh Producto.hh
# 	g++ -c Inventario.cc $(OPCIONS)

# Cjt_productos.o: Cjt_productos.cc Cjt_productos.hh Producto.hh
# 	g++ -c Cjt_productos.cc $(OPCIONS)

# Producto.o: Producto.cc Producto.hh
# 	g++ -c Producto.cc $(OPCIONS)

# run: program.exe
# 	./program.exe < sample/sample.inp

# clean:
# 	rm *.o
# 	rm *.exe

p2++ := g++ -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -fno-extended-identifiers -std=c++11

# Source files
SOURCES=program.cc Cuenca.cc Cjt_ciudades.cc Barco.cc Cjt_productos.cc Ciudad.cc Inventario.cc Producto.cc
# Object files
OBJECTS=$(SOURCES:.cc=.o)
# Executable name
EXECUTABLE=program.exe

$(EXECUTABLE): $(OBJECTS)
	$(p2++) $(OBJECTS) -o $(EXECUTABLE)

.cc.o:
	$(p2++) -c $< -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE) < sample.inp

tar:
	tar -cvf practica.tar $(SOURCES) *.hh Makefile

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
