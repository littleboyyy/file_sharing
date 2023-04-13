gcc -o run app.c $(pkg-config --cflags --libs gtk4 gmodule-2.0)

./run