#/Users/diogoantunes/norminette/venv/bin/norminette | egrep -B1 'Error|Warning' >check_norm
norminette | egrep -B1 'Error|Warning' >check_norm

printf "\x1b[33m[NORMINETTE]: \x1b[0m"

if [ -s check_norm ]
then
	printf "\033[1;31m[KO]\x1b[0m\n"
	cat check_norm | egrep 'Error|Warning'
else
	printf "\033[1;32m[OK]\x1b[0m\n"
fi

rm check_norm
