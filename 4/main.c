
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <iostream>

typedef struct pt {
    std::map<std::string, std::string> kvmap;
    bool is_valid_cidopt = false;
} passport_t;

void check_valid_cidopt(passport_t* passport);

void empty_passport(passport_t* passport){
    passport->kvmap.clear();
    passport->is_valid_cidopt = false;
}

int main(int argc, char** argv)
{

    const char* filename = "input.txt";
    std::fstream file;
    std::string line;
    file.open(filename);

    passport_t passport;

    std::vector<passport_t> inputs;

    if(file.is_open())
    {
        while(std::getline(file, line))
        {
            if ( line.length() == 0 )
            {
                passport.is_valid_cidopt = true;
                inputs.push_back(passport);
                empty_passport(&passport);
                continue;
            }


        }

    }



}

