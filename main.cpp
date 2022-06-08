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
#include <fstream>

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
        std::string name;
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

            int flag = rand() % 50 + 1;
            //cout<<"radio active flag: "<<flag<<endl;
            (flag == 5)? radioactive_mutant_vampire_bunny = true: radioactive_mutant_vampire_bunny=false;
        }
        ~Bunny()=default;
         string getName(){
             return name;
         }

         string getSex(){
             return sex;
         }

         void addAge(){
             age++;
         }

         int getAge(){
             return age;
         }

         bool isRadioActive(){
             return radioactive_mutant_vampire_bunny;
         }

};

int main(){
    srand(time(NULL));

    cout<<"Bunny Assignment v0.01"<<endl;
    
    list<Bunny> bunnyList;// = new list<Bunny>();
    string output;
    ofstream outputFile("./bunnyRunHistory.txt");
    outputFile << "";

    for(int i = 0; i<5; i++){
        Bunny mBunny;
        if(mBunny.isRadioActive()){
             cout<<"Radioactive bunny "<<mBunny.getName()<<" is born!"<<" It's a "<< mBunny.getSex()<<"\n";
            output = output + "Radioactive bunny "+ mBunny.getName()+" is born!" + " It's a "+mBunny.getSex()+"\n"; 
        }else{
            cout<<mBunny.getName()<<" is born!"<<" It's a "<< mBunny.getSex()<<"\n";
            output = output + mBunny.getName()+" is born!" + " It's a "+mBunny.getSex()+"\n"; 
        }
        bunnyList.push_back(mBunny);
    } 
    list<Bunny>::iterator it;
    int turn = 1;
    
    while(true){
        int femaleBunnyCount = 0;
        bool maleBunnyAlive = false;
        cout<<"=======================Turn "<<turn<<"===========\n";
        cout<<"Total number of bunnies alive: "<<bunnyList.size()<<"\n";
        output = output + "Total number of bunnies alive: " + to_string(bunnyList.size()) +"\n";
        output = output + "=======================Turn " + to_string(turn) + "===========\n";
        //update age
        for(it = bunnyList.begin();it!=bunnyList.end();){
            it->addAge();
            cout<<"name: "<<it->getName()<<" age: "<<it->getAge()<<"\n";
            if (it->getSex()=="Male"){
                maleBunnyAlive = true;
            }else if(it->getAge()>2){
                femaleBunnyCount++;
            }
            if(it->getAge()>10 && !(it->isRadioActive())){// bunny end
                cout<<"in here"<<endl;
                cout<<it->getName()<<" has been removed!\n";
                output = output + it->getName()+" has been removed!\n";
                it = bunnyList.erase(it);  
               }else{
                    if(it->isRadioActive() && it->getAge()>50){
                            cout<<"RadioActive bunny "<<it->getName()<<" has been removed!\n";
                            output = output + "RadioActive bunny "+ it->getName() + " has been removed!\n";
                            it = bunnyList.erase(it);  
                    }else{
                        ++it;
                    }
                }
            
        }
        cout<<"bringing out the new bunnies==============\n";
        //adding new bunnies based on female Bunnies
        if(maleBunnyAlive){
            for(int i = 0; i< femaleBunnyCount; i++){
                Bunny mBunny;
                 if(mBunny.isRadioActive()){
                        cout<<"Radioactive bunny "<<mBunny.getName()<<" is born!"<<" It's a "<< mBunny.getSex()<<"\n";
                        output = output + "Radioactive bunny "+ mBunny.getName()+" is born!" + " It's a "+mBunny.getSex()+"\n"; 
                    }else{
                        cout<<mBunny.getName()<<" is born!"<<" It's a "<< mBunny.getSex()<<"\n";
                        output = output + mBunny.getName()+" is born!" + " It's a "+mBunny.getSex()+"\n"; 
                    }
                bunnyList.push_back(mBunny);
            }
        }
        if(bunnyList.size()>10000){
            cout<<"famine! Quitting..\n";
            output = output + "famine! Quitting..\n";
            outputFile << output;
            outputFile.close();
            return 0;
        }
        turn++;
    }
  

    return 0;
}
