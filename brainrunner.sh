make re > /dev/null
./brainrunner "${1}"
gcc temp.c
./a.out
rm -f temp.c
rm -f a.out
rm -f brainrunner