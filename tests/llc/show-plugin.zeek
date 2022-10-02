# @TEST-EXEC: zeek -NN Zeek::LLC |sed -e 's/version.*)/version)/g' >output
# @TEST-EXEC: btest-diff output
