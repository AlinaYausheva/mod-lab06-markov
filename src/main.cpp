#include <iostream>
#include "generator.h"

int main() {
    std::string txt;

    txt = ReadFile("text.txt");
    TextGenerator gen = TextGenerator();
    std::string ans = gen.GenerationText(txt);

    WriteFile(ans);
}