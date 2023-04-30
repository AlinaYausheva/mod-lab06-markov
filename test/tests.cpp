// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "generator.h"

TEST(TestCaseName1, TestName1) {
    std::string txt = ReadFile("text.txt");
    TextGenerator gen = TextGenerator(2,100);
    gen.GenerationText(txt);

    for (prefix pr : gen.Prefixes) {
        EXPECT_EQ(2, pr.size());
    }
}

TEST(TestCaseName2, TestName2) {
    std::string txt = ReadFile("text.txt");
    TextGenerator gen = TextGenerator(4, 100);
    gen.GenerationText(txt);

    for (prefix pr : gen.Prefixes) {
        EXPECT_EQ(4, pr.size());
    }  
}

TEST(TestCaseName3, TestName3) {
    std::string txt = ReadFile("text.txt");
    TextGenerator gen = TextGenerator(2, 100);
    gen.GenerationText(txt);

    prefix pr1;
    pr1.push_back("Пришел");
    pr1.push_back("невод");

    EXPECT_EQ(3, gen.statetab[pr1].size());
}

TEST(TestCaseName4, TestName4) {
    std::string txt = ReadFile("text.txt");
    TextGenerator gen = TextGenerator(2, 100);
    gen.GenerationText(txt);

    prefix pr1;
    pr1.push_back("тридцать");
    pr1.push_back("лет");

    EXPECT_EQ(2, gen.statetab[pr1].size());
}

TEST(TestCaseName5, TestName5) {
    std::string txt = ReadFile("text.txt");
    TextGenerator gen = TextGenerator(2, 100);
    gen.GenerationText(txt);

    prefix pr1;
    pr1.push_back("моя");
    pr1.push_back("старуха");
    int index = rand() % gen.statetab[pr1].size();

    EXPECT_EQ("бунтует.", gen.statetab[pr1].at(index));
}

TEST(TestCaseName6, TestName6) {
    std::string txt = ReadFile("text.txt");
    TextGenerator gen = TextGenerator(2, 100);
    gen.GenerationText(txt);

    prefix pr1;
    pr1.push_back("государыня");
    pr1.push_back("рыбка!");
    int index = 1;

    EXPECT_EQ("Пуще", gen.statetab[pr1].at(index));
}

TEST(TestCaseName7, TestName7) {
    std::string txt = ReadFile("text.txt");
    TextGenerator gen = TextGenerator(4, 100);
    std::string ans = gen.GenerationText(txt);

    EXPECT_EQ(100, SplitText(ans).size());
}
