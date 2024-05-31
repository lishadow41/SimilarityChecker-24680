#include "pch.h"
#include "../TDD_SimilarityChecker/similarity_checker.cpp"

class SimilarityCheckFixture : public testing::Test
{
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckFixture, SameLength) {
	EXPECT_EQ(checker.getLengthScore("ABD", "GED"), 60);
}

TEST_F(SimilarityCheckFixture, LengthScoreZero) {
	EXPECT_EQ(checker.getLengthScore("A", "BB"), 0);
}

TEST_F(SimilarityCheckFixture, LengthPartScore) {
	EXPECT_EQ(checker.getLengthScore("AAABB", "BAA"), 20);
	EXPECT_EQ(checker.getLengthScore("AA", "AAE"), 30);
}
