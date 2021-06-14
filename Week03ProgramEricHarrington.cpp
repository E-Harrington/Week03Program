/************************************************************
Week 03 Programming Assignment
Eric Harrington
*************************************************************
1. Declare constants for shipping costs
2. Declare variables for user input and order calculations
3. Declare an output stream variable
4. Declare and initialize strings to help with output
formatting
5. Prompt user for item name, then convert item name to
uppercase so the output matches assignment example and 
to help manage selection in program
6. Prompt user to say whether item is fragile, and convert
character to uppercase for same reasons as Step 5.
7. Use an if-else statement to check whether user input
is valid for fragile char data type
8. User if else if statements to check destination, then
nest if else if statements to decide shipping costs 
9. Open order.txt file and send write outdata to it
10. Close output stream file
11. Use iomanip to pause program at the end

************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cctype>
#include<algorithm>

using namespace std;

//Step 1
const int USA_LOW = 6;
const int USA_MID = 9;
const int USA_HIGH = 12;
const int CANADA_LOW = 8;
const int CANADA_MID = 12;
const int CANADA_HIGH = 15;
const int AUSTRALIA_LOW = 10;
const int AUSTRALIA_MID = 14;
const int AUSTRALIA_HIGH = 17;
const int MOON = 1'000'000;
const int IS_FRAGILE = 2;


int main()
{
    //Step2
    string itemName;
    char fragile;
    double orderTotal = 0;
    string destination;
    double shippingCost = 0;
    //Step3
    ofstream outData;
    //Step4
    string itemPrompt = "Please enter the item name (no spaces)";
    string fragilePrompt = "Is the item fragile? (y=yes/n=no)";
    string orderPrompt = "Please enter your order total";
    string destinationPrompt = "Please enter destination. (usa/can/aus/moon)";
    //Step 4
    string itemOutput = "Your item is";
    string shippingCostOutput = "Your shipping cost is";
    string shippingToOutput = "You are shipping to";
    string orderTotalOutput = "Your total shipping costs are";
    string thankYou = "Thank You!";

    cout << setw(100) << setfill('.') << '.' << endl;
    cout << "ITCS 2530 - Programming Assignment for Week 03" << endl;
    cout << setw(100) << setfill('.') << '.' << endl << endl;
    //Step 5
    cout << setw(itemPrompt.length()) << itemPrompt << setw(100-itemPrompt.length()) << setfill('.') << ':';
    cin >> itemName; 
    transform(itemName.begin(),itemName.end(),itemName.begin(),::toupper);
    //Step 6
    cout << setw(fragilePrompt.length()) << fragilePrompt << setw(100-fragilePrompt.length()) << setfill('.') << ':';
    cin >> fragile;
    fragile = toupper(fragile);

    cout << fixed << showpoint << setprecision(2);
    //Step 7
    if (fragile != 'Y' && fragile != 'N')
    {   
        cout << "Invalid entry, exiting" << endl;
        system("pause");
    }
    else 
    {
    cout << setw(orderPrompt.length()) << orderPrompt << setw(100-orderPrompt.length()) << setfill('.') << ':';
    cin >> orderTotal;

    cout << setw(destinationPrompt.length()) << destinationPrompt << setw(100-destinationPrompt.length()) << setfill('.') << ':';
    cin >> destination;
    cout << endl;
    transform(destination.begin(),destination.end(),destination.begin(),::toupper);

        if (destination != "USA" && destination != "CAN" && destination != "AUS" && destination != "MOON")
        {    
            cout << "Invalid entry, exiting" << endl;
            system("pause");
        }
        else
        {
            if (fragile == 'Y')
                shippingCost += IS_FRAGILE;
            //Step 8
            if (destination == "USA")
            {
                if (orderTotal > 0.00 && orderTotal <= 50.00)
                {
                    shippingCost += USA_LOW;
                    orderTotal += shippingCost;
                }
                else if (orderTotal > 50.00 && orderTotal <= 100.00)
                {
                    shippingCost += USA_MID;
                    orderTotal += shippingCost;
                }
                else if (orderTotal > 100.00 && orderTotal <= 150.00)
                {
                    shippingCost += USA_HIGH;
                    orderTotal += shippingCost;
                }
                else
                    orderTotal += shippingCost;
            }
            else if (destination == "CAN")
            {
                if (orderTotal > 0.00 && orderTotal <= 50.00)
                {
                    shippingCost += CANADA_LOW;
                    orderTotal += shippingCost;
                }
                else if (orderTotal > 50.00 && orderTotal <= 100.00)
                {
                    shippingCost += CANADA_MID;
                    orderTotal += shippingCost;
                }
                else if (orderTotal > 100.00 && orderTotal <= 150.00)
                {
                    shippingCost += CANADA_HIGH;
                    orderTotal += shippingCost;
                }
                else
                    orderTotal += shippingCost;
            }
            else if (destination == "AUS")
            {
                if (orderTotal > 0.00 && orderTotal <= 50.00)
                {
                    shippingCost += AUSTRALIA_LOW;
                    orderTotal += shippingCost;
                }
                else if (orderTotal > 50.00 && orderTotal <= 100.00)
                {
                    shippingCost += AUSTRALIA_MID;
                    orderTotal += shippingCost;
                }
                else if (orderTotal > 100.00 && orderTotal <= 150.00)
                {
                    shippingCost += AUSTRALIA_HIGH;
                    orderTotal += shippingCost;
                }
                else
                    orderTotal += shippingCost;
            }
            else if (destination == "MOON")
            {
                shippingCost += MOON;
                orderTotal += shippingCost;
            }


            cout << setw(itemOutput.length()) << itemOutput << setw(100-itemOutput.length()+itemName.length()) << setfill('.') << itemName << endl;


            cout << setw(shippingCostOutput.length()) << shippingCostOutput << setw(100-shippingCostOutput.length()+1) << setfill('.')  
            << '$' << shippingCost << endl;

            cout << setw(shippingToOutput.length()) << shippingToOutput << setw(100-shippingToOutput.length()+destination.length()) << setfill('.')
            << destination << endl;

            cout << setw(orderTotalOutput.length()) << orderTotalOutput << setw(100-orderTotalOutput.length()+1) << setfill('.')  
            << '$' << orderTotal << endl << endl;

            cout << setw(100+thankYou.length()) << setfill('=') << right << "Thank You!" << endl << endl;
            //Step 9
            outData.open("Order.txt");

            outData << "Item to ship: " << itemName << endl;
            outData << "Shipping cost: $" << shippingCost << endl;
            outData << "Destination: " << destination << endl;
            outData << "Total shipping cost: $" << orderTotal << endl;
            //Step 10
            outData.close();
            //Step 11
            system("pause");

            
        }
    }    
        

        

    return 0;
}


