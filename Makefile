#variables
EJECUTABLE := $(notdir $(shell pwd)) 

SRC_PATH := src
INC_PATH := inc
OUT_PATH := out
OBJ_PATH := $(OUT_PATH)/obj

#de ser necesarias mas librerias de opencv, agregarlas aca
LIBS := -lopencv_imgproc -lopencv_core -lopencv_highgui



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
	g++ -Wall -c $< -o $(OBJ_PATH)/$@ -I $(INC_PATH)

#regla de linkeo y generacion de direcctorios de salida (si no existen)
$(EJECUTABLE): $(OBJ_PATH) | $(OBJ_FILES)
	g++ $(OBJS) $(LIBS) -o $(OUT_PATH)/$(EJECUTABLE)


#regla clean
clean:
	rm -f $(OBJS) $(OUT_PATH)/$(EJECUTABLE)

#make info para ver variables
info:
	@echo $(SOURCES)
	@echo $(OBJS)

#pre-requisito para poder compilar, es que existan los directorios de salida, si no existen, se crean
$(OBJ_PATH):
	mkdir -p $(OUT_PATH) 
	mkdir -p $(OBJ_PATH)
	
