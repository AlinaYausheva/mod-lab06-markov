// Copyright 2021 GHA Test Team
#include "textgen.h"

TextGenerator::TextGenerator() {
    prefixNum = NPREF;
    maxGen = MAXGEN;
}

TextGenerator::TextGenerator(int p, int m) {
    prefixNum = p;
    maxGen = m;
}

void TextGenerator::CreateStatetab(std::vector<std::string> words) {
    for (int i = 0; i < words.size()- prefixNum + 1; i++) {
        prefix pr = prefix();
        for (int j = 0; j < prefixNum; j++) {
            pr.push_back(words[i + j]);
        }

        if (i + prefixNum < words.size())
            statetab[pr].push_back(words[i + prefixNum]);
        else
            statetab[pr];

        if (statetab[pr].size() <= 1)
            Prefixes.push_back(pr);
    }
}

std::string TextGenerator::GenerationText(std::string text) {
    std::vector<std::string> words = SplitText(text);
    CreateStatetab(words);
    std::string result = "";
    prefix pr = Prefixes[0];
    for (int j = 0; j < prefixNum; j++) {
        result += pr[j] + " ";
    }
    int index;
    for (int i = 0; i < maxGen - prefixNum; i++) {
        if (statetab[pr].size() == 0) {
            index = rand_r() % statetab.size() - 1;
            pr = Prefixes[index];
            for (int j = 0; j < prefixNum; j++) {
                result += pr[j] + " ";
            }
        }
        index = rand_r() % statetab[pr].size();
        std::string nextWord = statetab[pr].at(index);
        result += nextWord + " ";
        pr.pop_front();
        pr.push_back(nextWord);
    }

    return result;
}

std::string ReadFile(std::string title) {
    std::string text;
    std::ifstream reading(title);
    if (reading.is_open()) {
        std::string line;
        while (std::getline(reading, line)) {
            text += line + " ";
        }
    }
    reading.close();
    return text;
}

void WriteFile(std::string info) {
    std::ofstream writing("result.txt");

    if (writing.is_open()) {
        writing << info << std::endl;
    }
    writing.close();
}

std::vector<std::string> SplitText(std::string text) {
    std::vector<std::string> words;
    std::string word = "";
    for (int i = 0; i < text.size(); i++) {
        if (text[i] != ' ') {
            word += text[i];
        } else {
            words.push_back(word);
            word = "";
        }
    }
    return words;
}
