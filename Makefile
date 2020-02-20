program: convert_to_csv.o read_csv.o main.o
	gcc -o program convert_to_csv.o read_csv.o main.o
convert_to_csv.o: convert_to_csv.c
	gcc -c convert_to_csv.c
read_csv.o: read_csv.c
	gcc -c read_csv.c
main.o: main.c
	gcc -c main.c
