#include <iostream>
#include <SFML/Network.hpp>
#include "player.h"
#include "card.h"
#include <string>
using namespace std;
using namespace sf;

int send(TcpSocket &, char[]);
int bettingRound(int, Player*);
void dealTwoCardsToEach();
void hitOrStand();
void decideCalling();
void endRound();

string commander = "Commander"; // 9
string mistress = "Mistress";	  // 8
string master = "Master";	  // 6
string ace = "Ace";			  // 3
string star = "The Star";	  // 8
string evil = "The Evil One";	  // 12
string mod = "Moderation";	  // 10
string demise = "Demise";	  // 6
string balance = "Balance";	  // 7
string endurance = "Endurance"; // 9
string queen = "Queen of Air and Darkness"; // 25
string idiot = "Idiot";		  // 5

Card cards[] = {
    Card(NULL, -1, 1, 0, -1, false),		    // 1 of Sabers
    Card(NULL, -1, 2, 0, -1, false),		    // 2 of Sabers
    Card(NULL, -1, 3, 0, -1, false),		    // 3 of Sabers
    Card(NULL, -1, 4, 0, -1, false),		    // 4 of Sabers
    Card(NULL, -1, 5, 0, -1, false),		    // 5 of Sabers
    Card(NULL, -1, 6, 0, -1, false),		    // 6 of Sabers
    Card(NULL, -1, 7, 0, -1, false),		    // 7 of Sabers
    Card(NULL, -1, 8, 0, -1, false),		    // 8 of Sabers
    Card(NULL, -1, 9, 0, -1, false),		    // 9 of Sabers
    Card(NULL, -1, 10, 0, -1, false),		    // 10 of Sabers
    Card(NULL, -1, 11, 0, -1, false),		    // 11 of Sabers
    Card(commander.c_str(), 9, 12, 0, -1, true), // Commander of Sabers
    Card(mistress.c_str(), 8, 13, 0, -1, true),  // Mistress of Sabers
    Card(master.c_str(), 6, 14, 0, -1, true),    // Master of Sabers
    Card(ace.c_str(), 3, 15, 0, -1, true),	    // Ace of Sabers

    Card(NULL, -1, 1, 1, -1, false),		    // 1 of Flasks
    Card(NULL, -1, 2, 1, -1, false),		    // 2 of Flasks
    Card(NULL, -1, 3, 1, -1, false),		    // 3 of Flasks
    Card(NULL, -1, 4, 1, -1, false),		    // 4 of Flasks
    Card(NULL, -1, 5, 1, -1, false),		    // 5 of Flasks
    Card(NULL, -1, 6, 1, -1, false),		    // 6 of Flasks
    Card(NULL, -1, 7, 1, -1, false),		    // 7 of Flasks
    Card(NULL, -1, 8, 1, -1, false),		    // 8 of Flasks
    Card(NULL, -1, 9, 1, -1, false),		    // 9 of Flasks
    Card(NULL, -1, 10, 1, -1, false),		    // 10 of Flasks
    Card(NULL, -1, 11, 1, -1, false),		    // 11 of Flasks
    Card(commander.c_str(), 9, 12, 1, -1, true), // Commander of Flasks
    Card(mistress.c_str(), 8, 13, 1, -1, true),  // Mistress of Flasks
    Card(master.c_str(), 6, 14, 1, -1, true),    // Master of Flasks
    Card(ace.c_str(), 3, 15, 1, -1, true),	    // Ace of Flasks

    Card(NULL, -1, 1, 2, -1, false),		    // 1 of Coins
    Card(NULL, -1, 2, 2, -1, false),		    // 2 of Coins
    Card(NULL, -1, 3, 2, -1, false),		    // 3 of Coins
    Card(NULL, -1, 4, 2, -1, false),		    // 4 of Coins
    Card(NULL, -1, 5, 2, -1, false),		    // 5 of Coins
    Card(NULL, -1, 6, 2, -1, false),		    // 6 of Coins
    Card(NULL, -1, 7, 2, -1, false),		    // 7 of Coins
    Card(NULL, -1, 8, 2, -1, false),		    // 8 of Coins
    Card(NULL, -1, 9, 2, -1, false),		    // 9 of Coins
    Card(NULL, -1, 10, 2, -1, false),		    // 10 of Coins
    Card(NULL, -1, 11, 2, -1, false),		    // 11 of Coins
    Card(commander.c_str(), 9, 12, 2, -1, true), // Commander of Coins
    Card(mistress.c_str(), 8, 13, 2, -1, true),  // Mistress of Coins
    Card(master.c_str(), 6, 14, 2, -1, true),    // Master of Coins
    Card(ace.c_str(), 3, 15, 2, -1, true),	    // Ace of Coins

    Card(NULL, -1, 1, 3, -1, false),		    // 1 of Staffs
    Card(NULL, -1, 2, 3, -1, false),		    // 2 of Staffs
    Card(NULL, -1, 3, 3, -1, false),		    // 3 of Staffs
    Card(NULL, -1, 4, 3, -1, false),		    // 4 of Staffs
    Card(NULL, -1, 5, 3, -1, false),		    // 5 of Staffs
    Card(NULL, -1, 6, 3, -1, false),		    // 6 of Staffs
    Card(NULL, -1, 7, 3, -1, false),		    // 7 of Staffs
    Card(NULL, -1, 8, 3, -1, false),		    // 8 of Staffs
    Card(NULL, -1, 9, 3, -1, false),		    // 9 of Staffs
    Card(NULL, -1, 10, 3, -1, false),		    // 10 of Staffs
    Card(NULL, -1, 11, 3, -1, false),		    // 11 of Staffs
    Card(commander.c_str(), 9, 12, 3, -1, true), // Commander of Staffs
    Card(mistress.c_str(), 8, 13, 3, -1, true),  // Mistress of Staffs
    Card(master.c_str(), 6, 14, 3, -1, true),    // Master of Staffs
    Card(ace.c_str(), 3, 15, 3, -1, true),	    // Ace of Staffs

    Card(star.c_str(), 8, -17, -1, 0, false),    // The Star 1
    Card(star.c_str(), 8, -17, -1, 1, false),    // The Star 2
    Card(evil.c_str(), 12, -15, -1, 0, false),   // The Evil One 1
    Card(evil.c_str(), 12, -15, -1, 1, false),   // The Evil One 2
    Card(mod.c_str(), 10, -14, -1, 0, false),    // Moderation 1
    Card(mod.c_str(), 10, -14, -1, 1, false),    // Moderation 2
    Card(demise.c_str(), 6, -13, -1, 0, false),  // Demise 1
    Card(demise.c_str(), 6, -13, -1, 1, false),  // Demise 2
    Card(balance.c_str(), 7, -11, -1, 0, false), // Balance 1
    Card(balance.c_str(), 7, -11, -1, 1, false), // Balance 2
    Card(endurance.c_str(), 9, -8, -1, 0, false),// Endurance 1
    Card(endurance.c_str(), 9, -8, -1, 1, false),// Endurance 2
    Card(queen.c_str(), 25, -2, -1, 0, false),   // Queen of Air and Darkness 1
    Card(queen.c_str(), 25, -2, -1, 1, false),   // Queen of Air and Darkness 2
    Card(idiot.c_str(), 5, 0, -1, 0, false),	    // Idiot 1
    Card(idiot.c_str(), 5, 0, -1, 1, false)	    // Idiot 2
};

