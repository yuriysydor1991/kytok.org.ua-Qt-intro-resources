CXXFLAGS=-g -Wall -Werror \
	-I build/ -I window/ \
	`pkg-config --cflags Qt5Widgets` \
	`pkg-config --cflags Qt5Core`

QTLIBS=`pkg-config --libs Qt5Widgets` \
	`pkg-config --libs Qt5Core`

debug:
	mkdir -vp build
	moc window/WindowWithMenu.h -o build/WindowWithMenu.moc.h
	c++ -c -fPIC $(CXXFLAGS) window/WindowWithMenu.cpp -o build/WindowWithMenu.cpp.o
	c++ -c -fPIC $(CXXFLAGS) main.cpp -o build/main.cpp.o
	c++ -o build/Qt5WindowWithMenu build/main.cpp.o build/WindowWithMenu.cpp.o $(QTLIBS)

clean:
	rm -fr build
	rm -f *.o
