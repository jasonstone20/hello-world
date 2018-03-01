#include <iostream>
#include <sstream>
#include <cmath>

void RollDie(int numberOfRolls, int numberOfDie, int sidesOfDie);
void get_int(int& d, std::string prompt, std::string fail);
void UserInput();

int main()
{
   UserInput();
}

void RollDie(int numberOfRolls, int numberOfDie, int numberOfSides)
{
    for (int j = 0; j < numberOfRolls; j++)
    {
        std::cout << "Roll#-" << j+1;
        std::cout << std::endl;
        for (int i = 0; i < numberOfDie; i++)
        {
            std::cout << "Die#-" << i+1 << ":> " << (rand() % numberOfSides) + 1 << std::endl;
        }
    }
}

void get_int(int& d, std::string prompt, std::string fail)
{
    while(1) {

            std::cout << prompt;
            std::string str;
            std::cin >> str;

            std::istringstream ss(str);
            int val1;
            ss >> val1;

            if(!ss.eof()) {
            std::cout  << fail ;
            continue;
            } else {
                d = val1;
                break;
            }
        }
    }
void UserInput()
    {
        int numberOfRolls;
        int numberOfDie;
        int numberOfSides;
        get_int(numberOfRolls, "Enter number of rolls=> ", "Sorry, that's not an integer. \n");
        get_int(numberOfDie, "Enter number of die=> ", "Sorry, that's not an integer. \n");
        get_int(numberOfSides, "Enter number of sides=> ", "Sorry, that's not an integer. \n");
        //std::cout << "Enter Number of rolls\n";
        //std::cin >> numberOfRolls;
        //std::cout << "Enter number of die\n";
        //std::cin >> numberOfDie;
        //std::cout << "Enter number of sides\n";
        //std::cin >> sidesOfDie;

        RollDie(numberOfRolls, numberOfDie, numberOfSides);

    }
