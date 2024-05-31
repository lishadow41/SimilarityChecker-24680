#include <string>
#include <utility>
using namespace std;

class SimilarityChecker
{
public:
	SimilarityChecker() = default;
	virtual ~SimilarityChecker() = default;

public:
	int getLengthScore(const string& firstStr, const string& secondStr) {
		int longLength = getLongLength(firstStr, secondStr);
		int shortLength = getShortLength(firstStr, secondStr);
		return getLengthScore(longLength, shortLength);
	}

	int getLengthScore(int longStrLength, int shortStrLength) {
		if (isLengthSame(longStrLength, shortStrLength)) return 60;
		if (isLengthZeroScore(longStrLength, shortStrLength)) return 0;
		return getLengthPartScore(longStrLength, shortStrLength);
	}

	int getLongLength(const std::string& firstStr, const std::string& secondStr) {
		return max(firstStr.length(), secondStr.length());
	}

	int getShortLength(const std::string& firstStr, const std::string& secondStr) {
		return min(firstStr.length(), secondStr.length());
	}

	bool isLengthSame(int longStrLength, int shortStrLength) {
		return longStrLength == shortStrLength;
	}

	bool isLengthZeroScore(int longStrLength, int shortStrLength) {
		return longStrLength / 2 >= shortStrLength;
	}

	int getLengthPartScore(int longStrLength, int shortStrLength) {
		int gap = longStrLength - shortStrLength;
		return 60 - 60 * (double)gap / (double)shortStrLength;
	}
};
