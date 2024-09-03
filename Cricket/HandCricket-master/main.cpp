#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "match_terminal.h"
using namespace std;
int main()
{
    system("cls");
    cout << "Welcome to the Tri Match Hand-Cricket Series!\n";
    Batsman *b1 = new Batsman[3];
    Batsman *b2 = new Batsman[3];
    Bowler *bo1 = new Bowler[2];
    Bowler *bo2 = new Bowler[2];
    string name;
    cout << "Enter name of team 1 : ";
    cin >> name;
    Team team1(name, b1, bo1);
    cout << "Enter name of team 2 : ";
    cin >> name;
    Team team2(name, b2, bo2);
    Matchterminal mt(team1, team2);
    mt.choices();
    return 0;
}