p=7; 
for((m=1; m<=p; m++)) 
do
    for((a=i; a<=p; a++)) 
    do
      echo -ne " "; 
    done
    for((n=1; n<=m; n++)) 
    do
      echo -ne "*"; 
    done
    for((i=1; i<m; i++)) 
    do
      echo -ne "*"; 
    done 
    # New line 
    echo; 
done
