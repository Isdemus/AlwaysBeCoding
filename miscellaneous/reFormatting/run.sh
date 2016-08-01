#!/bin/bash

./listing.sh
python separator.py
cp listing.sh main simple.py new
cd new
./listing.sh
mkdir new
./main
cp listing.sh simple.py new
cd new
./listing.sh
python simple.py
mv final ../../
cd -
cd -
rm main listing.sh simple.py main separator.py
