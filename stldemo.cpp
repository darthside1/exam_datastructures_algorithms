#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>

struct ChristmasWish{
    std::string Name;
    int Price;
    ChristmasWish(std::string name, int price){
        Name = name;
        Price = price;
    }        
};

class Movie{
public:
    typedef enum {
        MovieType_Film,
        MovieType_Tv
    }MovieType;

    Movie(){

    }

    Movie(std::string name, int year,MovieType type, int price)
    :name(name),year(year),type(type),price(price){
    }
    std::string getName() const{
        return name;
    }
    int getYear()     const{
        return year;
    }
    int getPrice() const{
        return price;
    }
    MovieType getMovieType() const{
        return type;
    }
    void setPrice(int p){
        price = p;
    }
private:
    std::string name;
    MovieType type;
    int year;
    int price;
};

/* RECURSION EXEMPEL */

// summeraTalFrom(4)   
//     return  4 + 6 //summeraTalFrom(3)
//                      summeraTalFrom(3)
//                         return 3 +  3 // summeraTalFrom(2)
//                                      summeraTalFrom(2)
//                                        return 2 + 1 // summeraTalFrom(1)
    //                                      summeraTalFrom(1)
//                                              return 1 + 0 //summeraTalFrom(0)            

int summeraTalFrom(int talet){
    if(talet == 0){
        return 0;                
    }
    return talet + summeraTalFrom(talet-1);
}

int summeraTalFromFor(int talet){
    int summa = 0;
    for(int i = talet; i > 0; i--){
        summa += i;
    }
    return summa;
}

// void skapa(){
//     int j = 12;
//     // Ange namn    
//     // 
//     huvudMeny();
// }

// void huvudMeny(){
//     int i = 0;
//     // 1. Lista
//     // 2 . Skapa
//     // 3. Logga in
//     // 4 . Exit
//     while(true){
//         if(i == 2)
//             skapa();
//     }
// }
// void printName(Movie m){
//     std::cout << m.getName() << std::endl;
// }


/* HUR MAN GJORDE INNAN LAMBDAS */

// void printNameAndPrice(Movie m){
//     std::cout << m.getName() << m.getPrice() <<  std::endl;
// }

// void printAllNewMovies(std::vector<Movie> movies, void (printFunc)(Movie m)){
//     for(Movie &m : movies){
//         if(m.getYear() > 2000)
//         {
//             printFunc(m);
//         }
//     }
// }



// 1 Innan lambda
// 2 LAMBDA !!!
// 3 Egen algoritm och funktionspekare?
bool comparePrice(const Movie &m1, const Movie &m2){
        return m1.getPrice() < m2.getPrice();
    }

bool compareName(const Movie &m1, const Movie &m2){
        return m1.getName() < m2.getName();
    }

bool compareYear(const Movie &m1, const Movie &m2){
        return m1.getYear() < m2.getYear();
    }

bool compareYearDesc(const Movie &m1, const Movie &m2){
        return m1.getYear() > m2.getYear();
    }


