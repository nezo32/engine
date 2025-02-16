#include "TextureSubSystem.h"

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}


TextureSubSystem::TextureSubSystem(const char* path) {
	std::string tmp = std::string(path);

    int channels = SOIL_LOAD_RGB;
    GLint textureChannels = GL_RGB;
    if (split(tmp, ".").back() == "png") {
        channels = SOIL_LOAD_RGBA;
        textureChannels = GL_RGBA;
    }

	unsigned char* image = SOIL_load_image(path, &width, &height, NULL, channels);

    if (image) {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, textureChannels, width, height, 0, textureChannels, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cerr << "ERROR :: TextureSystem :: Failed to load image - '" << path << "'\n";
        throw std::exception();
    }

    glActiveTexture(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    SOIL_free_image_data(image);
}

TextureSubSystem::~TextureSubSystem() {

}

void TextureSubSystem::ConfigTextureParams() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void TextureSubSystem::Activate(GLenum type, GLuint texture) {
    glActiveTexture(type);
    glBindTexture(GL_TEXTURE_2D, texture);
}