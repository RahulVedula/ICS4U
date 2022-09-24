#include <bits/stdc++.h> //This library imports a variety of libraries as a header file 
#include <ctime> //True random variables 
#include <iostream> //Library contains all the functions used inside the C++ code
#include <random> //Randomizes, but doesnt create a true random order each run
#include <stdio.h>
#include <stdlib.h>
#include <string> //String library imports useful functions for manipulating or taking in strings
#include <time.h> //Also true random variables
#include <vector> //Vectors are dynamic arrays, making it easier to manipulate especially with dynamic sizes of discard piles
using namespace std;

const string faces[] = {"Deuce", "Three", "Four", "Five", "Six",
                        "Seven", "Eight", "Nine", "Ten",  "Jack",
                        "Queen", "King",  "Ace"};  //Constant array for faces, helps when creating the whole deck
const string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"}; //Constant array for suits, helps when creating the whole deck
string wholeDeck[52] = {}; //The array holds all the cards in the deck, it creates 52 cards.
vector<string> player1Cards; //This array holds all of player 1s card
vector<string> player2Cards;//This array holds all of player 2s card
string player1Hand[4] = {}; //This array holds the 4 cards in p1's hand
string player2Hand[4] = {}; //This array holds the 4 cards in p2's hand
vector<string> player1Discard; //This creates a vector for the discard piles
vector<string> player2Discard; //This creates a vector for the discard piles of player 2
string inputArr[3] = {}; //The input array is used to split the input lines
string player1Name, player2Name; //The names of both players

void makeDeck() { //This function creates a deck of 52 cards
  for (int i = 0; i < 52; i++) {
    wholeDeck[i] = faces[i % 13] + " of " + suits[i % 4];
  }
}

void split(string s) { //This function splits a string by whitespace
  stringstream ss(s);
  string word;
  int i = 0;
  while (ss >> word) {
    inputArr[i] = word;
    i++;
  }
}

void shuffleDeck() { //This function shuffles the deck into random parts, althugh its only used by the original deck
  srand((unsigned int)time(NULL));
  for (int i = 0; i < 52; i++) {
    int randomCheck = rand() % 52;
    string temp = wholeDeck[randomCheck];
    wholeDeck[randomCheck] = wholeDeck[51 - i];
    wholeDeck[51 - i] = temp;
  }
}

void shufflePlayer1() { //This method shuffles player1's deck
  srand((unsigned int)time(NULL));
  for (int i = 0; i < player1Cards.size(); i++) {
    int randomCheck = rand() % player1Cards.size();
    string temp = player1Cards.at(randomCheck);
    player1Cards.at(randomCheck) = player1Cards.at(player1Cards.size() - 1 - i);
    player1Cards.at(player1Cards.size() - 1 - i) = temp;
  }
}
void shufflePlayer2() { //This method shuffles player2's deck
  srand((unsigned int)time(NULL));
  for (int i = 0; i < player2Cards.size(); i++) {
    int randomCheck = rand() % player2Cards.size();
    string temp = player2Cards.at(randomCheck);
    player2Cards.at(randomCheck) = player2Cards.at(player2Cards.size() - 1 - i);
    player2Cards.at(player2Cards.size() - 1 - i) = temp;
  }
}

void splitDeck() { //This method distributes the cards equally to P1Hands and P2Hands (26 each)
  for (int i = 0; i < 52; i++) {
    if (i > 25) {
      player1Cards.push_back(wholeDeck[i]);
    } else {
      player2Cards.push_back(wholeDeck[i]);
    }
  }
}
void distributeCards() { //This function distributes the cards into the players hands and pops back the original decks 
  for (int i = 0; i < 4; i++) {
    player1Hand[i] = player1Cards.at(player1Cards.size() - 1 - i);

    player2Hand[i] = player2Cards.at(player2Cards.size() - 1 - i);
  }
  for (int j = 0; j < 4; j++) {
    player1Cards.pop_back();
    player2Cards.pop_back();
  }
}

int cardToNumber(string input) { //This method converts a card into a number

  split(input);
  int value = 0;
  for (int i = 0; i < 13; i++) {
    if (inputArr[0] == faces[i]) {
      value = i * 4;
    }
  }
  for (int j = 0; j < 4; j++) {
    if (inputArr[2] == suits[j]) {
      value = value + j + 1;
    }
  }
  return value;
}

void checkWinner(int p1Input, int p2Input) { //This method checks the winner using the numerical values while also popping back/printing important info
  int digit1, digit2, digit3, digit4;
  int p2Digit1, p2Digit2, p2Digit3, p2Digit4;
  digit1 = (p1Input % 10) - 1;
  digit2 = (p1Input / 10 % 10) - 1;
  digit3 = (p1Input / 100 % 10) - 1;
  digit4 = (p1Input / 1000 % 10) - 1;

  p2Digit1 = (p2Input % 10) - 1;
  p2Digit2 = (p2Input / 10 % 10) - 1;
  p2Digit3 = (p2Input / 100 % 10) - 1;
  p2Digit4 = (p2Input / 1000 % 10) - 1;

  int player1Input[] = {digit4, digit3, digit2, digit1};
  int player2Input[] = {p2Digit4, p2Digit3, p2Digit2, p2Digit1};

  for (int i = 0; i < 4; i++) {
    int storeP1 = cardToNumber(player1Hand[player1Input[i]]);
    int storeP2 = cardToNumber(player2Hand[player2Input[i]]);

    if (storeP1 > storeP2) {
      cout << player1Hand[player1Input[i]] << " vs "
           << player2Hand[player2Input[i]] << ", winner: " << player1Name
           << endl;
      player1Discard.push_back(player1Hand[player1Input[i]]);
      player1Discard.push_back(player2Hand[player2Input[i]]);
    } else {
      cout << player1Hand[player1Input[i]] << " vs "
           << player2Hand[player2Input[i]] << ", winner: " << player2Name
           << endl;
      player2Discard.push_back(player1Hand[player1Input[i]]);
      player2Discard.push_back(player2Hand[player2Input[i]]);
    }
  }
}
void clear() { std::cout << "\x1B[2J\x1B[H"; } //Clears console