int main(){  

    std::vector<Movie> greatMovies{
        Movie("The Mummy returns",2022,Movie::MovieType::MovieType_Film,40), // <- begin
        Movie("Fast and Furious 7",2014,Movie::MovieType::MovieType_Film,99),  // <-items
        Movie("Star Trek: Voyager",2000,Movie::MovieType::MovieType_Tv,50),
        Movie("Fast & Furious Presents: Hobbs & Shaw",2019,Movie::MovieType::MovieType_Film,88),
       Movie("Young Rock",2021,Movie::MovieType::MovieType_Tv,82),
    };

    // printAllNewMovies(greatMovies,printName);
    
    // printAllNewMovies(greatMovies,printNameAndPrice);
    int aaa = 0;
    std::sort(std::begin(greatMovies),std::end(greatMovies),compareName);
    std::sort(std::begin(greatMovies),std::end(greatMovies),comparePrice);

    std::sort(std::begin(greatMovies),std::end(greatMovies),compareYear);
    std::sort(std::begin(greatMovies),std::end(greatMovies),compareYearDesc);

    // Vad är en funktion ? KODBLOCK { ...  }  med ett namn som man kan kalla på (anropa)
    // reusable, bidra till bättre läsbarhet
    // LAMBDA  - FUNKTION utan NAMN (anonymous function)
    // WHY Poängen? Man slipper SKAPA  funktion, hoppa in i en funktion för att läsa kod

    // SORTERING: ska ta en lambda med TVÅ paramterar 
    // TIPS: hoppa över const i ALLA ERA LAMBDAS
    // och returnera en BOOL 
    //   True  om parameter 1 ska ligga framför parameter 2
    std::sort(std::begin(greatMovies),std::end(greatMovies),[]( Movie &m1,  Movie &m2){
        if(m1.getPrice() < m2.getPrice()){
            return true;
        }
        return false;
        //return m1.getPrice() < m2.getPrice();
    });

    //ChristmasWish

    
    // 1 rekursion exempel - Fibonachi
    // Summera alla tal från START ned till 0
    int svar = summeraTalFrom(4);   // 4 + 3 + 2 + 1 + 0

    // 2 For loop istället ??? 
    // alla dagar i veckan - om det inte är enklare med rekursion

    // 3 Farligt exempel!!! Anropa sig själv indirekt! - Menyer

    // 4 Rekursion i DFS

    // 5 Hitta ur en labyrint - kod (sjävkörande bil som stöter på hinder){}
        // https://www.linkedin.com/in/daniel-s%C3%B6derberg-094ab5258/recent-activity/all/

    // 6 Algoritmer: Lambdas

    // 7 EXTRAUPPGIFT: https://docs.google.com/document/d/1btU93wWrMD5xfOXu-vqqhjdwX_MicFgK/edit?usp=sharing&ouid=108635195046115821096&rtpof=true&sd=true




    // Det som skiljer sig i en sort är JÄMFÖRELSEN som säger om en swapp ska ske eller inte
    
    // sort pris
    std::sort(std::begin(greatMovies),std::end(greatMovies),[](const Movie &m1, const Movie &m2){
        return m1.getPrice() < m2.getPrice();
    });      
        std::cout << "PRIS" << std::endl;
    for(Movie m : greatMovies){
        std::cout << m.getName() << std::endl;
    }

    // sort year
    std::sort(std::begin(greatMovies),std::end(greatMovies),[](const Movie &m1, const Movie &m2){
        return m1.getYear() < m2.getYear();
    });      
        std::cout << "YEAR" << std::endl;
    for(Movie m : greatMovies){
        std::cout << m.getName() << std::endl;
    }

        std::cout << "KLART" << std::endl;



    //int j=12;

    //  Loopa igenom alla - C/C++
    // jag behöver i:et
    // PLUS - vana
    // MINUS - lätt att göra fel
    // MINUS - "sämre semantik"  - while(true)
    for(int i = 0; i < greatMovies.size(); i++){
        Movie m = greatMovies[i];
        std::cout << m.getName() << std::endl;
    }
    // vs for each BARA C++
    // Alla algoritmer tar 
    //         1. en start
    //         2. en slut
    //         3. en lambda - en funktion att applicera på alla element mellan start och slut
    
    // BÄTTRE SEMANTIK - for varje
    // MÖJLIGT MED BÄTTRE PRESTANDA! - parallellism
    // MÖJLIGT MED BÄTTRE PRESTANDA! - EXPERTER -> Assembler-kod

    // openssl - hash uis743289jkwfe342dfkslö890
    // färdig källkod cpp
    // openssl.h  -> 20% snabbare   ASM

    // FOR EACH: ska ta en lambda med EN paramterar 
    // TIPS: hoppa över const i ALLA ERA LAMBDAS
    // och returnerar INGENTING
    //   I lambdan  så för vad ni vill

    std::for_each( std::begin(greatMovies),std::end(greatMovies),[](const Movie &m){
        std::cout << m.getName() << std::endl;
    } );


    // INFLATION! Alla movies ska kosta 10 kr mer
    std::for_each( std::begin(greatMovies),std::end(greatMovies),[](Movie &m){
        m.setPrice(m.getPrice()+10);
    } );
    

 



    // vs auto : 
    // BÄTTRE SEMANTIK - for varje - möjligt att breaka
    for(Movie m : greatMovies){
        std::cout << m.getName() << std::endl;
    }
    int ant = 0;

    // hur många filmer kostar mer än 70 kr
    int antal = 0;
    for(int i = 0; i < greatMovies.size(); i++){ // GENERISK LOOP
        Movie m = greatMovies[i];
        if(m.getPrice() > 70){  // 
            antal++;   //
        }
    }
    std::cout << antal << std::endl;

    // Förtäckt forloop

    // COUNT: ska ta en lambda med EN paramterar 
    // TIPS: hoppa över const i ALLA ERA LAMBDAS
    // och returnera TRUE om den ska räknas med

    int nyaAntal = std::count_if(std::begin(greatMovies),std::end(greatMovies), [](const Movie &m){
        return m.getPrice() > 70;  // OM true Räknas den!
    });


    // count_if
    //  std::count_iof( std::begin(greatMovies),std::end(greatMovies),3 )

    // finns det nån som kostar mer   JA NEJ
    //          92 

    // ANY OF: ska ta en lambda med EN paramterar 
    // TIPS: hoppa över const i ALLA ERA LAMBDAS
    // och returnera TRUE om den ska räknas med    
    // Finns det nån film som är gjord innan 2015  YES / NO
    bool anyInnan2015 = std::any_of(std::begin(greatMovies),std::end(greatMovies), [](const Movie &m){
        return m.getYear() < 2015;  // OM true Räknas den!
    });

    //int antalInnan2015 = std::count_if(std::begin(greatMovies),std::end(greatMovies), [](const Movie &m){
    //     return m.getYear() < 2015;  // OM true Räknas den!
    // });
    // bool anyInnan2015 = false;
    // // antalInnan2015  = 2
    // if(antalInnan2015 > 0){
    //     anyInnan2015 = true;
    // }

    
    // any of
    // std::any_of( std::begin(greatMovies),std::end(greatMovies),3 )
    // sort
    // find_if
    // filter - ta fram alla som kostar minst X kr.. NÄSTA TORSDAG = ranges

    // int total = 0;
    // for(int i = 0; i < greatMovies.size(); i++){
    //     total += greatMovies[i].getYear();
    //     if(i == 2){
    //         break;
    //     }
    //     std::cout << greatMovies[i].getName() << std::endl;
    // }




}