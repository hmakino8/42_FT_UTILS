gcc *.c -I ../../../include/ ../../string/*.c ../get_next_line/*.c ../../stdlib/*.c ../../ctype/*.c ../../linkedlist/*.c ../*.c -D FT_PRINTF; ./a.out > ft.txt; gcc *.c -I ../../../include/ ../../string/*.c ../get_next_line/*.c ../../stdlib/*.c ../../ctype/*.c ../../linkedlist/*.c ../*.c;./a.out > original.txt;diff -a --suppress-common-lines ft.txt original.txt; rm ft.txt original.txt

