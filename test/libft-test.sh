make re -C ../
gcc libft-test.c ../libft.a -I../include -o libfttest
./libfttest
rm libfttest
make fclean -C ../
