PATH-TO-QT=s21_3DViewer_V2_App/s21_3DViewer_V2/
OS=$(shell uname)

EXECUTABLE=install


all: $(EXECUTABLE)

install:
	rm -rf temp
	rm -rf ../../s21_3DViewer_V2_App
	mkdir temp
	cd temp; qmake ../s21_3DViewer_V2_App/s21_3DViewer_V2/s21_3DViewer_V2.pro
	cd temp; make
	cd temp; make clean
	mkdir ../../s21_3DViewer_V2_App
ifeq ($(OS), Darwin)
	cp temp/s21_3DViewer_V2.app/Contents/MacOS/s21_3DViewer_V2 ../../s21_3DViewer_V2_App/s21_3DViewer_V2
else
	cp temp/s21_3DViewer_V2 ../../s21_3DViewer_V2_App/s21_3DViewer_V2
endif
	rm -rf temp
	../../s21_3DViewer_V2_App/s21_3DViewer_V2

uninstall:
	rm -rf temp
	rm -rf ../../s21_3DViewer_V2_App

dist:
	rm -rf ../../s21_3DViewer_V2_App-tar
	mkdir ../../s21_3DViewer_V2_App-tar
	tar -cf ../../s21_3DViewer_V2_App-tar/s21_3DViewer_V2.tar Makefile $(PATH-TO-QT)*.*

dvi:
	rm -rf ../../s21_3DViewer_V2_Pdf
	mkdir ../../s21_3DViewer_V2_Pdf
	cp s21_3D-Viewer-v2.pdf ../../s21_3DViewer_V2_Pdf/s21_3D-Viewer-v2.pdf

check:
	cd s21_3DViewer_V2_App/s21_3DViewer_V2; clang-format -i ./*.cc *.h
	cd s21_3DViewer_V2_App/s21_3DViewer_V2; clang-format -n ./*.cc *.h
