echo enter a number
read n

f=1

while (($n >= 1))
do 
  let "f *= n"
  let "n -= 1"
done

echo factorial is $f