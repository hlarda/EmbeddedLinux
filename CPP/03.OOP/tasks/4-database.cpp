#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
class database;

/* 
TODO: add begin and end to the database class to make it iterable containing all the functions
TODO: data integrity check
*/
void dbPrint  (vector<database> db);
void dbSearch (vector<database> db , int id);
void dbSearch (vector<database> db , string name);
void dbAdd    (vector<database> &db , string name, int age, int id);
void dbAdd    (vector<database> &db , string data);
void dbDelete (vector<database> &db , int id);
void dbDelete (vector<database> &db , string name);

class database
{
private:
    string name;
    int age;
    int id;
    static int counter;
public:
    database()=delete;
    database(string name, int age, int id);
    database(string data);      //?supposed to take all data as a single string and parse it
    ~database();

    int     getAge(void);
    string  getName(void);
    int     getId(void);
    static  int getCounter(void);
            void display(void);
};
int database::counter = 0;
database::database(string name, int age, int id):name(name), age(age), id(id){
    counter++;
}
database::database(string data){
    //?parse the data and assign it to the variables
    vector<string> tokens;
    string token;

    istringstream strStream(data);
    while(getline(strStream, token, ',')){
        tokens.push_back(token);
    }
    name = tokens[0];
    age = stoi(tokens[1]);
    id = stoi(tokens[2]);
    counter++;
}
database::~database(){
    counter--;
}
int database::getCounter(void){
    return counter;
}
void database::display(void){
    cout << name << " " << age << " " << id << endl;
}
int database::getAge(void){
    return age;
}
string database::getName(void){
    return name;
}
int database::getId(void){
    return id;
}
void dbPrint(vector<database> db){
    for(database element : db){
        element.display();
    }
}
void dbSearch (vector<database> db , int id){
    auto searchIterator = find_if(db.begin(), db.end(), [id](database element){return element.getId() == id;});
    if(searchIterator == db.end()){
        cout << "Not found" << endl;
    } else {
        searchIterator -> display();
    }
}
void dbSearch (vector<database> db , string name){
    auto searchIterator = find_if(db.begin(), db.end(), [name](database element){return element.getName() == name;});
    if(searchIterator == db.end()){
        cout << "Not found" << endl;
    } else {
        searchIterator -> display();
    }
}
void dbAdd    (vector<database> &db , string name, int age, int id){
    db.push_back(database(name, age, id));
}
void dbAdd    (vector<database> &db , string data){
    db.push_back(database(data));
}
void dbDelete (vector<database> &db , int id){
    auto deleteIterator = remove_if(db.begin(), db.end(), [id](database element){return element.getId() == id;});
    if (deleteIterator == db.end()) {
        cout << "Not found" << endl;
    } else {
        db.erase(deleteIterator, db.end());
    }
}
void dbDelete (vector<database> &db , string name){
    auto deleteIterator = remove_if(db.begin(), db.end(), [name](database element){return element.getName() == name;});
    if (deleteIterator == db.end()) {
        cout << "Not found" << endl;
    } else {
        db.erase(deleteIterator, db.end());
    }
}

int main(int argc, char const *argv[])
{
    vector<database> db;
    db.push_back(database("lilo", 20, 1));
    db.push_back(database("mnna, 23, 5"));
    db.push_back(database("hla, 21, 3"));
    dbPrint(db);

    dbSearch(db, 1);
    dbSearch(db, "hla");
    dbSearch(db, "hl");

    dbAdd(db, "mmm, 21, 10");

    dbDelete(db, 1);
    dbDelete(db, "hla");
    
    dbPrint(db);
    return 0;
}
