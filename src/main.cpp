// Copyright 2021 GHA Test Team
#include <iostream>
#include "textgen.h"

int main() {
    std::string txt;

    txt = ReadFile("text.txt");
    TextGenerator gen = TextGenerator();
    std::string ans = gen.GenerationText(txt);

    WriteFile(ans);
}
