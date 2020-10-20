EXEC=$1
TMP_OUT=$2

for i in {0..5..1}; do
  testname=$(printf "%03d" $i)
  errout=$(printf "error_%03d" $i)
  $EXEC input/$testname.in > $TMP_OUT
  if ! diff -qwB test/$testname.out $TMP_OUT &>/dev/null; then
    diff -qwB test/$testname.out $TMP_OUT > output/$errout
    echo "Test $testname failed"
  else
    rm $TMP_OUT
    echo "Test $testname passed"
  fi
done