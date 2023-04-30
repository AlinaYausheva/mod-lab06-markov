// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(TestCaseName1, TestName1) {
    std::string txt = ReadFile("text.txt");
    TextGenerator gen = TextGenerator(2, 100);
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
    std::string txt = ReadFile("text2.txt");
    TextGenerator gen = TextGenerator(2, 100);
    gen.GenerationText(txt);

    prefix pr1;
    pr1.push_back("is");
    pr1.push_back("the");

    EXPECT_EQ(5, gen.statetab[pr1].size());
}

TEST(TestCaseName4, TestName4) {
    std::string txt = ReadFile("text2.txt");
    TextGenerator gen = TextGenerator(2, 100);
    gen.GenerationText(txt);

    prefix pr1;
    pr1.push_back("killed");
    pr1.push_back("the");

    EXPECT_EQ(2, gen.statetab[pr1].size());
}

TEST(TestCaseName5, TestName5) {
    std::string txt = ReadFile("text2.txt");
    TextGenerator gen = TextGenerator(2, 100);
    gen.GenerationText(txt);

    prefix pr1;
    pr1.push_back("killed");
    pr1.push_back("the");
    int index = std::rand() % gen.statetab[pr1].size();

    EXPECT_EQ("rat", gen.statetab[pr1].at(index));
}

TEST(TestCaseName6, TestName6) {
    std::string txt = ReadFile("text2.txt");
    TextGenerator gen = TextGenerator(2, 100);
    gen.GenerationText(txt);

    prefix pr1;
    pr1.push_back("is");
    pr1.push_back("the");
    int index = 1;

    EXPECT_EQ("malt", gen.statetab[pr1].at(index));
}

TEST(TestCaseName7, TestName7) {
    std::string txt = ReadFile("text.txt");
    TextGenerator gen = TextGenerator(4, 100);
    std::string ans = gen.GenerationText(txt);

    EXPECT_EQ(100, SplitText(ans).size());
}
