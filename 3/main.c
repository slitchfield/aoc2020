
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

typedef struct map
{
    int numcols;
    int numrows;
    std::vector<std::string> rows;
} map_t;

int count_trees(map_t map, int dx, int dy);

int main(int argc, char** argv)
{

    const char* filename = "input.txt";
    std::fstream file;
    std::string line;
    file.open(filename);

    map_t map;
    map.numcols = 0;
    map.numrows = 0;

    if(file.is_open())
    {
        while(std::getline(file, line))
        {
            if ( map.numcols == 0 ) map.numcols = line.length();
            else if ( map.numcols != line.length() )
            {
                std::cout << "Found strange map!" << std::endl;
                std::cout << "\tmap.numcols: " << map.numcols << " | line.length(): " << line.length() << std::endl;
                return 0;
            }

            map.rows.push_back(line);
            map.numrows++;
        }

    }

    std::cout << "Final Map: (Cols: " << map.numcols << "| Rows: " << map.numrows << ")" << std::endl;

    for ( auto line : map.rows )
    {
        std::cout << "\t" << line << std::endl;
    }

    printf("We'll hit %u trees\n", 1);
    unsigned int num_trees = count_trees(map, 1, 1);
    printf("We'll hit %u trees\n", num_trees);
    num_trees *= count_trees(map, 3, 1);
    printf("We'll hit %u trees\n", num_trees);
    num_trees *= count_trees(map, 5, 1);
    printf("We'll hit %u trees\n", num_trees);
    num_trees *= count_trees(map, 7, 1);
    printf("We'll hit %u trees\n", num_trees);
    num_trees *= count_trees(map, 1, 2);
    printf("We'll hit %u trees\n", num_trees);
}

int count_trees(map_t map, int dx, int dy)
{

    int x = 0;
    int y = 0;
    int num_trees = 0;

    while ( y < map.numrows )
    {
        if ( map.rows[y][x] == '#' )
        {
            num_trees++;
        }
        x = (x + dx) % map.numcols;
        y = y + dy;
    }
    return num_trees;
}
