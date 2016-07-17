g++ -I../../include -I../../share -I../../dvm -I../Birdee -DBD_ON_GCC -DBD_ON_LINUX -DBD_ON_X86 -DBD_MULTITHREAD -fPIC -c libNativeTest.cpp
g++ -shared -o libNativeTest.so libNativeTest.o
ln libNativeTest.so ../Birdee/bin/Debug/libNativeTest.so
