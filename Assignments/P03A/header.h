#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ROCK u8"\U0001F5FB"
#define PAPER u8"\U0001F4C3"
#define SCISSORS u8"\U0001F52A"
#define LIZARD u8"\U0001F438"
#define SPOCK u8"\U0001F596"

class Hands {
  public:
    const string rock = ROCK;
    const string paper = PAPER;
    const string scissors = SCISSORS;
    const string lizard = LIZARD;
    const string spock = SPOCK;
    
    string arr[5] = {ROCK, PAPER, SCISSORS, LIZARD, SPOCK};

    static string Rock() {
        return ROCK;
    }
    static string Paper() {
        return PAPER;
    }
    static string Scissors() {
        return SCISSORS;
    }
    static string Lizard() {
        return LIZARD;
    }
    static string Spock() {
        return SPOCK;
    }
    
    string RandHand(){
      return arr[rand()%5];
    }

    void heading(){
      cout << "Welcome to Rock Paper Scissors Lizard Spock!" << endl;
      cout << "--------------------------------------------" << endl;
      cout << "    " << "Player 1:" << "             " << "Player 2: " << endl;
    }
};

class Player : public Hands{
  public:
    string weapon1;
    string weapon2;
    /**
     * Constructor guarantees a player has two different "weapons"
     */
    Player(){
        weapon1 = RandHand();
        weapon2 = RandHand();

        while(weapon2==weapon1){
            weapon2 = Hands::RandHand();
        }
    }
    // other possible methods
};
