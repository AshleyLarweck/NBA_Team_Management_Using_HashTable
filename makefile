p5: yya310Project5.o HashTable.o
	gcc yya310Project5.o HashTable.o -o p5
yya310Project5.o: yya310Project5.c HashTable.h
	gcc -c yya310Project5.c -o yya310Project5.o 
HashTable.o: HashTable.c HashTable.h
	gcc -c HashTable.c -o HashTable.o  
clean:
	rm -rf *.o 
	rm p5