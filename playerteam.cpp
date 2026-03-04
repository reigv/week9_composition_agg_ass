#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    string name_;
    int number_;

public:
    Player(string name, int number) : name_(name), number_(number)
    {
        cout << "Constructor for player called." << endl;
    }
    ~Player()
    {
        cout << "Destructor for player called." << endl;
    }
    void display() const
    {
        cout << "Name: " << name_
             << ", Number: " << number_ << endl;
    }
};

class Team
{
private:
    string name_;
    Player *players_;   // aggregation: Team has Players, but Players can exist independently of the Team
                        // POITER, so the Team class does not manage the lifecycle of the Player objects
    int num_players_;

public:
    Team(string name, int num, Player *players)
        : name_(name), num_players_(num), players_(players)
    {
        cout << "Constructor for team called." << endl;
    }
    ~Team()
    {
        cout << "Destructor for team called." << endl;
    }
    void display() const
    {
        for (int i = 0; i < num_players_; i++)
        {
            players_[i].display();
        }
    }
};

int main()
{

    Player players[3] = {
        Player("Dembele", 10),
        Player("Marquinhos", 4),
        Player("Hakimi", 2)};

    Team PSG("PSG", 3, players);  // if delete PSG, it will not delete the players because the players are not managed by the Team class, they are managed by the main function

    PSG.display();
    delete PSG; // this will cause an error because we are trying to delete a stack-allocated object, not a heap-allocated object

    return 0;
}