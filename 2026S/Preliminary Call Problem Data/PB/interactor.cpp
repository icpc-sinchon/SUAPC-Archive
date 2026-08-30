#include "testlib.h"
#include <string>
using namespace std;

int main(int argc, char **argv) {
    registerInteraction(argc, argv);

    int T = inf.readInt();

    if (T == 1) {
        // Original password
        string password = inf.readToken();

        // Send first-step input to participant
        cout << "1\n";
        cout << password << endl;

        // Read participant's hint
        string hint = ouf.readToken();

        // Must be exactly 8 digits
        if (hint.size() != 8) {
            quitf(_wa, "Hint must contain exactly 8 digits");
        }

        for (int i = 0; i < 8; ++i) {
            if (hint[i] < '0' || hint[i] > '9') {
                quitf(_wa, "Hint contains a non-digit");
            }

            if (hint[i] == password[i]) {
                quitf(_wa, "Hint matches password at position %d", i + 1);
            }
        }

        // Data for the second invocation.
        // The last field is hidden from the participant,
        // but is needed by the second interactor to verify the answer.
        tout << "2\n";
        tout << hint << '\n';
        tout << password << '\n';

        quitf(_ok, "First step accepted");
    }

    else if (T == 2) {
        string hint = inf.readToken();
        string password = inf.readToken();

        // Send second-step input to participant
        cout << "2\n";
        cout << hint << endl;

        // Read reconstructed password
        string answer = ouf.readToken();

        if (answer != password) {
            quitf(_wa, "Wrong password");
        }


        if (!ouf.seekEof()) {
            quitf(_pe, "Extra tokens");
        }

        // checker에게 전달
        tout << answer << '\n';

        quitf(_ok, "Second run accepted");
    }

    else {
        quitf(_fail, "Invalid internal T");
    }
}