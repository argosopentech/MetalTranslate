#include <string>

#include "MetalTranslateConfig.h"

namespace MetalTranslate {
class MetalTranslate {
public:
  MetalTranslate(MetalTranslateConfig config);
  std::string Translate(std::string source, std::string source_code,
                        std::string target_code);

private:
  MetalTranslateConfig _config;
};
} // namespace MetalTranslate
