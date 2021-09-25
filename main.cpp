#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;

struct Node{
    long ISBN;
    string full_name;
    string adress;
};

class ListGenerator{
private:
    vector <string> Name = {"Liam", "Olivia", "Noah", "Emma", "Oliver", "Ava", "Elijah", "Charlotte",
                           "William", "Sophia", "James", "Amelia", "Benjamin", "Isabella", "Lucas", "Mia",
                           "Henry", "Evelyn", "Alexander", "Harper"};
    vector <string> SurName = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis",
                           "Rodriguez", "Martinez", "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson", "Thomas",
                           "Henry", "Moore", "Jackson", "Martin"};
    vector <string> Street = {"Second", "Third", "First", "First", "Fourth", " Fifth", "Main", "Sixth",
                               "Oak", "Seventh", "Pine", "Maple", "Cedar", "Eighth", "Elm", "View",
                               "Washington", "Ninth", "Lake", "Hill"};
public:
    void Gen(int size){
        srand(1234);
        ofstream out;
        out.open("/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/cmake-build-debug/in.txt");
        for(int i = 0; i < size; i++){
            out << to_string(random() % 90000 + 10000) << "@" << Name[rand() % 20] + " " +
            SurName[rand() % 20] + "@" + Street[rand() % 20] + " Str. " + to_string(rand() % 200 + 1) + "\n";
        }
    }

};

class HashTable{
    int size = 0;
    int amount = 0;
    vector <Node*> table;
public:
    void resize(int S){ // rezize table
        amount = 0;
        vector <Node*> temp = table; // copy of old table
        size = S;
        table.clear();
        table.resize(size);
        for(int i = 0; i < temp.size(); i++){ // insert Nodes from old table to resized
            if (temp[i] != nullptr)
                this->push(temp[i]);
        }
        temp.clear();
    }

    HashTable(int s){
        size = s;
        table.resize(s);
    }

    void push(Node* N){ // insert Node in the table
        int hash = this->hash(*N);
        int first_hash = hash - 1; // we'll need it to check if there's a loop
        while((table[hash] != nullptr) && (hash != first_hash))
            hash = (hash + 1) % size;
        if(hash == first_hash) // if ended because of a loop
            std::cout << "PUSH ERROR, table need to be resized" << hash << "\n"; // needed resize
        else {
            this->table[hash] = N; //push N
            amount++;
        }
    }

    void pop(int ISBN) { // takes Node, delete Node from the table
        int hash = this->hash(ISBN);
        int first_hash = hash - 1; // we'll need it to check if there's a loop
        if (table[hash] != nullptr) {
            while ((table[hash]->ISBN != ISBN) && (hash != first_hash))
                hash = (hash + 1) % size;
            this->table.erase(table.begin() + hash); // delete Node from the table
            amount--;
        }
        else
            cout << "POP ERROR, there's no node with ISBN = " << hash << "\n"; // needed resize
    }

    const int hash(Node N){ // takes Node, returns hash number
        int code = int(N.ISBN % size);
        //std::cout << code << "\n";
        return code;
    }

    const int hash(long ISBN){ // overloaded function - takes ISBN, returns hash number
        int code = int(ISBN % size);
        //std::cout << "num: " << code << "\n";
        return code;
    }

    void print(){ // console output
        for(int i = 0; i < size; i++) {
            if (table[i] != nullptr)
                std::cout << i + 1 << "     " << table[i]->ISBN << "     "
                << table[i]->full_name << "     " << table[i]->adress << "\n";
        }
    }

    Node* find(long ISBN){ // takes ISBN, returns corresponding Node
        //auto t1 = std::chrono::high_resolution_clock::now(); // start time
        int hash = this->hash(ISBN);
        int first_hash = hash - 1; // we'll need it to check if there's a loop
        while((table[hash]->ISBN != ISBN) && (hash != first_hash))
            hash = (hash + 1) % size;
        //auto t2 = std::chrono::high_resolution_clock::now(); // end time
        //auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        // total time of the search execution, ns
        //std::cout << "time: " << duration << "\n"; console output time of the search execution
        return this->table[hash];
    }

    ~HashTable(){
        table.clear();
    }

    bool isOverflowed() { // returns true if needed resize
        return ((double) amount / size) > 0.75 ? true : false;
    }

    void fill(bool print){
        ifstream in;
        in.open("/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/cmake-build-debug/in.txt"); //open filestream
        string str;
        int S = 0; // number of strings
        if (print){ // if needed print
            while (getline(in, str)){
                S ++;
                std::cout << str << "\n"; // console output
            }
        }
        else{
            while (getline(in, str)){
                S ++;
            }
        }
        this->resize(this->size + S * 4/3); //resize table
        in.close(); //close filestream
        in.open("/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/cmake-build-debug/in.txt"); //open filestream again
        while (getline(in, str))
        {
            long ISBN = stol(str.substr(0, str.find("@"))); //parse str to get ISBN
            string full_name = str.substr(str.find("@") + 1, str.rfind("@") - str.find("@") - 1); //parse str to get full_name
            string adress = str.substr(str.rfind("@") + 1); //parse str to get adress
            //std::cout << ISBN << "  " << full_name << "  " << adress <<"\n"; // you can print every parse result
            Node* N = new Node{ISBN, full_name, adress}; //create new node
            this->push(N); //push node
        }
        in.close(); //close filestream
    }

    void toFile(){ // file output
        ofstream out;
        out.open("/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/cmake-build-debug/out.txt"); // open file stream
        string str;
        for(int i = 0; i < size; i++){
            if(table[i] != nullptr)
            {
                out << table[i]->ISBN << "     " << table[i]->full_name <<
                "     " << table[i]->adress << "\n"; // make a record
            }
        }
    }

    string Info(){ //returns information about the Hashtable- size and amount of Nodes
        return "HashTable, size: " + to_string(size) + " , amount: " + to_string(amount) + "\n";
    }
};

int main() { // just remove /* ... */
    HashTable* Table = new HashTable(10);
    //1 hash function
    /*long ISBN = 12345;
    cout << "ISBN = " << ISBN << "\n" << "hash = " << Table->hash(ISBN);*/
    //2 read from file and push in the table
    ListGenerator G0;
    G0.Gen(3000);
    cout << Table->Info();
    Table->fill(0);
    Table->print();
    cout << Table->Info();
    //3 pop from table and file
    /*ListGenerator G1;
    G1.Gen(10);
    Table->fill(0);
    cout << "before\n";
    Table->print();
    cout << Table->Info();
    Table->pop(96649);
    cout << "after\n";
    Table->print();
    cout << Table->Info();*/
    //4 find using hashtable
    /*ListGenerator G2;
    G2.Gen(10);
    Table->fill(0);
    Table->print();
    cout << Table->Info();
    Node* N = Table->find(96649);
    cout << "Found a node: " << N->ISBN << "  " << N->full_name << "  " << N->adress;*/
    //5 do rehash
    /*ListGenerator G3;
    G3.Gen(10);
    Table->fill(0);
    cout << "before\n";
    Table->print();
    cout << Table->Info();
    Table->resize(100);
    cout << "after\n";
    Table->print();
    cout << Table->Info();*/
    return 0;
}
