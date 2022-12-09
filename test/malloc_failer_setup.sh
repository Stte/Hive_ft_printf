#!/bin/sh

docker build -t malloc-failer .
docker run -dti --name printf_malloc_failer -v $(dirname $(pwd)):/project/ malloc-failer
docker exec -ti printf_malloc_failer make malloc_failer -C ./test
