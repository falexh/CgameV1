/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: Main function for Final Project
********************/

#include "Player.hpp"
#include "Board.hpp"
#include "Space.hpp"

#include <iostream>
#include <string>
#include <cstdlib>


int main()
{
    
    // seed random value from the clock!
    srand(time(NULL));

    bool isTrue = true;
    int choice,choice2;

    Board b = Board();
    Player p = Player(&b);

    std::cout << "|-----------------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "      ••• Llama Knight v1 •••" << std::endl;
    std::cout << '\n';
    std::cout << "      |----------------------------------     " << std::endl;
    std::cout << "      |------------------------------                          " << std::endl;
    std::cout << "      |--------------------------     " << std::endl;
    std::cout << "      |-------------------     " << std::endl;
    std::cout << "      |-------------------------------------     " << std::endl;
    std::cout << "      |-------------------------------------     " << std::endl;
    std::cout << '\n';
    std::cout << "|-----------------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << '\n';
    std::cout << "In this game, you will play a llama that must navigate the surrounding lands and jungles." << std::endl;
    std::cout << "Lizards have invaded the land with a deadly poison that is damaging the planet." << std::endl;
    std::cout << "The only way to eradicate the disease is to gather the items necessary to defeat the lizard king." << std::endl;
    std::cout << "Once you defeat the lizard king, you will receive a bundle of hay to bring back to your llama friends!" << std::endl;
    std::cout << '\n';
    std::cout << "You must interact with the land and jungle for items to add to your inventory! " << std::endl;
    std::cout << "As the llama knight, you must find the sword, shield, and armor!" << std::endl;
    std::cout << "Even though you are poisoned, there are blueberries in the Jungle!" << std::endl;
    std::cout << '\n';
    std::cout << "∆        Any inspection with a jungle space returns health!        ∆" << std::endl;

    std::cout << '\n';
    std::cout << '\n';

    std::cout << "|-----------------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "  '~' = land, '∆' = jungle, 'F' = farm, '*' = player, 'C' = castle " << std::endl;
    std::cout << "|-----------------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << '\n';

    std::cout << "Once you make a move, the player (*) will appear on the board" << std::endl;
    std::cout << '\n';
    std::cout << "****** First move must be UP, LEFT, or RIGHT. " << std::endl;
    std::cout << '\n';

    //display the board
    b.showBoard();

    do
    {

        std::cout << "|-----------------------------------------------------------------------------------------------------------|" << std::endl;
        std::cout << '\n';
        std::cout << "Please select an option: " << std::endl;

        std::cout << "1) Show Bag" << std::endl;
        std::cout << "2) Move" << std::endl;
        std::cout << "3) Inspect" << std::endl;
        std::cout << "4) Display Health" << std::endl;
        std::cout << "5) End Program" << std::endl;
        std::cout << '\n';
        std::cout << "|-----------------------------------------------------------------------------------------------------------|" << std::endl;


        while (isTrue)
        {
            std::cout << '\n';
            std::cout << "Enter your choice: " << std::endl;
            std::cin >> choice;

            if (choice == 1) // SHOW BAG
            {
                std::cout << "Here is what is in your bag: " << std::endl;
                p.showBag();
                std::cout << '\n';
                b.showBoard();

                isTrue = false;
            }
            else if (choice == 2) // MOVE
            {
                std::cout << " UP = 'W' , DOWN = 'S', LEFT = 'A', RIGHT = 'D' " << std::endl;
                char dir;
                std::cout << "Enter your movement: " << std::endl;

                std::cin >> dir;


                p.move(dir);
                std::cout << '\n';
                b.showBoard();


                isTrue = false;
            }
            else if (choice == 3) // INSPECT
            {
                std::cout << "Inspecting the area..." << std::endl;
                p.inspect();
                std::cout << '\n';
                b.showBoard();



                isTrue = false;
            }
            else if (choice == 4) // DISPLAY HEALTH
            {
                p.displayHealth();
                std::cout << '\n';
                b.showBoard();
                isTrue = false;
            }
            else
            {
                std::cout << "Program ending!!" << std::endl;
                return 0;
            }
        }
        isTrue = true;

        while(isTrue)
        {

            std::cout<< "Return to function menu? Enter 1 for YES or 2 for NO" << std::endl;
            std::cin >> choice2;

            if (choice2 == 1)
            {
                isTrue = false;
            }
            else if (choice2 == 2)
            {
                std::cout << "Program now ending!" << std::endl;
                return 0;
            }
            else if (choice2 != 1 || choice2 != 2)  // INPUT VALIDATION
            {
                std::cout << "Please enter 1 or 2!" << std::endl;
            }

        }
        isTrue = true;

    }while (isTrue);


    return 0;
}
