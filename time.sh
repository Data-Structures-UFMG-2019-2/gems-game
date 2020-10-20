EXEC=$1
TMP_OUT=$2
INPUT_GENERATOR=$3

for i in {1..255..1}; do
    testname=$(printf "%03d_tmp" $i)
    $INPUT_GENERATOR $i input/$testname.in
    for j in {1..10..1}; do
        $EXEC input/$testname.in timed > $TMP_OUT
    done
    rm input/$testname.in
done
rm $TMP_OUT