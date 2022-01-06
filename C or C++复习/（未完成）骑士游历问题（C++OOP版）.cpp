#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int total;
const int n = 5;

class Daemon
{
private:
	int x;
	int y;
public:
	Daemon(int x,int y){
		this->x = x;
		this->y = y;
	}
	
	bool move1();
	bool move2(int n);
	bool move3(int n);
	bool move4(int n);
	bool move5(int n);
	bool move6(int n);
	bool move7(int n);
	bool move8();
	
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
};

bool Daemon::move1()
{
	if(x-1 < 0 || y-2 < 0) return false;
	else
	{
		x-=1;y-=2;return true;
	}
}

bool Daemon::move2(int n)
{
	if(x+1 > n-1 || y-2 < 0) return false;
	else
	{
		x+=1;y-=2;return true;
	}
}

bool Daemon::move3(int n)
{
	if(x+2 > n-1 || y-1 < 0) return false;
	else
	{
		x+=2;y-=1;return true;
	}
}

bool Daemon::move4(int n)
{
	if(x+2 > n-1 || y+1 > n-1) return false;
	else
	{
		x+=2;y+=1;return true;
	}
}

bool Daemon::move5(int n)
{
	if(x+1 > n-1 || y+2 > n-1) return false;
	else
	{
		x+=1;y+=2;return true;
	}
}

bool Daemon::move6(int n)
{
	if(x-1 < 0 || y+2 > n-1) return false;
	else
	{
		x-=1;y+=2;return true;
	}
}

bool Daemon::move7(int n)
{
	if(x-2 < 0 || y+1 > n-1) return false;
	else
	{
		x-=2;y+=1;return true;
	}
}

bool Daemon::move8()
{
	if(x-2 < 0 || y-1 < 0) return false;
	else
	{
		x-=2;y-=1;return true;
	}
}

void DaemonQ(Daemon daemon,int n)
{
	if(daemon.getX() == n-1 && daemon.getY() == n-1)
	{
		total += 1;
		return;
	}
	if(daemon.move1())
		DaemonQ(daemon,n);
	else if(daemon.move2(n))
		DaemonQ(daemon,n);
	else if(daemon.move3(n))
		DaemonQ(daemon,n);
	else if(daemon.move4(n))
		DaemonQ(daemon,n);
	else if(daemon.move5(n))
		DaemonQ(daemon,n);
	else if(daemon.move6(n))
		DaemonQ(daemon,n);
	else if(daemon.move7(n))
		DaemonQ(daemon,n);
	else if(daemon.move8())
		DaemonQ(daemon,n);
}

int main(int argc, char** argv) 
{
	Daemon d(0,0);
	DaemonQ(d,n);
	cout << total << endl;
	return 0;
}
