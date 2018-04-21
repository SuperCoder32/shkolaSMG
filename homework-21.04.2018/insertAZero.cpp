//vuvejda se sortiran masiv
//vuvejda se sushtia masiv sus insertnata 0 niakude bez 0 i posledno miasto
//da se nameri indexa na 0 bez lineino tursene(priemame che ne moje da da q namerim
// po vreme na vuvejdaneto)

#include <iostream>
using namespace std;

const int MAXN = 1000000;
int n;
int originArr[MAXN];
int insertedArr[MAXN + 1];

int indexOfZero() {
	int start = 0, end = n;
	while (start < end) {
		int middle = (end - start) / 2 + start;
		if (insertedArr[middle] == 0) {
			return middle;
		} else if (insertedArr[middle] == originArr[middle]) {
			start = middle + 1;
		} else {
			end = middle;
		}
	}
	return -1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> originArr[i];
	}
	for (int i = 0; i < n + 1; i++) {
		cin >> insertedArr[i];
	}

	cout << indexOfZero();

	return 0;
}