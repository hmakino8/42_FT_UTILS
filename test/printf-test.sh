make re -C ../
gcc ../libft.a printf-test.c -I../include -o printf
gcc ../libft.a printf-test.c -I../include -D FT_PRINTF -o ft_printf
./printf > printf.txt
./ft_printf > ft_printf.txt
diff -a --suppress-common-lines printf.txt ft_printf.txt
rm -rf printf ft_printf printf.txt ft_printf.txt
make fclean -C ../
