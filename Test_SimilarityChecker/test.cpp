#include "pch.h"
#include "../TDD_SimilarityChecker/similarity_checker.cpp"

class SimilarityCheckParamFixture : public testing::TestWithParam<std::tuple<string, string, int>>
{
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckParamFixture, SameLength) {
	EXPECT_EQ(checker.getLengthScore("ABD", "GED"), 60);
}

class SimilarityCheckLengthZeroScoreParamFixture : public SimilarityCheckParamFixture {
};

TEST_P(SimilarityCheckLengthZeroScoreParamFixture, LengthScoreZero) {
	string firstString = std::get<0>(GetParam());
	string secondString = std::get<1>(GetParam());
	int expectedScore = std::get<2>(GetParam());
	EXPECT_EQ(checker.getLengthScore(firstString, secondString), expectedScore);
}

INSTANTIATE_TEST_CASE_P(
	SimilarityCheckLengthZeroScoreParamFixtures,
	SimilarityCheckLengthZeroScoreParamFixture,
	::testing::Values(
		std::make_tuple("A", "BB", 0),
		std::make_tuple("As", "BBdfa", 0),
		std::make_tuple("Aasdfdafd", "BB", 0)
	)
);

class SimilarityCheckLengthPartScoreParamFixture : public SimilarityCheckParamFixture {
};

TEST_P(SimilarityCheckLengthPartScoreParamFixture, LengthPartScore) {
	string firstString = std::get<0>(GetParam());
	string secondString = std::get<1>(GetParam());
	int expectedScore = std::get<2>(GetParam());
	EXPECT_EQ(checker.getLengthScore(firstString, secondString), expectedScore);
}

INSTANTIATE_TEST_CASE_P(
	SimilarityCheckLengthPartScoreParamFixtures,
	SimilarityCheckLengthPartScoreParamFixture,
	::testing::Values(
		std::make_tuple("AAABB", "BAA", 20),
		std::make_tuple("AA", "AAE", 30),
		std::make_tuple("AAABBvdfe", "BAAdfeg", 42),
		std::make_tuple("AAdfsf", "AAdfadsfasE", 10)
	)
);
