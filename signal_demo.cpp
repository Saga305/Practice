/*.

Run this on other ide where yiu can send a signal to a process.

Basically this program is a demo for graceful termination upon arrival of interrupt signal.
*/



#include <iostream>

#include <csignal>

#include <unistd.h>

#include <atomic>

std::atomic<bool> quit(false);

using namespace std;

void (*oldHandler)(int);

void signal_handler( int signal_num )

{

cout<<"In to signal handler"<<std::endl;

quit.store(true);

}

class SignalHandler

{

public:

void sigH()

{

oldHandler = signal(SIGINT,signal_handler);

if(oldHandler == SIG_ERR)

{

exit(-1);

}

return;

}

};

class Test: public SignalHandler

{

private:

char *p;

public:

Test()

{

p = new char[20];

}

~Test()

{

cout<<"In Destructor"<<std::endl;

if(p)

{

delete p;

p = nullptr;

}

}

void start()

{

while(true)

{

cout<<"1"<<std::endl;

if(quit.load())

{

break;

}

}

}

};
class Test1: public SignalHandler

{

private:

char *p;

public:

Test1()

{

p = new char[20];

}

~Test1()

{

cout<<"In Destructor in 1"<<std::endl;

if(p)

{

delete p;

p = nullptr;

}

}

void start()

{

while(true)

{

cout<<"2"<<std::endl;

if(quit.load())

{

break;

}

}

}

};
int main()

{

Test t;

Test1 t1;

t1.sigH();

t.sigH();

t.start();

t1.start();

return 0;

}