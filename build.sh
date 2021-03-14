#!/bin/bash
cat tests.tar|openssl aes-256-cbc -a -d -pass pass:$token |tar xv
cd tests
cmake -S . -B build
cmake --build build --config Release
