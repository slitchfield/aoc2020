
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

int main(int argc, char** argv)
{

    const char* filename = "input.txt";
    std::fstream file;
    std::string line;
    file.open(filename);

    std::vector<int> input;

    if(file.is_open())
    {
        while(std::getline(file, line))
        {
            input.push_back(stoi(line));
        }

    }

    bool found = false;
    for (int i = 0; i < input.size(); i++ )
    {
        for ( int j = 0; j < input.size(); j++ )
        {
            if ( !found && input[i] + input[j] == 2020 )
            {
                std::cout << "The first answer is: " << input[i] * input[j] << std::endl;
                found = true;
            }
        }
    }
   
    found = false;
    for (int i = 0; i < input.size(); i++ )
    {
        for ( int j = 0; j < input.size(); j++ )
        {
            for ( int k = 0; k < input.size(); k++ )
            {
                if ( ((input[i] + input[j] + input[k]) == 2020) && !found )
                {
                    std::cout << "The second answer is: " << input[i] * input[j] * input[k] << std::endl;
                    found = true;
                }
            }
        }
    }
}
