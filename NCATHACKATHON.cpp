#include <iostream>
#include <iomanip>
using namespace std;

//Declared ROWS and COLS as a constanst integer and assigned them to 15 and 30
const int ROWS = 10;
const int COLS = 30;

//FUNCTION PROTOTYPE
//Original board that shows seats available
void getBoard();
//Options to choose: Purchase tickets, Availablilty of seats, Price of tickets, Row availablity
void Menu();
//Prompts user to enter in choice from the menu
int getChoice();
//Displays the price for each row
void RowMoney(const double []);
//Displays a ticket is purhcases along with price
void PurchTicket( char [][COLS], const double[], double&);
//Displays seat availability
void AvailableSeat(const char [] [COLS]);
//Display the total profit of the program
void SeatSales(double);

//GLOBAL VARIABLES

//Delcared choice, row1, seat, seatTot as an integer
int choice, row1, seat, seatTot, SEATS;
//Declared salesTOT as a double
double TotSales = 0.00;
//Delcared open as a constant character
const char open = '#';
//Delcared taken as a constant character
const char taken = '*';


int main()
{
    //Declared theaterTics[ROWS][COLS] and response as a character
    char theaterTics[ROWS][COLS];
    //Delcares ticPrice as a double and assigns it to 0.0
    double ticPrice[ROWS] = { 0.0 };
    //Declares totSales as a double and assigns it to 0.0
    double TotSales = 0.0;
    //For loop that shows the original board with every seat being available
    for (int row = 0; row < ROWS; row++){
        for (int col = 0; col < COLS; col++){
            //Display the board will all available seats open
            theaterTics[row][col] = open;
        }
    }
    //For loop that prompt the user to enter a price for each row
    for (int row = 0; row < ROWS; row++)
    {
        //Prompt the user to enter a price for row 1-15
        cout << " Enter a price for each row " << (row+1) << ": ";
        //Enter their price
        cin >> ticPrice[row];
    }

    do
    {
        //References the menu of choices from 1-4 and displays that to screen
        Menu();
        //Prompts user to enter in choice
        choice = getChoice();

        //Switch statment
        switch (choice)
        {
        case 1:
            //Calls the PurchTicket to the switch statement
            PurchTicket(theaterTics,ticPrice,TotSales);
            break;
        case 2:
            //Calls the AvailableSeat function to the switch statement
            AvailableSeat(theaterTics);
            break;
        case 3:
            //Calls the SeatSales function to the switch statement
            SeatSales(TotSales);
            break;
        case 4:
            //Calls the RowMoney function to the swich statment
            RowMoney(ticPrice);
            break;
            //Default
        default:
            break;
        }
    //Loop till the user enter other than 1-4
    }while (choice != 5);
    //Pause the screen
    system("PAUSE");
    return 0;
}

//Display the following menu for the theatre
void Menu()
{
    //Display the Menu
    cout << " MENU " << endl;
    //Choice one will allow the user to purchase a ticket
    cout << " 1. Purchase a Ticket " << endl;
    //Choice two will allow the user to view the available seats
    cout << " 2. View Avaliable Seats " << endl;
    //Chocie three will allow the user to view the total amount of sales when tickets were purchased
    cout << " 3. View Ticket Sales" << endl;
    //Choice four will display the prices for each row
    cout << " 4. Display for prices for each Row" <<endl;
    cout << "*************************" << endl;
    cout << endl;
}

//Function will be consist of switch statement based on the user selection based on the menu and will return the choice
int getChoice()
{
    //Declares choice
    int choice;
    //Prompts user to enter in choice
    cin >> choice;

    //Input validation - choice must be 1-5
    while (choice < 1 || choice > 5)
    {
        //Ask the user to make a selection between 1 through 4
        cout << "MAKE A SELECTION FROM (1-4)";
        cin >> choice;
    }

    //Returns that choice that the user selects
    return choice;
}

