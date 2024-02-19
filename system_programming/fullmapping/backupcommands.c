leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -c -fPIC MemoryMappingFullFuncs2
MemoryMappingFullFuncs2Explicit.c  MemoryMappingFullFuncs2Static.c
MemoryMappingFullFuncs2Implicit.c  
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -c -fPIC MemoryMappingFullFuncs2Explicit.c 
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -c -fPIC MemoryMappingFullFuncs2Explicit.c MemoryMappingFullFuncs2Static.c MemoryMappingFullFuncs2Implicit.c MemoryMappingFullFunctionsStatic.c MemoryMappingFullFuncsImplicit.c MemoryMappingFullFuncsExplicit.c 
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ ar -rv libmemorystatic.a MemoryMappingFullFuncs2Static.o MemoryMappingFullFunctionsStatic.o 
ar: creating libmemorystatic.a
a - MemoryMappingFullFuncs2Static.o
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -o libmemorymappingfullimplicit.so -Wl,--whole-archive libmemorystatic.a -Wl,--no-whole-archive -shared MemoryMappingFullFuncsImplicit.o MemoryMappingFullFuncs2Implicit.o
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -o libmemorymappingfullimplicit.so -Wl,--whole-archive libmemorystatic.a -Wl,--no-whole-archive -shared MemoryMappingFullFuncsImplicit.o MemoryMappingFullFuncs2Implicit.o
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -o -shared libmemorymappingfullexplicit.so MemoryMappingFullFuncsExplicit.o MemoryMappingFullFuncs2Explicit.o
gcc: error: libmemorymappingfullexplicit.so: No such file or directory
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -shared -o libmemorymappingfullexplicit.so MemoryMappingFullFuncsExplicit.o MemoryMappingFullFuncs2Explicit.o
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -c -g -fPIC MemoryMappingFullFuncs2Explicit.c MemoryMappingFullFuncs2Static.c MemoryMappingFullFuncs2Implicit.c MemoryMappingFullFunctionsStatic.c MemoryMappingFullFuncsImplicit.c MemoryMappingFullFuncsExplicit.c 
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ ar -rv libmemorystatic.a MemoryMappingFullFuncs2Static.o MemoryMappingFullFunctionsStatic.o 
r - MemoryMappingFullFuncs2Static.o
r - MemoryMappingFullFunctionsStatic.o
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ ranlib libmemorystatic.a 
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -o libmemorymappingfullimplicit.so -Wl,--whole-archive libmemorystatic.a -Wl,--no-whole-archive -shared MemoryMappingFullFuncsImplicit.o MemoryMappingFullFuncs2Implicit.o
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -shared -o libmemorymappingfullexplicit.so MemoryMappingFullFuncsExplicit.o MemoryMappingFullFuncs2Explicit.o
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -c -g MemoryMappingFull.c 
gcc: error: MemoryMappingFull.c: No such file or directory
gcc: fatal error: no input files
compilation terminated.
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ leon@leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -c -g MemoryMappingFullMain.c 
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -c -g MemoryMappingFullMain.c 
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ sudo cp libmemorymappingfullexplicit.so /usr/lib
[sudo] password for leon: 
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ sudo cp libmemorymappingfullimplicit.so /usr/lib
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ gcc -o execute MemoryMappingFullMain.o -lmemorymappingfullimplicit -lmemorymappingfullexplicit -ldl
leon@leon-HP-Notebook:~/leonid.golovko/system_programming/fullmapping$ ./execute 

