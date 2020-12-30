
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

typedef struct pwds {
    int min;
    int max;
    char req;
    std::string pwd;
} pwd_t;

bool validate_password_A(pwd_t password)
{
    
    int count = 0;
    for ( int i = 0; i < password.pwd.length(); i++ )
    {
        if ( password.pwd[i] == password.req )
        {
            count++;
        }
    }
    if ( password.min <= count && count <= password.max ) return true;
    else return false;
}

bool validate_password_B(pwd_t password)
{
    int pos_a = password.min - 1;
    int pos_b = password.max - 1;

    if ( pos_a >= password.pwd.length() || pos_b >= password.pwd.length() ) return false;
    
    char char_a = password.pwd[pos_a];
    char char_b = password.pwd[pos_b];

    if ( char_a == password.req || char_b == password.req )
    {
        if ( char_a == char_b ) return false;
        else return true;
    }
    else return false;
}

int main(int argc, char** argv)
{

    const char* filename = "input.txt";
    std::fstream file;
    std::string line;
    file.open(filename);

    std::vector<pwd_t> input;

    if(file.is_open())
    {
        while(std::getline(file, line))
        {
            pwd_t password;
            password.min = 0;
            password.max = 0;
            password.req = 'c';
            password.pwd = "hello";

            char* str = new char [line.length()+1];
            std::strcpy(str, line.c_str() );

            char* token = strtok(str, "- :");

            std::cout << "Processing line: \"" << line << "\"" << std::endl;

            int state = 0;
            while ( token != NULL )
            {
                if ( state == 0 )
                {
                    password.min = atoi(token);
                    std::cout << "\tFound min: " << password.min << std::endl;
                    state = 1;
                }
                else if ( state == 1 )
                {
                    password.max = atoi(token);
                    std::cout << "\tFound max: " << password.max << std::endl;
                    state = 2;
                }
                else if ( state == 2 )
                {
                    password.req = *token;
                    std::cout << "\tFound req: " << password.req << std::endl;
                    state = 3;
                }
                else if ( state == 3 )
                {
                    password.pwd = std::string(token);
                    std::cout << "\tFound pwd: " << password.pwd << std::endl;
                    state = 0;
                }
                token = strtok(NULL, "- :");
            }
            delete[] str;
            input.push_back(password);
        }

    }

    int num_valid = 0;
    for ( auto item : input )
    {
        if ( validate_password_B(item) )
        {
            num_valid++;
        }
    }

    std::cout << "Found " << num_valid << " valid passwords!" << std::endl;

}