bool checkInput(int checkInput1) { //Validates the input of both players 
  int digit1, digit2, digit3, digit4;
  digit1 = checkInput1 % 10;
  digit2 = checkInput1 / 10 % 10;
  digit3 = checkInput1 / 100 % 10;
  digit4 = checkInput1 / 1000 % 10;

  int arr[] = {digit1, digit2, digit3, digit4};
  int arrCheck[] = {4, 3, 2, 1};
  bool validifyStatement = true;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {

      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  for (int match = 0; match < 4; match++) {
    if (arrCheck[match] != arr[match]) {
      validifyStatement = false;
    }
  }
  return validifyStatement;
}

void gamePlayStart() { //This method holds all the functions needed to start the inpu
  int p1Input, p2Input;
  //Stores the names of the players into variables. 
  cout << "Please enter player 1's name:" << endl;
  getline (cin, player1Name);

  cout << "Please enter player 2's name:" << endl;
  getline (cin, player2Name);


  // Nested While Loop
  int voidCheck = 0;
  while (player1Cards.size() >= 4 && player2Cards.size() >= 4) {
    //This loop identifies when all player cards are over
    while (player1Cards.size() >= 4 && player2Cards.size() >= 4) {
      //This loop identifies when the player cards are up, then adds the discard pile to the player cards
      if (voidCheck != 0) { //Prints the cards on every turn but the first
        cout << player1Name << " has " << player1Cards.size() << " cards left!"
             << endl;
        //cout << player1Discard.size() << endl;
        cout << player2Name << " has " << player2Cards.size() << " cards left!"
             << endl;
        string apple;
        cout << "Please press enter to continue" << endl;
        cin >> apple;
        clear();
      }
    //Distributes the cards from P1/P2 cards into each players hands
      distributeCards();
      cout << "These are the cards that " << player1Name
           << " has in their hand: " << player1Hand[0] << ", " << player1Hand[1]
           << ", " << player1Hand[2] << ", " << player1Hand[3] << endl;

      cout << player1Name
           << " Please enter the order you would like to play:" << endl;
      cin >> p1Input;
      int conditional = 0;

      //Checks the input to see if its valid
      while (!checkInput(p1Input)) {
        if (conditional == 10) {
          break;
        } else {
          cout << "Please enter a valid order" << endl;
          cin >> p1Input;
        }
      }
      clear();
      //Prints p2's cards
      cout << "These are the cards that " << player2Name
           << " has in their hand: " << player2Hand[0] << ", " << player2Hand[1]
           << ", " << player2Hand[2] << ", " << player2Hand[3] << endl;

      cout << player2Name
           << " Please enter the order you would like to play:" << endl;
      cin >> p2Input;
      //Checks the input to see if its valid

      while (!checkInput(p2Input)) {
        if (conditional == 10) {
          break;
        } else {
          cout << "Please enter a valid order (One line like '1234' or '4312')"
               << endl;
          cin >> p2Input;
        }
      }
      clear();
      //Checks the winnerws between the two
      checkWinner(p1Input, p2Input);
      voidCheck++;
    }
    //Resets iteration variables back to 0
    int countIts1 = 0;
    int countIts2 = 0;

    //Adds the discard cards from player1s deck back to player1s cards
    for (int iterate = 0; iterate < player1Discard.size(); iterate++) {
      player1Cards.push_back(
          player1Discard.at(player1Discard.size() - 1 - iterate));
      countIts1++;
    }
        //Adds the discard cards from player2s deck back to player2s cards
    for (int iterate1 = 0; iterate1 < player2Discard.size(); iterate1++) {
      player2Cards.push_back(
          player2Discard.at(player2Discard.size() - 1 - iterate1));
      countIts2++;
    }
    //Removes cards from p1Discard
    for (int check1 = 0; check1 < countIts1; check1++) {
      player1Discard.pop_back();
    }
    //Removes cards from p2Discard
    for (int check2 = 0; check2 < countIts2; check2++) {
      player2Discard.pop_back();
    }
    shufflePlayer1();
    shufflePlayer2();
  }

  //Determines the winner of the game
  if (player1Cards.size() > player2Cards.size()) {
    cout << player1Name << " has won the game!" << endl;
  }
  if (player2Cards.size() > player1Cards.size()) {
    cout << player2Name << " has won the game!" << endl;
  }
}

//Main function has all the functions, could be reduced even further by putting all functiosn into gamePlayStart, but it looks nice so I decided to keep it. 
int main() {
  makeDeck();
  shuffleDeck();
  splitDeck();
  gamePlayStart();
  return 0;
}
