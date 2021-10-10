
#include "Hands.H"

using namespace std;

bool compare(Player, Player);

bool operator >(const Player p1, const Player p2) {
    
  Player lhs = p1;
  Player rhs = p2;
  //weapon 1 logic
  //Checks to see if rhs wins
  if ((lhs.weapon1 == ROCK && rhs.weapon1 == PAPER) || (lhs.weapon1 == SPOCK && rhs.weapon1 == PAPER)){
    return false;
  }

  else if ((lhs.weapon1 == PAPER && rhs.weapon1 == SCISSORS) || (lhs.weapon1 == LIZARD && rhs.weapon1 == SCISSORS)){
    return false;
  }
  
  else if ((lhs.weapon1 == LIZARD && rhs.weapon1 == ROCK) || (lhs.weapon1 == SCISSORS && rhs.weapon1 == ROCK)){
    return false;
  }

  else if ((lhs.weapon1 == SPOCK && rhs.weapon1 == LIZARD) || (lhs.weapon1 == PAPER && rhs.weapon1 == LIZARD)){
    return false;
  }

  else if ((lhs.weapon1 == SCISSORS && rhs.weapon1 == SPOCK) || (lhs.weapon1 == ROCK && rhs.weapon1 == SPOCK)){
    return false;
  }

  //Checking to see if lhs wins

  else if ((rhs.weapon1 == ROCK && lhs.weapon1 == PAPER) || (rhs.weapon1 == SPOCK && lhs.weapon1 == PAPER)){
    return true;
  }

  else if ((rhs.weapon1 == PAPER && lhs.weapon1 == SCISSORS) || (rhs.weapon1 == LIZARD && lhs.weapon1 == SCISSORS)){
    return true;
  }
  
  else if ((rhs.weapon1 == LIZARD && lhs.weapon1 == ROCK) || (rhs.weapon1 == SCISSORS && lhs.weapon1 == ROCK)){
    return true;
  }

  else if ((rhs.weapon1 == SPOCK && lhs.weapon1 == LIZARD) || (rhs.weapon1 == PAPER && lhs.weapon1 == LIZARD)){
    return true;
  }

  else if ((rhs.weapon1 == SCISSORS && lhs.weapon1 == SPOCK) || (rhs.weapon1 == ROCK && lhs.weapon1 == SPOCK)){
    return true;
  }

  //weapon 2 logic
  else if ((lhs.weapon2 == ROCK && rhs.weapon2 == PAPER) || (lhs.weapon2 == SPOCK && rhs.weapon2 == PAPER)){
    return false;
  }

  else if ((lhs.weapon2 == PAPER && rhs.weapon2 == SCISSORS) || (lhs.weapon2 == LIZARD && rhs.weapon2 == SCISSORS)){
    return false;
  }
  
  else if ((lhs.weapon2 == LIZARD && rhs.weapon2 == ROCK) || (lhs.weapon2 == SCISSORS && rhs.weapon2 == ROCK)){
    return false;
  }

  else if ((lhs.weapon2 == SPOCK && rhs.weapon2 == LIZARD) || (lhs.weapon2 == PAPER && rhs.weapon2 == LIZARD)){
    return false;
  }

  else if ((lhs.weapon2 == SCISSORS && rhs.weapon2 == SPOCK) || (lhs.weapon2 == ROCK && rhs.weapon2 == SPOCK)){
    return false;
  }

  //checking for lhs weapon 2
  else if ((rhs.weapon2 == ROCK && lhs.weapon2 == PAPER) || (rhs.weapon2 == SPOCK && lhs.weapon2 == PAPER)){
    return true;
  }

  else if ((rhs.weapon2 == PAPER && lhs.weapon2 == SCISSORS) || (rhs.weapon2 == LIZARD && lhs.weapon2 == SCISSORS)){
    return true;
  }
  
  else if ((rhs.weapon2 == LIZARD && lhs.weapon1 == ROCK) || (rhs.weapon2 == SCISSORS && lhs.weapon2 == ROCK)){
    return true;
  }

  else if ((rhs.weapon2 == SPOCK && lhs.weapon2 == LIZARD) || (rhs.weapon2 == PAPER && lhs.weapon2 == LIZARD)){
    return true;  
  }

  else if ((rhs.weapon2 == SCISSORS && lhs.weapon2 == SPOCK) || (rhs.weapon2 == ROCK && lhs.weapon2 == SPOCK)){
    return true;
  }
 
  
  return false;
}

int main() {
  srand(time(0));
  Hands h;
  Player p1; 
  Player p2;
  h.heading();
  cout << "      " << p1.weapon1 << "                   " << p2.weapon1 << endl;
  cout << "      " << p1.weapon2 << "                   " << p2.weapon2 << endl;
  return 0;

  if (p1 > p2){
    cout << "Player 1's " << p1.weapon1 << "defeated Player 2's " << p2.weapon1 << endl;
  }
  else if (p2 > p1){
    cout << "Player 2's " << p2.weapon1 << "defeated Player 1's " << p1.weapon1 << endl;
  }
  else 
  cout << "It was a tie!";

}

bool compare(Player p1, Player p2) {
  

  
 return 1; 
}
