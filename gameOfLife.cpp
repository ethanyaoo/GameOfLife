//
//  main.cpp
// 

// Game uses a start file named as 'life.txt' where the symbol '*' is used to represent a
// living cell while the symbol '-' is used to symbolize a dead cell. In the game, if a living
// cell is surrounded by 2-3 other living cells, it survives to the next generation otherwise
// it dies. If a dead cell is surrounded by exactly 3 other living cells it lives in the next
// generation. The game displays the initial generation as well as 10 further generations.
//
//  Created by Ethan Yao on 2/1/19.
//  Copyright © 2019 Ethan Yao. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int lifeChecker(int position, int lengthX, const string& lifeString) {
    int pos = position;
    int lifeCounter = 0;
    if (lifeString[pos - lengthX -1] == '*') {
        lifeCounter++;
    }
    if (lifeString[pos - lengthX] == '*') {
        lifeCounter++;
    }
    if (lifeString[pos - lengthX + 1] == '*') {
        lifeCounter++;
    }
    if (lifeString[pos - 1] == '*') {
        lifeCounter++;
    }
    if (lifeString[pos + 1] == '*') {
        lifeCounter++;
    }
    if (lifeString[pos + lengthX - 1] == '*') {
        lifeCounter++;
    }
    if (lifeString[pos + lengthX] == '*') {
        lifeCounter++;
    }
    if (lifeString[pos + lengthX + 1] == '*') {
        lifeCounter++;
    }
    return lifeCounter;
}

void display(const string& newString, const int lengthX)
{
    int lengthCounter = 0;
    for (int i = 0; i < newString.size(); i++) { 
        lengthCounter++;
        cout << newString[i];
        if (lengthCounter == lengthX) {
            cout << endl;
            lengthCounter = 0;
        }
    }
    cout << "====================" << endl;
}

string newGen(const string& oldString, const int lengthX)
{
    string newString = "";
    for(int pos=0; pos<oldString.size(); pos++)
    {
        if(oldString[pos] == '*')
        {
            int lifeCounter = lifeChecker(pos, lengthX, oldString);
            if (lifeCounter == 2 || lifeCounter == 3)
            {
                newString += '*';
            }
            else
            {
                newString += '-';
            }
        }
        else if (oldString[pos] == '-')
        {
            int lifeCounter = lifeChecker(pos, lengthX, oldString);
            if (lifeCounter == 3)
            {
                newString += '*';
            }
            else 
            {
                newString += '-';
            }
        }
    }
    return newString;
}


int main() {
    ifstream ifs("life.txt");
    
    cout << "Initial World" << endl;
    
    string lineIfs;
    string oldString = "";
    int lengthY = 0;
    int lengthX = 0;
    
    if (!ifs)
    {
      cerr << "failed to open life.txt" << endl;
      exit(1);
    }
    
    while (ifs >> lineIfs)
    {
        lengthY++;
        cout << lineIfs << endl;
        oldString += lineIfs;
    }
    cout << "========================" << endl;

    lengthX = lineIfs.size();
    
    for (size_t i=1; i < 11; i++)
    {
        string newString = "";
        cout << "Generation: " << i << endl;
        
        newString = newGen(oldString, lengthX);

        display(newString, lengthX);
        
        oldString = newString; //Replaces old string with new string
    }
    
    ifs.close();

    return 0;
}
