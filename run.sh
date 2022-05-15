test_list=(file log reference_counting string utility)

for i in ${test_list[@]}
do
  build/test/$i/test_$i
done
