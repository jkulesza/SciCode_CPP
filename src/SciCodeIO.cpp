#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "pugixml.hpp"
#include "SciCodeIO.hpp"

// Converts a string read from an input file made up of a list of values to a
// vector of doubles.
std::vector<double> makeDblVectorFromStr(std::string const &fromStr)
{
  std::istringstream iss(fromStr);

  return std::vector<double>{
    std::istream_iterator<double>(iss),
    std::istream_iterator<double>()
  };
}

// Constructor.
inputParameters::inputParameters(const char* inFilename) {

  pugi::xml_document doc;
  doc.load_file(inFilename);

  try {
    if(!doc.load_file(inFilename)) {
      throw("Failed to read inputfile.");
    }
  } catch(const char* err) {
    std::cout << "An exception occurred: " << err << std::endl;
  }

  // Read scalar input variables.
  pugi::xml_node scalars = doc.child("input").child("scalars");
  title        = scalars.child_value("title");
  author       = scalars.child_value("author");
  genre        = scalars.child_value("genre");
  price        = scalars.child_value("price");

  pugi::xml_node arrays = doc.child("input").child("arrays");

  xmesh = makeDblVectorFromStr(arrays.child_value("xmesh"));

}

// Destructor.
inputParameters::~inputParameters() { }

