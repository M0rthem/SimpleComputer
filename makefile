all: ./console/pr01

./console/pr01:
	cd ./console && make

clean:
	rm -rf *.o test
