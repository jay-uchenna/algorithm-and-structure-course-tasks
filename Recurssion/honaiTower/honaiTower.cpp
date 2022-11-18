#include <iostream>
#include <chrono>
#include <thread>

class Tower
{
public:
	Tower(int );
	~Tower();

	void printTower();
	void move(int, int);
private:
	int ** tower_arr;
	int numberOfDisks;
	int spaceInTower[3];
	int steps;
};

void pause(float& );
void solveTOH(Tower& , int, int, int, int, float&);
void workboard(int, float&);
void errorM();

int main()
{	
	system("clear");
	int numberOfDisks;
	std::cout << "Welcome to the Tower or Hanoi app, ";

	std::cout << "set delay time (s): ";
	float delayTime;
	std::cin >> delayTime;
	if (std::cin.fail() || delayTime < 0 ) errorM();
	
	char out = 'c';
	do
	{	
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Please enter the number of disks: ";
		std::cin >> numberOfDisks;
		if (std::cin.fail() || numberOfDisks < 1) errorM();
		workboard(numberOfDisks, delayTime);
		std::cout << "press x to exit or any key to try again: ";
		std::cin >> out;

	}while(out != 'x' && out != 'X');
	return 0;
}

Tower::Tower(int numberOfDisks)
{
	this->tower_arr = new int* [3];
	for(int i = 0; i < 3; i++) this->tower_arr[i] = new int[numberOfDisks];

	for(int i = 0; i < numberOfDisks; i++) this->tower_arr[0][i] = i + 1;
	for(int i = 0; i < numberOfDisks; i++) this->tower_arr[1][i] = 0;
	for(int i = 0; i < numberOfDisks; i++) this->tower_arr[2][i] = 0;
	this->spaceInTower[0] = -1;
	this->spaceInTower[1] = numberOfDisks-1;
	this->spaceInTower[2] = numberOfDisks-1;
	this->numberOfDisks = numberOfDisks;
	this->steps = 0;
}
Tower::~Tower()
{
	for(int i = 0; i < 3; i++) delete [] this->tower_arr[i];
	delete [] this->tower_arr;
}
void Tower::printTower()
{
	std::cout << "step " << this->steps++ << "\n";
	for(int j = 0; j < this->numberOfDisks; j ++ ) 
		std::cout << this->tower_arr[0][j] << " : "  
				  	<< this->tower_arr[1][j] << " : " 
						<< this->tower_arr[2][j] << "\n";
	std::cout << "\n";
}
void Tower::move(int a, int b)
{
	this->tower_arr[b][this->spaceInTower[b]--] = this->tower_arr[a][++this->spaceInTower[a]];
	this->tower_arr[a][this->spaceInTower[a]] = 0;
}


void pause(float& delayTime)
{
    int T = 1000 * (float)delayTime;
    std::this_thread::sleep_for(std::chrono::milliseconds(T));
}
void solveTOH(Tower& T, int numberOfDisks, int firstTower, int secontTower, int thirdTower, float& delayTime)
{   
	if(numberOfDisks > 0 )
	{
		solveTOH(T, numberOfDisks-1, firstTower, thirdTower, secontTower, delayTime);
		T.move(firstTower, thirdTower);
		T.printTower();
		pause(delayTime);
		solveTOH(T, numberOfDisks-1, secontTower, firstTower, thirdTower, delayTime);
	}
}
void workboard(int numberOfDisks, float& delayTime)
{
	Tower towerT(numberOfDisks);
	towerT.printTower();
    pause(delayTime);
	solveTOH(towerT, numberOfDisks, 0, 1, 2, delayTime);
}
void errorM()
{
	std::cout << "you entered a wrong input\n";
	exit(1);
}








