all :
	ninja -C build

build :
	cmake -G Ninja -B build

install :
	sudo ninja -C build install

clean :
	sudo ninja -C build uninstall
	sudo rm -r build

run:
	./build/crpdfcpp
