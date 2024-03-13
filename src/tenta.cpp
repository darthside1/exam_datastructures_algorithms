#include <iostream>

// Kan komma på tentan
/*
    ***************************************************************************************************
    - std::sort         -->     "Sortera alla i prisordning (billigast först)"

        Ascending (billigast först):    '<'
        Descending (dyrast först):      '>' 
        
        std::sort(computers.begin(), computers.end(), [] (auto c1, auto c2) {
            return c1.getPrice() < c2.getPrice();
        });
    
    ***************************************************************************************************
    - std::for_each     -->     "Skriv ut alla"

        for (auto c : computers) { 
            std::cout << c.getManufacturer() << " - " << c.getCpu() << std::endl; 
        }

    ***************************************************************************************************
    - std::count_if     -->     "Hur många .. finns det?" "Räkna hur många som har..?"

        int desktopCount = std::count_if(computers.begin(), computers.end(), [](Computer c) {
            return c.getType() == Desktop && c.getCpu() == "Core i9-11900K";
        });

    ***************************************************************************************************
    - std::any_of       -->     "Finns det någon.. som kostar mer än 41 500 kr?"

        bool found = std::any_of(computers.begin(), computers.end(), [] (Computer c){
            return c.getPrice() > 41500;
        });

    ***************************************************************************************************

    Kommer ej på tentan men bra att känna till:

    - std::transform    -->     Ändrar värden på elements
    - std::find_if      -->     C++20 (ranges)

    * Alla algoritmer ovan ska skrivas med lambdas
    * Skippa const när vi skriver lambdas
    * Använd auto
    
*/


int main() {

    system("clear");
    std::cout << std::endl;
    std::cout << "Tenta" << std::endl;
    std::cout << std::endl;




    return 0;
}
