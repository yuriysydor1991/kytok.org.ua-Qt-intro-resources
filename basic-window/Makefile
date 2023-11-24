CXXFLAGS=-g -Wall -Werror \
	-I build/ -I window/ \
	`pkg-config --cflags Qt5Widgets` \
	`pkg-config --cflags Qt5Core`

QTLIBS=`pkg-config --libs Qt5Widgets` \
	`pkg-config --libs Qt5Core`

debug:
	mkdir -vp build
	moc window/ArbitraryWindow.h -o build/ArbitraryWindow.moc.h
	c++ -c -fPIC $(CXXFLAGS) window/ArbitraryWindow.cpp -o build/ArbitraryWindow.cpp.o
	c++ -c -fPIC $(CXXFLAGS) main.cpp -o build/main.cpp.o
	c++ -o build/Qt5BasicMainWindow build/main.cpp.o build/ArbitraryWindow.cpp.o $(QTLIBS)

clean:
	rm -fr build
	rm -f *.o