char ready[50] = "xready";
char name[50] = "xname";
char cash[50];
char mr[50] = "matchraise";

bool callingPhase = false;

int main()
{
    TcpListener listener;

    // bind the listener to a port
    if (listener.listen(53000) != Socket::Done)
    {
	   cout << "There was an error with binding the listener to a port." << endl << "Please contact the creator of this version of Sabacc regarding this error." << endl;
	   return 1;
    }

    int numPlayers;

    cout << "Please enter the number of players: ";
    cin >> numPlayers;

    while ((numPlayers < 2) || (numPlayers > 8))
    {
	   cout << "This game was built for 2-8 players." << endl << "Please enter the number of players: ";
	   cin >> numPlayers;
    }

    Player * players = new Player[numPlayers];

    for (int i = 0; i < numPlayers; i++)
    {
	   int garbage;
	   cout << "Please press enter to connect Player " << (i + 1) << ": ";
	   cin >> garbage;

	   if (listener.accept((players + i)->socket) != Socket::Done)
	   {
		  cout << "There was an error with accepting a new connection for Player " << (i + 1) << "." << endl;
		  cout << "Please contact the creator of this version of Sabacc regarding this error." << endl;
		  return 1;
	   }
    }

    for (int i = 0; i < numPlayers; i++)
    {
	   ready[0] = i + '0';
	   
	   int status = send((players + i)->socket, ready);
	   
	   if (status == 1)
	   {
		  return status;
	   }
    }

    size_t * r_ready = new size_t[numPlayers];

    while (true)
    {
	   for (int i = 0; i < numPlayers; i++)
	   {
		  ready[0] = i + '0';
		  (players + i)->socket.receive(ready, 100, *(r_ready + i));
	   }

	   int finished = 0;

	   for (int i = 0; i < numPlayers; i++)
	   {
		  if (*(r_ready + i) != NULL)
		  {
			 finished++;
		  }
	   }

	   if (finished == numPlayers)
	   {
		  break;
	   }
    }

    for (int i = 0; i < numPlayers; i++)
    {
	   cout << "Getting player name for player " << (i + 1) << "..." << endl;
	   name[0] = i + '0';
	   int status = send((players + i)->socket, name);

	   if (status == 1)
	   {
		  return status;
	   }
    }

    size_t * r_name = new size_t[numPlayers];

    while (true)
    {
	   for (int i = 0; i < numPlayers; i++)
	   {
		  name[0] = i + '0';
		  Socket::Status status = (players + i)->socket.receive(name, 100, *(r_name + i));

		  if (status == Socket::Done)
		  {
			 (players + i)->setName(name, *(r_name + i));
		  }
	   }

	   int finished = 0;

	   for (int i = 0; i < numPlayers; i++)
	   {
		  if (*(r_name + i) != NULL)
		  {
			 finished++;
		  }
	   }

	   if (finished == numPlayers)
	   {
		  break;
	   }
    }

    callingPhase = false;
    int status = bettingRound(numPlayers, players);

    if (status == 1)
    {
	   return status;
    }

    /*
    // Sending data
    char data[100] = ...;

    // TCP socket:
    if (socket.send(data, 100) != Socket::Done)
    {
	   // error...
    }
    */

    /*
    // Receiving data
    char data[100];
    size_t received;

    // TCP socket:
    if (socket.receive(data, 100, received) != Socket::Done)
    {
	   // error...
    }
    
    cout << "Received " << received << " bytes" << endl;
    */

    delete[] players;
    delete[] r_ready;
    return 0;
}

