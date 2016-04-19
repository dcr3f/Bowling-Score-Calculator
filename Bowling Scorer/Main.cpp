#include <iostream>

using namespace std;

enum single {Strike = 10, Spare};

struct frame {
	int firstBowl;
	int secondBowl;
	int thirdBowl;
};

void getFrames(frame []);
int calcScore(frame []);

int main()
{
	frame frames[10];

	getFrames(frames);
	calcScore(frames);
	system("pause");
	return 0;
}

void getFrames(frame frames[])
{
	char temp;
	
	for (int i = 0; i < 10; i++)
	{
		int pins = 10;
		if (i < 9) {
			cout << "Input first bowl for frame " << i + 1 << ":" << endl;
			cin >> temp;
			if (temp == 'x' || temp == 'X') {
				frames[i].firstBowl = Strike;
			}
			else {
				frames[i].firstBowl = temp - '0';
				pins = 10 - (temp - '0');
				cout << "Input second bowl for frame " << i + 1 << ":" << endl;
				cin >> temp;
				if (temp == '/') {
					frames[i].secondBowl = Spare;
					frames[i].thirdBowl = 0;
				}
				else if ((temp - '0') >= pins) {
					frames[i].secondBowl = Spare;
					frames[i].thirdBowl = 0;
				}
				else {
					frames[i].secondBowl = temp - '0';
					frames[i].thirdBowl = 0;
				}
			}
		}
		else {
			cout << "Input first bowl for final frame:" << endl;
			cin >> temp;
			if (temp == 'x' || temp == 'X') {
				frames[i].firstBowl = Strike;
				pins = 10;
				cout << "Input second bowl for final frame (Can't be '/'):" << endl;
				cin >> temp;
				if (temp == 'x' || temp == 'X') {
					frames[i].secondBowl = Strike;
				}
				else {
					frames[i].secondBowl = temp - '0';
					pins = 10 - (temp - '0');
				}
				cout << "Input third bowl for final frame:" << endl;
				cin >> temp;
				if (temp == 'x' || temp == 'X') {
					frames[i].thirdBowl = Strike;
				}
				else if (temp == '/') {
					frames[i].thirdBowl = Spare;
				}
				else if ((temp - '0') >= pins) {
					frames[i].thirdBowl = Spare;
				}
				else {
					frames[i].thirdBowl = temp - '0';
				}
			}
			else {
				frames[i].firstBowl = temp - '0';
				pins = 10 - (temp - '0');
				cout << "Input second bowl for final frame:" << endl;
				cin >> temp;
				if (temp == '/') {
					frames[i].secondBowl = Spare;
					cout << "Input third bowl for final frame:" << endl;
					cin >> temp;
					if (temp == 'x' || temp == 'X') {
						frames[i].thirdBowl = Strike;
					}
					else {
						frames[i].thirdBowl = temp - '0';
					}
				}
				else if ((temp - '0') >= pins) {
					frames[i].secondBowl = Spare;
					cout << "Input third bowl for final frame:" << endl;
					cin >> temp;
					if (temp == 'x' || temp == 'X') {
						frames[i].thirdBowl = Strike;
					}
					else {
						frames[i].thirdBowl = temp - '0';
					}
				}
				else {
					frames[i].secondBowl = temp - '0';
					frames[i].thirdBowl = 0;
				}
			}
		}
	}
	cout << "Overall Frames:" << endl;
	for (int z = 1; z < 11; z++) {
		cout << "Frame " << z << "\t";
	}
	cout << endl;
	for (int k = 0; k < 10; k++) {
		if (k < 9) {
			if (frames[k].firstBowl == Strike) {
				cout << "X" << "\t";
			}
			else {
				cout << frames[k].firstBowl << " ";
				if (frames[k].secondBowl == Spare) {
					cout << "/" << "\t";
				}
				else {
					cout << frames[k].secondBowl << "\t";
				}
			}
		}
		else {
			if (frames[k].firstBowl == Strike) {
				cout << "X" << " ";
			}
			else {
				cout << frames[k].firstBowl << " ";
				if (frames[k].secondBowl == Spare) {
					if (frames[k].thirdBowl == Strike) {
						cout << "/" << " " << frames[k].thirdBowl << endl;
					}
					else {
						cout << "/" << frames[k].thirdBowl << endl;
					}
				}
				else {
					cout << frames[k].secondBowl << endl;
				}
			}
			if (frames[k].secondBowl == Strike) {
				cout << "X" << " ";
			}
			else {
				cout << frames[k].secondBowl << " ";
				if (frames[k].thirdBowl == Spare) {
					cout << "/" << endl;
				}
				else {
					cout << frames[k].thirdBowl << endl;
				}
			}
			if (frames[k].thirdBowl == Strike) {
				cout << "X" << endl;
			}

		}
	}
}

int calcScore(frame frames[]) {
	int total = 0;
	int frameTotal[10];
	for (int i = 0; i < 10; i++) {
		if (i < 8) {
			if (frames[i].firstBowl == Strike) {
				if (frames[i + 1].firstBowl == Strike) {
					frameTotal[i] = frames[i].firstBowl + frames[i + 1].firstBowl + frames[i + 2].firstBowl;
					total = total + frameTotal[i];
				}
				else if (frames[i+1].secondBowl == Spare) {
					frameTotal[i] = frames[i].firstBowl + 10;
					total = total + frameTotal[i];
				}
				else {
					frameTotal[i] = frames[i].firstBowl + frames[i + 1].firstBowl + frames[i + 1].secondBowl;
					total = total + frameTotal[i];
				}
			}
			else if (frames[i].secondBowl == Spare) {
				frameTotal[i] = 10 + frames[i + 1].firstBowl;
				total = total + frameTotal[i];
			}
			else {
				frameTotal[i] = frames[i].firstBowl + frames[i].secondBowl;
				total = total + frameTotal[i];
			}
		}
		else if(i == 8){
			if (frames[i].firstBowl == Strike) {
				if (frames[i + 1].secondBowl == Spare) {
					frameTotal[i] = frames[i].firstBowl + 10;
					total = total + frameTotal[i];
				}
				else {
					frameTotal[i] = frames[i].firstBowl + frames[i + 1].firstBowl + frames[i + 1].secondBowl;
					total = total + frameTotal[i];
				}
			}
			else if (frames[i].secondBowl == Spare) {
				frameTotal[i] = frames[i + 1].firstBowl + 10;
				total = total + frameTotal[i];
			}
			else {
				frameTotal[i] = frames[i].firstBowl + frames[i].secondBowl;
				total = total + frameTotal[i];
			}
		}
		else {
			if (frames[i].firstBowl == Strike) {
				if (frames[i].thirdBowl == Spare) {
					frameTotal[i] = 20;
					total = total + frameTotal[i];
				}
				else if (frames[i].thirdBowl = Strike) {
					frameTotal[i] = 30;
					total = total + frameTotal[i];
				}
				else {
					frameTotal[i] = 10 + frames[i].secondBowl + frames[i].thirdBowl;
					total = total + frameTotal[i];
				}
			}
			else if (frames[i].secondBowl == Spare) {
				frameTotal[i] = 10 + frames[i].thirdBowl;
				total = total + frameTotal[i];
			}
			else {
				frameTotal[i] = frames[i].firstBowl + frames[i].secondBowl;
				total = total + frameTotal[i];
			}
		}
		cout << total << "\t";
	}
	cout << endl;
	return total;
}