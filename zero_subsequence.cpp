for length L ,

rem = L%4;

count = ( L/4 + (rem>0) ) * ( L/4 + ( rem>1) ) * ( L/4 + (rem>2) ) * (L/4);

if(count > n)
return true;
else
return false;
