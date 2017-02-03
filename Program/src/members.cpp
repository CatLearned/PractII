#include <vector>
#include <iostream>
#include <fstream>

#include "struct.h"
#include "io.h"

vector<man> members;

int next_id = 0;

void free_memory()
{
    members.clear();
}

void savefile()
{
    string path = "./bd.txt";
    
    ofstream file;
    file.open(path);
    
    if (file.is_open())
    {
        for (man mem : members) 
        {
            file << mem.id << endl;
            file << mem.fam << endl;
            file << mem.name << endl;
            file << mem.surname << endl;
            file << mem.typebike << endl;
            file << mem.ages << endl;
            if (!file) 
            {
                cout << "Error writing to file '" << path << "'" << endl;
                return;
            }
        }
        
        file.close();
        if (!file) 
        {
            cout << "Error writing to file '" << path << "'" << endl;
            return;
        }
        else
        {
            cout << "Writing to file - ready" << endl;
            
        }
    }
    else
    {
        cout << "Error writing to file '" << path << "'" << endl;
    }
    return;
}

void nullMan(man * mem)
{
    mem->id = 0;
    mem->fam = "";
    mem->name = "";
    mem->surname = "";
    mem->typebike = 1;
    mem->ages = 0; 
    
}

void readfile()
{
    members.clear();
    man buf;
    string path = "./bd.txt";
    ifstream file;
    file.open(path);
    if (file.is_open())
    {
        do
        {
            file >> buf.id;
            file >> buf.fam;
            file >> buf.name;
            file >> buf.surname;
            file >> buf.typebike;
            file >> buf.ages;
            if (buf.id != 0) 
                members.push_back(buf);
            
            nullMan(&buf);
            
            
        }while (!file.eof() || buf.id!=0);
        file.close();
        cout << "Reading from file - ready" << endl;
    }
    else
    {
        cout << "Error reading from file '" << path << "'" << endl;
    }
    
}


bool read_member(man* new_member)
{
    new_member->fam      = give_meaning("last name");
    new_member->name     = give_meaning("first name");
    new_member->surname  = give_meaning("middle name");
    new_member->typebike = give_typebike();
    new_member->ages     = give_ages();
    
    string in = give_meaning("Is data correct? (y/n)");
    return (in == "y" || in == "yes");
}

void add_member()
{
    man new_member;
    
    bool confirmed = read_member(&new_member);
    
    if (confirmed) {
        new_member.id = ++next_id;
        members.push_back(new_member);
        cout << "Member with id " << new_member.id << " added." << endl;
    } else {
        cout << "Canceled." << endl;
    }
}

bool check_id(int id)
{
    if(id>0 && id <= next_id)
    {
        for (man member : members) 
        {
            
            if (member.id == id)
            {
                return true;
            }
        }
    }
    return false;
}

void del_member()
{
    int id = read_member_id();
    if (check_id(id)) {
        int number = 0;
        
        for (man member : members) 
        {
            
            cout << "   DEL CHECK ID: " << member.id << " =? " << id << endl;
            if (member.id == id)
            {
                members.erase(members.begin() + number);
                break;
            }
            number++;
        }
        
        cout << "Deleted." << endl;
    } else {
        cout << "Error. ID: " << id << endl;
    }
}

void print_members(man* mem) 
{
    cout << mem->fam << " " 
         << mem->name << " "
         << mem->surname << endl;
    
    cout << "Stage: " ;
    cout << mem->ages << endl;
 
    cout << "Byke type: " ;
    cout << (mem->typebike == 1 ? "MTP" : "")
         << (mem->typebike == 2 ? "Road" : "")
         << (mem->typebike == 3 ? "Hibrid" : "") 
         << (mem->typebike == 4 ? "Electro" : "");
}



void show_help()
{
    cout << endl
         << "add    Create a student" << endl
         << "ls     Browse students" << endl
         << "save   Export students into JSON file" << endl
         << "load   Import students from JSON file" << endl
         << "help   Show this message" << endl 
         << endl
         << "Type 'exit' to quit" << endl;
}

void print_all()
{
    int i = 1;
    for (man mem : members)
    {
        cout << i++ << ". ";
        print_members(&mem);
        cout << endl;
    }
}

void change_members()
{
    int id = read_member_id();
    if (check_id(id)) {
        int number = 0;
        man new_member;
        if(read_member(&new_member) == true)
        {
            for (man member : members) 
            {
                if (member.id == id)
                {
                    new_member.id = member.id;
                    members.at(number) = new_member;
                }
                number++;
            }
        }
        cout << "Saved." << endl;
    } else {
        cout << "Error." << endl;
    }
}