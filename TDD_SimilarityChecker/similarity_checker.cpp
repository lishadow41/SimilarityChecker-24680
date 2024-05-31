#include <string>
using namespace std;

class SimilarityChecker
{
public:
	SimilarityChecker() = default;
	virtual ~SimilarityChecker() = default;

public:
	int check(const string& a, const string& b) {
		if (a.length() == b.length()) return 60;

		int longLength = a.length();
		int shortLength = b.length();
		if (longLength < shortLength) {
			int temp = longLength;
			longLength = shortLength;
			shortLength = temp;
		}

		if (longLength / 2 >= shortLength) return 0;

		int gap = longLength - shortLength;
		int score = 60 - 60 * gap / shortLength;
		return score;
	}
};
