#include <string>

namespace MetalTranslate {
class MetalTranslateConfig {
public:
  std::string ModelPath = "models/translate-fairseq_m2m_100_418M/";
};

class MetalTranslate {
public:
  MetalTranslate(MetalTranslateConfig config);
  std::string Translate(std::string source, std::string source_code,
                        std::string target_code);

private:
  MetalTranslateConfig _config;
};
} // namespace MetalTranslate
