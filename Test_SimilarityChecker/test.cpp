#include "pch.h"
#include "../TDD_SimilarityChecker/similarity_checker.cpp"

TEST(SimilarityChecker, Empty) {
	SimilarityChecker checker;
	EXPECT_EQ(1, 1);
}
