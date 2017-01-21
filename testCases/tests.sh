#!/bin/bash

for file in $( ls inputs/*.in ); do
    #echo -n "Testing with ${file} -- "

   BASE=`basename ${file} .in`

   # program testing
   #cat < ${file} > outputs/${BASE}.out
   echo  "Running: ../mytr $(cat inputs/${BASE}.param)              ${file}"
   ../mytr $(cat inputs/${BASE}.param) < ${file} > outputs/${BASE}.out

   echo "generating expected ..."
   #Generate expected
    tr  $(cat inputs/${BASE}.param) < ${file} > expected/${BASE}.expect

   
   # compare results
   diff outputs/${BASE}.out expected/${BASE}.expect &> outputs/${BASE}.diff

   if [ $? -eq 0 ]; then
      echo "Succeeded"

      # comment out these lines to retain output and diff files
      #\rm outputs/${BASE}.out
      #\rm outputs/${BASE}.diff
   else
      echo "Failed"
      echo "   See differences in outputs/${BASE}.diff"
   fi
done
