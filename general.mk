include config.mk

all: $(TARGET).a
	ar -t $^

examples: $(TARGET_DEBUG).a
	ar -t $^
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(PATH_EXAMPLES)/example1.c -L. -lBMP_image -o $(PATH_OUT)/example1.$(EXTENSION)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(PATH_EXAMPLES)/example2.c -L. -lBMP_image -o $(PATH_OUT)/example2.$(EXTENSION)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(PATH_EXAMPLES)/example3.c -L. -lBMP_image -o $(PATH_OUT)/example3.$(EXTENSION)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(PATH_EXAMPLES)/example4.c -L. -lBMP_image -o $(PATH_OUT)/example4.$(EXTENSION)

$(TARGET_DEBUG).a: $(OBJECTS)
	$(ARR) $(ARR_FLAGS) $@ $^
	ranlib $@

$(TARGET).a: $(OBJECTS)
	$(ARR) $(ARR_FLAGS) $@ $^
	ranlib $@

BMP_image.o: BMP_image.c
	$(CC) $(CFLAGS) -c $^ -o $@

cleanobj:
	$(RM) $(RMFLAGS) $(OBJECTS)

cleanall: cleanobj
	$(RM) $(RMFLAGS) $(TARGET).o $(TARGET).a \
	$(TARGET_DEBUG).a *.exe
	$(RM) $(RMFLAGS) example.$(EXTENSION)

.SILENT: clean cleanobj cleanall
.IGNORE: cleanobj cleanall
.PHONY:  cleanobj cleanall