make re -C ../../../
gcc *.c -I../../../include ../../../libft.a -o gnltest
./gnltest
make fclean -C ../../../
rm gnltest
