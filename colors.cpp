#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

/*
    ***************************************************************************************************
    - std::sort         -->     "Sortera alla i prisordning (billigast först)"

        Ascending (billigast först):    '<'
        Descending (dyrast först):      '>' 
        
        std::sort(computers.begin(), computers.end(), [] (auto c1, auto c2) {
            return c1.getPrice() < c2.getPrice();
        });
    
    ***************************************************************************************************
    - std::for_each     -->     "Skriv ut alla", "Öka priset med 10% på alla datorer"

        * Med STL (bättre semantik):
        std::for_each(colors.begin(), colors.end(), [](std::string c) { std::cout << c << std::endl; });

        * med for loop:
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

/*
    Program som testar olika STL algoritmer på en vektor med strings

    To-do:      - skriv om till funktioner
                - Gör template så att algoritmerna kan hantera alla typer i vektorn
                - Gör programmet interaktivt med menu loops
                - Testa find_if
*/

int main() {

    system("clear");

    std::vector<std::string> colors = { "red", 
                                        "green", 
                                        "blue", 
                                        "orange",
                                        "pink", 
                                        "yellow", 
                                        "gray", 
                                        "purple", 
                                        "black", 
                                        "white" };

    std::vector<std::string> colors2;


    // Finns färgen "black"?
    bool blackExists = std::any_of(colors.begin(), colors.end(), [](std::string c) { return c == "black"; });
    std::cout << "\nFinns färgen 'black'?" << std::endl;
    blackExists ? std::cout << "JA\n" << std::endl : std::cout << "NEJ\n" << std::endl;

    // Hur många färger har 5 bokstäver?
    int fiveLetterColors = std::count_if(colors.begin(), colors.end(), [](std::string c) { return c.size() == 5; });
    std::cout << "\nHur många färger har 5 bokstäver?\n" << fiveLetterColors << std::endl;

    // Skriv ut alla färger före sortering
    std::cout << "\n\nAlla färger före sortering: \n" << std::endl;
    std::for_each(colors.begin(), colors.end(), [](std::string c) { std::cout << c << std::endl; });

    // Sortera alla färger i ordlängd (descending)
    std::sort(colors.begin(), colors.end(), [](std::string c1, std::string c2) { return c1.size() > c2.size(); });

    // Skriv ut alla färger efter sortering
    std::cout << "\n\nAlla färger efter sortering (ordlängd, descending):\n" << std::endl;
    std::for_each(colors.begin(), colors.end(), [](std::string c) { std::cout << c << std::endl; });

    // Gör om alla färger till versaler i en ny vector
    std::transform(colors.begin(), colors.end(), std::back_inserter(colors2), [](std::string str) {
        std::string copy = str;
        std::transform(copy.begin(), copy.end(), copy.begin(), [](char c){ return std::toupper(c); });
        return copy;
    });

    // Sortera båda vektorerna i bokstavsordning (ascending)
    std::sort(colors.begin(), colors.end(), [](std::string c1, std::string c2) { return c1 < c2; });
    std::sort(colors2.begin(), colors2.end(), [](std::string c1, std::string c2) { return c1 < c2; });


    // Skriv ut båda vektorerna
    std::cout << "\nFärger som gemener (sorterade i bokstavsordning, ascending): \n" << std::endl;
    std::for_each(colors.begin(), colors.end(), [](std::string c) { std::cout << c << std::endl; });
    std::cout << "\nFärger som versaler (sorterade i bokstavsordning, ascending): \n" << std::endl;
    std::for_each(colors2.begin(), colors2.end(), [](std::string c) { std::cout << c << std::endl; });



    return 0;
}
