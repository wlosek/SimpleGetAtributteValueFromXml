#include <iostream>
#include <string>
#include <exception>
#include <fstream>

int main(int argc, char *argv[])
{
  std::string pathToFile {""};
  std::string tagName {""};
  std::string attributeName {""};
  std::cin >> pathToFile >> tagName >> attributeName;
  if (pathToFile.empty()) {
      std::logic_error("pathToFile is empty");
  }
  if (tagName.empty()) {
      std::logic_error("tagName is empty");
  }
  if (attributeName.empty()) {
      std::logic_error("attributeName is empty");
  }

  std::ifstream infile(pathToFile.c_str());
  std::string line {""};
  while (std::getline(infile, line)) {
    std::size_t foundTag = line.find({"<" + tagName});
    if (foundTag != std::string::npos) {
      std::size_t foundAttr = line.find({" " + attributeName + "="});
      if (foundAttr != std::string::npos) {
        bool foundValue {false};
        for(std::size_t i = foundAttr; i < line.size(); ++i)
        {
          if (line.at(i) == '"' && !foundValue) {
            foundValue = true;
            continue;
          } else if (line.at(i) == '"' && foundValue) {
            std::cout << std::endl;
            break;
          }

          if (foundValue) {
            std::cout << line.at(i);
          }
        }
      }

    }
  }
  return 0;
}
