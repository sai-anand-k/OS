echo enter limit
read n

first=0
second=1
i=2
echo fibonacci numbers upto $n are 
while (($i<=n))
do
  if (($i==2))
  then
      echo 0
      echo 1
  fi 
let 'current = first + second'
echo $current
let 'first = second'
let 'second = current'
let 'i+=1'
done