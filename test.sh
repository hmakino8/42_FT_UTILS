make re
gcc main.c libft.a -I./include/*.h -o libfttest
./libfttest
rm libfttest
make fclean
