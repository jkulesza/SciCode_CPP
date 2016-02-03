#ifndef SciCodeIO_H
#define SciCodeIO_H

std::vector<double> makeDblVectorFromStr(std::string const& fromStr);

class inputParameters {
  public:
    inputParameters(const char* inFilename);
    ~inputParameters();
    std::string title;
    std::string author;
    std::string genre;
    std::string price;
  
    std::vector<double> xmesh;  
    std::vector<double> ymesh;
    std::vector<double> zmesh;

  private:
};

#endif
