#include <iostream>
using namespace std;

string parkingExit(int array[][5]);
int findNumber(int number, int array[], int size);
string parkingExit(int array[][5])
{
    int tempArray[3][5];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tempArray[i][j] = array[i][j];
        }
    }
    string direction = "";
    int objectCurrentLocation;
    int stairsLocation = 0;
    objectCurrentLocation = findNumber(2, tempArray[0], 5);
    for (int i = 0; i < 2; i++)
    {
        stairsLocation = findNumber(1, tempArray[i], 5);
        if (stairsLocation > objectCurrentLocation)
        {
            direction += "\nRight: ";
            direction += char(stairsLocation - objectCurrentLocation + '0');
        }
        else if (stairsLocation < objectCurrentLocation)
        {
            direction += "\nLeft: ";
            direction += char(objectCurrentLocation - stairsLocation + '0');
        }
        objectCurrentLocation = stairsLocation;
        if (tempArray[i + 1][stairsLocation] == 1)
        {
            direction += "\nDown: 2";
            i++;
        }
        else
        {
            direction += "\nDown: 1";
        }
    }
    if (objectCurrentLocation != 4)
    {
        direction += "\nRight: ";
        direction += char(4 - objectCurrentLocation + '0');
    }
    direction += '\n';
    return direction;
}
int findNumber(int number, int array[], int size)
{
    for (int i = 0; i < 5; i++)
    {
        if (array[i] == number)
        {
            return i;
        }
    }

    return -1;
}
int main()
{
    int parkingLot[3][5] = {
        {2, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
    };
    cout << parkingExit(parkingLot);
}