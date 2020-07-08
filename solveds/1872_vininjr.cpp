#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int cases;
    vector < double > output;

    cin >> cases;

    while (cases--) {
        string number = "";
        cin >> number;
        int i;
        bool point = false;
        int fin = number.size()-1;
        
        while(number[fin] == '0') fin--;
        if(number[fin] == '.') fin--;

        number = number.substr(0, fin+1);

        for (i = 0; i < number.size(); i++) {
            if (number[i] == '.') {
                point = true;
                break;
            }
        }

        if (!point) number += ".000";

        string integer, dec;
        integer = number.substr(0, i);
        dec = "0.";
        dec += number.substr(i + 1, number.size());

        double numero = stod(number);
        double decimal = stod(dec);
        double result;
        string revert = integer;
        reverse(revert.begin(), revert.end());

        if (revert == integer && dec == "0.000") {
            result = 0;
        } 
        else {
            revert = "0." + revert;
            double num = stod(revert);
            result = 0;

            if (num < decimal) {
                int i = stoi(integer);
                i++;
                integer = to_string(i);
                revert = integer;
                reverse(revert.begin(), revert.end());
                if (revert == integer) {
                    num = stod(revert);
                    result = num - numero;
                } else {
                    revert = "0." + revert;
                    num = 1.0;
                    num += stod(revert);
                    result = num - decimal;
                }
            } else {
                result = num - decimal;
            }
        }
        output.push_back(result);
    }

    for (int i = 0; i < output.size(); ++i) {
        printf("%lf\n", output[i]);
    }
}