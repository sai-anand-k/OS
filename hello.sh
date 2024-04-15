echo enter size
read n

echo enter the elements
for((i=0; i<n; i++))
do
  read arr[i]
done

echo entered array is
echo ${arr[*]}

echo enter ascending or descending
read f

if ((f==1))
then
    for((i=0; i<n; i++))
    do
      for((j=0; j<n-i-1 ; j++))
      do
        if (( ${arr[j]}>=${arr[j+1]} ))
        then 
            temp=${arr[$j]}
            arr[$j]=${arr[$((j+1))]}
            arr[$((j+1))]=$temp
        fi
      done
    done
else
    for((i=0; i<n; i++))
    do
      for((j=0; j<n-i-1 ; j++))
      do
        if (( ${arr[j]}<=${arr[j+1]} ))
        then 
            temp=${arr[$j]}
            arr[$j]=${arr[$((j+1))]}
            arr[$((j+1))]=$temp
        fi
      done
    done
fi

echo sorted array is
echo ${arr[*]}


