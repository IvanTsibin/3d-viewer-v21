CC=g++ -std=c++17
CFLAGS_FOR_FUNC=-g -Wall -Wextra -Werror
ADD_CFLAGS=-g
LIBS=-lgtest -lpthread -lm
SOURCES= s21_afines.cc s21_model.cc s21_matrix_oop.cc
OBJECTS=$(SOURCES:.cc=.o)
PATH-TO-QT=s21_3DViewer_V2-1_App/s21_3DViewer_V2-1/
GCOV_TEST = gcov_test
GCOV_DIR = report
TEST_TARGET = s21_3DViewer_V2-1_test
OS=$(shell uname)

EXECUTABLE=test dvi dist install clean


all: $(EXECUTABLE)

install:
	rm -rf temp
	rm -rf ../../s21_3DViewer_V2-1_App
	mkdir temp
	cd temp; qmake ../s21_3DViewer_V2-1_App/s21_3DViewer_V2-1/s21_3DViewer_V2-1.pro
	cd temp; make
	cd temp; make clean
	mkdir ../../s21_3DViewer_V2-1_App
ifeq ($(OS), Darwin)
	cp temp/s21_3DViewer_V2-1.app/Contents/MacOS/s21_3DViewer_V2-1 ../../s21_3DViewer_V2-1_App/s21_3DViewer_V2-1
else
	cp temp/s21_3DViewer_V2-1 ../../s21_3DViewer_V2-1_App/s21_3DViewer_V2-1
endif
	rm -rf temp
	../../s21_3DViewer_V2-1_App/s21_3DViewer_V2-1

uninstall:
	rm -rf temp
	rm -rf ../../s21_3DViewer_V2-1_App

dist:
	rm -rf ../../s21_3DViewer_V2-1_App-tar
	mkdir ../../s21_3DViewer_V2-1_App-tar
	tar -cf ../../s21_3DViewer_V2-1_App-tar/s21_3DViewer_V2-1.tar Makefile $(PATH-TO-QT)*.*

dvi:
	rm -rf ../../s21_3DViewer_V2-1_Pdf
	mkdir ../../s21_3DViewer_V2-1_Pdf
	cp s21_3DViewer_V2-1.pdf ../../s21_3DViewer_V2-1_Pdf/s21_3DViewer_V2-1.pdf


test:
	rm -rf test
	mkdir test
	cd test; qmake -Wnone ../s21_3DViewer_V2-1_App/s21_3DViewer_V2-1/s21_3DViewer_V2-1_test.pro
	cd test; make
	cd test; make clean
	cp obj-images/cube-4.obj test/cube-4.obj
ifeq ($(OS), Darwin)
	cp test/s21_3DViewer_V2-1.app/Contents/MacOS/s21_3DViewer_V2-1_test test/s21_3DViewer_V2-1_test
	cd test; CK_FORK=no leaks -atExit -- ./s21_3DViewer_V2-1_test
	cd test; lcov -t "s21_3DViewer_V2-1_test" -o s21_3DViewer_V2-1_test.info -c -d .
	cd test; lcov -r s21_3DViewer_V2-1_test.info "/usr*" -o s21_3DViewer_V2-1_test.info
	cd test; genhtml -o report s21_3DViewer_V2-1_test.info
	cd test; open ./report/index.html
	cd test; rm -rf *.gcda *.gcno s21_3DViewer_V2-1_test s21_3DViewer_V2-1_test.info
    else
	cd test; valgrind --tool=memcheck --undef-value-errors=no ./s21_3DViewer_V2-1_test
	cd test; lcov -t "s21_3DViewer_V2-1_test" -o s21_3DViewer_V2-1_test.info -c -d .
	cd test; lcov -r s21_3DViewer_V2-1_test.info "/usr*" -o s21_3DViewer_V2-1_test.info
	cd test; genhtml -o report s21_3DViewer_V2-1_test.info
	cd test; xdg-open ./report/index.html
	cd test; rm -rf *.gcda *.gcno s21_3DViewer_V2-1_test s21_3DViewer_V2-1_test.info
endif

mem_test:
	rm -rf test
	mkdir test
	cd test; qmake -Wnone ../s21_3DViewer_V2-1_App/s21_3DViewer_V2-1/s21_3DViewer_V2-1_test.pro
	cd test; make
	cd test; make clean
	cp obj-images/cube-4.obj test/cube-4.obj
ifeq ($(OS), Darwin)
	cp test/s21_3DViewer_V2-1.app/Contents/MacOS/s21_3DViewer_V2-1_test test/s21_3DViewer_V2-1_test
	cd test; CK_FORK=no leaks -atExit -- ./s21_3DViewer_V2-1_test
    else
	cd test; valgrind --tool=memcheck --undef-value-errors=no ./s21_3DViewer_V2-1_test
endif

clean_all: clean clean_gcov

clean:
	rm -rf test

clean_gcov:
	cd test; rm -rf ./*.gcda ./*.gcno ./*.info ./$(GCOV_TEST) ./$(GCOV_DIR)


check:
	cd s21_3DViewer_V2-1_App/s21_3DViewer_V2-1; clang-format -i ./*.cc *.h
	cd s21_3DViewer_V2-1_App/s21_3DViewer_V2-1; clang-format -n ./*.cc *.h