int send(TcpSocket &socket, char data[])
{
    if (socket.send(data, 100) != Socket::Done)
    {
	   cout << "There was an error sending the data: " << data << "." << endl;
	   cout << "Please contact the creator of this version of Sabacc regarding this error." << endl;
	   return 1;
    }

    return 0;
}

int bettingRound(int numPlayers, Player * players)
{
    int * bets = new int[numPlayers];
    size_t r_bet;
    size_t r_mr;

    for (int i = 0; i < numPlayers; i++)
    {
	   itoa((players + i)->getMoney(), cash, 10);
	   int status = send((players + i)->socket, cash);

	   if (i == 0)
	   {
		  if ((!(players + i)->getBombedOut()) && (!(players + i)->getFold()))
		  {
			 Socket::Status status = (players + i)->socket.receive(cash, 100, r_bet);

			 while (true)
			 {
				if (status == Socket::Done)
				{
				    bets[i] = atoi(cash);
				    (players + i)->setMoney((players + i)->getMoney() - bets[i]);
				    break;
				}
			 }

			 continue;
		  }
		  else if ((players + i)->getBombedOut())
		  {
			 cout << "Player " << (i + 1) << " (" << (players + i)->getName() << ") has bombed out. They may not bet." << endl;
			 continue;
		  }
		  else if ((players + i)->getFold())
		  {
			 cout << "Player " << (i + 1) << " (" << (players + i)->getName() << ") has folded. They may not bet." << endl;
			 continue;
		  }
	   }
	   else
	   {
		  if ((!(players + i)->getBombedOut()) && (!(players + i)->getFold()))
		  {
			 while (true)
			 {
				status = send((players + i)->socket, mr);

				if (status == 1)
				{
				    return status;
				}

				Socket::Status status = (players + i)->socket.receive(mr, 100, r_mr);

				while (true)
				{
				    if (status == Socket::Done)
				    {
					   if (mr == "match")
					   {
						  
					   }
					   else if (mr == "raise")
					   {
						  
					   }
				    }
				}

				/*
				while (true)
				{
				for (int i = 0; i < numPlayers; i++)
				{
				name[0] = i + '0';
				Socket::Status status = (players + i)->socket.receive(name, 100, *(r_name + i));

				if (status == Socket::Done)
				{
				(players + i)->setName(name, *(r_name + i));
				}
				}

				int finished = 0;

				for (int i = 0; i < numPlayers; i++)
				{
				if (*(r_name + i) != NULL)
				{
				finished++;
				}
				}

				if (finished == numPlayers)
				{
				break;
				}
				}*/
			 }
		  }
		  else if ((players + i)->getBombedOut())
		  {
			 cout << "Player " << (i + 1) << " (" << (players + i)->getName() << ") has bombed out. They may not bet." << endl;
			 continue;
		  }
		  else if ((players + i)->getFold())
		  {
			 cout << "Player " << (i + 1) << " (" << (players + i)->getName() << ") has folded. They may not bet." << endl;
			 continue;
		  }
	   }
    }
}