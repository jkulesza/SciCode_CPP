#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "SciCodeIO.hpp"

using namespace std;

int main(int argc, char* argv[]) {

  cout.precision(3);
  cout << std::scientific;

  // Get input file name from command line.
  inputParameters myInput(argv[1]);

  // Perform calculation.


  // Output results.
  cout << myInput.title << endl;

  for(int i = 0; i < myInput.xmesh.size(); i++) {
    cout << myInput.xmesh[i] << endl;
  }

  return(0);

}
