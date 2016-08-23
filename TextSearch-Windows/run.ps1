#Test case 1
$app='.\Debug\cppClient.exe'
$arg1='.'
$arg2='main'
$arg3='4'
$arg4='"*.cpp"'
$arg5='"*.h"'
& $app $arg1 $arg2 $arg3 $arg4 $arg5  

#Test case 2
$app='.\Debug\cppClient.exe'
$arg1='.'
$arg2='#include'
$arg3='2'
$arg4='"*.cpp"'
$arg5='"*.h"'
& $app $arg1 $arg2 $arg3 $arg4 $arg5  
cmd /c "pause"
