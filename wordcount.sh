echo enter filename
read filename
echo enter word to search
read word

if grep -q $word $filename; then
   echo no .of occurrences of $word in $filename is 
   grep -i -o $word $filename | wc -l
else
   echo not found
fi