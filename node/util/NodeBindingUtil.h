#ifndef UTIL_H
#define UTIL_H
#include <napi.h>
#define TIMEOUT_VALUE 5L
namespace NodeBinding
{
struct ImageContent
{
    char *memory;
    unsigned int size;
};
enum PIC_FORMAT
{
    PNG_FORAMT,
    JPEG_FORMAT,
    UNKOWN_PIC_FORMAT,
};
PIC_FORMAT getPicFormatFromContent(char *content, int len);
void decodeFromJEPGImage(std::vector<unsigned char> &pixels, unsigned int &width, unsigned int &height, const unsigned char *content, int len);
void decodeFromPNGImage(std::vector<unsigned char> &pixels, unsigned int &width, unsigned int &height, const unsigned char *content, int len);
int readLocalImage(const std::string &path, ImageContent *content);
bool checkArgs(const Napi::CallbackInfo &info, int exectedN);
unsigned int downloadImage(const std::string &src, ImageContent *content);
void throwError(const Napi::CallbackInfo &info, const std::string &exception);
void throwError(const Napi::Env &env, const std::string &exception);
} // namespace NodeBinding
#endif