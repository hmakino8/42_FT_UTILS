make re -C ../
gcc ../libft.a gnl-test.c -I../include -o gnltest
./gnltest
make fclean -C ../
rm gnltest
