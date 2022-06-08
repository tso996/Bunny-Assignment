/* 
Write a program that creates a linked list of bunny objects.
Each bunny object must have
Sex: Male, Female (random at creation 50/50)
color: white, brown, black, spotted
age : 0-10 (years old)
Name : randomly chosen at creation from a list of bunny names.
radioactive_mutant_vampire_bunny: true/false (decided at time of bunny creation 2% chance of true)

At program initialization 5 bunnies must be created and given random colors.
Each turn afterwards the bunnies age 1 year.
So long as there is at least one male age 2 or older, for each female bunny in the list age 2 or older;
a new bunny is created each turn. (i.e. if there was 1 adult male and 3 adult female bunnies, three new bunnies would be born each turn)
New bunnies born should be the same color as their mother.
If a bunny becomes older than 10 years old, it dies.
If a radioactive mutant vampire bunny is born then each turn it will change exactly one non radioactive bunny into a radioactive vampire bunny.
(if there are two radioactive mutant vampire bunnies two bunnies will be changed each turn and so on...)
Radioactive vampire bunnies are excluded from regular breeding and do not count as adult bunnies.
Radioactive vampire bunnies do not die until they reach age 50.
The program should print a list of all the bunnies in the colony each turn along w/ all the bunnies details, sorted by age.
The program should also output each turns events such as
"Bunny Thumper was born!
Bunny Fufu was born!
Radioactive Mutant Vampire Bunny Darth Maul was born!
Bunny Julius Caesar died!
The program should write all screen output to a file.
When all the bunnies have died the program terminates.
If the bunny population exceeds 1000 a food shortage must occur killing exactly half of the bunnies (randomly chosen)
*/
#include <iostream>
#include <list>

using namespace std;

const std::string BunnyNames[] =  { 
"Vesper",
"Nova",
"Riven",
"Titan",
"Psionic",
"Vermillion",
"Quiver",
"Intrinsic",
"Paragon",
"Cosmic",
"Arcanum",
"Nexus",
"Axiom",
"Nebula",
"Cardinal",
"Winter",
"Trojan",
"Hurricane",
"Mustang",
"Blaze",
"Amaranth",
"Charger",
"Gambit",
"Morph",
"Hellion",
"Hyperion" };
const std::string BunnyColors[] = {"white", "brown", "black", "spotted"};

class Bunny
{
    private:
        std::string name="unknown";
        std::string sex;
        std::string color;
        int age;
        bool radioactive_mutant_vampire_bunny;

    public:
        Bunny()
        {
            int index = rand() % 25 + 1;
            name = BunnyNames[index];
            
            int val = rand() % 2 + 1;
            (val==1)?sex = "Male": sex = "Female";

            int colorIndex = rand() % 4 + 1;
            color = BunnyColors[colorIndex];

            age = 0;

            int flag = rand() % 2 + 1;
            (flag == 1)? radioactive_mutant_vampire_bunny = true: radioactive_mutant_vampire_bunny=false;
        }
        ~Bunny()=default;
         string getName(){
             return name;
         }

         string getSex(){
             return sex;
         }

};

int main(){
    srand(time(NULL));

    cout<<"Bunny Assignment v0.01"<<endl;
    list<Bunny> bunnyList;
    for(int i = 0; i<5; i++){
        Bunny mBunny;
        bunnyList.push_back(mBunny);
    }

    for(auto& bunny: bunnyList){
        cout<<bunny.getName()<<endl;;
    }
  

    return 0;
}
