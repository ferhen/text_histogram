#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

// Read file content as std::string from filepath
std::string readFile(std::string const& filepath)
{
    std::ifstream t(filepath);
    std::stringstream buffer;
    buffer << t.rdbuf();

    return buffer.str();
}

// Count letters in std::string using std::map
std::map<char, uint8_t> countLetters(std::string text)
{
    std::map<char, uint8_t> letter_map;
    for (char& c : text)
    {
        if (isalpha(c)) 
        {
            letter_map[char(tolower(c))] += 1;
        }
    }

    return letter_map;
}

// Transform std::map into std::vector\<std::pair> and sort by values first and letters second
std::vector<std::pair<char, uint8_t>> sortLetterCount(std::map<char, uint8_t> letter_map) 
{
    std::vector<std::pair<char, uint8_t>> letter_vector(letter_map.begin(), letter_map.end());
    sort(letter_vector.begin(), letter_vector.end(), [](std::pair<char, uint8_t> &left, std::pair<char, uint8_t> &right) { 
        if (left.second == right.second) {
            return left.first < right.first;
        }
        return left.second > right.second; 
    });

    return letter_vector;
}

// Execute logic and print out the result
void run(std::string const& filepath)
{
    std::string text = readFile(filepath);
    std::map<char, uint8_t> letter_map = countLetters(text);
    std::vector<std::pair<char, uint8_t>> sorted_letter_vector = sortLetterCount(letter_map);
    for (auto const& value : sorted_letter_vector)
    {
        std::cout << value.first << " " << (int)value.second << std::endl;
    }
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
        run(argv[i]);
        std::cout << std::endl;
    }
}