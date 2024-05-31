#include "pch.h"
#include "../TDD_SimilarityChecker/similarity_checker.cpp"

TEST(SimilarityChecker, SameLength) {
	SimilarityChecker checker;
	int n = checker.check("ABD", "GED");
	EXPECT_EQ(n, 60);
}

TEST(SimilarityChecker, LengthScoreZero) {
	SimilarityChecker checker;
	int n = checker.check("A", "BB");
	EXPECT_EQ(n, 0);
}

TEST(SimilarityChecker, LengthPartScore1) {
	SimilarityChecker checker;
	int n = checker.check("AAABB", "BAA");
	EXPECT_EQ(n, 20);
}

TEST(SimilarityChecker, LengthPartScore2) {
	SimilarityChecker checker;
	int n = checker.check("AA", "AAE");
	EXPECT_EQ(n, 30);
}
