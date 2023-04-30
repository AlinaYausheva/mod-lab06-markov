#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include <map>
#include <deque>
#include <vector>
#include <random>

typedef std::deque<std::string> prefix;

class TextGenerator {
public:
    static const int NPREF = 2;
    static const int MAXGEN = 1000;
    int prefixNum;
    int maxGen;
    TextGenerator();
    TextGenerator(int p, int m);
    std::vector<prefix> Prefixes;
    std::map<prefix, std::vector<std::string> > statetab;
    void CreateStatetab(std::vector<std::string> words);
    std::string GenerationText(std::string text);
};
std::string ReadFile(std::string title);
void WriteFile(std::string text);
std::vector<std::string> SplitText(std::string text);