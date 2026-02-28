#include "arguments.h"

#include <iostream>
#include <string>

static bool isNumber(const std::string &str) {
  std::string::const_iterator iterator = str.begin();
  while (iterator != str.end() && std::isdigit(*iterator)) {
    iterator++;
  }

  return !str.empty() && iterator == str.end();
}

Arguments::Arguments(int argc, char **argv) {
  handleArgs(argc, argv);
}

Arguments::~Arguments() {

}

bool Arguments::getIsOutputANSI() const {
  return m_isOutputANSI;
}

double Arguments::getAspectRatio() const {
  return m_aspectRatio;
}

std::uint32_t Arguments::getWidth() const {
  return m_width;
}

std::uint32_t Arguments::getHeight() const {
  return m_height;
}

void Arguments::handleArgs(int argc, char **argv) {
  for (std::size_t i = 1; i < argc; i++) {
    std::string arg = argv[i];

    if (arg == "--ppm") {
      m_isOutputANSI = false;
    } else if (arg == "--ansi") {
      m_isOutputANSI = true;
    } else if (arg == "--width") {
      std::size_t nextIndex = i + 1;
      if (nextIndex < argc && isNumber(argv[i + 1])) {
        m_width = std::stoi(argv[i + 1]);
        i++;
      }
    } else if (arg == "--aspect") {
      std::size_t nextIndex = i + 1;
      if (nextIndex < argc) {
        std::string aspectStr = argv[nextIndex];

        std::size_t colonIndex = aspectStr.find(':');
        if (colonIndex != std::string::npos) {
          std::string widthStr = aspectStr.substr(0, colonIndex);
          std::string heightStr = aspectStr.substr(colonIndex + 1);

          double width = (isNumber(widthStr)) ? std::stod(widthStr) : 16.0;
          double height = (isNumber(heightStr)) ? std::stod(heightStr) : 9.0;

          m_aspectRatio = width / height;
        }

        i++;
      }
    } else {
      std::cerr << "Unknown argument: " << argv[i] << '\n';
    }
  }

  if (m_width == 0) {
    m_width = (m_isOutputANSI) ? 64 : 1920;
  }

  m_height = m_width / static_cast<double>(m_aspectRatio);
  if (m_isOutputANSI) {
    m_height /= 2;
  }
}
