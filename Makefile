#variables
EJECUTABLE := $(notdir $(shell pwd)) 

SRC_PATH := src
INC_PATH := inc
OUT_PATH := out
OBJ_PATH := $(OUT_PATH)/obj

#de ser necesarias mas librerias de opencv, agregarlas aca
LIBS := $(shell pkg-config --libs opencv)



vpath %.cpp $(SRC_PATH)
vpath %.o $(OBJ_PATH)

#variables de directorios
SOURCES := $(wildcard $(SRC_PATH)/*.cpp)
OBJS := $(subst $(SRC_PATH),$(OBJ_PATH),$(SOURCES:.cpp=.o))
OBJ_FILES := $(notdir $(OBJS))


#regla all para compatibilizar con eclipse out of the box
all: $(EJECUTABLE)

#regla de compilacio
%.o: %.cpp
	g++ -Wall -I $(INC_PATH) `pkg-config --cflags opencv` -c $< -o $(OBJ_PATH)/$@ 

#regla de linkeo y generacion de direcctorios de salida (si no existen)
$(EJECUTABLE): $(OBJ_PATH) | $(OBJ_FILES)
	g++ `pkg-config --cflags --libs opencv` $(OBJS)  -o $(OUT_PATH)/$(EJECUTABLE)


#regla clean
clean:
	rm -rf $(OUT_PATH)

#make info para ver variables
info:
	@echo $(SOURCES)
	@echo $(OBJS)
	@echo $(LIBS)

#pre-requisito para poder compilar, es que existan los directorios de salida, si no existen, se crean
$(OBJ_PATH):
	mkdir -p $(OUT_PATH) 
	mkdir -p $(OBJ_PATH)
	