//Function displays the prices for each row
void RowMoney(const double price[])
{
    //Print out the the words Row and Price
    cout << "      Row    Price" <<endl;
    //Print out the dotted lines
    cout << "********************" <<endl;
    //For loop to print out to redisplay the prices that the user entered in earlier
    for(int row = 0; row < ROWS; row++)
    {
        //Display the prices with the correct width so it will align correctly
        cout << setw(8) << row+1 << setw(10) << price[row] <<endl;
    }

}
//Void Function will ask the user to buy a ticket and will update the seating chart after the user buys a ticket
void PurchTicket(char theaterTics[][COLS], const double price[], double &TotSales)
{
    //Declares row1 to integer
    int row1;
    //Declares seat to integer
    int seat;
    //Declares and sets seats to zero
    int SEATS = 0;
    //Declares and sets total price to double
    double priceTot = 0;

    char response;

    //Declared seat to integer and assigns seatTot to zero
    //Declared salesTot to double and assigns salesTot to zero
    //Do while loop for the user to purchase a ticket and if the user want to buy another ticket it will let them buy another ticket

                //Prompting the user to buy another ticket
                cout << " Do you want to buy a ticket: " <<endl;
                //Prompt the user to enter a character for theit response
                cout << "(y,n)" <<endl;
                cin >> response;

                //If the user response is an Y or n it will prompt the user to select their row and seat
         if (response == 'Y' || response == 'y'){
            //Called the function to show the seating chart
             AvailableSeat(theaterTics);
             cout << " " <<endl;
        do
            {
                //Prompt the user to select the row they want to sit in
                cout << " Please select the row you would like to sit in: " << endl;
                //Prompt user to enter in row selection
                cin >> row1;

                //Input validaiton - row selected must be within the range of rows available
                while (row1 < 1 || row1 > ROWS)
                {
                    //Prints ERROR to screen and asks to re-eneter another row selection
                    cout << " ERROR " << ROWS << " RE-ENTER" <<endl;
                    //Prompts user to enter in another row selection
                    cin >> row1;
                }

                //Prompt the user to select the seat/column they want to sit in
                cout << " Please select the seat you would like to sit in: " << endl;
                //Prompts user to enter in seat selection
                cin >> seat;

                //Input validation - seat selected must be within the range of seats avaiable
                while (seat < 1 || seat > COLS)
                {
                    //Prints ERROR to screen and asks to re-eneter another seat selection
                    cout << "ERROR " << COLS << "RE-ENTER" <<endl;
                    //Prompts user to enter in another row selection
                    cin >> seat;
                }

                //If the row and seat are available, the purhcase is confirmed
                if (theaterTics [row1-1][seat-1] = open)
                {
                    //Once the user selects the row and seat it will put an astrik
                    theaterTics[row1-1][seat-1] = taken;
                    //Increment to the amount of
                    SEATS++;
                    priceTot += price[row1-1];
                }
                //If row and seat are not avaialble, the user is prompted that the row/seat is taken
                else
                {
                    //Display that the Seat is taken
                    cout << " SEAT TAKEN " <<endl;
                }
                //Prompt the user to buy another ticket
                cout << " BUY ANOTHER TICKET? (y,n)" <<endl;
                cin >> response;
            //Loop will keep going the user keeps wanting to buy another ticket
            } while (response == 'Y' || response == 'y');

            //Confirms purchased tickets and displays the row, seat selected with the total price of purchased tickets
            cout << " TOTAL TICKETS PURCHASED: " << SEATS <<endl;
            cout << " TOTAL PRICE: $" << priceTot <<endl;
            //Add space
            cout << " " <<endl;

            //Adds price of purchased tickets together to get the final total price
            TotSales += priceTot;
         }

}

//Void function will display the total sales of the tickets and the total of seats sold
void SeatSales(double TotSales)
{
    //Displays the signs
    cout << "******************************************" <<endl;
    cout << "         TOTAL AMOUNT OF SALES                  " <<endl;
    cout << "******************************************" <<endl;

    //Display the total amount of money that the user purchased
    cout << "TOTAL PROFIT IS : " << TotSales <<endl;
}

// Void Function will show the available seats if the user chooses choice number two
void AvailableSeat(const char theaterTics[][COLS])
{
    //Print out the word seats
    cout << "\n\t\tSeats";
    //Label out the columns
    cout << "\n        123456789012345678901234567890" << endl;
    //For loop that will display a chart ad updates when the user buys a tickets
    for(int row = 0; row < ROWS; row++)
    {
        //Label out the rows
        cout << "\nRow " << setw(2) << row+1 << "\t";
        //For loop for the columns
        for (int col = 0; col < COLS; col++)
        {
            //Display the seating chart
            cout << theaterTics[row][col];

        }
    }

}
