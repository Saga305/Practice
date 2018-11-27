#include <iostream>

#include <cstring>

#include <chrono>

​

using namespace std;

​

typedef struct Buffer

{

char data[3000];

int size;

​

Buffer():size(0)

{

memset(data,'\0',sizeof(data));

}

}DataBuffer;

​

typedef struct Buffer1

{

char data[3000];

int size;

​

Buffer1():size(0)

{

memset(data,'\0',sizeof(data));

}

​

Buffer1& operator = (const Buffer1 &b)

{

strcpy(data,b.data);

}

​

}DataBuffer1;

​

typedef struct Buffer2

{

char data[3000];

int size;

​

Buffer2():size(0)

{

memset(data,'\0',sizeof(data));

}

​

Buffer2& operator = (const Buffer2 &b)

{

memcpy(data,b.data+1,b.size);

}

​

}DataBuffer2;

​

typedef struct Buffer3

{

char data[3000];

int size;

​

Buffer3():size(0)

{

memset(data,'\0',sizeof(data));

}

​

Buffer3& operator = (const Buffer3 &b)

{

snprintf(data,b.size,"%s",b.data);

}

​

}DataBuffer3;

​

​

class Test

{

private:

DataBuffer buf;

DataBuffer1 buf1;

DataBuffer2 buf2;

DataBuffer3 buf3;

public:

​

void checkNormal()

{

DataBuffer temp;

strcpy(temp.data,"2018-11-22 08:23:26.008 [2618]: (DEBUG, test.cpp:15 [testMethod]) I am in testMethod at Line");

temp.size = strlen(temp.data);

auto start = std::chrono::high_resolution_clock::now();

for(int i = 0; i < 100000000; ++i)

{

buf = temp;

}

auto finish = std::chrono::high_resolution_clock::now();

std::chrono::duration<double> elapsed = finish - start;

cout<<"Default Copy Assignment: "<<elapsed.count()<<endl;

return;

}

​

	 void checkstrcpy()

{

DataBuffer1 temp;

strcpy(temp.data,"2018-11-22 08:23:26.008 [2618]: (DEBUG, test.cpp:15 [testMethod]) I am in testMethod at Line");

temp.size = strlen(temp.data);

auto start = std::chrono::high_resolution_clock::now();

for(int i = 0; i < 100000000; ++i)

{

buf1 = temp;

}

auto finish = std::chrono::high_resolution_clock::now();

std::chrono::duration<double> elapsed = finish - start;

cout<<"strcpy Copy Assignment: "<<elapsed.count()<<endl;

return;

}

​

void checkmemcpy()

{

DataBuffer2 temp;

strcpy(temp.data,"2018-11-22 08:23:26.008 [2618]: (DEBUG, test.cpp:15 [testMethod]) I am in testMethod at Line");

temp.size = strlen(temp.data);

auto start = std::chrono::high_resolution_clock::now();

for(int i = 0; i < 100000000; ++i)

{

buf2 = temp;

}

auto finish = std::chrono::high_resolution_clock::now();

std::chrono::duration<double> elapsed = finish - start;

cout<<"memcpy Copy Assignment: "<<elapsed.count()<<endl;

return;

}

​

void checksnprintf()

{

DataBuffer3 temp;

strcpy(temp.data,"2018-11-22 08:23:26.008 [2618]: (DEBUG, test.cpp:15 [testMethod]) I am in testMethod at Line");

temp.size = strlen(temp.data);

auto start = std::chrono::high_resolution_clock::now();

for(int i = 0; i < 100000000; ++i)

{

buf3 = temp;

}

auto finish = std::chrono::high_resolution_clock::now();

std::chrono::duration<double> elapsed = finish - start;

cout<<"snprintf Copy Assignment: "<<elapsed.count()<<endl;

return;

}

​

};

​

​

​

int main()

{

Test t;

t.checkNormal();

t.checkstrcpy();

t.checkmemcpy();

t.checksnprintf();

return 0;

}

